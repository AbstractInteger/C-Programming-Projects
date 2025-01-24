/*output information for the lables the hospital pharmacy places on the bags of iv*/

//preprocessor files
#include <stdio.h>
#include <string.h>

//clear buffer function
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    //declare char array for medication name
    char medicationName[15] = {};
    
    //declare medication volume varaible
    int medicationVolume = -1;

    //get user to input medication name
    printf("enter the name of the medication: \n");
    fgets(medicationName, sizeof(medicationName), stdin);

    clearBuffer();

    printf("%s", medicationName);






    return 0;
}