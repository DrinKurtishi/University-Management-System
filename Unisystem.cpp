/*
    University management system - a C++ project for University
    Author: Drin Kurtishi
    Author ID: 130814   
    Mentor: Prof. Lejla Abazi-Bexheti
    Version: 1.0.0

    This is a program that manages student records at a university. It uses a main menu with options to register new students, 
    view all registered students, view students of a specific faculty, view university statistics, and end the program.

    The program is written using the class Student, which serves as a blueprint for creating student objects. The class encapsulates
    all the relevant information and behaviors of a student, making it easier to manage and manipulate student data. 

    When registering a new student, the program generates a unique ID and stores it in a vector to avoid duplicates. It also sorts the student 
    into the appropriate faculty vector and increments the number of students in that faculty. 

    After storing the registered students in vectors, the program alphabetically sorts the students for better readability.

    The main program is structured with a do-while loop that continues to prompt the user for input until they choose to end the program. The program 
    uses various helper functions to carry out specific tasks such as registering a new student, displaying all students, and displaying university statistics.

    In addition to these features, the program also boasts a robust input validation system. Before any user input is processed, the program checks 
    to ensure that it is in the correct format and meets any necessary requirements. This helps to prevent errors and ensure that the program runs smoothly. 
    If the input is invalid, the program provides clear and helpful error messages to the user, guiding them through the correct input format. 
    The input validation system is an important component of the program, ensuring that users are able to make the most of its features without encountering frustrating errors.

*/

#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iomanip>
using std::string;
using std::vector;
using std::cout;
using std::cin;

class Student{
    private:
        string Name;
        string Surname;
        string ID;
        string Faculty;

    public:
        //flags to check if user input is valid
        bool surnameFlag = false; 
        bool nameFlag = false;
        
        //getters and setters for private variables
        string getName();
        void setName(string);

        string getSurname();
        void setSurname(string);

        string getID();
        void setID(string);

        string getFaculty();
        void setFaculty(string);

        //default constructor and custom constructor
        Student(); 
        Student(string, string, string, string);

        //methods for showing information
        void showStudentInfo();
        void showStudentInfoFaculty();//used when displaying only students of the same faculty(doesnt print students faculty because its redundant information)
};

//Main helper functions for every switch case (these use the functions specified below)
int showMainMenu();
void registerStudent(vector<Student>&, int&, string&, vector<int>&, vector<Student>&, vector<Student>&, vector<Student>&, vector<Student>&, int&, int&, int&, int&, string, string);
void displayAllStudents(vector<Student>&, int);
void displayUniversityStatistics(int, int, int, int, int);
void EndingProgramText(int);

//functions for input validation
bool validateAttribute(string);
int CheckAndSetID(int, vector<int>);
int ValidateChoice(string);

//functions for simplyfying
string GetAndSetAttribute(string);
int IDgenerator();
string formatString(string, int);//formats users input(Uppercase letters followed by lowercase letters)
string ChooseFaculty();
void chooseFacultyList(vector<Student>&, vector<Student>&, vector<Student>&, vector<Student>&, int&, int&, int&, int&);
void showStudents(int, string);

//function for sorting algorithm
bool compareByName(Student&, Student&); //comparator used to tell std::sort to sort by student name

int main()
{
    system("CLS");
    int choice;
    string input;
    string Name;
    string ID;
    string Surname;
    string Faculty;
    srand(time(0));//seed for random number that changes with time for giving unique IDs
    bool exitLoop = false;//to end program if user chooses
    vector<Student> student; //using vector instead of array to dynamically size it instead of having a prefixed limit of students
    Student newStudent;//create blank student object
    vector<int> IDvector;//vector to store unique IDs (and to check for potential duplicates)

    vector<Student> CSstudent;//vector to store only cs students for display
    vector<Student> BEstudent;//vector for business economics students
    vector<Student> LWstudent;//vector for law students
    vector<Student> LNstudent;//vector for language students

    //keeping track of the number of students of specific faculties
    int i = 0;//used to increment student vector and the number of all students
    int CSnumber = 0; //nr of Cs students
    int BEnumber = 0; //nr of BE students
    int LWnumber = 0; //nr of Law students
    int LNnumber = 0; //nr of Language students

    do{
        choice = showMainMenu();
        
        switch(choice)
        { 
            case 1://registers new student
                registerStudent(student, i, ID, IDvector, CSstudent, BEstudent, LWstudent, LNstudent, CSnumber, BEnumber, LWnumber, LNnumber, Name, Surname);
            break;

            case 2://displays all registered students
                displayAllStudents(student, i);
            break; 

            case 3://displays students of specific faculty
                chooseFacultyList(CSstudent, BEstudent, LWstudent, LNstudent, CSnumber, BEnumber, LWnumber, LNnumber);
            break;

            case 4://displays some information about the University
                displayUniversityStatistics(i, CSnumber, BEnumber, LWnumber, LNnumber);
            break;

            case 5://Terminates program
                EndingProgramText(i);  
                exitLoop = true;
            break; 

            default:
                cout << "Invalid input, please try again.\n";
                system("PAUSE");
                system("CLS");
        }
    }while(exitLoop == false);
    return 0;
}

