//predict the score needed to achive a desired grade

//preprocessors
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//global constants and functions
//name length constant
const int NAME_LENGTH = 21;

//clear buffer (scanf)
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {

    //declared local variables
    //name
    char name[NAME_LENGTH] = {0};
    //desired grade holder
    char desiredGrade = 0;
    //current grade
    float currentGrade = 0.0, requiredGrade = 0.0, minRequiredAverage = 0.0;
    //final exam weight (percentage)
    int finalExamWeight = -1;

    //ask user for their name
    printf("enter your name: (20 characters max)\n");
    //if user enters valid input it will check for the newline character and replace it with null terminator
    if (fgets(name, sizeof(name), stdin) != NULL) {
        size_t name_len = strlen(name);
        if (name_len > 0 && name[name_len - 1] == '\n') {
            name[name_len - 1 ] = '\0';
        }
    }

    //ask user for desired grade
    printf("what is your desired grade?: (enter a letter grade such as A, B, or C)\n");
    while (scanf(" %c", &desiredGrade) != 1 || strchr("ABC", toupper(desiredGrade)) == NULL) {
        printf("invalid input. enter a single character only such as A, B, or C. \n");
        clearBuffer();
    }
    //if user inputs lowercase values convert to upper
    desiredGrade = toupper(desiredGrade);

    //ask user for their desired minimum average grade desired
    printf("enter your desired minimum average: (between 0 and 100): \n");
    while (scanf(" %f", &minRequiredAverage) != 1 || minRequiredAverage < 0 || minRequiredAverage > 100){
        printf("invalid input. enter a value between 0 and 100 for minimum desired average.\n");
        clearBuffer();
    }

    //ask user for their current class grade
    printf("enter your current class grade: (between 0 and 100)\n");
    while (scanf(" %f", &currentGrade) != 1 || currentGrade < 0 || currentGrade > 100) {
        printf("invalid input. enter a value between 0 and 100 for current class grade. \n");
        clearBuffer();
    }

    //ask user for exam weight
    printf("what is the exam weight?: (between 0 and 100)\n");
    while (scanf(" %i", &finalExamWeight) != 1 || finalExamWeight <= 0 || finalExamWeight > 100) {
        printf("invalid input. enter a value between 1 and 100 (percentage) for exam weight. \n");
        clearBuffer();
    }

    //required grade calculation
    requiredGrade = (minRequiredAverage - ((100 - finalExamWeight) / 100.0) * currentGrade) / (finalExamWeight / 100.0);

    //display results
    printf("howdy %s you need to score at least a %.2f on your final exam to get a %c as your average class grade.\n", name, requiredGrade, desiredGrade);

    return 0;
}