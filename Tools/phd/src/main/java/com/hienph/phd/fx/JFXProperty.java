package com.hienph.phd.fx;

public class JFXProperty {
  public static void main(String[] args) {
    PersonObservable qq = new PersonObservable();

    qq.firstNameProperty().addListener((e, oldVal, newVal) -> {
      System.out.println(e.toString());
      System.out.println("oldval " + oldVal);
      System.out.println("newVal " + newVal);
    });

    PersonObservable ph = new PersonObservable();
    // bind ph with qq
    ph.firstNameProperty().bind(qq.firstNameProperty());
    ph.firstNameProperty().addListener((e, oldVal, newVal) -> {
      System.out.println("New val is now " + newVal);
    });

    qq.setFirstName("QQ now");

    qq.setFirstName("QQ later");


  }
}
