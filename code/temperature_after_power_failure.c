/*estimate the temperature in a freezer given the elapsed time (hours) since a power failure*/


#include <stdio.h>

//time constant: minutes in an hour
const double MINUTES_IN_HOURS = 60.0;

//function to clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float calculateTotalTime(int hours, float minutes) {
    return (hours + (minutes / MINUTES_IN_HOURS));
}

int main() {

//time variables declared
int elapsedHours = -1, elapsedMinutes = -1;

//ask user for input regarding time variables (hours)
while (elapsedHours < 0) {
    printf("how many hours have passed since the power failure?: \n");

    if (scanf(" %i", &elapsedHours) != 1 || elapsedHours < 0) {
        printf("please enter zero or a positive value for how many hours has elapsed since the power failure. \n");
        clearBuffer();
        elapsedHours = -1;
    }
}

//ask user for input regarding time varibles (minutes)
while (elapsedMinutes < 0) {
    printf("how many minutes have passed since the power failure?: \n");

    if (scanf(" %i", &elapsedMinutes) != 1 || elapsedMinutes < 0) {
        printf("please enter zero or a positive value for how many minutes has elapsed since the power failure. \n");
        clearBuffer();
        elapsedMinutes = -1;
    }
}

//convert totalTime (minutes) to hours with new variable
float totalHours = calculateTotalTime(elapsedHours, elapsedMinutes);

//use newTotalTimeHours with forumla
float temperature = (4 * totalHours * totalHours) / (totalHours + 2);

//print the estimated temperature
printf("estimated freezer temperature in celsius: %.2f\n", temperature);


return 0;


}