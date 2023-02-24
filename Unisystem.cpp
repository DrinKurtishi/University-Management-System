#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>

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
        bool IDflag = false;
        bool facultyFlag = false;

        //getters and setters for private variables
        std::string getName()
        {
            return Name;
        }
        void setName(std::string newName)
        {
            int nameLength = newName.length();
            bool continueCheck = true;
            for(int i = 0; i < nameLength; i++)
            {
                if(!isalpha(newName[i]))//if theres a number in the input
                {
                    std::cout << "Invalid input: Name must be a single word and without numbers.\n";
                    nameFlag = true;
                    continueCheck = false;
                    break;
                }
            }
            if(continueCheck == true)
            {
                if(newName.find(' ') != std::string::npos)//Makes input invalid if there is more than one word in input
                {
                    std::cout << "Invalid input: Name must be a single word and without numbers.\n";
                    nameFlag = true;
                }
                else//if input is valid
                {
                    newName = formatString(newName, nameLength);
                    Name = newName;
                    nameFlag = false;
                }
            }
        }

        std::string getSurname()
        {
            return Surname;
        }
        void setSurname(std::string newSurname)
        {
            int surnameLength = newSurname.length();
            bool continueCheck = true;
            for(int i = 0; i < surnameLength; i++)
            {
                if(!isalpha(newSurname[i]))//if theres a number in the input
                {
                    std::cout << "Invalid input: Surname must be a single word and without numbers.\n";
                    surnameFlag = true;
                    continueCheck = false;
                    break;
                }
            }
            if(continueCheck == true){
                if(newSurname.find(' ') != std::string::npos)//Makes input invalid if there is more than one word in input
                {//Makes input invalid if there is more than one word in input
                    std::cout << "Invalid input: Surname must be a single word and without numbers.\n";
                    surnameFlag = true;
                }
                else//if input is valid
                {
                    newSurname = formatString(newSurname, surnameLength);
                    Surname = newSurname;
                    surnameFlag = false;
                }
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
            int newfacultyLength = newFaculty.length(); 
            bool print = true;
            for(int i = 0; i < newfacultyLength; i++)
            {
                if(isdigit(newFaculty[i]))
                {
                    std::cout << "Invalid input: No numbers allowed in faculty name. \n";
                    print = false;
                    facultyFlag = true;
                    break;
                }
            }
            if(print == true)
            {
                newFaculty = formatString(newFaculty, newfacultyLength);
                Faculty = newFaculty;
                facultyFlag = false;
            }
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
            std::cout << "Name: " << Name << "\n"
                      << "Surname: " << Surname << "\n"
                      << "ID: " << ID << "\n"
                      << "Faculty: " << Faculty << "\n"
                      << "\n*************************\n";
        }
};

//functions for main function
std::string formatString(std::string userInput, int inputLength);
int CheckAndSetID(int random, std::vector<int> IDvector);
int ValidateChoice(std::string input);
std::string GetAndSetAttribute(std::string Attribute);

int main()
{
    int choice;
    std::string input;
    std::string Name;
    std::string ID;
    std::string Surname;
    std::string Faculty;
    int i = 0;//used to increment student array
    srand(time(0));//seed for random number that changes with time for giving unique ID
    int random;//storing generated ID
    bool exitLoop = false;//to end program if user chooses
    std::vector<Student> student; //using vector instead of array to dynamically size it instead of having a prefixed limit of students
    Student newStudent;//create blank student object
    std::vector<int> IDvector;//vector to store unique IDs (for duplicate checking)
    do{
        std::cout << "\nPress 1 to register new student: \n";
        std::cout << "\nPress 2 to view student list: \n";
        std::cout << "\nPress 3 to end program(WARNING! This will erase your entire database)\n";
        std::getline(std::cin, input);
        system("CLS");//clear screen

        choice = ValidateChoice(input);
        
        switch(choice)
        { 
            case 1://registers new student
                student.push_back(newStudent);//add blank student to vector
                do{
                    std::cout << "Enter Student Name: ";
                    student[i].setName(GetAndSetAttribute(Name));
                }
                while(student[i].nameFlag == true);//if invalid, prompt again.
    
                do{
                    std::cout << "Enter Student Surname: ";
                    student[i].setName(GetAndSetAttribute(Surname));
                }
                while(student[i].surnameFlag == true);//if invalid, prompt again.
        
                do{
                    std::cout << "Enter student Faculty: ";
                    student[i].setName(GetAndSetAttribute(Faculty));
                }
                while(student[i].facultyFlag == true);//if invalid, prompt again.

                std::cout << "\nStudent " << student[i].getName() << " " << student[i].getSurname()//display student name after registering
                          << " has been succesfuly registered!\n";

                random = 130000 + (rand() % 9999); //generate random ID in range 130000 ~ 139999
                ID = std::to_string(CheckAndSetID(random, IDvector));
                student[i].setID(ID); //set unique ID to Student
                i++; //increment i to move to the next student in the array

            break;

            case 2://shows list of all students
                if(i == 0)//if user chooses case 2 before registering any students execute this
                {
                    std::cout << "Please enter at least one student.\n";
                }
                else
                {
                    for(int j = 0; j<i; j++)
                    {
                        std::cout << "Student " << j + 1 << ": \n";
                        student[j].showStudentInfo();
                        std::cout << std::endl;
                    }
                }
            break; 

            case 3://Ends program
                std::cout<< "Terminating program.. Thank you for using UniSystem!\n";
                exitLoop = true;
            break; 

            default:
                std::cout << "Invalid input, please try again.\n";
        }
    }while(exitLoop == false);
}
    

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

int CheckAndSetID(int random, std::vector<int> IDvector)
{
    //this code makes sure no duplicate ID is generated
    while(std::count(IDvector.begin(), IDvector.end(), random))//if random is duplicate in ID vector,
    {                                                          //then generate a new ID until it is 
        random = 130000 + (rand() % 9999);                     //unique
    }
    IDvector.push_back(random);//adds ID to the vector
    return random;
}

int ValidateChoice(std::string input)
{
     if (input.length() == 1 && std::isdigit(input[0])) {//accept choice input only if input is one digit
            return input[0] - '0';  // Convert char to int
        }
        else 
        {
            return 999;//set choice to an invalid input so default case is triggered
        }
}

std::string GetAndSetAttribute(std::string Attribute)
{
    std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
    std::getline(std::cin, Attribute);
    return Attribute;
}