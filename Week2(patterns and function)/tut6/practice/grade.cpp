// Write a function of student and grade problem //

#include <iostream>
using namespace std;

// Here the marks is called parameter //
char getGrade(int marks)
{
    // if (marks >= 90)
    // {
    //     return 'A';
    // }
    // else if (marks >= 80)
    // {
    //     return 'B';
    // }
    // else if (marks >= 70)
    // {
    //     return 'C';
    // }
    // else if (marks >= 60)
    // {
    //     return 'D';
    // }
    // else if (marks >= 50)
    // {
    //     return 'E';
    // }
    // else
    // {
    //     return 'F';
    // }

    // assuming the no. btwn 0 to 100 //
    switch (marks / 10)
    {
    case 10:
        return 'A';
        break;
    case 9:
        return 'A';
        break;
    case 8:
        return 'B';
        break;
    case 7:
        return 'C';
        break;
    case 6:
        return 'D';
        break;
    case 5:
        return 'E';
        break;

    default:
        return 'F';
        break;
    }
}

int main()
{
    int marks;
    cout << "Enter Your Marks ";
    cin >> marks;

    // Here the marks is called argument //
    char result = getGrade(marks);

    cout << result;

    return 0;
}