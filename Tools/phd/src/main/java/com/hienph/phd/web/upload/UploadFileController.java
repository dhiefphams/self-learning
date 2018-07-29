package com.hienph.phd.web.upload;

import java.util.List;
import java.util.stream.Collectors;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.mvc.method.annotation.MvcUriComponentsBuilder;

@RestController
public class UploadFileController {
  private StorageService storageService;

  @Autowired
  public UploadFileController(StorageService storageService) {
    this.storageService = storageService;
  }

  @GetMapping("/")
  public List<String> loadAllFiles() throws StorageException {
    return storageService.loadAll()
      .map(path -> MvcUriComponentsBuilder.fromMethodName(
        UploadFileController.class,
        "serveFile",
        path.getFileName().toString()).build().toString()
      )
      .collect(Collectors.toList());
  }

  @GetMapping("/{filename:.+}")
  public ResponseEntity<Resource> serveFile(@PathVariable String filename) throws StorageException {
    Resource file = storageService.loadAsResource(filename);
    return ResponseEntity
      .ok()
      .header(
        HttpHeaders.CONTENT_DISPOSITION,
        "attachment;filename=\"" + file.getFilename() + "\""
        )
      .body(file);
  }

  @PostMapping("/")
  public String handleUploadFile(
    @RequestParam("file") MultipartFile file) throws Exception {
    storageService.store(file);
    return file.getOriginalFilename();
  }

  @ExceptionHandler(Exception.class)
  public ResponseEntity<?> handleStorageFileNotfound(Exception err) {
    return ResponseEntity.notFound().build();
  }
}
