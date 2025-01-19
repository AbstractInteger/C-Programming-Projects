/*convert customer change to a personalized credit slip*/


//preprocessor (these header files execute before the file gets sent to the compiler)
#include <stdio.h>
#include <string.h>


int main(void) {


//declare variables 
char name[15] = {0};
int dollars = 0, quarters = 0, dimes = 0, nickles = 0, pennies = 0;
int total_value_in_cents = 0;
int total_dollars = 0;
int total_change = 0;

//get and display customer name
printf("what is your name?: ");
//checks if function was sucessfull or not
if (fgets(name,sizeof(name), stdin) != NULL) {
    //remove newline from the string
    name[strcspn(name, "\n")] = '\0';
    //output if sucessfull
    printf("you entered %s.\n", name);
}
//output if not successfull
else {
    printf("you entry failed.");
}

//get the count for each currency
printf("how many dollars do you have? ");
if (scanf(" %i", &dollars) != 1) {
    printf("enter a valid integer for dollars.");
}

printf("how many quarters do you have? ");
if (scanf(" %i", &quarters) != 1) {
    printf("enter a valid integer for quarters.");
}

printf("how many dimes do you have? ");
if (scanf(" %i", &dimes) != 1) {
    printf("enter a valid integer for quarters.");
}

printf("how many nickles do you have? ");
if (scanf(" %i", &nickles) != 1) {
    printf("enter a valid integer for quarters.");
}

printf("how many pennies do you have? ");
if (scanf(" %i", &pennies) != 1) {
    printf("enter a valid integer for quarters.");
}

//compute total value of user input into pennies
total_value_in_cents = (dollars * 100) + (quarters * 25) + (dimes * 10) + (nickles * 5) + (pennies);
printf("you have a total of %i cents. \n", total_value_in_cents);

//calculate total value in dollars
total_dollars = total_value_in_cents/100;

//calculate total change
total_change = total_value_in_cents % 100;

//display username with dollars/change amount
printf("howdy %s! you have %i dollars with %i cents avaiable on this credit slip. please go to the checkout to get your cash! \n", name, total_dollars, total_change);

return 0;

}