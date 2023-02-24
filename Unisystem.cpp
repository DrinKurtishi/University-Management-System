#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

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
    int random;

    bool exitLoop = false;//to end program if user chooses
    const int maxSize = 100;
    Student student[maxSize];//max 100 students, all having blank attributes
    do{
        std::cout << "\nPress 1 to register new student: \n";
        std::cout << "\nPress 2 to view student list: \n";
        std::cout << "\nPress 3 to end program(WARNING! This will erase your entire database)\n";
        std::getline(std::cin, input);
        system("CLS");//clear screen

        if (input.length() == 1 && std::isdigit(input[0])) {//accept choice input iff it it only one digit
            choice = input[0] - '0';  // Convert char to int
        }
        else 
        {
            choice = 999;//set choice to an invalid input so default case is triggered
        }
        
        switch(choice)
        { 
            case 1://registers new student
                do{
                    std::cout << "Enter Student Name: ";
                    std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                    std::getline(std::cin, Name);
                    student[i].setName(Name);
                }
                while(student[i].nameFlag == true);//if invalid, prompt again.
    
                do{
                    std::cout << "Enter Student Surname: ";
                    std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                    std::getline(std::cin, Surname);
                    student[i].setSurname(Surname);
                }
                while(student[i].surnameFlag == true);//if invalid, prompt again.
        
                do{
                    std::cout << "Enter student Faculty: ";
                    std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                    std::getline(std::cin, Faculty);
                    student[i].setFaculty(Faculty); 
                }
                while(student[i].facultyFlag == true);//if invalid, prompt again.

                std::cout << "\nStudent " << student[i].getName() << " " << student[i].getSurname()//display student name after registering
                          << " has been succesfuly registered!\n";

            
                //this code generates a unique ID for every new student.
                random = 130000 + (rand() % 9999); //generate random ID in range 130000 ~ 139999
                ID = std::to_string(random);//convert random ID to a string
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
    