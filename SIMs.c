/******************************************************************************

                            Online C Compiler.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_StudS 100
#define MAX_FACULTY 30
#define CREDIT_COST 236.45
#define ADMIN_FEE 52.0
#define GPA_DISCOUNT 3.85
#define DISCOUNT_RATE 0.25

typedef struct {
    char stud_name[100];
    char id[9];
    float gpa;
    int crdh;
} Stud;

typedef struct {
    char stud_name[100];
    char id[9];
    char department[10];
    char rank[10];
} Faculty;

Stud Studs[MAX_StudS];
Faculty faculty[MAX_FACULTY];
int StudCount = 0;
int facultyCount = 0;

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int validateID(char *id) {
    if (strlen(id) != 8 || !isalpha(id[0]) || !isalpha(id[1])) return 0;
    for (int i = 2; i < 8; i++) {
        if (!isdigit(id[i])) return 0;
    }
    return 1;
}

int validateDepartment(char *dept) {
    toUpperCase(dept);
    return strcmp(dept, "MATH") == 0 || strcmp(dept, "CS") == 0 || strcmp(dept, "SCIENCE") == 0;
}

int validateRank(char *rank) {
    toUpperCase(rank);
    return strcmp(rank, "PROFESSOR") == 0 || strcmp(rank, "ADJUNCT") == 0;
}

void addStud() {
    if (StudCount >= MAX_StudS) {
        printf("Stud capacity reached. Cannot add more Studs.\n");
        return;
    }

    Stud s;
    printf("Enter the Stud’s info:\n");
    printf("Name of Stud: ");
    getchar();
    fgets(s.stud_name, 100, stdin);
    s.stud_name[strcspn(s.stud_name, "\n")] = '\0';

    for (int attempts = 0; attempts < 3; attempts++) {
        printf("ID: ");
        scanf("%s", s.id);
        toUpperCase(s.id);
        if (validateID(s.id)) break;
        printf("Invalid ID format. Try again.\n");
        if (attempts == 2) {
            printf("You have tried too many times. Goodbye.\n");
            return;
        }
    }

    printf("GPA: ");
    scanf("%f", &s.gpa);

    printf("Credit hours: ");
    scanf("%d", &s.crdh);

    Studs[StudCount++] = s;
    printf("Thanks!\n");
}

void addFaculty() {
    if (facultyCount >= MAX_FACULTY) {
        printf("Faculty capacity reached. Cannot add more faculty.\n");
        return;
    }

    Faculty f;
    printf("Enter the faculty’s info:\n");
    printf("Name of the faculty: ");
    getchar();
    fgets(f.stud_name, 100, stdin);
    f.stud_name[strcspn(f.stud_name, "\n")] = '\0';

    for (int attempts = 0; attempts < 3; attempts++) {
        printf("ID: ");
        scanf("%s", f.id);
        toUpperCase(f.id);
        if (validateID(f.id)) break;
        printf("Invalid ID format. Try again.\n");
        if (attempts == 2) {
            printf("You have tried too many times. Goodbye.\n");
            return;
        }
    }

    for (int attempts = 0; attempts < 3; attempts++) {
        printf("Rank: ");
        scanf("%s", f.rank);
        if (validateRank(f.rank)) break;
        printf("Invalid rank. Try again.\n");
        if (attempts == 2) {
            printf("You have tried too many times. Goodbye.\n");
            return;
        }
    }

    for (int attempts = 0; attempts < 3; attempts++) {
        printf("Department: ");
        scanf("%s", f.department);
        if (validateDepartment(f.department)) break;
        printf("Invalid department. Try again.\n");
        if (attempts == 2) {
            printf("You have tried too many times. Goodbye.\n");
            return;
        }
    }

    faculty[facultyCount++] = f;
    printf("Thanks!\n");
}

void printTuitionInvoice(Stud s) {
    float totalCost = s.crdh * CREDIT_COST + ADMIN_FEE;
    float discount = (s.gpa >= GPA_DISCOUNT) ? totalCost * DISCOUNT_RATE : 0.0;
    totalCost -= discount;

    printf("Here is the tuition invoice for %s:\n", s.stud_name);
    printf("---------------------------------------------------------------------------\n");
    printf("%s %s\n", s.stud_name, s.id);
    printf("Credit Hours: %d ($%.2f/credit hour)\n", s.crdh, CREDIT_COST);
    printf("Fees: $%.2f\n", ADMIN_FEE);
    printf("Total payment: $%.2f ($%.2f discount applied)\n", totalCost, discount);
    printf("---------------------------------------------------------------------------\n");
}

void searchStud() {
    char id[9];
    printf("Enter the Stud’s id: ");
    scanf("%s", id);
    toUpperCase(id);

    for (int i = 0; i < StudCount; i++) {
        if (strcmp(Studs[i].id, id) == 0) {
            printTuitionInvoice(Studs[i]);
            return;
        }
    }
    printf("Sorry-Stud not found!\n");
}

void searchFaculty() {
    char id[9];
    printf("Enter the faculty’s id: ");
    scanf("%s", id);
    toUpperCase(id);

    for (int i = 0; i < facultyCount; i++) {
        if (strcmp(faculty[i].id, id) == 0) {
            printf("Faculty found:\n");
            printf("---------------------------------------------------------------------------\n");
            printf("%s\n%s department, %s\n", faculty[i].stud_name, faculty[i].department, faculty[i].rank);
            printf("---------------------------------------------------------------------------\n");
            return;
        }
    }
    printf("Sorry %s doesn’t exist\n", id);
}

void menu() {
    int choice;
    do {
        printf("\nChoose one of the options:\n");
        printf("1- Add a new faculty member\n");
        printf("2- Add a new Stud\n");
        printf("3- Print tuition invoice for a Stud\n");
        printf("4- Print information of a faculty\n");
        printf("5- Exit Program\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFaculty();
                break;
            case 2:
                addStud();
                break;
            case 3:
                searchStud();
                break;
            case 4:
                searchFaculty();
                break;
            case 5:
                printf("Thank you for using PerPro. Goodbye!\n");
                break;
            default:
                printf("Invalid entry- please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