//MAIN HELPER FUNCTIONS

int showMainMenu() {
    cout << "UNIVERSITY MANAGEMENT SYSTEM\n"
         << "Press 1 to register new student: \n"
         << "Press 2 to view every student list: \n"
         << "Press 3 to view student list of a specific faculty:\n"
         << "Press 4 to view University statistics:\n"
         << "Press 5 to end program(WARNING! This will erase your entire database)\n";

    string input;
    std::getline(cin, input);
    system("CLS");
    return ValidateChoice(input);
}

void registerStudent(vector<Student>& student, int& i, string& ID, vector<int>& IDvector, vector<Student>& CSstudent, vector<Student>& BEstudent, vector<Student>& LWstudent, vector<Student>& LNstudent, int& CSnumber, int& BEnumber, int& LWnumber, int& LNnumber, string Name, string Surname)
{
    student.push_back(Student()); // add blank student to vector
    
    student[i].setFaculty(ChooseFaculty());

    do {
        cout << "Enter Student Name: ";
        student[i].setName(GetAndSetAttribute(Name));
    } while(student[i].nameFlag == true); // if invalid, prompt again.

    do {
        cout << "Enter Student Surname: ";
        student[i].setSurname(GetAndSetAttribute(Surname));
    } while(student[i].surnameFlag == true); // if invalid, prompt again.

    cout << "\nStudent " << student[i].getName() << " " << student[i].getSurname() // display student name after registering
              << " has been succesfuly registered!\n";

    ID = std::to_string(CheckAndSetID(IDgenerator(), IDvector)); // generate and validate ID so no duplicates are registered
    student[i].setID(ID); // set unique ID to Student

    system("PAUSE");
    system("CLS");

    // choose in which faculty vector to put student
    string Faculty = student[i].getFaculty();
    if(Faculty == "Computer sciences") {
        CSstudent.push_back(student[i]);
        CSnumber++; // increment number of students in faculty
    } else if(Faculty == "Business economics") {
        BEstudent.push_back(student[i]);
        BEnumber++;
    } else if(Faculty == "Law") {
        LWstudent.push_back(student[i]);
        LWnumber++;
    } else {
        LNstudent.push_back(student[i]);
        LNnumber++;
    }
    i++; // increment i to move to the next student in the array
    sort(student.begin(), student.end(), compareByName);//sort main student vector
    //sort individual faculty vectors
    sort(CSstudent.begin(), CSstudent.end(), compareByName);
    sort(BEstudent.begin(), BEstudent.end(), compareByName);
    sort(LWstudent.begin(), LWstudent.end(), compareByName);
    sort(LNstudent.begin(), LNstudent.end(), compareByName);
}
void displayAllStudents(vector<Student>& student, int i) {//displays all registered students
    if (i != 0) {
        for (int j = 0; j < i; j++) {
            cout << "Student " << j + 1 << ":\n";
            student[j].showStudentInfo();
        }
    }
    else {
        cout << "Please enter at least one student.\n";
    }
}

void displayUniversityStatistics(int i, int CSnumber, int BEnumber, int LWnumber, int LNnumber) {
    system("CLS");
    cout << "You have selected to view University statistics!\n";
    if (i == 0) {
        cout << "\nThere are no students enrolled in your University.\n";
        system("PAUSE");
        system("CLS");
    }
    else if (i == 1) {
        cout << "\nThere is one student enrolled in your University. ";
        if (CSnumber == 1) {
            cout << "He/she is studying Computer science.\n";
        }
        else if (BEnumber == 1) {
            cout << "He/she is studying Business economics.\n";
        }
        else if (LWnumber == 1) {
            cout << "He/she is studying Law.\n";
        }
        else {
            cout << "He/she is studying Languages.\n";
        }
        system("PAUSE");
        system("CLS");
    }
    else {
        cout << "\nThere are a total of " << i << " students enrolled in your University.\n";
        showStudents(CSnumber, "Computer science");
        showStudents(BEnumber, "Business economics");
        showStudents(LWnumber, "Law");
        showStudents(LNnumber, "Language");
        system("PAUSE");
        system("CLS");
    }
}

