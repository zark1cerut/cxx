#include <iostream>
#include <string>

struct Student {

    string lastname;
    string firstname;
    int balls[3];
};

void print(Student* st)
{
    setlocale(LC_ALL, "ru");
    for (int i = 0; i < sizeof(st); ++i)
    {

        std::cout << "Student number " << i + 1 << ": ";
        std::cout << "Surname: "; std::cout << st[i].lastname;
        std::cout << " Name: "; std::cout << st[i].firstname;
        std::cout << " 3 rating: ";
        for (int j = 0; j < 3; j++)
        {
           std::cout << st[i].balls[j] << " ";
        }
        std::cout << std::endl;

    }
}

Student* sort(Student* st)
{
    int sr[sizeof(st)] = { 0, 0, 0 };
    for (int i = 0; i < sizeof(st); ++i)
    {
        for (int j = 0; j < 3; ++j) 
        {
            sr[i] += st[i].balls[j];
        }
    }

    Student tempst;
    unsigned int tempsr;                      
    for (int i = 0; i < sizeof(st) - 1; ++i)
    {
        for (int j = 0; j < sizeof(st) - i - 1; ++j) 
        {
            if (sr[j] > sr[j + 1]) 
            {

                tempsr = sr[j];
                sr[j] = sr[j + 1];
                sr[j + 1] = tempsr;
                //___________________
                tempst = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tempst;
            }
        }
    }

    return st;
}

int main()
{
    setlocale(LC_ALL, "ru");
    unsigned int numberOfStudents = 0;
    do {
        std::cout << "Enter number of students: ";
        std::cin >> numberOfStudents;
        
        if (numberOfStudents < 5)
        {
            std::cout << "Quantity must be greater than or equal to 5!\n";
        }
    } while (numberOfStudents < 5);

    Student* students = new Student[numberOfStudents];

    for (int i = 0; i < numberOfStudents; ++i)
    {
        std::cout << "Student number " << i + 1 << ":\n";
        std::cout << "Surname: "; std::cin >> students[i].lastname;
        std::cout << "Name: "; std::cin >> students[i].firstname;
        std::cout << "3 rating: ";
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> students[i].balls[j];
        }
    }

    std::cout << "_____________________________________________________________________" << std::endl;
    std::print(students);
    std::cout << "__________________Sorted array_____________________________" << std::endl;
    std::sort(students);
    std::print(students);

    delete[] students;
    return 0;
}
