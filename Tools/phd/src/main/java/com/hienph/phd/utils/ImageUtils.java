package com.hienph.phd.utils;

import javafx.scene.image.Image;
import org.opencv.core.Mat;
import org.opencv.core.MatOfByte;
import org.opencv.imgcodecs.Imgcodecs;

import java.io.ByteArrayInputStream;

public class ImageUtils {
  /**
   * Convert opencv Matrix to java fx Image
   * @param original The opencv Matrix
   * @return Javafx Image instance
   */
  public static Image matToImage(Mat original) {
    MatOfByte byteMat = new MatOfByte();
    Imgcodecs.imencode(".bmp", original, byteMat);
    return new Image(new ByteArrayInputStream(byteMat.toArray()));
  }
}
