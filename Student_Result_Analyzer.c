
#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
    int pass;
};

// Function to add student
void addStudent(struct Student s[], int *n) {
    int i;

    if (*n >= 50) {
        printf("Maximum student limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*n].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[*n].name);

    s[*n].total = 0;
    s[*n].pass = 1;

    for (i = 0; i < 5; i++) {
        printf("Enter marks in Subject %d: ", i + 1);
        scanf("%f", &s[*n].marks[i]);

        s[*n].total += s[*n].marks[i];

        if (s[*n].marks[i] < 33) {
            s[*n].pass = 0;
        }
    }

    s[*n].percentage = s[*n].total / 5;

    if (s[*n].pass == 0)
        s[*n].grade = 'F';
    else if (s[*n].percentage >= 90)
        s[*n].grade = 'A';
    else if (s[*n].percentage >= 75)
        s[*n].grade = 'B';
    else if (s[*n].percentage >= 60)
        s[*n].grade = 'C';
    else if (s[*n].percentage >= 45)
        s[*n].grade = 'D';
    else
        s[*n].grade = 'E';

    (*n)++;

    printf("\nStudent Added Successfully!\n");
}

// Function to display all results
void displayResult(struct Student s[], int n) {
    int i;

    if (n == 0) {
        printf("\nNo Student Records Found!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\n===== STUDENT RESULT =====\n");
        printf("Roll Number: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Total Marks: %.2f/500\n", s[i].total);
        printf("Percentage: %.2f%%\n", s[i].percentage);
        printf("Grade: %c\n", s[i].grade);

        if (s[i].pass == 1)
            printf("Result: PASS\n");
        else
            printf("Result: FAIL\n");
    }
}

// Function to search student
void searchStudent(struct Student s[], int n) {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            printf("\nName: %s\n", s[i].name);
            printf("Total: %.2f\n", s[i].total);
            printf("Percentage: %.2f%%\n", s[i].percentage);
            printf("Grade: %c\n", s[i].grade);

            if (s[i].pass == 1)
                printf("Result: PASS\n");
            else
                printf("Result: FAIL\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nStudent Not Found!\n");
}

// Function to find topper and class average
void classTopperAverage(struct Student s[], int n) {
    int i, topper = 0;
    float sum = 0, average;

    if (n == 0) {
        printf("\nNo Student Records Found!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        sum += s[i].percentage;

        if (s[i].percentage > s[topper].percentage) {
            topper = i;
        }
    }

    average = sum / n;

    printf("\n===== CLASS TOPPER =====\n");
    printf("Name: %s\n", s[topper].name);
    printf("Roll Number: %d\n", s[topper].roll);
    printf("Percentage: %.2f%%\n", s[topper].percentage);

    printf("\nClass Average: %.2f%%\n", average);
}

// Main function
int main() {
    struct Student s[50];
    int n = 0, choice;

    do {
        printf("\n===== GRADTECH STUDENT RESULT ANALYZER =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Results\n");
        printf("3. Search Student\n");
        printf("4. Class Topper and Average\n");
        printf("5. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(s, &n);
                break;

            case 2:
                displayResult(s, n);
                break;

            case 3:
                searchStudent(s, n);
                break;

            case 4:
                classTopperAverage(s, n);
                break;

            case 5:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}
