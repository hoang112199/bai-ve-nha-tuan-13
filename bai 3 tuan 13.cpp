#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
    string name;
    float score;

public:
    string getName() { return name; }
    float getScore() { return score; }
    Student()
    {
        this->name = "no name";
        this->score = 0;
    }
    Student(string aName, float aScore)
    {
        this->name = aName;
        this->score = aScore;
    }

    friend ostream& operator<<(ostream& os, const Student& z);
    friend istream& operator>>(istream& is, Student& z);
};

ostream& operator<<(ostream& os, const Student& z)
{
    cout << "Ten: " << z.name << "\tDiem: " << z.score;
    return os;
}
istream& operator>>(istream& is, Student& z)
{
    cout << "nhap ten: ";
    fflush(stdin);
    getline(cin, z.name);
    cout << "nhap diem: ";
    cin >> z.score;
    return is;
}
bool operator<(Student& a, Student& b)
{
    return a.getScore() > b.getScore();
}

void printStudentList(int N, Student* A)
{
    for (int i = 0; i < N; i++)
    {
        cout << "\nSTT " << i + 1 << endl;
        cout << *(A + i);
    }
}
void inputStudentData(int N, Student* A)
{
    for (int i = 0; i < N; i++)
    {
        cout << "+) nhap du lieu cho sinh vien thu " << i + 1 << endl;
        cin >> *(A + i);
    }
}
int main()
{
    int N;
    Student studentArray[10];
    cout << "nhap so hoc sinh: ";
    cin >> N;
    inputStudentData(N, studentArray);
    cout << "Truoc khi sap xep:";
    printStudentList(N, studentArray);
    sort(studentArray, studentArray + N);
    cout << "\nSau khi sap xep: ";
    printStudentList(N, studentArray);
    return 0;
}
