/*
    University management system - a C++ project for University
    Author: Drin Kurtishi, ID: 130814   
    Mentor: Prof. Dr. Lejla Abazi-Bexheti
    Version: 1.0.0

    This is a program that manages student records at a university. It uses a main menu with options to register new students, 
    view all registered students, view students of a specific faculty, view university statistics, and end the program.

    The program is written using the class Student, which serves as a blueprint for creating student objects. The class encapsulates
    all the relevant information and behaviors of a student, making it easier to manage and manipulate student data. 

    When registering a new student, the program generates a unique ID and stores it in a vector to avoid duplicates. It also formats the users
    name and surname for consistency (Uppercase first letter followed by lowercase letters).

    After storing the registered students in vectors, the program alphabetically sorts the students by name for better readability.

    For better readability, I have used different system functions to pause and clear the screen.

    In addition to these features, the program also has an input validation system. Before any user input is processed, the program checks 
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
        
        //getters and setters for hte private variables (attributes)
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

        //methods for showing student information
        void showStudentInfo();
        void showStudentInfoFaculty();//used when displaying only students of the same faculty(doesnt print students faculty because its redundant information)
};

//Main helper functions for every switch case (these use the functions specified below)
int showMainMenu(); //prints main menu and returns4 users choice (for the menu)
void registerStudent(vector<Student>&, int&, string&, vector<int>&, vector<Student>&, vector<Student>&, vector<Student>&, vector<Student>&, int&, int&, int&, int&, string, string); //registers new student
void displayAllStudents(vector<Student>&, int&); //prints list of all registered students
void chooseFacultyList(vector<Student>&, vector<Student>&, vector<Student>&, vector<Student>&, int&, int&, int&, int&);//for choosing and displaying student lists of specifid faculties
void displayUniversityStatistics(int&, int&, int&, int&, int&); //displays number of students and which faculty they belong to
void endingProgramText(int); //shows when user ends program

//functions for input validation
bool validateAttribute(string); //validates input for name and surname
int CheckAndSetID(int, vector<int>&); //checks for duplicate IDs and sets them
int ValidateChoice(string); //used for validating choice for switch statements

//functions for simplyfying the code
string GetAndSetAttribute(string);//prompts user for student name & surname
int IDgenerator();//generates Student IDs
string formatString(string, int);//formats users input(Uppercase letters followed by lowercase letters)
string ChooseFaculty(); //function used to set a faculty to a new student
void showStudents(int, string);//used when displaying University statistics

//function for sorting algorithm
bool compareByName(Student& a, Student& b){
    return a.getName() < b.getName(); //comparator used to tell std::sort to sort by student name
} 

int main()
{
    system("CLS");//clears screen 
    int choice;
    string Name;
    string ID;
    string Surname;
    string Faculty;
    srand(time(0));//seed for random number that changes with time for giving unique IDs
    bool exitLoop = false;//to end program if user chooses
    vector<Student> student; //using vector instead of array to dynamically size it instead of having a prefixed limit of students
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
        choice = showMainMenu();//this function displays the main menu and also returns users choice
        
        switch(choice)//main menu
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

            case 4://displays some information about the University (nr of students)
                displayUniversityStatistics(i, CSnumber, BEnumber, LWnumber, LNnumber);
            break;

            case 5://Terminates program
                endingProgramText(i);  
                exitLoop = true;
            break; 

            default:
                cout << "Invalid input, please try again.\n\n";
                system("PAUSE");// pauses the screen for better user experience ("Press any key to continue...")
                system("CLS");
        }
    }while(exitLoop == false);
    return 0;
}

//MAIN HELPER FUNCTIONS

int showMainMenu() {//this function displays the main menu and also returns users choice
    
    //printing char(x) gives cool borders
    cout << char(201);   for(int i = 0; i < 50; i++){cout << char(205);}   cout << char(187) << "\n"; //top row
    cout << char(186) << "           UNIVERSITY MANAGEMENT SYSTEM           "   << char(186) << "\n" 
         << char(186) << "--------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Press 1 to register new student:                 "   << char(186) << "\n"  
         << char(186) << "--------------------------------------------------"   << char(186) << "\n" 
         << char(186) << " Press 2 to view list of all students:            "   << char(186) << "\n"  
         << char(186) << "--------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " Press 3 to view students of a specific faculty:  "   << char(186) << "\n" 
         << char(186) << "--------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Press 4 to view University statistics:           "   << char(186) << "\n" 
         << char(186) << "--------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
         << char(186) << " Press 5 to end program                           "   << char(186) << "\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    cout << char(200);    for(int i = 0; i < 50; i++){cout << char(205);}  cout << char(188) << "\n"; //bottom row

    string input;
    cout << "\n-------------------------------------\n"
         << "Enter your choice here:  ";
    std::getline(cin, input);
    system("CLS");
    return ValidateChoice(input);//validates users input before returning it
}

void registerStudent(vector<Student>& student, int& i, string& ID, vector<int>& IDvector, vector<Student>& CSstudent, vector<Student>& BEstudent, vector<Student>& LWstudent, vector<Student>& LNstudent, int& CSnumber, int& BEnumber, int& LWnumber, int& LNnumber, string Name, string Surname)
{
    student.push_back(Student()); // add blank student to vector
    
    student[i].setFaculty(ChooseFaculty());//ChooseFaculty prints the choose faculty menu and returns the users choice which is used by SetFaculty of student object

    do 
    {
        cout << "Enter Student Name: ";
        student[i].setName(GetAndSetAttribute(Name));//Same thing here

    } while(student[i].nameFlag == true); // if invalid, prompt again.

    do 
    {
        cout << "Enter Student Surname: ";
        student[i].setSurname(GetAndSetAttribute(Surname));//and here

    } while(student[i].surnameFlag == true); // if invalid, prompt again.

    cout << "\nStudent " << student[i].getName() << " " << student[i].getSurname() // display student name after registering
              << " has been succesfuly registered!\n\n\n";

    ID = std::to_string(CheckAndSetID(IDgenerator(), IDvector)); // generate and validate ID so no duplicates are registered,(IDgenerator generates an ID which is stored in IDVector and validated with CheckAndSetID 
    student[i].setID(ID);                                        //which then is turned into a string and assigned to students ID)

    // Find out in which faculty vector to put student
    string Faculty = student[i].getFaculty();
    if(Faculty == "Computer sciences") 
    {
        CSstudent.push_back(student[i]);
        CSnumber++; // increment number of students in faculty
    } 
    else if(Faculty == "Business economics") 
    {
        BEstudent.push_back(student[i]);
        BEnumber++;
    } 
    else if(Faculty == "Law") 
    {
        LWstudent.push_back(student[i]);
        LWnumber++;
    } 
    else 
    {
        LNstudent.push_back(student[i]);
        LNnumber++;
    }
    i++; // increment i to move to the next student in the array

    //sort main student vector
    sort(student.begin(), student.end(), compareByName);
    //sort individual faculty vectors
    sort(CSstudent.begin(), CSstudent.end(), compareByName);
    sort(BEstudent.begin(), BEstudent.end(), compareByName);
    sort(LWstudent.begin(), LWstudent.end(), compareByName);
    sort(LNstudent.begin(), LNstudent.end(), compareByName);

    system("PAUSE");
    system("CLS");
}
void displayAllStudents(vector<Student>& student, int& i) {//displays all registered students
    if (i != 0) 
    {
        cout << "         LIST OF ALL STUDENTS\n"
             << "------------------------------------\n\n";
        for (int j = 0; j < i; j++) {
            cout << char(201); for(int i = 0; i < 35; i++){cout << char(205);}//top row
            cout << "\n" << char(186) << "            STUDENT " << j + 1 << ":\n";
            student[j].showStudentInfo();
        }
    }
    else 
    {
        cout << "Please enter at least one student.\n\n";
    }
    system("PAUSE");
    system("CLS");
}

void chooseFacultyList(vector<Student>& CSstudent, vector<Student>& BEstudent, vector<Student>& LWstudent, vector<Student>& LNstudent, int& CSnumber, int& BEnumber, int& LWnumber, int& LNnumber)
{
    //this function shows menu and lists the individual student vectors
    bool exitLoop = false;
    string input;
    int choice;
    do 
    {
       
        cout << char(201);   for(int i = 0; i < 54; i++){cout << char(205);}       cout << char(187) << "\n"; //top row
        cout << char(186) << "                 VIEW SPECIFIC FACULTY                "   << char(186) << "\n" 
             << char(186) << "------------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
             << char(186) << " Press 1 to view list of Computer science students:   "   << char(186) << "\n"  
             << char(186) << "------------------------------------------------------"   << char(186) << "\n" 
             << char(186) << " Press 2 to view list of Business economics students: "   << char(186) << "\n"  
             << char(186) << "------------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
             << char(186) << " Press 3 to view list of Law students:                "   << char(186) << "\n" 
             << char(186) << "------------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
             << char(186) << " Press 4 to view list of Language students:           "   << char(186) << "\n" 
             << char(186) << "------------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
             << char(186) << " Press 5 to go back to main menu:                     "   << char(186) << "\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        cout << char(200);    for(int i = 0; i < 54; i++){cout << char(205);}      cout << char(188) << "\n"; //bottom row

        cout << "\n-------------------------------------\n"
             << "Enter your choice here:  ";
        std::getline(cin, input);
        system("CLS");
        choice = ValidateChoice(input);

        switch(choice)
        {
            case 1:
                if(CSnumber != 0)
                {
                    cout << "LIST OF COMPUTER SCIENCE STUDENTS\n"
                         << "---------------------------------\n\n";
                    for(int j = 0; j < CSnumber; j++)
                    {
                        cout << char(201); for(int i = 0; i < 30; i++){cout << char(205);}//top row
                        cout << "\n" << char(186) << "          STUDENT " << j + 1 << ":\n";
                        CSstudent[j].showStudentInfoFaculty();
                    }
                }
                else
                {
                    cout << "Please enter at least one Computer science student.\n\n";
                }
                system("PAUSE");
                system("CLS");
               
            break;

            case 2:
                if(BEnumber != 0)
                {
                    cout << "LIST OF BUSINESS ECONOMICS STUDENTS\n"
                         << "-----------------------------------\n\n";

                    for(int j = 0; j < BEnumber; j++)
                    {
                        cout << char(201); for(int i = 0; i < 30; i++){cout << char(205);}//top row
                        cout << "\n" << char(186) << "          STUDENT " << j + 1 << ":\n";
                        BEstudent[j].showStudentInfoFaculty();
                        cout << "\n";
                    }
                }
                else
                {
                     cout << "Please enter at least one Business economics student.\n\n";
                }
                system("PAUSE");
                system("CLS");
               
            break;

            case 3:
                if(LWnumber != 0)
                {
                    cout << "LIST OF LAW STUDENTS\n"
                         << "---------------------------------\n\n";

                    for(int j = 0; j < LWnumber; j++)
                    {
                        cout << char(201); for(int i = 0; i < 30; i++){cout << char(205);}//top row
                        cout << "\n" << char(186) << "          STUDENT " << j + 1 << ":\n";
                        LWstudent[j].showStudentInfoFaculty();
                        cout << "\n";
                    }
                }
                else
                {
                    cout << "Please enter at least one Law student.\n\n";
                }
                system("PAUSE");
                system("CLS");
               
            break;

            case 4:
                if(LNnumber != 0)
                {
                    cout << "LIST OF LANGUAGE STUDENTS\n"
                         << "---------------------------------\n\n";

                    for(int j = 0; j < LNnumber; j++)
                    {
                        cout << char(201); for(int i = 0; i < 30; i++){cout << char(205);}//top row
                        cout << "\n" << char(186) << "          STUDENT " << j + 1 << ":\n";
                        LNstudent[j].showStudentInfoFaculty();
                        cout << "\n";
                    }
                }
                else
                {
                    cout << "Please enter at least one Language student.\n\n";
                }
                system("PAUSE");
                system("CLS");
                
            break;

            case 5:
                exitLoop = true; //goes to main menu
            break;

            default:
                cout << "Invalid input, please try again.\n\n";
                system("PAUSE");
                system("CLS");
        }
    }while (exitLoop == false);
}

void displayUniversityStatistics(int& i, int& CSnumber, int& BEnumber, int& LWnumber, int& LNnumber) {
    system("CLS");
    cout << "UNIVERSITY STATISTICS\n"
         << "-----------------------------\n";
    if (i == 0) 
    {
        cout << "\nThere are no students enrolled in your University.\n";
        system("PAUSE");
        system("CLS");
    }
    else if (i == 1) 
    {
        cout << "\nThere is one student enrolled in your University. ";
        if (CSnumber == 1) 
        {
            cout << "He/she is studying Computer science.\n";
        }
        else if (BEnumber == 1)
        {
            cout << "He/she is studying Business economics.\n";
        }
        else if (LWnumber == 1) 
        {
            cout << "He/she is studying Law.\n";
        }
        else 
        {
            cout << "He/she is studying Languages.\n";
        }
        cout << "\n";
        system("PAUSE");
        system("CLS");
    }
    else 
    {
            cout << char(201);   for(int i = 0; i < 50; i++){cout << char(205);}  cout << "\n"; //top row
            cout << char(186) << "There are " << i << " students enrolled in your University.   " << "\n"   
                 << char(186) << "--------------------------------------------------" << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                 << char(186);    showStudents(CSnumber, "Computer science");          
            cout << char(186) << "--------------------------------------------------" << "\n"    
                 << char(186);    showStudents(BEnumber, "Business economics");         
            cout << char(186) << "--------------------------------------------------" << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
                 << char(186);    showStudents(LWnumber, "Law");                          
            cout << char(186) << "--------------------------------------------------" << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                 << char(186);    showStudents(LNnumber, "Language");                    
            cout << char(186) << "--------------------------------------------------" << "\n\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          

        system("PAUSE");
        system("CLS");
    }
}

void endingProgramText(int i)//this is the text that is printed when user terminates program
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
    cout<< "Thank you for using Unisystem!\n"; Sleep(1500);
}

//FUNCTIONS FOR INPUT VALIDATION

bool validateAttribute(string attribute) //validates the input of name and surname
{
    int attributeLength = attribute.length();
    for (int i = 0; i < attributeLength; i++) 
    {
        if (!isalpha(attribute[i])) 
        {
            return false; // if there is a number in the input
        }
    }
    if(attribute.length() >= 15)//invalidate input if more than 15 characters
    {
        return false;
    }
    if (attribute.find(' ') != string::npos) 
    {
        return false; // if there is more than one word in input
    }
    return true; // if input is valid
}

int CheckAndSetID(int randomN, vector<int>& IDvector)
{
    //this loop makes sure no duplicate ID is generated
    while(std::count(IDvector.begin(), IDvector.end(), randomN))//if random is duplicate in ID vector,
    {                                                          //then generate a new ID until it is 
        randomN = IDgenerator();                                //unique
    }
    IDvector.push_back(randomN);//adds ID to the IDvector
    return randomN;
}

int ValidateChoice(string input)
{
    if (input.length() == 1 && std::isdigit(input[0])) //accept choice input only if input is one digit
    {
        return input[0] - '0';  // Convert char to int
    }
    else 
    {
        return 999;//set choice to an invalid input so default(invalid) case is triggered
    }
}

//FUNCTIONS FOR SIMPLYFYING

string GetAndSetAttribute(string Attribute)
{
    cin >> std::ws; // consume whitespace characters (to remove anything left in cin buffer that causes bugs)
    std::getline(cin, Attribute);
    return Attribute;
}

int IDgenerator()
{
    int n = 130000 + (rand() % 9999);//generates a random ID from 130000 to 139999 to imitate our IDs (also uses srand() to have different IDs every time the program is run)
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
        cout << char(201);   for(int i = 0; i < 50; i++){cout << char(205);}   cout << char(187) << "\n"; //top row
        cout << char(186) << "              CHOOSE STUDENT FACULTY              "   << char(186) << "\n" 
             << char(186) << "--------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
             << char(186) << " Press 1 for Computer science                     "   << char(186) << "\n"  
             << char(186) << "--------------------------------------------------"   << char(186) << "\n" 
             << char(186) << " Press 2 for Business economics                   "   << char(186) << "\n"  
             << char(186) << "--------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
             << char(186) << " Press 3 for Law                                  "   << char(186) << "\n" 
             << char(186) << "--------------------------------------------------"   << char(186) << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
             << char(186) << " Press 4 for Languages                            "   << char(186) << "\n";
        cout << char(200);    for(int i = 0; i < 50; i++){cout << char(205);}  cout << char(188) << "\n"; //bottom row

         cout << "\n-------------------------------------\n"
              << "Enter your choice here:  ";
        std::getline(cin, faculty);
        system("CLS");
        facultyChoice = ValidateChoice(faculty);//validates first

        switch(facultyChoice)
        {
            case 1:
                cout << "You have selected the faculty of Computer sciences!\n";
                faculty = "Computer sciences"; //sets Students faculty attribute
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
                cout << "Invalid input, please try again\n\n";
                system("PAUSE");
                system("CLS");
        }
    }while(exitFacultyLoop == false);
    return faculty;
}

void showStudents(int studentNumber, string faculty)//function used in the University Statistics menu
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

//METHODS OF STUDENT CLASS

string Student::getName()
{
    return Name;
}

void Student::setName(string newName)
{
     if (validateAttribute(newName)) //if input is valid (returns true)
     {
        newName = formatString(newName, newName.length()); //format users input and set it as the attribute
        Name = newName;
        nameFlag = false; 
     }       
     else 
     {
        cout << "Invalid input: Name must contain a single word, without numbers and less than 15 characters.\n\n";
        nameFlag = true; //flag used to reprompt user if invalid input is written
     }
}

string Student::getSurname()
{
    return Surname;
}

void Student::setSurname(string newSurname)
{
     if (validateAttribute(newSurname)) //if input is valid (returns true)
    {
        newSurname = formatString(newSurname, newSurname.length()); //format users input and set it as the attribute
        Surname = newSurname;
        surnameFlag = false; 
    } 
    else 
    {
        cout << "Invalid input: Surname must contain a single word, without numbers and less than 15 characters.\n\n";
        surnameFlag = true; //flag used to reprompt user if invalid input is written
    }
}

string Student::getID()
{
    return ID;
}

void Student::setID(string newID)
{
    ID = newID;
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

    cout << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Name: " << Name << "\n"  
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Surname: "<< Surname  << "\n"  
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " ID: " << ID << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Faculty: " << Faculty << "\n"
         << char(186) << "-----------------------------------"   << "\n\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

}

void Student::showStudentInfoFaculty()//used when displaying students of the same faculty (we dont need their faculty because we know it)
{
    cout << char(186) << "------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Name: " << Name << "\n"  
         << char(186) << "------------------------------"   << "\n" 
         << char(186) << " Surname: "<< Surname  << "\n"  
         << char(186) << "------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " ID: " << ID << "\n" 
         << char(186) << "------------------------------"   << "\n\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}
