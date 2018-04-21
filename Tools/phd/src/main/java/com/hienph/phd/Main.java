package com.hienph.phd;

import org.opencv.core.Core;
import org.tensorflow.TensorFlow;


public class Main {
  static {
    System.out.println(Core.NATIVE_LIBRARY_NAME);
    System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
  }
  public static void main(String[] args) {
    System.out.println(Core.getIppVersion());
    System.out.println(TensorFlow.version());
    NdArray arr = new NdArray();
    arr.example();

    VideoCamera cam = new VideoCamera();
     cam.frame();
  }
}

