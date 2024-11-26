#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fields {
    char *Day_Name;
    int Day_Date;
    char *Discription;
};

typedef struct fields Fields;
Fields **Activity;

Fields *Create(char *Name, int Day, char *Disc)
{
    Fields *data;
    int nlen, nDisc;
    nlen = strlen(Name);
    nDisc = strlen(Disc);
    data = (Fields *)malloc(sizeof(struct fields));
    data->Day_Name = (char *)calloc(nlen, sizeof(char));
    data->Discription = (char *)calloc(nDisc, sizeof(char));
    data->Day_Date = Day;
    strcpy(data->Day_Name, Name);
    strcpy(data->Discription, Disc);
    return data;
}

void readData(void)
{
    char Name[15], Disc[25], c;
    int Day, i;
    Activity = (Fields **)calloc(7, sizeof(Fields *));
    printf("\nEnter the calendar details: ");
    for (i = 0; i < 7; i++) {
        printf("\nEnter the Week Name: ");
        fgets(Name, sizeof(Name), stdin);
        Name[strlen(Name)-1] = '\0';
        printf("Enter the Week Discription: ");
        fgets(Disc, sizeof(Disc), stdin);
        printf("Enter the Week Day: ");
        scanf("%d", &Day);
        c = getchar();
        Activity[i] = Create(Name, Day, Disc);
        fflush(stdin);
    }
}

void display(void)
{
    int i;
    printf("\nWeek Name\tDay\tDiscription\n");
    for (i = 0; i < 7; i++) {
        printf("%10s\t%d\t%s\n",
               Activity[i]->Day_Name,
               Activity[i]->Day_Date,
               Activity[i]->Discription);
    }
}

int main(void)
{
    readData();
    display();
    return 0;
}
