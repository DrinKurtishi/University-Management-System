#include <iostream>
#include <cstring>
#include <string>
#include <limits>

std::string formatString(std::string userInput)//function to capitalize first letter if user doesn't
{
    if(islower(userInput[0]))
    {
        userInput[0] = toupper(userInput[0]);
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
        //flag to check if user input is valid
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
                if(!isalpha(newName[i]))
                {
                    std::cout << "Invalid input: Name must be a single word and without numbers.\n";
                    nameFlag = true;
                    continueCheck = false;
                    break;
                }
            }
            if(continueCheck == true)
            {
                if(newName.find(' ') != std::string::npos)
                {//Makes input invalid if there is more than one word in input
                    std::cout << "Invalid input: Name must be a single word and without numbers.\n";
                    nameFlag = true;
                }
                else
                {
                    newName = formatString(newName);
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
                if(!isalpha(newSurname[i]))
                {
                    std::cout << "Invalid input: Surname must be a single word and without numbers.\n";
                    surnameFlag = true;
                    continueCheck = false;
                    break;
                }
            }
            if(continueCheck == true){
                if(newSurname.find(' ') != std::string::npos)
                {//Makes input invalid if there is more than one word in input
                    std::cout << "Invalid input: Surname must be a single word and without numbers.\n";
                    surnameFlag = true;
                }
                else
                {
                    newSurname = formatString(newSurname);
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
            //this code checks in newID if there only and ONLY 6 numbers

            int IDlength = newID.length();
            bool continueCheck = true;//flag to continue checking validity if first validity check passes
            for(int i = 0; i < IDlength; i++)
            {
                if (!isdigit(newID[i]))
                {
                    std::cout << "Invalid input: ID must only contain 6 numbers.\n";
                    IDflag = true;
                    continueCheck = false;//if there is a non digit in newID then prompt again for ID
                    break;
                } 
            }
            if(continueCheck == true)
            {
                if(newID.find(' ') != std::string::npos)//if there is a space in newID (indicating an input of two block of text) then prompt for new ID
                { 
                    std::cout << "Invalid ID, ID must consist of 6 numbers.\n";
                    IDflag = true;
                    continueCheck = false;
                } 
                else
                {
                    if(continueCheck == true)//If there aren't any non digits in newID, check if there are exactly 6 numbers
                    {
                
                        if(IDlength < 6 || IDlength > 6)
                        {
                            std::cout << "Invalid ID, ID must consist of 6 numbers.\n";
                            IDflag = true;
                        }
                        else
                        {//if there are exactly 6 numbers without letters then continue student registration
                            ID = newID;
                            IDflag = false;
                        }
                    }
                }
            }     
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
                newFaculty = formatString(newFaculty);
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
            std::cout << "Student name: " << Name << "\n"
                      << "Student surname: " << Surname << "\n"
                      << "Student ID: " << ID << "\n"
                      << "Student Faculty: " << Faculty << "\n";
        }
};

int main()
{
    int choice;
    std::string input;
    std::string Name;
    std::string Surname;
    std::string ID;
    std::string Faculty;
    int i = 0;
    bool exitLoop = false;
    const int maxSize = 100;
    Student student[maxSize];//max 100 students, all having blank attributes
    do{
        std::cout << "\nPress 1 to register new student: \n";
        std::cout << "\nPress 2 to view student list: \n";
        std::cout << "\nPress 3 to end program(WARNING! This will erase your entire database)\n";
        std::getline(std::cin, input);

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
                while(student[i].nameFlag == true);
    

                do{
                    std::cout << "Enter Student Surname: ";
                    std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                    std::getline(std::cin, Surname);
                    student[i].setSurname(Surname);
                }
                while(student[i].surnameFlag == true);
         

                do{
                    std::cout << "Enter student ID: ";
                    std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                    std::getline(std::cin, ID);
                    student[i].setID(ID);
                }
                while(student[i].IDflag == true);//if invalid ID, prompt again.
        

                do{
                    std::cout << "Enter student Faculty: ";
                    std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                    std::getline(std::cin, Faculty);
                    student[i].setFaculty(Faculty); 
                }
                while(student[i].facultyFlag == true);
                std::cout << "\nStudent " << student[i].getName() << " " << student[i].getSurname()
                          << " has been succesfuly registered!\n";
                i++; //increment i to move to the next student in the array
            break;

            case 2://shows list of all students
                if(i == 0)
                {
                    std::cout << "Please enter at least one student.\n";
                }
                else
                {
                    for(int j = 0; j<i; j++)
                    {
                        student[j].showStudentInfo();
                        std::cout << std::endl;
                    }
                }
            break; 

            case 3:
                std::cout<< "Terminating program.. Thank you for using UniSystem!\n";
                exitLoop = true;
            break; 

            default:
                std::cout << "Invalid input, please try again.\n";
 
        }

    }while(exitLoop == false);
}

    
    