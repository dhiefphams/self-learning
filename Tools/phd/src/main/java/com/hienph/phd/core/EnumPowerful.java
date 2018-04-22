package com.hienph.phd.core;

public enum EnumPowerful {
  MERCURY (3.303e+23, 2.4397e6), // each item will call the EnumPowerFul constructor
  VENUS   (4.869e+24, 6.0518e6),
  EARTH   (5.976e+24, 6.37814e6),
  MARS    (6.421e+23, 3.3972e6),
  JUPITER (1.9e+27,   7.1492e7),
  SATURN  (5.688e+26, 6.0268e7),
  URANUS  (8.686e+25, 2.5559e7),
  NEPTUNE (1.024e+26, 2.4746e7);

  private final double mass; // kg
  private final double radius; // km

  EnumPowerful(double mass, double radius)  {
    this.mass = mass;
    this.radius = radius;
  }

  public double getMass() {
    return this.mass;
  }

  public double getRadius() {
    return radius;
  }

  public static double G = 6.67300E-11;

  double surfaceGravity() {
    return G * mass / (radius * radius);
  }

  double surfaceWeight(double otherMass) {
    return otherMass * this.surfaceGravity();
  }

  public static void main(String[] args) {
    double earthWeight = 199.19;
    double mass = earthWeight / EARTH.surfaceGravity();
    for (EnumPowerful p: EnumPowerful.values())  {
      System.out.printf("Your weight on %s is %f%n", p, p.surfaceWeight(mass));
    }
  }
}
