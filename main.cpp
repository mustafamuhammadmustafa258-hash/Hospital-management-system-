
#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
};

Patient patients[100];
int count = 0;

// Function to add a patient
void addPatient() {
    if (count >= 100) {
        cout << "Hospital record is full!\n";
        return;
    }

    cout << "\nEnter Patient ID: ";
    cin >> patients[count].id;

    // Check duplicate ID
    for (int i = 0; i < count; i++) {
        if (patients[i].id == patients[count].id) {
            cout << "Patient ID already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, patients[count].name);

    cout << "Enter Patient Age: ";
    cin >> patients[count].age;

    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, patients[count].disease);

    count++;

    cout << "\nPatient Added Successfully!\n";
}

// Function to display all patients
void displayPatients() {
    if (count == 0) {
        cout << "\nNo Patient Records Found!\n";
        return;
    }

    cout << "\n--- Patient Records ---\n";

    for (int i = 0; i < count; i++) {
        cout << "\nPatient ID: " << patients[i].id;
        cout << "\nName: " << patients[i].name;
        cout << "\nAge: " << patients[i].age;
        cout << "\nDisease: " << patients[i].disease;
        cout << "\n----------------------\n";
    }
}

// Function to search a patient
void searchPatient() {
    int id;
    cout << "\nEnter Patient ID to Search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            cout << "\nPatient Found!";
            cout << "\nName: " << patients[i].name;
            cout << "\nAge: " << patients[i].age;
            cout << "\nDisease: " << patients[i].disease;
            return;
        }
    }

    cout << "\nPatient Not Found!\n";
}

// Function to discharge a patient
void dischargePatient() {
    int id;
    cout << "\nEnter Patient ID to Discharge: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                patients[j] = patients[j + 1];
            }

            count--;

            cout << "\nPatient Discharged Successfully!\n";
            return;
        }
    }

    cout << "\nPatient Not Found!\n";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====";
        cout << "\n1. Add New Patient";
        cout << "\n2. Display All Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Discharge Patient";
        cout << "\n5. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                dischargePatient();
                break;

            case 5:
                cout << "\nThank You for Using Hospital Management System!";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.";
        }

    } while (choice != 5);

    return 0;
}
