//  problem: Consider a scenario where ICE dept. of RU wants to maintain the record of its 
// students. The record contains Students ID (last two digits), Year (1 or 2 or 3 or 4) that are 
// saved in a singly linked list called ICE_St-List. Do the following... 
//  Initially linked list will be empty.  
//  Every insertion of a student’s record will be performed at the beginning of the linked list.  
//  User can insert students record as many as s/he wish. 
//  After every insertion, ICE_St-List will be displayed.  
//  Example: 11 1 -> 32 2 -> 43 1 ->24 3

#include <iostream>
#include <cstdlib>

using namespace std;

struct Student {
    int id;
    int year;
    struct Student* next;
};

struct Student* head = NULL;

void insertAtBeginning(int id, int year) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    newStudent->year = year;
    newStudent->next = head;
    head = newStudent;
}

void display() {
    cout << "ICE_St-List:" << endl;
    struct Student* cur = head;
    while (cur != NULL) {
        cout << cur->id << " " << cur->year << " -> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

int main() {
    char choice;
    do {
        int id, year;
        cout << "Enter Student ID (last two digits): ";
        cin >> id;
        cout << "Enter Year (1, 2, 3, or 4): ";
        cin >> year;
        insertAtBeginning(id, year);
        display();
        cout << "Do you want to insert another record? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
