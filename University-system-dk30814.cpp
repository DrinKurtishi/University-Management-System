#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;

class Student {
public:
    Student(string name, string surname, int id, string faculty)
        : name(name), surname(surname), id(id), faculty(faculty) {}

    string getName() const {
        return name;
    }

    string getSurname() const {
        return surname;
    }

    int getID() const {
        return id;
    }

    string getFaculty() const {
        return faculty;
    }

    int getGrade1() const {
        return grade1;
    }

    int getGrade2() const {
        return grade2;
    }

    int getGrade3() const {
        return grade3;
    }


    virtual void displayInfo() const = 0;

    // Function to calculate GPA based on faculty
    virtual float calculateGPA() const = 0;

    // Function to prompt user to enter grades
    virtual void enterGrades() = 0;

protected:
    string name;
    string surname;
    int id;
    string faculty;
    int grade1;
    int grade2;
    int grade3;
};

class ComputerScienceStudent : public Student {
public:
    ComputerScienceStudent(string name, string surname, int id)
        : Student(name, surname, id, "Computer Science") {}

    void displayInfo() const override {
        float averageGrade = calculateGPA();
        cout << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Name: " << name << "\n"  
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Surname: "<< surname  << "\n"  
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " ID: " << id << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Faculty: " << faculty << "\n"
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
         << char(186) << " Course 1: Programming: " << grade1   << "\n" 
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Course 2: Algorithms: " << grade1 << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " Course 3: Data Structures: " << grade1   << "\n"
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Average Grade: " << averageGrade      << "\n"
         << char(186) << "-----------------------------------"   << "\n\n\n\n"; 
    }

    void enterGrades() override {
        cout << "Enter grades for Programming, Algorithms, and Data Structures:\n";
        cout << "Grade 1: ";
        cin >> grade1;
        cout << "Grade 2: ";
        cin >> grade2;
        cout << "Grade 3: ";
        cin >> grade3;
    }

    float calculateGPA() const override {
        float weightedSum = (grade1 * 0.4f) + (grade2 * 0.3f) + (grade3 * 0.3f);
        return weightedSum;
    }
};

class BusinessEconomicsStudent : public Student {
public:
    BusinessEconomicsStudent(string name, string surname, int id)
        : Student(name, surname, id, "Business Economics") {}

    void displayInfo() const override {
        float averageGrade = calculateGPA();
        cout << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Name: " << name << "\n"  
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Surname: "<< surname  << "\n"  
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " ID: " << id << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Faculty: " << faculty << "\n"
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
         << char(186) << " Course 1: Microeconomics: " << grade1   << "\n" 
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Course 2: Macroeconomics: " << grade1 << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " Course 3: Business Finance: " << grade1   << "\n"
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Average Grade: " << averageGrade      << "\n"
         << char(186) << "-----------------------------------"   << "\n\n\n\n"; 
  
    }

    void enterGrades() override {
        cout << "Enter grades for Microeconomics, Macroeconomics, and Business Finance:\n";
        cout << "Grade 1: ";
        cin >> grade1;
        cout << "Grade 2: ";
        cin >> grade2;
        cout << "Grade 3: ";
        cin >> grade3;
    }

    float calculateGPA() const override {
        float weightedSum = (grade1 * 0.5f) + (grade2 * 0.3f) + (grade3 * 0.2f);
        return weightedSum;
    }
};

class LawStudent : public Student {
public:
    LawStudent(string name, string surname, int id)
        : Student(name, surname, id, "Law") {}

    void displayInfo() const override {
        float averageGrade = calculateGPA();
        cout << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Name: " << name << "\n"  
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Surname: "<< surname  << "\n"  
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " ID: " << id << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Faculty: " << faculty << "\n"
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
         << char(186) << " Course 1: Criminal Law: " << grade1   << "\n" 
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Course 2: Constitutional Law: " << grade1 << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " Course 3: Contract Law: " << grade1   << "\n"
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Average Grade: " << averageGrade      << "\n"
         << char(186) << "-----------------------------------"   << "\n\n\n\n"; 
    }

