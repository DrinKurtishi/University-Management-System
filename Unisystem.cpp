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

std::string formatString(std::string, int);
bool validateAttribute(std::string);
int CheckAndSetID(int, std::vector<int>);
int ValidateChoice(std::string);
std::string GetAndSetAttribute(std::string);
int IDgenerator();
std::string ChooseFaculty();
void EndingProgramText(int);
void showStudents(int, std::string);



class Student{
    private:
        std::string Name;
        std::string Surname;
        std::string ID;
        std::string Faculty;

    public:
        //flags to check if user input is valid
        bool surnameFlag = false; 
        bool nameFlag = false;
        
        //getters and setters for private variables
        std::string getName()
        {
            return Name;
        }
        
        void setName(std::string newName) 
        {
            if (validateAttribute(newName)) 
            {
                newName = formatString(newName, newName.length());
                Name = newName;
                nameFlag = false;
            }       
            else 
            {
                std::cout << "Invalid input: Name must contain a single word, without numbers and less than 15 characters.\n";
                nameFlag = true;
            }
        }

        std::string getSurname()
        {
            return Surname;
        }

        void setSurname(std::string newSurname) 
        {
            if (validateAttribute(newSurname)) 
            {
                newSurname = formatString(newSurname, newSurname.length());
                Surname = newSurname;
                surnameFlag = false;
            } 
            else 
            {
                std::cout << "Invalid input: Surname must contain a single word, without numbers and less than 15 characters.\n";
                surnameFlag = true;
            }
        }

        std::string getID()
        {
            return ID;
        }

        void setID(std::string newID)
        {
            ID = newID;
        }
         
        std::string getFaculty()
        {
            return Faculty;
        }
        
        void setFaculty(std::string newFaculty)
        {
            Faculty = newFaculty;
        }

        Student() //default constructor for all students
        {
            Name = "blank";
            Surname = "blank";
            ID = "blank";
            Faculty = "blank";
        }

        Student(std::string name, std::string surname, std::string id, std::string faculty) //constructor
        {
            Name = name;
            Surname = surname;
            ID = id;
            Faculty = faculty;
        }

        void showStudentInfo()
        {
            std::cout 
            << "Name: " << Name << "\n"
            << "Surname: " << Surname << "\n"
            << "ID: " << ID << "\n"
            << "Faculty: " << Faculty << "\n"
            << "\n*************************\n";
        }
        void showStudentInfoFaculty()//used when displaying students of the same faculty (we dont need their faculty because we know it)
        {
            std::cout 
            << "Name: " << Name << "\n"
            << "Surname: " << Surname << "\n"
            << "ID: " << ID << "\n"
            << "\n*************************\n";
        }
};


void chooseFacultyList(std::vector<Student>, std::vector<Student>, std::vector<Student>, std::vector<Student>, int, int, int, int);

