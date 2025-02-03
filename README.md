# Hospital Management System in C

This is a simple hospital management system implemented in C. The system allows patient management.

## How to Compile
download the Code on Github, then Open the project in your IDE of choice, In The Terminal Run:

```shell
make
```

if this doesn't work or you don't have Make Installed then run this:

```shell
gcc history.c queue.c functions.c Main.c -o Hopital
```

**Note**: GCC Compiler has to be installed.

## Features

- **Add Patient**: Add a new patient to the system. Patients can be added to either the standard queue or the emergency queue.
- **Search Patient**: Search for a patient by their ID or other info.
- **Delete Patient**: Remove a patient from the system.
- **Patient History**: View the history of all patients added/removed to/from the system.

## Data Structures
- **Patient**: contains all the informations of a patient(ID, IP(first and last name), the illness or injury, Condition(standard or emergency), age, bloodtype, block of treatment, personal doctor).

- **Queues**: Two queues are used to manage patients:
  - **Standard Queue**: For patients with non-urgent conditions.
  - **Emergency Queue**: For patients requiring immediate attention.

## Functions

1. **`AddPatient`**:
   - Adds a patient to either the standard or emergency queue.
   - Parameters: `Patient struct`, `the standard queue`, `the emergency queue`.

2. **`SearchPatientAt`**:
   - Searches for a patient by their ID or other informations.
   - Parameters: `Patient struct`, `standard queue`, `emergency queue`.
   - Returns: true if found else false.

3. **`DeletePatient`**:
   - Deletes a patient from the system.
   - Parameters: `standard queue`, `emergency queue`.

4. **`ViewHistory`**:
   - Displays the history of all patients added/removed to/from the system.

## Some notes about the program
- The program uses headers for the primitive queue functions, main program + history functions and the patient + doctor structs.
- This Program is made using the Standard C I/O library (The Console).
