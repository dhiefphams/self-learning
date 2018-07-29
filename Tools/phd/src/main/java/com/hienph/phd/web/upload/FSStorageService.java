package com.hienph.phd.web.upload;

import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.stream.Stream;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.Resource;
import org.springframework.core.io.UrlResource;
import org.springframework.stereotype.Service;
import org.springframework.util.FileSystemUtils;
import org.springframework.util.StringUtils;
import org.springframework.web.multipart.MultipartFile;

@Service
public class FSStorageService implements StorageService {
  private final Path rootLocation;

  @Autowired
  FSStorageService(StorageProperties properties) {
    this.rootLocation = Paths.get(properties.getLocation());
  }

  @Override
  public void init() throws StorageException {
    try {
      Files.createDirectories(this.rootLocation);
    } catch (IOException e) {
      throw new StorageException("Could not initialize the storage", e);
    }
  }

  @Override
  public void store(MultipartFile file) throws StorageException {
    String filename = StringUtils.cleanPath(file.getOriginalFilename());
    if (file.isEmpty()) {
      throw new StorageException("Failed to store empty file " + filename);
    }
    if (filename.contains("..")) {
      // this is a security check
      throw new StorageException("Can not store file with relative path current dir " + filename);
    }
    try (InputStream inputStream = file.getInputStream()) {
      Files.copy(
        inputStream,
        this.rootLocation.resolve(filename),
        StandardCopyOption.REPLACE_EXISTING
      );
    } catch (IOException e) {
      throw new StorageException("Failed to store file" + file, e);
    }
  }

  @Override
  public Stream<Path> loadAll() throws StorageException {
    try {
      return Files.walk(this.rootLocation, 1)
        .filter(path -> !path.equals(this.rootLocation))
        .map(this.rootLocation::relativize);
    } catch (IOException e) {
      throw new StorageException("Failed to read stored files", e);
    }
  }

  @Override
  public Path load(String filename) {
    return this.rootLocation.resolve(filename);
  }

  @Override
  public Resource loadAsResource(String filename) throws StorageException {
    try {
      Path file = this.load(filename);
      Resource resource = new UrlResource(file.toUri());
      if (resource.exists() || resource.isReadable()) {
        return resource;
      }
      throw new StorageFileNotFoundException("Could not read file " + file.getFileName());
    } catch (MalformedURLException e) {
      throw new StorageFileNotFoundException("Could not read file " + filename, e);
    }
  }

  @Override
  public void deleteAll() throws StorageException {
    try {
      FileSystemUtils.deleteRecursively(this.rootLocation);
    } catch (IOException e) {
      throw new StorageException("Failed deleted the resources");
    }
  }
}
