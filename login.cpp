#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
using namespace std;

void showMenu();
void login();
void newUser();

int main()
{
    int option;

    do
    {
        showMenu();
        cout << ">>> ";
        cin >> option;

        switch (option)
        {
        case 1:
            login();
            break;
        case 2:
            newUser();
            break;
        case 3:
            break;
        default:
            cout << "Invalid input. Try again.\n";
            sleep(1);
        }
    } while (option != 3);
    return 0;
}

void showMenu()
{
    system("cls");
    cout << "-=-=-=-=-=-=-=-=-=-=-=-\n";
    cout << " THE (UN)SOCIAL MEDIA\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-\n";

    cout << "[1] Login\n";
    cout << "[2] Register\n";
    cout << "[3] Exit\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-\n";
}

void login()
{
    system("cls");
    string username, password;
    fstream dataBase;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    dataBase.open("database.txt", ios::in);

    if (dataBase.is_open())
    {
        string line;
        bool validation = false;
        while (getline(dataBase, line))
        {
            if (username == line)
            {
                getline(dataBase, line);
                if (password == line)
                    validation = true;
            }
        }

        if (validation)
            cout << "Access granted!\n";
        else
            cout << "Access denied!\n";

        sleep(1);
        dataBase.close();
    }
}

void newUser()
{
    system("cls");
    string username, password, confirmPassword;
    fstream dataBase;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    cout << "Confirm password: ";
    cin >> confirmPassword;

    if (password == confirmPassword)
    {
        dataBase.open("database.txt", ios::app);

        if (dataBase.is_open())
        {
            dataBase << username << endl;
            dataBase << password << endl;
        }

        dataBase.close();

        cout << "We're good to go!\n";
    }
    else
        cout << "Ops! You mispelled the password.\n";

    sleep(1);
}