void EndingProgramText(int i)
{
    if(i != 0)//if there are registered students also print this
    {
        cout << "Erasing student database."; Sleep(600);
        cout << "."; Sleep(600);
        cout << "."; Sleep(600);
        system("CLS");
    }
        cout<< "Terminating program."; Sleep(600);
        cout<< "."; Sleep(600);
        cout<< "."; Sleep(600);
        system("CLS");
        cout<< "Thank you for using Unisystem!\n"; Sleep(1000);
}
/////////////////////////////////////////////////////////////////////////////
//FUNCTIONS FOR INPUT VALIDATION

bool validateAttribute(string attribute) 
{
    int nameLength = attribute.length();
    for (int i = 0; i < nameLength; i++) 
    {
        if (!isalpha(attribute[i])) 
        {
            return false; // if there is a number in the input
        }
    }
    if(attribute.length() >= 10)
    {
        return false;
    }
    if (attribute.find(' ') != string::npos) 
    {
        return false; // if there is more than one word in input
    }
    return true; // if input is valid
}

int CheckAndSetID(int random, vector<int> IDvector)
{
    //this loop makes sure no duplicate ID is generated
    while(std::count(IDvector.begin(), IDvector.end(), random))//if random is duplicate in ID vector,
    {                                                          //then generate a new ID until it is 
        random = IDgenerator();                                //unique
    }
    IDvector.push_back(random);//adds ID to the IDvector
    return random;
}

int ValidateChoice(string input)
{
    if (input.length() == 1 && std::isdigit(input[0])) //accept choice input only if input is one digit
    {
        return input[0] - '0';  // Convert char to int
    }
    else 
    {
        return 999;//set choice to an invalid input so default case is triggered(invalid)
    }
}
/////////////////////////////////////////////////////////////////////////////
//FUNCTIONS FOR SIMPLYFYING

string GetAndSetAttribute(string Attribute)
{
    cin >> std::ws; // consume whitespace characters (te remove anything left in cin buffer that causes bugs)
    std::getline(cin, Attribute);
    return Attribute;
}

int IDgenerator()
{
    int n = 130000 + (rand() % 9999);
    return n;
}

string formatString(string userInput, int inputLength)//function to format users input
{
    if(islower(userInput[0]))//capitalize first letter
    {
        userInput[0] = toupper(userInput[0]);
    }
    for(int i = 1; i < inputLength; i++)//i is 1 so it doesnt check first letter
    {   
        if(isupper(userInput[i]))                   //lowercase all uppercase       
        {                                           //letters after first one
            userInput[i] = tolower(userInput[i]);
        }
    }
    return userInput;
}

string ChooseFaculty()//switch case for choosing faculty of student
{
    string faculty;
    int facultyChoice;
    bool exitFacultyLoop = false;
    do
    {
            
        cout << "Please choose faculty of student:\n"
                  << "Press 1 for Computer science\n"
                  << "Press 2 for Business economy\n"
                  << "Press 3 for Law\n"
                  << "Press 4 for Languages\n";

        std::getline(cin, faculty);
        system("CLS");
        facultyChoice = ValidateChoice(faculty);

        switch(facultyChoice)
        {
            case 1:
                cout << "You have selected the faculty of Computer sciences!\n";
                faculty = "Computer sciences";
                exitFacultyLoop = true;
            break;
                        
            case 2:
                cout << "You have selected the faculty of Business economics!\n";
                faculty = "Business economics";
                exitFacultyLoop = true;
            break;

            case 3:
                cout << "You have selected the faculty of Law!\n";
                faculty = "Law";
                exitFacultyLoop = true;
            break;

            case 4:
                cout << "You have selected the faculty of Languages!\n";
                faculty = "Languages";
                exitFacultyLoop = true;
            break;

            default:
                cout << "Invalid input, please try again\n";
                system("PAUSE");
                system("CLS");
        }
    }while(exitFacultyLoop == false);
    return faculty;
}

