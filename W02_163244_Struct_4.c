#include <stdio.h>
#include <string.h>

struct Course
{
    char cName[50];
    int sks, assigment, midExam, finalExam;
    float score;
};

struct Student
{
    char name[50];
    char major[35];
    float gpa;
    struct Course algorithm, multimedia;
};

struct Student newStudent(char name[], char major[], float gpa)
{
    struct Student s;
    strcpy(s.name, name);
    strcpy(s.major, major);
    s.gpa = gpa;

    return s;
}
int main()
{
    struct Student waldo = newStudent("Waldo", "Informatika", 3.98);
    strcpy(waldo.algorithm.cName, "Algoritma dan Struktur Data");
    waldo.algorithm.sks = 3;

    printf("%s\n\n", waldo.algorithm.cName);
    printf("Assigment   : ");
    scanf("%d", &waldo.algorithm.assigment);
    printf("Mid Exam   : ");
    scanf("%d", &waldo.algorithm.midExam);
    printf("Final Exam   : ");
    scanf("%d", &waldo.algorithm.finalExam);
    waldo.algorithm.score = 0.3 * waldo.algorithm.assigment + 0.3 * waldo.algorithm.midExam + 0.4 * waldo.algorithm.finalExam;
    printf("Final Score : %.2f\n", waldo.algorithm.score);
    return 0;
}