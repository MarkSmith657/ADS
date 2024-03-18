#include <stdio.h> // beginning of first commit 
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

void displayMenu() { // second commit fixing displaymenu(); and adding ; to printf statements 
printf("\n MAIN MENU \n");
printf("1. Add a new car to showroom\n");
printf("2. Sell car from showroom\n");
printf("3. Reserve / Unreserve a car in showroom\n");
printf("4. View all cars in showroom\n");
printf("5. View specific car in showroom\n");
printf("6. Preview newest model to be added to showroom\n");
printf("7. Exit the system\n");

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

    if  (current->next != NULL) { // Second Commit adding {}
    printf("Showroom is full\n");
    return; // ending of first commit 
    }

// beginning of second commit 
struct Car *newCar = (struct Car*)malloc(sizeof(struct Car));
if (newCar == NULL) {
printf("memory allocation failed\n");
return;
}

printf("Enter car registration: ");
scanf("%s" , newCar->registration);

current = *head;
while (current != NULL) {
    if (strcmp(current->registration, new_car->registration) == 0) {
        printf("Car with samer Reg already exists\n");
        free(newCar);
        return;
    }
    current = current->next;
}

printf("Enter car make and model: ");
scanf("%s" , newCar->makemodel);

printf("Enter number of previous owners (0-3): ");
scanf("%d" , &newCar->numPreviousOwners);
if (newCar->numPreviousOwners > 0 || newCar->numPreviousOwners < 3) {
    printf("Invalid No of previous owners\n");
    free(newCar);
    return;
}
newCar->reserved = false;
newCar->reservedAmount = 0.0;
newCar->next = NULL;

current-> = newCar;
printf("Car added successfully\n");

}

void sellCar(struct Car **head){ 
    char reg[ MAX_REG_LENGTH];
    printf("Enter car registration:");
    scanf("%s" , reg);

    struct Car *current = *head;
    struct Car *prev = NULL;

    while (current != NULL ){
        if(strcmp(current->registration, reg) == 0){
            if (current->reserved){
             if (prev != NULL){
                prev->next = current->next;
             }else {
                *head = current->next;
             }
             free(current);
             printf("Car sold !\n");
             return;
        }else {
            printf("Car is not reserved and cannot be sold !\n");
            return;

        }
    }
    prev = current;
    current = current->next;
}

printf("Car not found\n");
}

void reserveUnreserve(struct Car *head){
    char reg[MAX_REG_LENGTH];
    printf("Enter registration number: ");
    scanf("%s" , reg);

    struct Car *current = head;

    while (current != NULL) {
          if (strcmp(current->registration, reg) == 0) {
            if (current->reserved){
                printf("Car is already reserved. Do you want to unreserve it? (y/n): ");
                char choice;
                scanf("%c" , &choice);
                if  if (choice == 'y' || choice == 'Y') {
                    current->reserved = false;
                    current->reserve_amount = 0.0;
                    printf("Car unreserved successfully.\n");
                }
            }else {
                printf("Enter reserve amount: ")
                scanf("%f" , &current->reservedAmount);
                current-> = true;
                printf("Car reserved\n")

            }
            return;
          }
          current = current->next;
    }
    printf("Car not found\n");

}

void viewCars (struct Car *head) {
    if (head == NULL) {
        printf("No cars in showroom\n");
        return;
    } 
      printf("\n--- Cars in the showroom ---\n");
      struct Car *current = head;

      while (current != NULL){
      printf("Registration: %s, Make and Model: %s, Previous Owners: %d, Reserved: %s\n",
               current->registration, current->makenmodel, current->num_previous_owners,
               current->reserved ? "Yes" : "No");
               current = currrent->next;
      }

}    

void viewCar (struct car *head, char *registration){
    struct Car *current = head;

    while (current != NULl){
        if (strcmp(current->registration, registration) == 0 ){
            printf(Make and Model: "%s\n", current->makemodel);
            return;
        }
        current = current->next;
    }
    printf("Car nort found\n");

}
void loadData(struuct Car **head){

}
void saveData(struuct Car **head){
    
}
void cleanup (struuct Car **head){
    
}
// end of second commit 