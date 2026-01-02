#include <stdio.h>
#define SUBJECTS 5
#define MAX_STUDENTS 50

int calculateTotal(int marks[]) {
int total = 0;
for (int i = 0; i < SUBJECTS; i++) {
        total += marks[i];
    }
 return total;
}
float calculatePercentage(int total) {
    return (float) total / SUBJECTS;
}
char* calculateGrade(float percentage) {
if (percentage >= 90)
return "A+";
else if (percentage >= 80)
return "A";
else if (percentage >= 70)
return "B+";
else if (percentage >= 60)
return "B";
else if (percentage >= 50)
return "C";
else if (percentage >= 40)
return "D";
else
return "F";
}
int main() {
int students;
int subjectTotal[SUBJECTS] = {0};
int highestTotal = 0;
char topScorer[50];
char subjects[SUBJECTS][20] = {
"English","Hindi","Mathematics", "Social Science","Science"       
    };
printf("Enter number of students: ");
scanf("%d", &students);
for (int s = 0; s < students; s++) {
char name[50]; int marks[SUBJECTS]; int total; float percentage; char *grade;
printf("\nEnter name of student %d: ", s + 1);
scanf(" %49[^\n]", name);
for (int i = 0; i < SUBJECTS; i++) {
  do {
printf("Enter marks for %s (0-100): ", subjects[i]);
 scanf("%d", &marks[i]);
 if (marks[i] < 0 || marks[i] > 100) {
    printf(" Invalid marks! Enter between 0 and 100.\n");
                }
            } while (marks[i] < 0 || marks[i] > 100);

        subjectTotal[i] += marks[i];
        }
        total = calculateTotal(marks);
        percentage = calculatePercentage(total);
        grade = calculateGrade(percentage);
        if (total > highestTotal) {
            highestTotal = total;
            snprintf(topScorer, sizeof(topScorer), "%s", name);
        }
     printf("\n Student Report\n");
        printf("-------------------------\n");
        printf("Name: %s\n", name);
        for (int i = 0; i < SUBJECTS; i++) {
            printf("%s Marks: %d\n", subjects[i], marks[i]);
        }
        printf("Total Marks: %d\n", total);
        printf("Percentage: %.2f%%\n", percentage);
        printf("Grade: %s\n", grade);
        printf("-------------------------\n");
    }
    printf("\n Class Statistics\n");
    printf("-------------------------\n");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("Average marks in %s: %.2f\n",
               subjects[i], (float)subjectTotal[i] / students);
    }
    printf("Top Scorer: %s (%d marks)\n", topScorer, highestTotal);
    printf("-------------------------\n");
    return 0;
}
