/*hydroelectric dam design project*/


#include <stdio.h>
#include <string.h>

//constant declarations
const double EFFICIENCY = .90; // 90% efficiency
const double GRAVITY = 9.80; // universal gravitational constant
const double WATER_DENSITY = 1000; // density of water

//clear buffer function
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//global functions
//mass caluclation
double massCalculation(double flowRate) {
    return flowRate * WATER_DENSITY;
}

//work calculation
double workCalculation(double mass, double height) {
    return mass * height * GRAVITY;
}

//power output calculation
double powerOutputCalculation(double work) {
    return (work * EFFICIENCY) / 1e6;
}

int main() {

//variables for user input
double height = -1, flowRate = -1;

//get user input for height
while (height <= 0){
    printf("Enter the height of the dam (in meters): \n");

    if (scanf(" %lf", &height) != 1 || height <= 0) {
    printf("Enter an positive floating point value over 0. \n");
    clearBuffer();
    height = -1;
    }   
}

//clear buffer just in case user inputs other values after the expected double
clearBuffer();

//get user input for flow rate
while (flowRate <= 0) {
    printf("Enter the flow rate of the dam (in cubic meters per second): \n");

    if(scanf(" %lf", &flowRate) != 1 || flowRate <= 0){
        printf("Enter an positive floating point value over 0.\n");
        clearBuffer();
        flowRate = -1;
    }
}
//calculation function performed
double mass = massCalculation(flowRate);
double work = workCalculation(mass, height);
double powerOutput = powerOutputCalculation(work);

//display results
printf("mass of water flow per second: %.2f kg\n", mass);
printf("potential energy per second: %.2f joules\n", work);
printf("power output at 90%% efficency: %.2f MW\n", powerOutput);

return 0 ;


}