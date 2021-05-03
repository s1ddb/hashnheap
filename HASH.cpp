#include <iostream>
#include <cstring>
#include <iomanip>


/* 
Siddhartha Bobba
03/18/2021
A student list program to allow the user to keep track of all the students added, their gpas, and IDs. Student List allows the user to add new students to the list and print all of them out for a database and also delete when required. QUIT function to exit out of the program.
*/


using namespace std;

struct Student {//a struct object to hold data on every student

  char* firstname;
  char* lastname;
  int id; //ID of the student
  float gpa; //gpa of the student
  Student* next;
  Student* previous;


};

void addStudent(Student** list, Student* newStudent, int tablesize);
void printStudent(Student** list, int tablesize);
void checkCollisions(Student** list, int tablesize);
  
 


int main() {



    bool IsRunning = true; //boolean to check if the program is running or not, used in loop
    char input[10]; //gets user input to see what command or action they want to perform
    int DELinput = 0; //gets user input for what student ID has to be deleted
    int num = 0; //used in DELETE
      
    //vector<Student*>*list = new vector<Student*>();
	
    Student** list = new Student*[100];
    int tablesize = 100;

    while (IsRunning == true) { // while the program / code is running
	
	  
	  cout << "This is the Hash Table for Student Lists. What would you like to do?" << endl;
	  cout << endl;
	  cout << "ADD" << endl << "PRINT" << endl << "DELETE" << endl << "QUIT" << endl; //gives user the options
	  cout <<endl; //space
	  cout << "Please select from the above commands and enter:" << endl; //asks to enter

	  cin.get(input, 10);
	  cin.clear();
	  cin.ignore();

	  

	  if (input[0] == 'A' && input[1] == 'D' && input[2] == 'D') { //if the first input matches 'ADD', run add student function

		  
		Student* newStudent = new Student();
		newStudent->next = NULL;
		newStudent->previous = NULL;
		  
		
 	 //first name
  
 		char*first = new char[20]; //allocates memory space for a new char to the memory location of first

  		cout << "Enter a first name:" << endl;
		cin >> first;

 		 NewS->firstname = first; //sets the firstname to whatever is inside first after being read in by the cin in the previous line

 		 //last name

  		char*last = new char[20]; //allocates memory space for a new char to the memory location of last
  
  		cout << "Enter the last name:" << endl;
  		cin >> last; //gets last name
  		NewStudent->lastname = last;
				    

 		 // id
		
 		 cout << "What's the ID of the student? :" << endl;				    
		 cin >> NewStudent->id; //read in user input for id into the memory location of id inside of the struct student

  		//gpa

  		cout << "Enter the gpa: " << endl;
  		cin >> NewStudent->gpa; //read in the user input for gpa into the memory location of gpa inside the struct student
  		cin.ignore();

  		//----
  
		ADD(list, newStudent, tablesize);
		cout << "Student has been added." << endl;
		  
		  //collision balancing
		  
		if (checkCollision(list, tablesize)) {
			
			cout << "Collision detected in hash table, doubling table size" << endl;
			Student** tmp = new Student*[tablesize];
			for(int b = 0; b < tablesize; b++) {
			
				tmp[b] = list[b];
				
			}

            int sizenew = 2*tablesize;
            list = new Student[sizenew]// redraws to double it
			
            for (int c = 0; c < sizenew; c++) {

                list[c] = NULL;
            }

            //adds students back to redrawn list
            for (int dd = 0; dd < tablesize; dd++) {

                if (tmp[dd] != NULL) {

                    Student* readd = tmp[dd]

                    if (readd->next != NULL) {

                        Student* studnext = readd->next;
                        readd->next = NULL;
                        studnext -> previous = NULL;
                        ADD(list, studnext, sizenew);

                        if(studnext->next != NULL) {
                            Student* nxtagain = studnext->next;
                            studnext->next = NULL;
                            nxtagain->previous = NULL;
                            ADD(list, nxtagain, sizenew);
                        }
                    }
                    ADD(list, readd, sizenew);
                }
            }
            delte[] temp;
            tablesize = sizenew; //to update the orig table size to the new

		}
	  }

	  if (input[0] == 'P' && input[1] == 'R' && input[2] == 'I' && input[3] == 'N' && input[4] == 'T') {
	    
	    //what to do here
	    PRINT(list, size);

	  }

   	  if (input[0] == 'D' && input[1] == 'E' && input[2] == 'L' && input[3] == 'E' && input[4] == 'T' && input[5] == 'E') {

	    cout << "Enter the ID of the student you'd like to delete: " << endl; /// asks for the student ID
	    cin >> DELinput; //gets input from user
	    cin.get();
	    num = 0;

	    for (vector<Student*>::iterator it = list->begin(); it != list->end(); ++it) {
	      if((*it)->id == DELinput) {

		delete(*it);
		list->erase(it); //delete, end of iterator
		break;
	      }
	    }
	  }
	  
	  if (input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T') {

	    cout << "Terminating program..." << endl;
	    IsRunning = false; // Ends code, ends while loop

	  }

	}






  return 0;
}






//used a bit of help of a friend on indexing

void addStudent(Student** list, Student* newStudent, int tablesize) {

    int index = (newStudent->id) % size;

  //puts the new student in the current character array

    if (list[index] == NULL) {
    //if no colision, add the student to the list
     list[index] = newStudent;
    } 
    
    else {
    //if there is collision, then add as next pointer
        if ((list[index])->next == NULL) {
    
        //if no previous collisions occured
        (list[index])->next = newStudent;
        (list[index]->next)->previous = (list[index])->next;
    
        }
        
         else {
    
        //if a collision already existents there
    
        ((list[index])->next)->next = newStudent;
        (((list[index])->next)->next)->previous = ((list[index])->next)->next;
    
        }
    }


}



void printStudent(Student** list, int tablesize) {


  for (int i = 0; i < tablesize; i++) {
    Student* current = list[i];

    if (current != NULL) {

      cout << current->firstname;
      cout << " ";
      cout << current->lastname;

    //cout.precision(2); //sets precision of the decimal float to 2
		//cout << current->gpa << endl; //prints gpa

      cout << current->id << " GPA:";
      cout << fixed << setprecision(2) << current->gpa;
      Student* studnext = current->next;

      if (studnext != NULL) {
	cout << '\t' << studnext->firstname << " ";
	cout << studnext->lastname;
	cout << studnext->id << " GPA:";

	cout << fixed << setprecision(2) << studnext->gpa;
      }

      cout << endl;
    } 
  }

}


bool checkCollisions(Student** list, int tablesize) {

  bool listnew = false; //set to false  
  int chk = 0;

//Check if a new list needs to be made
  while (listnew == false && chk < size} {

    if (list[chk] != NULL) {

      if ((list[chk])->next != NULL) {

	    if (((list[chk])->next)->next != NULL) {

	listnew = true; //return true

	        }
        } 
    }
    chk++;
  }

  return listnew;
}