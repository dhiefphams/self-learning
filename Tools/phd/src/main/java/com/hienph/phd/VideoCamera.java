package com.hienph.phd;

import org.opencv.core.Mat;
import org.opencv.videoio.VideoCapture;

public class VideoCamera {
  private VideoCapture camCapture;

  VideoCamera() {
    this.camCapture = new VideoCapture();
    this.camCapture.open(0);
  }

  public Mat frame() {
    Mat frame = new Mat();
    this.camCapture.read(frame);
    return frame;

  }

  public void release() {
    this.camCapture.release();

  }
}
