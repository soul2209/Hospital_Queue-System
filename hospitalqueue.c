#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int priority; // 1 = Emergency, 2 = Normal
    struct Patient* next;
};

struct Patient* head = NULL;

// Create new patient
struct Patient* createPatient(int id, char name[], int priority) {
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->priority = priority;
    newPatient->next = NULL;
    return newPatient;
}

// Add patient (priority queue logic)
void addPatient(int id, char name[], int priority) {
    struct Patient* newPatient = createPatient(id, name, priority);

    if (head == NULL || priority < head->priority) {
        newPatient->next = head;
        head = newPatient;
    } else {
        struct Patient* temp = head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newPatient->next = temp->next;
        temp->next = newPatient;
    }

    printf("Patient added successfully!\n");
}

// Treat patient (delete from front)
void treatPatient() {
    if (head == NULL) {
        printf("No patients in queue.\n");
        return;
    }

    struct Patient* temp = head;
    printf("Treating Patient: %s (ID: %d)\n", temp->name, temp->id);
    head = head->next;
    free(temp);
}

// Display patients
void displayPatients() {
    if (head == NULL) {
        printf("No patients in queue.\n");
        return;
    }

    struct Patient* temp = head;
    printf("\n--- Patient Queue ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Priority: %s\n",
               temp->id,
               temp->name,
               temp->priority == 1 ? "Emergency" : "Normal");
        temp = temp->next;
    }
}

// Search patient
void searchPatient(int id) {
    struct Patient* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Patient Found: %s (Priority: %s)\n",
                   temp->name,
                   temp->priority == 1 ? "Emergency" : "Normal");
            return;
        }
        temp = temp->next;
    }

    printf("Patient not found.\n");
}

// Update patient
void updatePatient(int id) {
    struct Patient* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new priority (1 Emergency / 2 Normal): ");
            scanf("%d", &temp->priority);
            printf("Updated successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Patient not found.\n");
}

// Main menu
int main() {
    int choice, id, priority;
    char name[50];

    while (1) {
        printf("\n--- Hospital Queue System ---\n");
        printf("1. Add Patient\n");
        printf("2. Treat Patient\n");
        printf("3. Display Patients\n");
        printf("4. Search Patient\n");
        printf("5. Update Patient\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Priority (1 Emergency / 2 Normal): ");
                scanf("%d", &priority);
                addPatient(id, name, priority);
                break;

            case 2:
                treatPatient();
                break;

            case 3:
                displayPatients();
                break;

            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchPatient(id);
                break;

            case 5:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                updatePatient(id);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}