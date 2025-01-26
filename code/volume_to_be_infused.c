/*output information for the lables the hospital pharmacy places on the bags of iv*/


//preprocessor files
#include <stdio.h>
#include <string.h>


//clear buffer regarding scanf functions
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//infusion rate function
float infusionRate(float x, float y) {
    return x/y;
}

//medication name array limit
const int MEDICATION_LIMIT = 15;


int main() {

    //declare char array for medication name
    char medicationName[MEDICATION_LIMIT] = {};
    
    //declare medication volume/medication duration varaible
    int medicationVolume = -1;
    int medicationDuration = -1;

    //get medication name
    printf("enter the name of the medication: \n");
    if (fgets(medicationName, sizeof(medicationName), stdin) != NULL) {
        size_t len = strlen(medicationName);
        if (len > 0 && medicationName[len - 1] == '\n') {
            medicationName[len-1] = '\0'; //remove trailing newline from the fgets
        }
    }

    //get medication volumne (ml)
    //input error checking for valid input
    while (medicationVolume < 0) {
        printf("enter the volume of the medication (in ml): \n");

        if(scanf(" %i", &medicationVolume) != 1 || medicationVolume <= 0) {
            printf("enter a postive integer for ml for medication \n");
            clearBuffer();
            medicationVolume = -1;
        }
    }

    //get medication duration
    //input error checking for valid input
    while (medicationDuration < 0) {
    printf("what is the medication admistration time? (hours): \n");
    if (scanf(" %i", &medicationDuration) != 1 || medicationDuration <= 0) {
        printf("enter a valid interger representing hours\n");
        clearBuffer();
        medicationDuration = -1;
        }
    }

    //display user input
    printf("--------Medication Label--------\n");
    printf("Mediction Name: %s\n", medicationName);
    printf("Medication Volume: %i\n", medicationVolume);
    printf("Medication Infusion Rate: %.2f ML/HR\n", infusionRate(medicationVolume, medicationDuration));

    return 0;
}