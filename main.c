#include <stdio.h>
#include <stdlib.h>
#define NUM_STUDENTS 15

int main() {
  int choice, i, name, j;
  char temp_char[20];
  char firstName[NUM_STUDENTS][20];
  char lastName[NUM_STUDENTS][20];
  float scores[NUM_STUDENTS], min, max, temp;

    //Taking user input for names and scores
    printf("Enter first names : \n");
    for( i = 0; i < NUM_STUDENTS; i++) {
        fgets(firstName[i],20,stdin);
        strtok(firstName[i], "\n");
    }
    printf("Enter last names : \n");
    for( i = 0; i <NUM_STUDENTS; i++) {
        fgets(lastName[i],20,stdin);
        strtok(lastName[i], "\n");
    }

    printf("Enter Grades : \n");
    for(int i = 0; i <NUM_STUDENTS; i++) {
        scanf("%f", &scores[i]);
    }
    //Using while loop to start the menu
    while(1)
    {
        printf("Menu based program to keep student records\n");

        printf("Please choose from the options below : \n");
        printf("1. Print records\n");
        printf("2. Search by first name\n");
        printf("3. Search by last name\n");
        printf("4. Sort by score\n");
        printf("5. Sort by last name\n");
        printf("6. Find Max Score\n");
        printf("7. Find Min Score\n");
        printf("0. Exit the program\n");

        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            //This will print all the records of students
            case 1:
                for(i = 0; i <NUM_STUDENTS; i++) {
                    printf("\nFirst name : %s, Last name : %s, Score : %.2f \n\n", firstName[i], lastName[i], scores[i]);
                }
            break;

            //This will search the name of the student you're looking for
            case 2:
                printf("Please enter the first name of the student you are looking for : \n");
                getchar();
                fgets(name,20,stdin);
                strtok(name, "\n");
                for(i =0; i <NUM_STUDENTS; i++) {
                    if(strcmp(firstName[i], name) == 0) {
                        printf("\nFirst name : %s, Last name : %s, Score : %.2f \n\n", firstName[i], lastName[i], scores[i]);
                    }
                }
            break;
            //This will search the last nae of the student
            case 3:
                printf("Please enter the first name of the student you are looking for : \n");
                getchar();
                fgets(name,20,stdin);
                strtok(name, "\n");
                for(i =0; i <NUM_STUDENTS; i++) {
                    if(strcmp(lastName[i], name) == 0) {
                        printf("\nFirst name : %s, Last name : %s, Score : %.2f \n\n", firstName[i], lastName[i], scores[i]);
                    }
                }
            break;
            //This will sort the score of students and print their records
            case 4:
                for(i = 0; i < NUM_STUDENTS - 1; i++) {
                    for(j = 0; j <NUM_STUDENTS - i - 1; j++) {
                         if(scores[j]>scores[j+1]) {
                            temp = scores[j];
                            scores[j] = scores[j+1];
                            scores[j+1] = temp;

                            strcpy(temp_char, firstName[j]);
                            strcpy(firstName[j], firstName[j+1]);
                            strcpy(firstName[j+1], temp_char);

                            strcpy(temp_char, lastName[j]);
                            strcpy(lastName[j], lastName[j+1]);
                            strcpy(lastName[j+1], temp_char);
                         }
                    }
                }

                 for(i = 0; i <NUM_STUDENTS; i++) {
                    printf("\nFirst name : %s, Last name : %s, Score : %.2f \n\n", firstName[i], lastName[i], scores[i]);
                }
            break;
            //This will sort the last name of students alphabetically
            case 5:
                for(i = 0; i < NUM_STUDENTS - 1; i++) {
                    for(j = 0; j <NUM_STUDENTS - i - 1; j++) {
                         if(strcmp(lastName[j], lastName[j+1]) > 0) {
                            temp = scores[j];
                            scores[j] = scores[j+1];
                            scores[j+1] = temp;

                            strcpy(temp_char, firstName[j]);
                            strcpy(firstName[j], firstName[j+1]);
                            strcpy(firstName[j+1], temp_char);

                            strcpy(temp_char, lastName[j]);
                            strcpy(lastName[j], lastName[j+1]);
                            strcpy(lastName[j+1], temp_char);
                         }
                    }
                }

                 for(i = 0; i <NUM_STUDENTS; i++) {
                    printf("\nFirst name : %s, Last name : %s, Score : %.2f \n\n", firstName[i], lastName[i], scores[i]);
                }
                break;
                //This finds the max score
                case 6:
                max = scores[0];
                 for(i = 1; i <NUM_STUDENTS; i++) {
                        if(scores[i] > max) {
                            max = scores[i];
                        }
                 }
                 for(i = 0; i < NUM_STUDENTS; i++) {
                    if(scores[i] == max) {
                      printf("\nFirst name : %s, Last name : %s, Score : %.2f \n\n", firstName[i], lastName[i], scores[i]);
                    }
                 }
                 break;
                 //This finds the min score
                 case 7:
                 min = scores[0];
                 for(i = 1; i <NUM_STUDENTS; i++) {
                        if(scores[i] < min) {
                            min = scores[i];
                        }
                 }
                 for(i = 0; i < NUM_STUDENTS; i++) {
                    if(scores[i] == min) {
                      printf("\nFirst name : %s, Last name : %s, Score : %.2f \n\n", firstName[i], lastName[i], scores[i]);
                    }
                 }
                 break;
                 //This will exit the program
                case 0:
                exit(0);
                break;

        }

    }

    return 0;

}

