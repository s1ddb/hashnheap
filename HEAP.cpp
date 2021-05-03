#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

//functions

void printHeap(int* heap, int size);
void removeHeap(int* heap, int size);

void parse(char* in, int* mod, int &count);

void createHeap(int* mod, int* heap, int size);
int getMax(int* arr);


int main() {

char filename[30] //variable to get the file name
char input[1000]; //variable to get the input

char initinp[10]; 
int charcount = 0; //to count the number of characters
int mod[100];


for (int i = 0; i < 100; i++) { //to clear the integer array

    mod[i] = 0;
}

//main

cout << "This is a program for Heap." << endl;
cout << "You have two commands: 'HEAP', 'QUIT'. " << endl;

cin.get(initinp, 10); //gets the user's input for heap or quit
cin.clear();
cin.ignore(10000, '\n'); //terminating character

if (initinp[0] == 'H' && initinp[1] == 'E' && initinp[2] == 'A' && initinp[3] == "P") {

    cout << "Would you like to type in your input or feed in a file?" << endl;
    cout << "You have two commands: 'FILE', 'TYPE'. " << endl;

    cin.get(initinp, 10);
    cin.clear();
    cin.ignore(10000, '\n');

    if (initinp[0] == 'F' && initinp[1] == 'I' && initinp[2] == 'L' && initinp[3] == "E") {

        cout << "What is the name of the file?" << endl << "ENTER THE NAME OF THE FILE:";
        cout << endl;

        cin.get(filename, 30);
        cin.clear();
        cin.ignore(10,000, '\n'); //terminating character

        //getting the file
        streampos size;  //stream position
        ifstream file(filename, ios:in | ios:binary | ios:ate);

        //finish file stuff
    }
    else if (initinp[0] == 'T' && initinp[1] == 'Y' && initinp[2] == 'P' && initinp[3] == "E") {

        cout << "Type in numbers, seperated by a space:" << endl;
    }
}



}