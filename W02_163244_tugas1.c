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
int i = 0;
int count = 0;

void listMahasiswa()
{
    LINE;
    printf("\t\t\tList of Students Information\n");
    printf("|No.| Name\t\t\t| Major  \t\t\t| GPA |\n");
    LINE;
    for (i = 0; i < count; i++)
    {
        printf("|%-3d| %-20s\t| %-15s\t\t | %.02f|\n", i + 1, mhs[i].name, mhs[i].major, mhs[i].gpa);
    }
    LINE;
}

void addMahasiswa()
{
    printf("\tInsert Student Information\n");
    LINE;
    printf("Name\t: ");
    fgets(mhs[i].name, sizeof(mhs[i].name), stdin);
    mhs[i].name[strcspn(mhs[i].name, "\n")] = '\0';
    printf("Major\t: ");
    fgets(mhs[i].major, sizeof(mhs[i].major), stdin);
    mhs[i].major[strcspn(mhs[i].major, "\n")] = '\0';
    printf("GPA\t: ");
    scanf("%f", &mhs[i].gpa);
    i++;
    count++;
}
int main()
{
    int pilihin = 0;
    while (pilihin != 3)
    {

        printf("Welcome to simple student database (%d/20)\n", i);
        printf("1. Show all students\n");
        printf("2. Input new students\n");
        printf("3. Exit\n");
        printf("Input Pilihan: ");
        if (scanf("%d", &pilihin) == 0)
        {
            printf(RED "Error Masukan Pilihan Sesuai dengan Angka\n" RESET);
            pilihin = 0;
            continue;
        };
        getchar();
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
            if (i > 20)
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