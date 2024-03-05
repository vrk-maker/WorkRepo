#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Structure to represent a variable
struct stackvalues {
    char name[5]; ///< Name of the variable
    int value; ///< Value of the variable
};

struct stackvalues stack[MAX_STACK_SIZE]; ///< Stack to store variables
int top = -1; 

// Function prototypes
void push(struct stackvalues var);
struct stackvalues pop();
void assign_variable(char *var_name, int var_value);
int get_variable_value(char *var_name);
void display();

/**
 * @brief Push a variable onto the stack.
 * @param[in] var Variable to push onto the stack
 */
void push(struct stackvalues var) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = var;
}

/**
 * @brief Pop a variable from the stack.
 * @return The popped variable
 */
struct stackvalues pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        struct stackvalues empty_var;
        empty_var.value = -1;
        //empty_var.name = ' '; // Initializing with a space character
        return empty_var;
    }
    return stack[top--];
}

/**
 * @brief Assign a value to a variable and push it onto the stack.
 * @param[in] var_name Name of the variable
 * @param[in] var_value Value to assign to the variable
 */
void assign_variable(char *var_name, int var_value) 
{
    //printf("assigining value");
    struct stackvalues new_var;
    strcpy(new_var.name,var_name);
    new_var.value = var_value;
    push(new_var);
}

/**
 * @brief Retrieve the value of a variable from the stack.
 * @param[in] var_name Name of the variable to retrieve
 * @return The value of the variable, or 0 if not found
 */
int get_variable_value(char *var_name) {
    if (top == -1) {
        printf("No elements present\n");
        return 0;
    }
    for (int i = top; i >= 0; i--) {
         if (strcmp(stack[i].name, var_name) == 0) {
            return stack[i].value;
        }
    }
    printf("Variable '%s' not found\n", var_name);
    return 0; // Returning 0 as default value if variable not found
}

/**
 * @brief Display the contents of the stack.
 */
void display() {
    if (top == -1) {
        printf("No elements present\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--) {
        printf("Variable name: %s\tValue: %d\n", stack[i].name, stack[i].value);
    }
}


int main() {
    char command;
    char var_name[5];
    int var_value;

    while (1) {
        printf("Enter command (a for assign, r for retrieve, d for display stack, p for pop, q for quit): ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Exiting...\n");
            break;
        }

        struct stackvalues popvalue;

        switch (command) {
            case 'a':
                printf("Enter variable name: ");
                scanf(" %s", var_name);
                printf("Enter variable value: ");
                scanf("%d", &var_value);
                assign_variable(var_name, var_value);
                printf("Variable '%s' assigned with value %d\n", var_name, var_value);
                break;
            case 'r':
                printf("Enter variable name to retrieve: ");
                scanf(" %s", &var_name);
                int retrieved_value = get_variable_value(var_name);
                if (retrieved_value == 0) {
                    break;
                } else {
                    printf("Value of variable '%s': %d\n", var_name, retrieved_value);
                    break;
                }
            case 'd':
                display();
                break;
            case 'p':
                popvalue = pop(); // Use popvalue here
                if (popvalue.value == -1) {
                    break;
                }
                printf("Popped variable: %s\tValue: %d\n", popvalue.name, popvalue.value);
                break;
            default:
                printf("Invalid command\n");
        }
    }
    return 0;
}
