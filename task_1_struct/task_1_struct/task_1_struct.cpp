

#include <iostream>
#include <string>

using namespace std;


struct Student {

    string lastname;
    string firstname;
    int balls[3];



};

void print(Student* st) {
    setlocale(LC_ALL, "ru");
    for (int i = 0; i < sizeof(st); i++) {

        cout << "Student number " << i + 1 << ": ";
        cout << "Surname: "; cout << st[i].lastname;
        cout << " Name: "; cout << st[i].firstname;
        cout << " 3 rating: ";
        for (int j = 0; j < 3; j++) {
            cout << st[i].balls[j] << " ";
        }
        cout << endl;

    }
}

Student* sort(Student* st) {

    int sr[sizeof(st)] = { 0, 0, 0 };
    for (int i = 0; i < sizeof(st); i++) {
        for (int j = 0; j < 3; j++) {
            sr[i] += st[i].balls[j];
        }
    }

    Student tempst;
    int tempsr;                           // 4 1 5 3
    for (int i = 0; i < sizeof(st) - 1; i++) {
        for (int j = 0; j < sizeof(st) - i - 1; j++) {
            if (sr[j] > sr[j + 1]) {

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
    int N;
    do {
        cout << "Enter number of students: ";

        cin >> N;
        if (N < 5) {
            cout << "Quantity must be greater than or equal to 5!\n";
        }
    } while (N < 5);

    Student* students = new Student[N];


    for (int i = 0; i < N; i++) {

        cout << "Student number " << i + 1 << ":\n";
        cout << "Surname: "; cin >> students[i].lastname;
        cout << "Name: "; cin >> students[i].firstname;
        cout << "3 rating: ";
        for (int j = 0; j < 3; j++) {
            cin >> students[i].balls[j];
        }


    }

    cout << "_____________________________________________________________________" << endl;
    print(students);
    cout << "__________________Sorted array_____________________________" << endl;
    sort(students);

    print(students);


    delete[] students;
}
