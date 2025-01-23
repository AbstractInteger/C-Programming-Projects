/*convert fahrenheit to kelvin*/


#include <stdio.h>

//function to clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//function to convert fahrenheit to kelvin
float kelvinCalculation(float fahrenheit) {
    return (5.0/9.0)*(fahrenheit-32)+273.15;
}


int main() {

//decalre farenheit variable
float fahrenheit = 0.0;

//ask user for input
printf("what is the temperature in farenheit?: \n");
scanf(" %f", &fahrenheit);

//print the conversion
printf("You input of farenheit %.2f is %.2f in kelvin.\n", fahrenheit, kelvinCalculation(fahrenheit));


return 0;

}