    void enterGrades() override {
        cout << "Enter grades for Criminal Law, Constitutional Law, and Contract Law:\n";
        cout << "Grade 1: ";
        cin >> grade1;
        cout << "Grade 2: ";
        cin >> grade2;
        cout << "Grade 3: ";
        cin >> grade3;
    }

    float calculateGPA() const override {
        float weightedSum = (grade1 * 0.4f) + (grade2 * 0.4f) + (grade3 * 0.2f);
        return weightedSum;
    }
};

class LanguageStudent : public Student {
public:
    LanguageStudent(string name, string surname, int id)
        : Student(name, surname, id, "Language") {}

    void displayInfo() const override {
        float averageGrade = calculateGPA();
        cout << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Name: " << name << "\n"  
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Surname: "<< surname  << "\n"  
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " ID: " << id << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Faculty: " << faculty << "\n"
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
         << char(186) << " Course 1: English Literature: " << grade1   << "\n" 
         << char(186) << "-----------------------------------"   << "\n" 
         << char(186) << " Course 2: Linguistics: " << grade1 << "\n" 
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
         << char(186) << " Course 3: Translation Studies: " << grade1   << "\n"
         << char(186) << "-----------------------------------"   << "\n"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
         << char(186) << " Average Grade: " << averageGrade      << "\n"
         << char(186) << "-----------------------------------"   << "\n\n\n\n"; 
    }

    void enterGrades() override {
        cout << "Enter grades for English Literature, Linguistics, and Translation Studies:\n";
        cout << "Grade 1: ";
        cin >> grade1;
        cout << "Grade 2: ";
        cin >> grade2;
        cout << "Grade 3: ";
        cin >> grade3;
    }

    float calculateGPA() const override {
        float weightedSum = (grade1 * 0.2f) + (grade2 * 0.4f) + (grade3 * 0.4f);
        return weightedSum;
    }
};





string formatString(string userInput, int inputLength);
bool validateAttribute(string attribute);
int IDgenerator();
int CheckAndSetID(int, vector<int>&);
int ValidateChoice(string input);
void displayUniversityStatistics(int i, int CSnumber, int BEnumber, int LWnumber, int LNnumber);
void displayFacultyStudents(const vector<Student*>& students);
void showStudents(int studentNumber, string faculty);
int showMainMenu();
int chooseFaculty();

