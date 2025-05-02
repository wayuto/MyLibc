/*
 * This header file was written to implement some math functions.
 */
#ifndef MATH_H
#define MATH_H
int64_t abs(int64_t x) {
    return x > 0 ? x : -x;
}

double fabs(double x) {
    return x > 0 ? x : -x;
}
/* --- */

/* Logarithmic functions */
double ln(double x) {
    if (x <= 0) return -1;
    double term = (x - 1) / (x + 1);
    double sum = term;
    double power = term * term;
    for (int k = 1; k < x * 10; k++) {
        term *= power * (2*k - 1) / (2*k + 1);
        sum += term;
    }
    return 2 * sum;
}

double log(double b, double a) {
    if (b <= 1) return -1;
    return ln(a) / ln(b);
}

double lg(double x) {
    return ln(x) / ln(10);
}

double lb(double x) {
    return ln(x) / ln(2);
}
/* --- */

/* Exponential functions */
double exp(double x) {
    double sum = 1.0;
    double term = 1.0;
    for (int k = 1; k < x * 10; k++) {
        term *= x / k;
        sum += term;
    }
    return sum;
}

double pow(double x, double y) {
    if ((int)y - y) {
        if ((x == 0 && y <= 0) || (x < 0 && y - (int)y != 0)) return -1;
        double exponent = y * ln(fabs(x));
        return exp(exponent);
    }
    int sign = 0;
    double result = 1;
    if (!y) return result;
    if (y < 0) {
        sign = 1;
        y = -y;
    }
    while (y != 0) {
        result *= x;
        y--;
    }
    return sign ? 1/result : result;
}
/* --- */

/* Take the approximation */
int64_t ceil(double x) {
    if ((int)x - x) return (int)x + 1;
    return x;
}

int64_t floor(double x) {
    return (int)x;
}

int64_t round(double x) {
    return floor(x + 0.5);
}
/* --- */

/* Calculate the square root of `x` */
double sqrt(double x) {
    if (x <= 0) return -1;
    double exponent = 0.5 * ln(fabs(x));
    double result = exp(exponent);
    return ceil(result) * ceil(result) == x ? (double)ceil(result) : result;
}
/* --- */

/* Pythagorean theorem */
double hypot(double x, double y) {
    if (x == 0 || y == 0) return -1;
    return sqrt(x * x + y * y);
}
/* --- */

#endif