#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_REG_LENGTH 10
#define MAX_MAKE_MODEL_LENGTH 50
#define MAX_COLOR_LENGTH 10
#define MAX_CARS 5

struct Car {

char registration[MAX_REG_LENGTH];
char makemodel [MAX_MAKE_MODEL_LENGTH];
char color [MAX_COLOR_LENGTH];
int numPreviousOwners;
bool reserved;
float reserveAmount;
struct Car *next;


};

void displayMenu(); {
printf("\n MAIN MENU \n")
printf("1. Add a new car to showroom\n")
printf("2. Sell car from showroom\n")
printf("3. Reserve / Unreserve a car in showroom\n")
printf("4. View all cars in showroom\n")
printf("5. View specific car in showroom\n")
printf("6. Preview newest model to be added to showroom\n")
printf("7. Exit the system\n")

}

void addCar(struct Car **head) {
    if (*head == NULL) {
        *head = (struct Car*)malloc(sizeof(struct Car));
         if (*head == NULL) {
            printf("Memory allocation failed \n");
            return;
      }
      (*head)->next = NULL;
    }

    struct Car *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if  (current->next != NULL)
    printf("Showroom is full\n");
    return;
}