int main()
{
    int choice;
    std::string input;
    std::string Name;
    std::string ID;
    std::string Surname;
    std::string Faculty;
    srand(time(0));//seed for random number that changes with time for giving unique ID
    bool exitLoop = false;//to end program if user chooses
    std::vector<Student> student; //using vector instead of array to dynamically size it instead of having a prefixed limit of students
    Student newStudent;//create blank student object
    std::vector<int> IDvector;//vector to store unique IDs (and to check for potential duplicates)

    std::vector<Student> CSstudent;//vector to store only cs students for display
    std::vector<Student> BEstudent;//vector for business economics students
    std::vector<Student> LWstudent;//vector for law students
    std::vector<Student> LNstudent;//vector for language students

    //keeping track of the number of students of specific faculties
    int i = 0;//used to increment student array/ nr of all students
    int CSnumber = 0; //nr of Cs students
    int BEnumber = 0; //nr of BE students
    int LWnumber = 0; //nr of Law students
    int LNnumber = 0; //nr of Language students

    do{
        std::cout << "\nPress 1 to register new student: \n";
        std::cout << "\nPress 2 to view every student list: \n";
        std::cout << "\nPress 3 to view student list of a specific faculty:\n";
        std::cout << "\nPress 4 to view University statistics:\n";
        std::cout << "\nPress 5 to end program(WARNING! This will erase your entire database)\n";
        std::getline(std::cin, input);
        system("CLS");//clear screen

        choice = ValidateChoice(input);
        
        switch(choice)
        { 
            case 1://registers new student
                student.push_back(newStudent);//add blank student to vector
                
                student[i].setFaculty(ChooseFaculty());

                do
                {
                    std::cout << "Enter Student Name: ";
                    student[i].setName(GetAndSetAttribute(Name));
                }
                while(student[i].nameFlag == true);//if invalid, prompt again.
    
                do
                {
                    std::cout << "Enter Student Surname: ";
                    student[i].setSurname(GetAndSetAttribute(Surname));
                }
                while(student[i].surnameFlag == true);//if invalid, prompt again.
        
                std::cout << "\nStudent " << student[i].getName() << " " << student[i].getSurname()//display student name after registering
                          << " has been succesfuly registered!\n";

                ID = std::to_string(CheckAndSetID(IDgenerator(), IDvector));//generate and validate ID so no duplicates are registered
                student[i].setID(ID); //set unique ID to Student

                //SORT MAIN STUDENT ARRAY

                //choose in which faculty vector to put student
                Faculty = student[i].getFaculty();
                if(Faculty == "Computer sciences")
                {
                    CSstudent.push_back(student[i]);
                    //SORT STUDENT ARRAY
                    CSnumber++;//increment number of students in faculty
                }
                else if(Faculty == "Business economics")
                {
                    BEstudent.push_back(student[i]);
                    //SORT STUDENT ARRAY
                    BEnumber++;
                }
                else if(Faculty == "Law")
                {
                    LWstudent.push_back(student[i]);
                    //SORT STUDENT ARRAY
                    LWnumber++;
                }
                else
                {
                    LNstudent.push_back(student[i]);
                    //SORT STUDENT ARRAY
                    LNnumber++;
                }
                i++; //increment i to move to the next student in the array
            break;

            case 2://shows list of all students
                if(i != 0)
                {
                    for(int j = 0; j < i; j++)
                    {
                        std::cout << "Student " << j + 1 << ": \n";
                        student[j].showStudentInfo();
                    }   
                }
                else//if user chooses case 2 before registering any students execute this
                {
                   std::cout << "Please enter at least one student.\n";
                }
            break; 

            case 3:
                chooseFacultyList(CSstudent, BEstudent, LWstudent, LNstudent, CSnumber, BEnumber, LWnumber, LNnumber);//show student list of specific faculty
            break;

            case 4:
            //TOODOO CONTINUE THIS
                system("CLS");
                std::cout << "You have selected to view University statistics!\n";
                if(i == 0)
                {
                    std::cout << "\nThere are no students enrolled in your University\n";
                }
                else if(i == 1)
                {
                    std::cout << "\nThere is one student enrolled in your University ";
                    if(CSnumber == 1)
                    {
                       std::cout << "and he/she is studying Computer science.\n";
                    }
                    else if(BEnumber == 1)
                    {
                       std::cout << "and he/she is studying Business economics\n";
                    }
                    else if(LWnumber == 1)
                    {
                        std::cout << "and he/she is studying Law\n";
                    }
                    else
                    {
                        std::cout << "and he/she is studying Languages\n";
                    }
                }
                else
                {
                    std::cout << "\nThere are a total of " << i << " students enrolled in your University.\n";
                    showStudents(CSnumber, "Computer science");
                    showStudents(BEnumber, "Business economics");
                    showStudents(LWnumber, "Law");
                    showStudents(LNnumber, "Language");
                }
               
            break;




            case 5://Ends program
                EndingProgramText(i);  
                exitLoop = true;
            break; 

            default:
                std::cout << "Invalid input, please try again.\n";
        }
    }while(exitLoop == false);
}

//functions of student class

std::string formatString(std::string userInput, int inputLength)//function to format users input
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

bool validateAttribute(std::string attribute) 
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
    if (attribute.find(' ') != std::string::npos) 
    {
        return false; // if there is more than one word in input
    }
    return true; // if input is valid
}

//functions of main

int CheckAndSetID(int random, std::vector<int> IDvector)
{
    //this code makes sure no duplicate ID is generated
    while(std::count(IDvector.begin(), IDvector.end(), random))//if random is duplicate in ID vector,
    {                                                          //then generate a new ID until it is 
        random = IDgenerator();                                //unique
    }
    IDvector.push_back(random);//adds ID to the IDvector
    return random;
}

int ValidateChoice(std::string input)
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

std::string GetAndSetAttribute(std::string Attribute)
{
    std::cin >> std::ws; // consume whitespace characters (te remove anything left in std::cin buffer that causes bugs)
    std::getline(std::cin, Attribute);
    return Attribute;
}

int IDgenerator()
{
    int n = 130000 + (rand() % 9999);
    return n;
}

