#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"queue.h"


#define MAX_SIZE 50

typedef struct PersonalInformation{
    char firstName[MAX_SIZE];
    char lastName[MAX_SIZE]
}PersonalInformation;

typedef struct Doctor{
    PersonalInformation IP;//IP hiya mokhtasar ta3 PersonalInformation
    char specialization[MAX_SIZE];
    char block//block li Responsable 3lih
}Doctor;

typedef struct Patient{
    PersonalInformation IP;
    int age;
    char bloodType[3];
    bool emergencySituation;
    char illnessOrInjury[MAX_SIZE];//مرض او اصابة
    char block;
    int priority;//ndiroha 0 ida emergency
    Doctor personalDoctor;
}Patient;