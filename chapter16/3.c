/*Polar coordinates describe a vector in terms of magnitude and the counterclockwise angle 
from the x-axis to the vector. Rectangular coordinates describe the same vector in terms 
of x and y components (see Figure 16.3 ). Write a program that reads the magnitude and 
angle (in degrees) of a vector and then displays the x and y components. The relevant 
equations are these: 
 x = r cos A y = r sin A 
To do the conversion, use a function that takes a structure containing the polar 
coordinates and returns a structure containing the rectangular coordinates (or use 
pointers to such structures, if you prefer). */

#include <stdio.h>
#include <math.h>

#define DIG_IN_RAD(X) ((X) * 4.0 * atan(1) / 180.0)

struct polar{
    double magnitude;
    double angle;
};

struct rectangular{
    double x;
    double y;
};

struct rectangular polar_to_rectan(struct polar);

int main (void){
    struct polar polar;
    struct rectangular rectangular;

    printf("Enter magnitude: ");
    scanf("%lf", &(polar.magnitude));
    printf("Enter angle in degrees: ");
    scanf("%lf", &(polar.angle));
    polar.angle = DIG_IN_RAD(polar.angle);


    rectangular = polar_to_rectan(polar);

    printf("Rectangular coordinates are:\n");
    printf("x = %f\n", rectangular.x);
    printf("y = %f\n", rectangular.y);
    printf("Bye!");
}

struct rectangular polar_to_rectan(struct polar polar){
    struct rectangular rectangular;

    rectangular.x = polar.magnitude * cos(polar.angle);
    rectangular.y = polar.magnitude * sin(polar.angle);

    return rectangular;
}