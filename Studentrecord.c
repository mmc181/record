#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct Student
    {
        int ID;
        char name[20];
        int age;
        char course[500];    
        float cgpa;
    };

void DisplayStudentList(int nostudents, struct Student student[]){
    for(int i=0 ;i < nostudents; i++){
            printf("************** Student Details **************\n");
            printf("Name: %s\n", student[i].name);
            printf("ID: %d\n", student[i].ID);
            printf("Age: %d\n", student[i].age);
            printf("Course: %s", student[i].course);
            printf("CGPA: %.2f\n", student[i].cgpa);

        }
}

int main(){

    FILE *pF = fopen("StudentData.txt", "a");
    int nostudents;

    if(pF == NULL){
        printf("The text file is not found\n");
    }
    
    printf("Enter the number of students to add: ");
    scanf( "%d" , &nostudents);
    
    struct Student student[nostudents];
    
        for(int i=0 ; i < nostudents; i++){

            printf("************** Enter Student Credentials **************\n");
            
            printf("\nEnter name of Student: ");
            scanf("%s", &student[i].name);
            
            printf("Enter ID of student: ");
            scanf("%d" , &student[i].ID);

            printf("\nEnter age of Student: ");
            scanf("%d", &student[i].age);
            
            getchar();
            printf("\nEnter couse opt by the Student: ");
            fgets(student[i].course, sizeof(student[i].course) , stdin);
            
            printf("\nEnter CGPA: ");
            scanf("%f", &student[i].cgpa);

        }

        DisplayStudentList(nostudents, student );
        
        for(int i = 0; i < nostudents; i++){
            fprintf(pF, "Name: %s\n", student[i].name);
            fprintf(pF, "ID: %d\n", student[i].ID);
            fprintf(pF, "Age: %d\n", student[i].age);
            fprintf(pF, "Course: %s", student[i].course);
            fprintf(pF, "CGPA: %.2f\n\n", student[i].cgpa);
        }
    
    fclose(pF);

    FILE *pR = fopen("StudentData.txt", "r");
    
    char prompt, req;
    char srch[25];
    char line[2000];
    int found = 0;
    int linecount = 0;
    char ch;

    printf("Do you want to search about a student (Y/N): ");
    scanf(" %c", &prompt);
    prompt = toupper(prompt);
    
    if(prompt == 'Y'){
    printf("Enter the name to search: ");
    scanf("%s", srch);

    while(fgets(line, sizeof(line), pR)){
        if(strstr(line,srch)){
            found = 1;
            printf("%s is found!\n");
            printf("%s",line);

            for(int i =0; i < 4; i++){
                if(fgets(line,sizeof(line),pR)){
                    printf("%s", line);
                }
            
            }
            }
        }
        if(!found){
            printf("%s is not found");
        }
        
    }
     else if (prompt == 'N'){
        printf("Have a Great Day\n");
    }
    else{
        printf("Please enter Y or N only!");
    }

    printf("Do you want to view all the student details? (Y/N): ");
    scanf(" %c", &req);
    req = toupper(req);
   
    if(req == 'Y'){
        rewind(pR);
        while (fgets(line, sizeof(line), pR)) {
            printf("%s", line);
        }

    }
    
    fclose(pR);
    return 0;
}