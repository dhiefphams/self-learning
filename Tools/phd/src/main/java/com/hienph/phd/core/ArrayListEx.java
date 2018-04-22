package com.hienph.phd.core;

import java.util.ArrayList;
import java.util.Iterator;

public class ArrayListEx {
  public static void main(String[] args) {
    ArrayList<Integer> numbers = new ArrayList<>(10);
    numbers.add(22);
    numbers.add(23);
    numbers.add(27);
    numbers.add(28);
    for (Integer i: numbers) {
      System.out.println(i);
    }
    numbers.removeIf(v -> v > 25);
    Iterator<Integer> it = numbers.iterator();
    while (it.hasNext()) {
      System.out.println(it.next());
    }
  }
}