int main() {
   ofstream outputFile("students.txt");
   vector<Student*> students;
   vector<int> studentIDs;
   vector<int> IDvector;
   int CSnumber = 0;
   int BEnumber = 0;
   int LWnumber = 0;
   int LNnumber = 0;
   string name;
   bool validName = false;
   string surname;
   bool validSurname = false;
    while (true) {

        int choice = showMainMenu();

        switch (choice) {
            case 1: {
                    cout << "---------------------------------\n";

                   do{
                        cout << "Enter Student Name: ";
                        cin >> name;

                        name = formatString(name, name.length());

                        if (!validateAttribute(name)) {
                            cout << "Invalid name entered.\n";
                        } else {
                            validName = true;
                        }
                    } while (!validName);

                    do {
                        cout << "Enter Student Surname: ";
                        cin >> surname;

                        surname = formatString(surname, surname.length());

                        if (!validateAttribute(surname)) {
                            cout << "Invalid surname entered.\n";
                        } else {
                            validSurname = true;
                        }
                    } while (!validSurname);

                    int randomID = CheckAndSetID(IDgenerator(), IDvector);

                    int facultyChoice = chooseFaculty();

                    Student* student = nullptr;

    switch (facultyChoice) {
        case 1:
            student = new ComputerScienceStudent(name, surname, randomID);
            CSnumber++;
            break;
        case 2:
            student = new BusinessEconomicsStudent(name, surname, randomID);
            BEnumber++;
            break;
        case 3:
            student = new LawStudent(name, surname, randomID);
            LWnumber++;
            break;
        case 4:
            student = new LanguageStudent(name, surname, randomID);
            LNnumber++;
            break;
        default:
            cout << "Invalid faculty choice.\n";
            break;
        }

                if (student != nullptr) {
                    students.push_back(student);
                    cout << "Student registered successfully.\n";

                    student->enterGrades();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                   outputFile << "Name: " << student->getName() << "\n";
                   outputFile << "Surname: " << student->getSurname() << "\n";
                   outputFile << "Faculty: " << student->getFaculty() << "\n";
                   outputFile << "Grade 1: " << student->getGrade1() << "\n";
                   outputFile << "Grade 2: " << student->getGrade2() << "\n";
                   outputFile << "Grade 3: " << student->getGrade3() << "\n";
                   outputFile << "Average Grade: " << student->calculateGPA() << "\n";
                   outputFile << "-----------------------------------\n";
                }

                break;
            }
            case 2: {
                cout << "REGISTERED STUDENTS\n";
                cout << "-------------------\n";

                if (students.empty()) {
                    cout << "No students registered.\n";
                } else {
                    for (const auto& student : students) {
                        student->displayInfo();
                    }
                }

                cout << "\n";
                break;
            }
            case 3: {
                displayFacultyStudents(students);
                cout << "\n";
                break;
            }
            case 4: {
                displayUniversityStatistics(students.size(), CSnumber, BEnumber, LWnumber, LNnumber);
                break;
            }
            case 5: {
                cout << "Exiting the program.\n";
                return 0;
            }
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
outputFile.close();
    return 0;
}
void displayUniversityStatistics(int i, int CSnumber, int BEnumber, int LWnumber, int LNnumber) {
    system("CLS");
    cout << "UNIVERSITY STATISTICS\n";
    cout << "-----------------------------\n";

    if (i == 0) {
        cout << "\nThere are no students enrolled in your University.\n";
        system("PAUSE");
        system("CLS");
    } else if (i == 1) {
        cout << "\nThere is one student enrolled in your University. ";
        if (CSnumber == 1) {
            cout << "He/she is studying Computer science.\n";
        } else if (BEnumber == 1) {
            cout << "He/she is studying Business economics.\n";
        } else if (LWnumber == 1) {
            cout << "He/she is studying Law.\n";
        } else {
            cout << "He/she is studying Languages.\n";
        }
        cout << "\n";
        system("PAUSE");
        system("CLS");
    } else {
        cout << char(201);
        for (int i = 0; i < 50; i++) {
            cout << char(205);
        }
        cout << "\n";

        cout << char(186) << " There are " << i << " students enrolled in your University.   " << "\n"
             << char(186) << "--------------------------------------------------" << "\n"
             << char(186) << " ";
        showStudents(CSnumber, "Computer science");
        cout << char(186) << "--------------------------------------------------" << "\n"
             << char(186) << " ";
        showStudents(BEnumber, "Business economics");
        cout << char(186) << "--------------------------------------------------" << "\n"
             << char(186) << " ";
        showStudents(LWnumber, "Law");
        cout << char(186) << "--------------------------------------------------" << "\n"
             << char(186) << " ";
        showStudents(LNnumber, "Language");
        cout << char(186) << "--------------------------------------------------" << "\n\n";

        system("PAUSE");
        system("CLS");
    }
}

string formatString(string userInput, int inputLength) {
    if (islower(userInput[0])) {
        userInput[0] = toupper(userInput[0]);
    }

    for (int i = 1; i < inputLength; i++) {
        if (isupper(userInput[i])) {
            userInput[i] = tolower(userInput[i]);
        }
    }

    return userInput;
}

bool validateAttribute(string attribute) {
    int attributeLength = attribute.length();

    for (int i = 0; i < attributeLength; i++) {
        if (!isalpha(attribute[i])) {
            return false;
        }
    }

    if (attribute.length() >= 15) {
        return false;
    }

    if (attribute.find(' ') != string::npos) {
        return false;
    }

    return true;
}

int ValidateChoice(string input) {
    if (input.length() == 1 && isdigit(input[0])) {
        return input[0] - '0';
    } else {
        return 999;
    }
}

void displayAllStudents(vector<Student>& students, int& count) {
    if (count != 0) {
        cout << "LIST OF ALL STUDENTS\n";
        cout << "------------------------------------\n\n";
        for (int j = 0; j < count; j++) {
            cout << char(201);
            for (int i = 0; i < 35; i++) {
                cout << char(205);
            }
            cout << "\n" << char(186) << "            STUDENT " << j + 1 << ":\n";
            students[j].displayInfo();
        }
    } else {
        cout << "Please enter at least one student.\n\n";
    }
    system("PAUSE");
    system("CLS");
}

int IDgenerator()
{
    int n = 130000 + (rand() % 9999);//generates a random ID from 130000 to 139999 to imitate our IDs (also uses srand() to have different IDs every time the program is run)
    return n;
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

int CheckAndSetID(int randomN, vector<int>& IDvector)
{
    //this loop makes sure no duplicate ID is generated
    while(std::count(IDvector.begin(), IDvector.end(), randomN)) //if random is duplicate in ID vector,
    {                                                            //then generate a new ID until it is 
        randomN = IDgenerator();                                 //unique
    }
    IDvector.push_back(randomN);//adds ID to the IDvector
    return randomN;
}

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
int chooseFaculty()//switch case for choosing faculty of student
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
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::getline(cin, faculty);
        
        system("CLS");
        facultyChoice = ValidateChoice(faculty);//validates first
        exitFacultyLoop = true;
    }while(exitFacultyLoop == false);

    return facultyChoice;
}

void displayFacultyStudents(const vector<Student*>& students) {
    bool exitLoop = false;
    do {
        cout << char(201);
        for (int i = 0; i < 54; i++) {
            cout << char(205);
        }
        cout << char(187) << "\n"; // top row
        cout << char(186) << "                 VIEW SPECIFIC FACULTY                " << char(186) << "\n"
             << char(186) << "------------------------------------------------------" << char(186) << "\n"
             << char(186) << " Press 1 to view list of Computer science students:   " << char(186) << "\n"
             << char(186) << "------------------------------------------------------" << char(186) << "\n"
             << char(186) << " Press 2 to view list of Business economics students: " << char(186) << "\n"
             << char(186) << "------------------------------------------------------" << char(186) << "\n"
             << char(186) << " Press 3 to view list of Law students:                " << char(186) << "\n"
             << char(186) << "------------------------------------------------------" << char(186) << "\n"
             << char(186) << " Press 4 to view list of Language students:           " << char(186) << "\n"
             << char(186) << "------------------------------------------------------" << char(186) << "\n"
             << char(186) << " Press 5 to go back to main menu:                     " << char(186) << "\n";
        cout << char(200);
        for (int i = 0; i < 54; i++) {
            cout << char(205);
        }
        cout << char(188) << "\n"; // bottom row

        int facultyChoice;
        cout << "\n-------------------------------------\n"
             << "Enter your choice here:  ";
        cin >> facultyChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool studentsFound = false;  // Flag to track if students were found

        switch (facultyChoice) {
            case 1:
                cout << "Computer Science Students:\n";
                for (const auto& student : students) {
                    if (student->getFaculty() == "Computer Science") {
                        student->displayInfo();
                        studentsFound = true;
                    }
                }
                break;
            case 2:
                cout << "Business Economics Students:\n";
                for (const auto& student : students) {
                    if (student->getFaculty() == "Business Economics") {
                        student->displayInfo();
                        studentsFound = true;
                    }
                }
                break;
            case 3:
                cout << "Law Students:\n";
                for (const auto& student : students) {
                    if (student->getFaculty() == "Law") {
                        student->displayInfo();
                        studentsFound = true;
                    }
                }
                break;
            case 4:
                cout << "Language Students:\n";
                for (const auto& student : students) {
                    if (student->getFaculty() == "Language") {
                        student->displayInfo();
                        studentsFound = true;
                    }
                }
                break;
            case 5:
                exitLoop = true;
                break;
            default:
                cout << "Invalid faculty choice.\n";
                break;
        }

        if (!studentsFound) {
            cout << "No students found\n";
        }
    } while (!exitLoop);
}



