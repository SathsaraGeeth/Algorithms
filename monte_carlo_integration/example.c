#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point {
    double x;
    double y;
};

double pi(int no_samples);
int is_in_unit_circle(struct point p);
struct point a_random_point_in_bounded_square();

int main() {
    srand(time(NULL)); // seed with current time
    int no_samples = 10000;
    double pi_val = pi(no_samples);
    printf("Approximated value of pi with %d number of uniform samples: %f\n", no_samples, pi_val);
    return 0;
}

double pi(int no_samples) {
    int inside_circle = 0;

    // perform monte carlo integration
    for (int i = 0; i < no_samples; i++) {
        struct point p = a_random_point_in_bounded_square();
        if (is_in_unit_circle(p)) {
            inside_circle++;
        }
    }
    return (4.0 * inside_circle) / no_samples;
}

int is_in_unit_circle(struct point p) {
    // point is inside the unit circle
    return (p.x * p.x + p.y * p.y <= 1.0);
}

struct point a_random_point_in_bounded_square() {
    struct point p;
    // random points in [-1, 1]
    p.x = (2.0 * rand() / RAND_MAX) - 1.0;
    p.y = (2.0 * rand() / RAND_MAX) - 1.0;
    return p;
}
