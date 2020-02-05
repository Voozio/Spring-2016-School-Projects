//todo_list.cpp - A To-do List.
//Justin Voo - 5/20/16
//CISP 360

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <iterator>

using namespace std;

//Prototypes to foreshadow upcoming functions
string greeting();
vector<string> input(vector<string> list);
vector<string> menu(vector<string> list);
void display(vector<string> list);
vector<string> add(vector<string> list);
vector<string> remove(vector<string> list);
vector<string> complete(vector<string> list);
void save(vector<string> list);
vector<string> open();

int main()
{
    //The vector behind it all
    vector<string> list;
    string decision;

    decision = greeting();
    //Bonus - An option to create a new list or continue with the previous one (Novel Programmer Defined Feature)
    //Contraint speaks as if persisting is the only option
    if (decision == "0")
    {
        list = open();
        //This if statement checks to see if an existing list is valid
        //If not, the user has to create a new list
        if (list.size() < (unsigned)1)
        {
            cout << "\nToDoList.txt does not exist or is invalid.\n\n";
            list = input(list);
        }
    }
    else
    {
        list = input(list);
    }
    list = menu(list);
    save(list);
}

//A function to welcome to user
//The user is given the option to open an existing list or create a new one
string greeting()
{
    string decision;

    cout << "\nWelcome to the To-do List program.\n";
    cout << "Here, you can add and remove tasks to your list.\n";
    cout << "Would you like to open a pre-existing list?\n";
    cout << "The file must be in the same folder as this program AND";
    cout << " it must be called 'ToDoList.txt'.\n";
    cout << "If yes, type '0'. To create a new list, type anything else and press enter: ";
    getline(cin, decision);
    return decision;
}

//A function that serves as the initial list creation
//This function is only called for brand new lists
vector<string> input(vector<string> list)
{
    bool flag = false;
    int counter = list.size();
    string temp;

    cout << "\nA new list has been created.\n";
    cout << "Type nothing and press enter to stop adding tasks.\n\n";
    while (flag == false)
    {
        cout << "Enter a task for item #" << counter + 1 << ": ";
        getline(cin, temp);
        if (temp != "")
        {
            list.push_back(temp);
            counter++;
        }
        else
        {
            cout << "\nYour list has been created...\n";
            flag = true;
        }
    }
    return list;
}

//A function that serves as the menu after the initial program greeting
//Instructions are given and the decision is filtered through if-else statements
//Validity-checking is included
vector<string> menu(vector<string> list)
{
    bool flag = false;
    string decision;

    while (flag == false)
    {
        cout << "\n-------------------Menu-------------------";
        cout << "\n---Type '0' to display the current list---";
        cout << "\n-Type '1' to add another task to the list-";
        cout << "\n-Type '2' to remove a task from your list-";
        cout << "\n---Type '3' to mark a task as completed---";
        cout << "\n-------Type '4' to quit the program-------";
        cout << endl;
        cout << "\n                    ";
        getline(cin, decision);
        cout << "------------------------------------------";
        if (decision == "0")
        {
            display(list);
        }
        else if (decision == "1")
        {
            list = add(list);
        }
        else if (decision == "2")
        {
            list = remove(list);
        }
        else if (decision == "3")
        {
            list = complete(list);
        }
        else if (decision == "4")
        {
            cout << "\n\nThank you for choosing us. See you next time.\n\n";
            flag = true;
        }
        else
        {
            cout << "\nThat is not a valid option.\n\n";
        }
    }
    return list;
}

//A function that displays all the items in the vector
void display(vector<string> list)
{
    cout << endl;
    for (int x = 0; (unsigned)x < list.size(); x++)
    {
        cout << "Task #" << x + 1 << ": " << list[x];
        cout << endl;
    }
}

//A function that allows the user to add more tasks to the list
vector<string> add(vector<string> list)
{
    string newTask;

    cout << "\nAdding a task will be canceled if nothing is typed and enter is pressed.\n";
    cout << "Keep in mind that new tasks will be added to the end of the list.\n";
    cout << "Enter a task for item #" << (list.size() + 1) << ": ";
    getline(cin, newTask);
    list.push_back(newTask);
    return list;
}

//A function that allows the user to remove a task from the list
//Range-checking for the user input is included
vector<string> remove(vector<string> list)
{
    int taskSelected;
    bool valid = false;

    display(list);
    while (valid == false)
    {
        cout << "\nType the number of the item on the list you would like to remove: ";
        cin >> taskSelected;
        cin.ignore();
        if (taskSelected == 0)
        {
            valid = true;
        }
        if ((unsigned)taskSelected <= list.size())
        {
            list.erase(list.begin() + (taskSelected - 1));
            list.resize(list.size());
            cout << "Item removal successful...\n";
            display(list);
            valid = true;
        }
        else
        {
            cout << "\nThat number is invalid. It is either too low or too high.\n";
        }
    }
    return list;
}

//Bonus - An option to mark tasks as completed
//The user decides which task will be marked as completed
//Range-checking for the user input is included
vector<string> complete(vector<string> list)
{
    int taskSelected;
    bool valid = false;

    display(list);
    while (valid == false)
    {
        cout << "\nType the number of the item on the list you would like to complete: ";
        cin >> taskSelected;
        cin.ignore();
        if (taskSelected == 0)
        {
            valid = true;
        }
        if ((unsigned)taskSelected <= list.size())
        {
            list[taskSelected -1] += " (COMPLETED)";
            valid = true;
        }
        else
        {
            cout << "\nThat number is invalid. It is either too low or too high.\n";
        }
    }
    return list;
}

//A function that allows the user's list to be saved to a file
void save(vector<string> list)
{
    ofstream filestream("ToDoList.txt");
    copy(list.begin(), list.end(), ostream_iterator<string>(filestream, "\n"));
    filestream.close();
}

//A function that allows the user's list to be opened from a file
//Each line from the file is read and put into a single slot in the vector
vector<string> open()
{
    vector<string> list;
    string line;
    ifstream filestream("ToDoList.txt");
    bool flag = false;

    while (flag == false)
    {
        getline(filestream, line);
        if (line == "")
        {
            flag = true;
        }
        else
        {
            list.push_back(line);
        }
    }
    return list;
}


