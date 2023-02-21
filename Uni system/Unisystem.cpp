#include <iostream>
#include <cstring>
#include <string>
//commit test
class Student{
    private:
        std::string Name;
        std::string Surname;
        std::string ID;
        std::string Faculty;

    public:
        bool surnameFlag = false; 
        bool nameFlag = false;
        bool IDflag = false;//to check ID validity
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
            if(continueCheck == true){//If there aren't any non digits in newID, check if there are exactly 6 numbers
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
                Faculty = newFaculty;
                facultyFlag = false;
            }
        }

        Student(std::string name, std::string surname, std::string id, std::string faculty){//constructor
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
    std::string Name;
    std::string Surname;
    std::string ID;
    std::string Faculty;
    Student Drin = Student("blank", "blank", "blank", "blank");//initial blank student

        std::cout << "Press 1 to register new student: \n";
        std::cin >> choice;
        if(choice == 1)
        {

            do{
                std::cout << "Enter Student Name: ";
                std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                std::getline(std::cin, Name);
                Drin.setName(Name);
            }
            while(Drin.nameFlag == true);

            do{
                std::cout << "Enter Student Surname: ";
                std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                std::getline(std::cin, Surname);
                Drin.setSurname(Surname);
            }
            while(Drin.surnameFlag == true);
        
            do{
                std::cout << "Enter student ID: ";
                std::cin >> ID;
                Drin.setID(ID);
            }
            while(Drin.IDflag == true);//if invalid ID, prompt again.

            do{
                std::cout << "Enter student Faculty: ";
                std::cin >> std::ws; // consume whitespace characters (to prevent newline character from getline)
                std::getline(std::cin, Faculty);
                Drin.setFaculty(Faculty); 
            }
            while(Drin.facultyFlag == true);

        }

        std::cout << "Press 2 to see your student: ";
        std::cin >> choice;
        if(choice == 2)
        {
            Drin.showStudentInfo();
        }
    }

    
    