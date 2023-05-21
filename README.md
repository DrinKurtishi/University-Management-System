# University Management System
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
