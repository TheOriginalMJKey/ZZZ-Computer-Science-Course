#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define _USE_MATH_DEFINES

double function(double x) {
    return cos(x) - pow(M_E, (pow(x, 2) / -2)) + x - 1;
}

double func(double x) {
    return 1 - x + sin(x) - log(1 + x);
}

double simple_iterations(double a, double b, double tol) {
    double x = a;
    double y = func(a);
    double x1;
    double y1;

    if (y * func(b) > 0) {
        printf("Root does not lie between %f and %f\n", a, b);
        return -1;
    }

    while (fabs(y) > tol) {
        x1 = x - y / ((1 - x) + sin(x) - (1 + x) / (1 + x));
        y1 = func(x1);

        if (fabs(y1) <= tol) {
            return x1;
        }

        x = x1;
        y = y1;
    }

    return x;
}

double dichotomy(double left, double right, double eps) {
    double mid = (left + right) / 2;

    if (fabs(function(mid)) <= eps) {
        return mid;
    } else if (function(left) * function(mid) < 0) {
        return dichotomy(left, mid, eps);
    } else {
        return dichotomy(mid, right, eps);
    }
}

int Task() {
    double left = 1;
    double right = 2;
    double eps = DBL_EPSILON;

    double a = 1;
    double b = 1.5;

    printf("The root of the equation using dichotomy method is %.6f\n", dichotomy(left, right, eps));

    printf("The root of the equation using iterations method if %.6f\n", simple_iterations(a, b, eps));

    return 0;
}