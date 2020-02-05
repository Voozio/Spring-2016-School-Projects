//zak_attack.cpp - A grading program.
//Justin Voo - 3/14/16
//CISP 360

//Libraries required for the program
#include <iostream>
#include <string>

using namespace std;

//Structure used to hold input values
struct Student
{
    string name;
    double scores[9];
} ;

//Prototypes used to foreshadow functions
void greeting();
string input_name();
double input_scores(int counter);
double final_grade(Student a);

int main()
{
    //Variables used to store data
    Student user;
    double total;
    double grade;
    //A constant variable for the final maximum points
    const double real_total = 600;
    //Temporary variables
    int temp_1 = 0;
    double temp_2 = 100;
    //A string array grading chart
    string grading_chart[6];
    grading_chart[0] = "Your score equates to an F.\n";
    grading_chart[1] = "Your score equates to a D.\n";
    grading_chart[2] = "Your score equates to a C.\n";
    grading_chart[3] = "Your score equates to a B.\n";
    grading_chart[4] = "Your score equates to an A.\n";
    grading_chart[5] = "Your score equates to an A+!\n";
    //A string array advice chart that is parallel to the grading chart
    string advice[6];
    advice[0] = "You should drop the class before it's too late...";
    advice[1] = "See me. We need to talk about your grade.";
    advice[2] = "You should find a tutor.";
    advice[3] = "Study more. It'll help.";
    advice[4] = "A few minor mistakes. You're almost there!";
    advice[5] = "Amazing job. I'm impressed. Keep it up!";

    //The function body which contains function calls and loops
    greeting();
    user.name = input_name();
    //Bonus - Retrieving scores through a loop including a function
    for (int x = 0; x < 9; x++)
    {
        user.scores[x] = input_scores(x);
    }
    //Takes the three smallest scores in the array and sets them to 101
    //The total is the sum of the numbers below 101
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (temp_2 > user.scores[y])
            {
                temp_1 = y;
                temp_2 = user.scores[y];
            }
        }
        user.scores[temp_1] = 101;
        temp_1 = 0;
        temp_2 = 100;
    }
    total = final_grade(user);
    grade = (total/real_total)*100;
    if (grade < 60)
    {
        cout << grading_chart[0];
        cout << advice[0];
    }
    else if (grade < 70)
    {
        cout << grading_chart[1];
        cout << advice[1];
    }
    else if (grade < 80)
    {
        cout << grading_chart[2];
        cout << advice[2];
    }
    else if (grade < 90)
    {
        cout << grading_chart[3];
        cout << advice[3];
    }
    else if (grade < 100)
    {
        cout << grading_chart[4];
        cout << advice[4];
    }
    else if (grade == 100)
    {
        cout << grading_chart[5];
        cout << advice[5];
    }
}

//A function used to welcome the user
void greeting()
{
    cout << "Welcome to the Grade Calculator. Here, we will drop your three lowest quiz scores.\n\n";
}

//A function used to retrieve the user's name
string input_name()
{
    string name;
    cout << "Enter your first and last name seperated by a space: ";
    getline(cin, name);
    cout << endl;
    return name;
}

//Bonus - A function used to retrieve the user's quiz scores (Novel-defined feature)
//Returns one score at a time and is looped to return all 9
double input_scores(int counter)
{
    double score;
    bool flag = false;
    while (flag == false)
    {
        cout << "Enter your score for Quiz #" << counter + 1 << ": ";
        cin >> score;
        if (score >= 0 && score <= 100)
        {
            return score;
        }
        else
        {
            cout << "\nYou entered an invalid quiz score.\n\n";
        }
    }
}

//A function used to output the final grade and calculate the total points
double final_grade(Student a)
{
    double total = 0;
    for (int x = 0; x < 9; x++)
    {
        if (a.scores[x] < 101)
        {
            total += a.scores[x];
        }
    }
    cout << "\nAfter removing the three lowest quiz scores, " << a.name << " recieves a total of " << total << ".\n\n";
    return total;
}
