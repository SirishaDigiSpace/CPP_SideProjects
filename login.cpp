#include <iostream>

#include <fstream>

#include <string>

using namespace std;

void login();

void registration();

void forgotPassword();

int main()
{
    int c ;//c is for choice
    cout << "\t\t\t                                         Welcome to  GogS                                        \n\n\n" << endl;
    cout << "\t\t 1. Login to GogS " << endl;
    cout << "\t\t 2. Register to GogS " << endl;
    cout << "\t\t 3. Forgot Password " << endl;
    cout << "\t\t 4. Exit " << endl;
    cin >> c;
    cout << endl;

     switch(c)
     {
        case 1:
              login();
              break;
        case 2:
             registration();
             break;
        case 3:
             forgotPassword();
             break;
         case 4:
             cout << "\t\t\t     Thank you!      \n\n\n" ;
             break;
        default:
             cout << "\t\t\t Please select from the above given options.\n";
             main();
     }
 }
   void login()
   {
    int count;
    string userId, password, id, pass;
    cout << "\t\t\t Please enter the username and password : " << endl;
    cout << "\t\t\t USERNAME : ";
    cin >> userId;
    cout << "\t\t\t PASSWORD : ";
    cin >> password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id == userId && pass == password){
         count = 1;
        }
    }
    input.close();

    if(count == 1)
     {
        cout <<' '<< userId <<"\n You've logged in to 'GogS' successfully.\n";
        main();
     }
     else
     {
        cout << "\n Invalid login \n Please check again." << endl;
        main();
     }
   }
   void registration()
   {
     string r_userId, r_password, r_id, r_pass;
     cout << "\t\t\t Enter the Username : ";
     cin >> r_userId;
     cout << "\t\t\t Enter the Password : ";
     cin >> r_password;

     ofstream f1("records.txt", ios::app);
     f1 << r_userId << ' ' << r_password << endl;
     cout << "\n\t\t\t  You've registered to 'GogS' successfully." << endl;
     main();

   }
   void forgotPassword()
   {
    int option;
    cout << "\t\t\t Forgot the Password? Try again \n";
    cout << "\t\t\t Press 1 to search your id by username. \n" << endl;
    cout << "\t\t\t Press 2 to go back to the main menu. \n" << endl;
    cout << "\t\t\t Enter your choice :  \n";
    cin >> option;

    switch(option)
    {

        case 1:
        {
            int count = 0;
            string s_userId, s_id, s_pass;
            cout <<"\n\t\t Enter the username that you've remembered. \n"<< endl;
            cin >> s_userId;

            ifstream f2("records.txt");
            while(f2 >> s_id >> s_pass)
            {
                if(s_id == s_userId)
                {
                    count = 1;
                }
                f2.close();
                if(count == 1)
                {
                    cout << "\n\n\n Your account is found! \n";
                    cout << "\n\n\n Your password is : \n" << s_pass;
                    main();

                }
                else {
                    cout << "\n\t Sorry! your account is not found! \n";
                    main();
                }
                break;
            }
        }
            case 2:
            {
                main();
            }
            default :
            cout << "\n\t\t\t Wrong choice! Please try again." << endl;
            forgotPassword();
        }

    }




