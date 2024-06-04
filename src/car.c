#include "../include/graphics.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to project 3D point to 2D with a simple perspective projection
void project_point_perspective(Point *p3d, Point *p2d, double d) {
    p2d->val[0] = p3d->val[0] * d / (d + p3d->val[2]);
    p2d->val[1] = p3d->val[1] * d / (d + p3d->val[2]);
}

/*
  Program to draw a car from a side view.
*/
int main() {
    Image *src;
    const int rows = 90;
    const int cols = 140;
    Color Red;
    Color DarkRed;
    Color White;
    Color Blue;
    Color Black;
    Color Gray;
    int i;
    double d = 100.0;

    srand(42);
    color_set(&Red, 0.9, 0.2, 0.1);
    color_set(&DarkRed, 0.5, 0.1, 0.1);
    color_set(&White, 1.0, 1.0, 1.0);
    color_set(&Blue, 0.2, 0.1, 0.95);
    color_set(&Black, 0.0, 0.0, 0.0);
    color_set(&Gray, 0.5, 0.5, 0.5);

    src = image_create(rows, cols);

    // set car body points 3D for side view
    Point carBody3D[6] = {
        {{25, 100, 100}},
        {{150, 100, 100}},
        {{150, 50, 100}},
        {{50, 50, 100}},
        {{50, 50, 0}},
        {{120, 50, 0}}
    };
    // project car body points to 2D
    Point carBody2D[6];
    for (i = 0; i < 6; i++) {
        project_point_perspective(&carBody3D[i], &carBody2D[i], d);
    }

    // draw car body
    Polygon carBody;
    polygon_set(&carBody, 4, carBody2D);
    polygon_drawFill(&carBody, src, DarkRed);
    polygon_set(&carBody, 4, carBody2D + 2);
    polygon_drawFill(&carBody, src, Red);

    // set car wheels points 3D (simplified as circles)
    Point carWheelFront3D = {{40, 55, 10}};
    Point carWheelBack3D = {{90, 55, 10}};
    // project car wheels to 2D
    Point carWheelFront2D, carWheelBack2D;
    project_point_perspective(&carWheelFront3D, &carWheelFront2D, d);
    project_point_perspective(&carWheelBack3D, &carWheelBack2D, d);

    // create Circle objects for the wheels
    Circle carWheelFront, carWheelBack;
    circle_set(&carWheelFront, carWheelFront2D, 8);
    circle_set(&carWheelBack, carWheelBack2D, 8);

    // draw wheels
    circle_drawFill(&carWheelFront, src, Gray);
    circle_drawFill(&carWheelBack, src, Gray);

    // set front window points 3D for side view
    Point frontWindow3D[4] = {
        {{120, 60, 100}},
        {{150, 60, 100}},
        {{150, 80, 100}},
        {{120, 80, 100}}
    };
    // project front window to 2D
    Point frontWindow2D[4];
    for (i = 0; i < 4; i++) {
        project_point_perspective(&frontWindow3D[i], &frontWindow2D[i], d);
    }

    // draw front window
    Polygon frontWindow;
    polygon_set(&frontWindow, 4, frontWindow2D);
    polygon_drawFill(&frontWindow, src, White);

    // set rear window points 3D for side view
    Point rearWindow3D[4] = {
        {{60, 60, 100}},
        {{90, 60, 100}},
        {{90, 80, 100}},
        {{60, 80, 100}}
    };
    // project rear window to 2D
    Point rearWindow2D[4];
    for (i = 0; i < 4; i++) {
        project_point_perspective(&rearWindow3D[i], &rearWindow2D[i], d);
    }

    // draw rear window
    Polygon rearWindow;
    polygon_set(&rearWindow, 4, rearWindow2D);
    polygon_drawFill(&rearWindow, src, White);


    image_write(src, "car_side_view.ppm");
    image_free(src);

    // free memory
    polygon_clear(&carBody);
    // circle_clear(&carWheelFront);
    // circle_clear(&carWheelBack);
    polygon_clear(&frontWindow);
    polygon_clear(&rearWindow);


    return 0;
}
