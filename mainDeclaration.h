#pragma once

#define MAX_SIZE 50

typedef struct PersonalInformation {
    char firstName[MAX_SIZE];
    char lastName[MAX_SIZE];
    char gender; //rani zdt gender
}PersonalInformation;

typedef struct Doctor {
    PersonalInformation IP; //IP hiya mokhtasar ta3 PersonalInformation
    char specialization[MAX_SIZE];
    char block; //block li Responsable 3lih
}Doctor;

typedef struct Patient {
    int id;
    PersonalInformation IP;
    int age;
    char bloodType[3];
    bool emergencySituation; // is this patient on a emergency or just the usual check in
    char illnessOrInjury[MAX_SIZE]; //مرض او اصابة
    char block; //The Block he will pass in to be checked
    //na7it priority ma na7tajohach
    Doctor personalDoctor;
}Patient;