void chooseFacultyList(vector<Student>& CSstudent, vector<Student>& BEstudent, vector<Student>& LWstudent, vector<Student>& LNstudent, int& CSnumber, int& BEnumber, int& LWnumber, int& LNnumber)
{
    bool exitLoop = false;
    string input;
    int choice;
    cout << "You have chosen to view a list of students from a specific faculty\n";
    do 
    {
        cout << "Press 1 to view list of Computer science students:\n";
        cout << "Press 2 to view list of Business economics students:\n";
        cout << "Press 3 to view list of Law students:\n";
        cout << "Press 4 to view list of Language students:\n";
        cout << "Press 5 to go back to main menu:\n";

        std::getline(cin, input);
        system("CLS");
        choice = ValidateChoice(input);

        switch(choice)
        {
            case 1:
                if(CSnumber != 0)
                {
                    cout << "You have chosen to view the list of Computer science students!:\n";
                    for(int j = 0; j < CSnumber; j++)
                    {
                        CSstudent[j].showStudentInfoFaculty();
                        cout << "\n";
                    }
                }
                else
                {
                    cout << "Please enter at least one Computer science student.\n";
                    system("PAUSE");
                    system("CLS");
                }
               
            break;

            case 2:
                if(BEnumber != 0)
                {
                    cout << "You have chosen to view the list of Business economics students\n";
                    for(int j = 0; j < BEnumber; j++)
                    {
                        BEstudent[j].showStudentInfoFaculty();
                        cout << "\n";
                    }
                }
                else
                {
                     cout << "Please enter at least one Business economics student.\n";
                     system("PAUSE");
                     system("CLS");
                }
               
            break;

            case 3:
                if(LWnumber != 0)
                {
                    cout << "You have chosen to view the list of Law students\n";
                    for(int j = 0; j < LWnumber; j++)
                    {
                        LWstudent[j].showStudentInfoFaculty();
                        cout << "\n";
                    }
                }
                else
                {
                    cout << "Please enter at least one Law student.\n";
                    system("PAUSE");
                    system("CLS");
                }
               
            break;

            case 4:
                if(LNnumber != 0)
                {
                    cout << "You have chosen to view the list of Language students\n";
                    for(int j = 0; j < LNnumber; j++)
                    {
                        LNstudent[j].showStudentInfoFaculty();
                        cout << "\n";
                    }
                }
                else
                {
                    cout << "Please enter at least one Language student.\n";
                    system("PAUSE");
                    system("CLS");
                }
                
            break;

            case 5:
                exitLoop = true;
            break;

            default:
                cout << "Invalid input, please try again.\n";
                system("PAUSE");
                system("CLS");
        }
    }while (exitLoop == false);
}

void showStudents(int studentNumber, string faculty)
{
    if(studentNumber == 0)//if there are no students in faculty
    {
        cout << "None in " << faculty; cout << ".\n";
    }
    else
    {
        cout << studentNumber << " in " << faculty; cout << ".\n";
    }
}

bool compareByName(Student& a, Student& b) { //comparator used for sorting algorithm
    return a.getName() < b.getName();
}
/////////////////////////////////////////////////////////////////////////////
//METHODS OF STUDENT CLASS

string Student::getName()
{
    return Name;
}

void Student::setName(string newName)
{
     if (validateAttribute(newName)) 
     {
        newName = formatString(newName, newName.length());
        Name = newName;
        nameFlag = false;
    }       
    else 
    {
        cout << "Invalid input: Name must contain a single word, without numbers and less than 15 characters.\n";
        nameFlag = true;
    }
}

string Student::getSurname()
{
    return Surname;
}

void Student::setSurname(string newSurname)
{
     if (validateAttribute(newSurname)) 
    {
        newSurname = formatString(newSurname, newSurname.length());
        Surname = newSurname;
        surnameFlag = false;
    } 
    else 
    {
        cout << "Invalid input: Surname must contain a single word, without numbers and less than 15 characters.\n";
        surnameFlag = true;
    }
}

string Student::getID()
{
    return ID;
}

void Student::setID(string newID)
{
    ID=newID;
}

string Student::getFaculty()
{
    return Faculty;
}

void Student::setFaculty(string newFaculty)
{
    Faculty = newFaculty;
}

Student::Student()//default constructor
{
    Name = "blank";
    Surname = "blank";
    ID = "blank";
    Faculty = "blank";
}

Student::Student(string name, string surname, string id, string faculty) //custom constructor
{
    Name = name;
    Surname = surname;
    ID = id;
    Faculty = faculty;
}

void Student::showStudentInfo()
{
    cout 
    << "Name: " << Name << "\n"
    << "Surname: " << Surname << "\n"
    << "ID: " << ID << "\n"
    << "Faculty: " << Faculty << "\n"
    << "\n*************************\n";
}

void Student::showStudentInfoFaculty()//used when displaying students of the same faculty (we dont need their faculty because we know it)
{
    cout 
    << "Name: " << Name << "\n"
    << "Surname: " << Surname << "\n"
    << "ID: " << ID << "\n"
    << "\n*************************\n";
}
