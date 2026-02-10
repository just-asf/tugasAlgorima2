#include <stdio.h>
#include <string.h>

#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define LINE printf("-----------------------------------------------------------------------\n")

typedef struct
{
    char name[50];
    char major[20];
    float gpa;
} Mahasiswa;

Mahasiswa mhs[20];
int count = 0;

void listMahasiswa()
{
    LINE;
    printf("\t\t\tList of Students Information\n");
    printf("|No.| Name\t\t\t| Major  \t\t\t| GPA |\n");
    LINE;
    for (int j = 0; j < count; j++)
    {
        printf("|%-3d| %-20s\t| %-15s\t\t | %.02f|\n", j + 1, mhs[j].name, mhs[j].major, mhs[j].gpa);
    }
    LINE;
}

void addMahasiswa()
{
    printf("\tInsert Student Information\n");
    LINE;
    printf("Name\t: ");
    fgets(mhs[count].name, sizeof(mhs[count].name), stdin);
    mhs[count].name[strcspn(mhs[count].name, "\n")] = '\0';
    printf("Major\t: ");
    fgets(mhs[count].major, sizeof(mhs[count].major), stdin);
    mhs[count].major[strcspn(mhs[count].major, "\n")] = '\0';
    printf("GPA\t: ");
    scanf("%f", &mhs[count].gpa);
    while (getchar() != '\n')
        ;
    count++;
}
int main()
{
    int pilihin = 0;
    while (pilihin != 3)
    {

        printf("Welcome to simple student database (%d/20)\n", count);
        printf("1. Show all students\n");
        printf("2. Input new students\n");
        printf("3. Exit\n");
        printf("Input Pilihan: ");
        if (scanf("%d", &pilihin) == 0)
        {
            printf(RED "Error Masukan Pilihan Sesuai dengan Angka\n" RESET);
            while (getchar() != '\n')
                ;
            pilihin = 0;
            continue;
        };
        while (getchar() != '\n')
            ;
        switch (pilihin)
        {
        case 1:
            if (count <= 0)
            {
                printf(RED "Error Data is Empty\n" RESET);
                break;
            }
            else
            {
                listMahasiswa();
            }
            break;
        case 2:
            if (count >= 20)
            {
                printf(RED "Database is full" RESET);
                break;
            }
            else
            {
                addMahasiswa();
                break;
            }
        case 3:
            printf(CYAN "Thanks for use my program :)\n" RESET);
            break;
        default:
            break;
        }
    }
    return 0;
}