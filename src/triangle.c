#include "graphics.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
  Program to draw a triangle
*/
int main() {
  Image *src;
  const int rows = 300;
  const int cols = 400;
  Polygon *p;
  Color Red;
  Color Orange;
  Color White;
  Color Blue;
  Point pt[3];
  int i;

  srand(42);
  color_set(&Red, 0.9, 0.2, 0.1);
  color_set(&Orange, 0.95, 0.7, 0.3);
  color_set(&White, 1.0, 1.0, 1.0);
  color_set(&Blue, 0.2, 0.1, 0.95);

  src = image_create(rows, cols);

  // make a simple triangle to test proper areas and locations
  // the triangle ought to be 20x20, include pixel (30,30) and exclude pixel
  // (50, 50)
  point_set2D(&(pt[0]), 50, 30);
  point_set2D(&(pt[1]), 50, 130);
  point_set2D(&(pt[2]), 140, 50);

  p = polygon_createp(3, pt);

  printf("drawing a triangle\n");
  // polygon_draw(p, src, Blue);
  // polygon_drawFill(p, src, Blue);
  polygon_drawFillB(p, src, Red);
  image_write(src, "traingle.ppm");

  image_free(src);
}