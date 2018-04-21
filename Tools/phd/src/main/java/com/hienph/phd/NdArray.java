package com.hienph.phd;

import org.nd4j.linalg.api.ndarray.INDArray;
import org.nd4j.linalg.factory.Nd4j;

class NdArray {
  void example() {
    int nRows = 2;
    int nColumns = 2;
    // Create INDArray of zeros
    INDArray zeros = Nd4j.zeros(nRows, nColumns);
    // Create one of all ones
    INDArray ones = Nd4j.ones(nRows, nColumns);
    // vstack
    INDArray vstack = Nd4j.vstack(ones,zeros);
    System.out.println("### VSTACK ####");
    System.out.println(vstack);
  }
}
