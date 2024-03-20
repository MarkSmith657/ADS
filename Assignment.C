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
float reservedAmount;
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
    struct Car *newCar = (struct Car*)malloc(sizeof(struct Car));
    if (newCar == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter car registration: ");
    scanf("%s", newCar->registration);

    
    if (*head == NULL) {
        *head = newCar;
        newCar->next = NULL;
    } else {
        struct Car *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCar;
        newCar->next = NULL;
    }

    printf("Enter car make and model: ");
    scanf("%s", newCar->makemodel);

    printf("Enter car color: ");
    scanf("%s", newCar->color);

    printf("Enter number of previous owners (0-3): ");
    scanf("%d", &newCar->numPreviousOwners);
    if (newCar->numPreviousOwners < 0 || newCar->numPreviousOwners > 3) {
        printf("Invalid number of previous owners\n");
        free(newCar);
        return;
    }

    newCar->reserved = false;
    newCar->reservedAmount = 0.0;

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
            if (current->reserved) {
                printf("Car is already reserved. Do you want to unreserve it? (y/n): ");
                char choice;
                scanf(" %c" , &choice);
                if  (choice == 'y' || choice == 'Y') {
                    current->reserved = false;
                    current->reservedAmount = 0.0;
                    printf("Car unreserved successfully.\n");
                }
            }else {
                printf("Enter reserve amount: "); 
                scanf("%f" , &current->reservedAmount); 
                current->reserved = true;
                printf("Car reserved\n");
// third commit added ; and reserved and fixed reserve amount
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
               current->registration, current->makemodel, current->numPreviousOwners, // third commit fixed makemodel and NPO
               current->reserved ? "Yes" : "No");
               current = current->next;
      }

}    

void viewCar (struct Car *head, char *registration){
    struct Car *current = head;

    while (current != NULL){ //third commit fixed NULL and " 
        if (strcmp(current->registration, registration) == 0 ){
            printf("Make and Model: %s\n", current->makemodel);
            return;
        }
        current = current->next;
    }
    printf("Car nort found\n");

}
void loadData(struct Car **head){

}
void saveData(struct Car **head){
    
}
void cleanup (struct Car **head){ // fixed struct from struuct
    
}
// end of second commit 
// Start of third commit 
int main() {
    struct Car *head = NULL;
    loadData(&head);
    int choice;
    do
    {
        displayMenu();
        printf("Please select a menu option :\n");
        scanf(" %d", &choice);
    
    

    switch (choice) {
            case 1:
                addCar(&head);
                break;
            case 2:
                sellCar(&head);
                break;
            case 3:
                reserveUnreserve(head);
                break;
            case 4:
                viewCars(head);
                break;
            case 5: {
                char reg[MAX_REG_LENGTH];
                printf("Enter Reg number: ");
                scanf("%s", reg);
                viewCar(head, reg);
                break;
            }
            case 6:
                printf("The newest car on show is the Audi RS3\n");
                printf("For a preview visit: https://youtu.be/uRmTbZCFfvA?si=NBL_pCC6rd1yJAtx\n");
                break;
            case 7:
                printf("Exiting the system..\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    saveData(&head);
    cleanup(&head);

    return 0;
}