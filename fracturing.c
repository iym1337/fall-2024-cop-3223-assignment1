#include <math.h>
#include <stdio.h>
#define PI 3.14159
/********************************************************
fracturing.c
Author: Ismail Mohammed
Date: 09/03/2024
Class: COP 3223, Professor Parra

Purpose: This program asks the user for coordinate inputs, which is then used to calculate many 
different properties of circles, such as perimeter, area, and width & height.

Input: None
Output: (to the command line) A brief Message
********************************************************/

/* distance calculation helper: 
computes sqrt( (x2 - x1)^2 + (y2 - y1)^2 ) */
double _distance(double x1, double y1, double x2, double y2) {
    double xCalc = (x2 - x1), yCalc = (y2 - y1); //finds the difference between the X and the Y
    xCalc = pow(xCalc, 2), yCalc = pow(yCalc, 2); //squares the difference between the X and the Y
    return sqrt(xCalc + yCalc); // square root of distance^2 -> distance
}

/* circle perimeter calculation helper:
computes PI * diameter (or 2 * PI * radius) */
double _perimeter(double diameter) {
    return PI * diameter;
}

/* circle area calculation helper:
computes PI * radius^2 (or PI * (diameter / 2)^2) */
double _area(double diameter) {
    double radiusCalc = diameter/2; //radius is half of diameter
    radiusCalc = pow(radiusCalc, 2); //square the radius
    return PI * radiusCalc; //radius^2 * PI -> area
}

double askForUserInput() {
    double value = 0.0;
    scanf("%lf", &value);
    return value;
}

double calculateDistance() {
    printf("X-Coordinate of Point #1: ");
    double x1 = askForUserInput();
    printf("X-Coordinate of Point #2: ");
    double x2 = askForUserInput();

    printf("Y-Coordinate of Point #1: ");
    double y1 = askForUserInput();
    printf("Y-Coordinate of Point #2: ");
    double y2 = askForUserInput();
    
    double distance = _distance(x1, y1, x2, y2);

    printf("\nPoint #1 entered: x1 = %f; y1 = %f\n", x1, y1); //there's a \n here to make extra space
    printf("Point #2 entered: x2 = %f; y2 = %f\n", x2, y2);
    printf("The distance between the two points is %.3f\n\n", distance); //extra \n so output looks cleaner, 3 decimal roundoff

    return distance;
}

double calculatePerimeter() {
    double diameter = calculateDistance();
    double perimeter = _perimeter(diameter);
    printf("The perimeter of the city encompassed by your request is %.3f\n\n", perimeter); //extra \n so output looks cleaner, 3 decimal roundoff

    return 2.0; //difficulty was around 2.0/5.0
}

double calculateArea() {
    double diameter = calculateDistance();
    double area = _area(diameter);
    printf("The area of the city encompassed by your request is %.3f\n\n", area); //extra \n so output looks cleaner, 3 decimal roundoff
    
    return 2.0; //difficulty was around 2.0/5.0
}

double calculateWidth() {
    double width = calculateDistance(); //since it is a circle, all points are equal distances from one another
    printf("The width of the city encompassed by your request is %.3f\n\n", width); //extra \n so output looks cleaner, 3 decimal roundoff

    return 1.0; //difficulty was around 1.0/5.0
}

double calculateHeight() {
    double height = calculateDistance(); //since it is a circle, all points are equal distances from one another
    printf("The height of the city encompassed by your request is %.3f\n", height); // 3 decimal roundoff

    return 1.0; //difficulty was around 1.0/5.0
}

int main (int argc, char **argv) {
    calculateDistance();
    calculatePerimeter();
    calculateArea();
    calculateWidth();
    calculateHeight();

    return 0;
}