std::string ChooseFaculty()//switch case for choosing faculty of student
{
    std::string faculty;
    int facultyChoice;
    bool exitFacultyLoop = false;
    do
    {
            
        std::cout << "Please choose faculty of student:\n"
                  << "Press 1 for Computer science\n"
                  << "Press 2 for Business economy\n"
                  << "Press 3 for Law\n"
                  << "Press 4 for Languages\n";

        std::getline(std::cin, faculty);
        system("CLS");
        facultyChoice = ValidateChoice(faculty);

        switch(facultyChoice)
        {
            case 1:
                std::cout << "You have selected the faculty of Computer sciences!\n";
                faculty = "Computer sciences";
                exitFacultyLoop = true;
            break;
                        
            case 2:
                std::cout << "You have selected the faculty of Business economics!\n";
                faculty = "Business economics";
                exitFacultyLoop = true;
            break;

            case 3:
                std::cout << "You have selected the faculty of Law!\n";
                faculty = "Law";
                exitFacultyLoop = true;
            break;

            case 4:
                std::cout << "You have selected the faculty of Languages!\n";
                faculty = "Languages";
                exitFacultyLoop = true;
            break;

            default:
                std::cout << "Invalid input, please try again\n";
        }
    }while(exitFacultyLoop == false);
    return faculty;
}

void chooseFacultyList(std::vector<Student> CSstudent, std::vector<Student> BEstudent, std::vector<Student> LWstudent, std::vector<Student> LNstudent, int CSnumber, int BEnumber, int LWnumber, int LNnumber)
{
    bool exitLoop = false;
    std::string input;
    int choice;
    std::cout << "You have chosen to view a list of students from a specific faculty\n";
    do 
    {
        std::cout << "Press 1 to view list of Computer science students:\n";
        std::cout << "Press 2 to view list of Business economics students:\n";
        std::cout << "Press 3 to view list of Law students:\n";
        std::cout << "Press 4 to view list of Language students:\n";
        std::cout << "Press 5 to go back to main menu:\n";

        std::getline(std::cin, input);
        system("CLS");
        choice = ValidateChoice(input);

        switch(choice)
        {
            case 1:
                if(CSnumber != 0)
                {
                    std::cout << "You have chosen to view the list of Computer science students!:\n";
                    for(int j = 0; j < CSnumber; j++)
                    {
                        CSstudent[j].showStudentInfoFaculty();
                        std::cout << "\n";
                    }
                }
                else
                {
                    std::cout << "Please enter at least one Computer science student.\n";
                }
               
            break;

            case 2:
                if(BEnumber != 0)
                {
                    std::cout << "You have chosen to view the list of Business economics students\n";
                    for(int j = 0; j < BEnumber; j++)
                    {
                        BEstudent[j].showStudentInfoFaculty();
                        std::cout << "\n";
                    }
                }
                else
                {
                     std::cout << "Please enter at least one Business economics student.\n";
                }
               
            break;

            case 3:
                if(LWnumber != 0)
                {
                    std::cout << "You have chosen to view the list of Law students\n";
                    for(int j = 0; j < LWnumber; j++)
                    {
                        LWstudent[j].showStudentInfoFaculty();
                        std::cout << "\n";
                    }
                }
                else
                {
                    std::cout << "Please enter at least one Law student.\n";
                }
               
            break;

            case 4:
                if(LNnumber != 0)
                {
                    std::cout << "You have chosen to view the list of Language students\n";
                    for(int j = 0; j < LNnumber; j++)
                    {
                        LNstudent[j].showStudentInfoFaculty();
                        std::cout << "\n";
                    }
                }
                else
                {
                    std::cout << "Please enter at least one Language student.\n";
                }
                
            break;

            case 5:
                exitLoop = true;
            break;

            default:
                std::cout << "Invalid input, please try again.\n";
        }
    }while (exitLoop == false);
}

void EndingProgramText(int i)
{
    if(i != 0)//if there are registered students also print this
    {
        std::cout << "Erasing student database."; Sleep(600);
        std::cout << "."; Sleep(600);
        std::cout << "."; Sleep(600);
        system("CLS");
    }
        std::cout<< "Terminating program."; Sleep(600);
        std::cout<< "."; Sleep(600);
        std::cout<< "."; Sleep(600);
        system("CLS");
        std::cout<< "Thank you for using Unisystem!\n"; Sleep(500);
}

void showStudents(int studentNumber, std::string faculty)
{
    std::cout << studentNumber << " in " << faculty; std::cout << ".\n";
}
















//TODO - Alphabetically order the student vectors (with one function for all of them)