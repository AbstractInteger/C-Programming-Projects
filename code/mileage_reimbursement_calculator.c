/*get total miles traveled to generate reimbursement total*/

#include <stdio.h>
#include <string.h>

//constants
const float cents_per_mile = .35;

//custom functions
void clear_input_buffer() {
    while (getchar() != '\n');
}

int main(void) {

//declare variables
char employee_name[20] = {0};
char date[11] = {0};
int employee_id = 0;
float starting_miles = -1, ending_miles = 0, traveled_miles = 0, reimbursement = 0;

//get employee name
printf("what is your name?: \n");
fgets(employee_name, sizeof(employee_name), stdin);
//remove the newline character and replace it with null terminating value
employee_name[strcspn(employee_name, "\n")] = '\0';

//clear buffer from fgets
clear_input_buffer();

//get employee id
while (employee_id <= 0) {
    printf("enter your employee id: \n");

    if (scanf(" %i", &employee_id) != 1) {
        printf("enter a valid positive integer. \n");
        clear_input_buffer();
        employee_id = 0; // ensures loop runs again to request input
    }
}

//get date of transaction
printf("enter the date of transaction: (yyyy-mm-dd) \n");
fgets(date, sizeof(date), stdin);

//clear buffer from fgets
clear_input_buffer();

//get starting miles
while (starting_miles < 0) {
    printf("enter your starting miles: \n");

    //ask for user input and validate input
    if(scanf(" %f", &starting_miles) != 1) {
        printf("enter a valid float that is positive. \n");

        //clear user input from buffer since input is invalid
        clear_input_buffer();
        starting_miles = -1; //this keeps the loop going
    }
}

//get ending miles
while (ending_miles <= 0 || ending_miles < starting_miles) {
    printf("enter your ending miles: \n");

    //ask user for input and validate input
    if(scanf(" %f", &ending_miles) != 1) {
        printf("enter a valid positive float. \n");

        //clear input buffer
        clear_input_buffer();
        ending_miles = 0;
    }
}

//difference calculation
traveled_miles = ending_miles - starting_miles;

//reimbursement calculation
reimbursement = traveled_miles * cents_per_mile;

//display employee reimbursement total
printf("you travled %.2f miles %s. your reimbusement total is %.2f which will take 5-7 business days to be processed. \n", traveled_miles, employee_name, reimbursement);

return 0;

}