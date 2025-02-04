#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mainDeclaration.h"
#include "history.h"
#include "queue.h"
#include "functions.h"

int main()
{
    PatQueue SQ; //Standard Queue
    PatQueue EQ; //Emergency Queue
    History* hist = 0; //The History of the actions taken
    HistoryData data;
    int numberChoice, currentDocArraySize = 0, chooseDoc, lastElemIndexHist = 0, indexChoice = 0;
    char ynq;
    bool isRunning = true;
    Doctor* docs;

    printf("------------------------------------------------------\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");   
    printf("|                      HOSPITAL                      |\n");
    printf("|                      MANAGER                       |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("------------------------------------------------------\n");
    printf("\nWelcome to Hospital Manager, pls choose your options by typing there number on their left or else death\n");

    SQ = InitQueue();
    EQ = InitQueue();
    hist = InitHistory();
    docs = 0;

    while (isRunning)
    {
        if (isRunning == false) break;

        printf("\n1 - Add Patient to the Queue \n2 - Remove Patient From The Queue (Passed his/her checkup or he/her are being treated rightnow) \n3 - View History of changes \n4 - Add A Doctor \n5 - Search For a Specific Patient \n6 - Exit\n");
        scanf("%d", &numberChoice);

        switch (numberChoice)
        {
            case 1:
                if (docs == 0)
                {
                    printf("You need to add in a Doctor first\n");
                }
                else
                {
                    Patient p;
                    printf("Enter The Patient's First Name: ");
                    scanf("%49s", &(p.IP.firstName));
                    printf("Enter The Patient's Last Name: ");
                    scanf("%49s", &(p.IP.lastName));
                    printf("Enter The Patient's Gender (M = male, F = female): ");
                    scanf(" %c", &(p.IP.gender));
                    while (!(p.IP.gender == 'F' || p.IP.gender == 'f' || p.IP.gender == 'M' || p.IP.gender == 'm'))
                    {
                        printf("Pls Re-enter The Patient's Gender (M = male, F = female): ");
                        scanf(" %c", &(p.IP.gender));
                    }
                    printf("Enter The Patient's Age: ");
                    scanf("%d", &(p.age));
                    printf("Enter The Patient's BloodType (ex: A+, O-, AB+, ect....): ");
                    scanf("%3s", &(p.bloodType));
                    while (!(stricmp(p.bloodType, "A+") == 0 || stricmp(p.bloodType, "A-") == 0 || stricmp(p.bloodType, "B+") == 0 || stricmp(p.bloodType, "B-") == 0 || stricmp(p.bloodType, "O+") == 0 || stricmp(p.bloodType, "O-") == 0 || stricmp(p.bloodType, "AB+") == 0 || stricmp(p.bloodType, "AB-") == 0))
                    {
                        printf("Pls Re-enter The Patient's BloodType: ");
                        scanf("%3s", &(p.bloodType));
                    }
                    printf("is The Patient in a Emergency State ? [Y/n]: ");
                    scanf(" %c", &ynq);
                    while (!(ynq == 'Y' || ynq == 'y' || ynq == 'n' || ynq == 'N'))
                    {
                        printf("reconfirm the Patient emergency state: ");
                        scanf(" %c", &ynq);
                    }
                    if (ynq == 'Y' || ynq == 'y')
                    {
                        p.emergencySituation = true;
                    }
                    else
                    {
                        p.emergencySituation = false;
                    }
                    printf("Enter The Patient's Illness/Injury (optional): ");
                    scanf("%49s", &(p.illnessOrInjury));
                    printf("Enter The Patient's Assigned Doctor (Choose a number from the listed): \n");
                    for (int i = 0; i <= currentDocArraySize-1; i++)
                    {
                        printf("%d:\n", i+1);
                        printf("Doc Full Name: %s %s\n", docs[i].IP.firstName, docs[i].IP.lastName);
                        printf("Doc's Specialiazation field: %s\n", docs[i].specialization);
                    }
                    scanf("%d", &chooseDoc);
                    while (chooseDoc > currentDocArraySize || chooseDoc < 1)
                    {
                        printf("Choose a number in the range of %d and 1", currentDocArraySize-1);
                        scanf("%d", &chooseDoc);
                    }
                    p.personalDoctor = docs[chooseDoc];
                    p.block = p.personalDoctor.block;
                    AddPatient(p, &SQ, &EQ, hist, &lastElemIndexHist);
                }
                break;
            case 2:
                DeletePatient(&SQ, &EQ, hist, &lastElemIndexHist);
                if (!IsEmpty(SQ) && !IsEmpty(EQ))
                {
                    printf("Patient Was Succesfully Deleted! \n");
                }
                break;
            case 3:
                ShowHistory(hist, lastElemIndexHist);
                printf("Show More Details ? [Y/n]");
                scanf(" %c", &ynq);
                while (!(ynq == 'Y' || ynq == 'y' || ynq == 'n' || ynq == 'N'))
                {
                    printf("State your answer correctly: ");
                    scanf(" %c", &ynq);
                }

                if (ynq == 'Y' || ynq == 'y')
                {
                    printf("Choose which One you want to see in more details: ");
                    scanf("%d", &indexChoice);
                    while (indexChoice < 1 || indexChoice > lastElemIndexHist)
                    {
                        printf("Make sure you choose a number within range: ");
                        scanf("%d", &indexChoice);
                    }
                    ShowMoreInfo(hist, indexChoice);
                }
                break;
            case 4:
                if (docs == 0)
                {
                    docs = malloc(MAX_SIZE*sizeof(Doctor));
                }
                Doctor d;
                printf("Enter The Doctor's First Name: ");
                scanf("%49s", &(d.IP.firstName));
                printf("Enter The Doctor's Last Name: ");
                scanf("%49s", &(d.IP.lastName));
                printf("Enter The Doctor's Gender (M = male, F = female): ");
                scanf(" %c", &(d.IP.gender));
                while (!(d.IP.gender == 'F' || d.IP.gender == 'f' || d.IP.gender == 'M' || d.IP.gender == 'm'))
                {
                    printf("Pls Re-enter The Doctor's Gender (M = male, F = female): ");
                    scanf(" %c", &(d.IP.gender));
                }
                printf("Enter The Doctor's Field (Optional): ");
                scanf("%49s", &(d.specialization));
                printf("Enter The Doctor's Block: ");
                scanf(" %c", &(d.block));
                docs[currentDocArraySize] = d;
                currentDocArraySize++;
                break;
            case 5:
                if (!IsEmpty(SQ) || !IsEmpty(EQ))
                {
                    Patient p;
                    printf("Enter The ID of the Patient you want to find: ");
                    scanf("%d", &(p.id));
                    printf("Enter The Patient's you want to find First Name: ");
                    scanf("%49s", &(p.IP.firstName));
                    printf("Enter The Patient's you want to find Last Name: ");
                    scanf("%49s", &(p.IP.lastName));
                    if (SearchPAt(SQ, EQ, &p))
                    {
                        printf("Patient Was Found\n");
                    }
                    else
                    {
                        printf("Patient Wasn't Found\n");
                    }
                }
                else
                {
                    printf("There are no patients to search for\n");
                }
                break;
            case 6:
                isRunning = false;
                break;         
            default:
                printf("You Can't input that number, pls choose again\n");
                break;
        }
    }

    printf("Progam Exited.\n");
    system("pause");
    return 0;
}
