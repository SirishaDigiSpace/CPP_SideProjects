#include <iostream>

#include <fstream>

#include <string.h>

using namespace std;

void login();

void registration();

void forgot();

int main()
{
    int c ;//c is for choice
    cout<<"\t\t\t                                         Welcome to  GogS                                        \n\n\n" << endl;
    cout<<"\t\t 1. Login to GogS " << endl;
    cout<<"\t\t 2. Register to GogS " << endl;
    cout<<"\t\t 3. Forgot Password " << endl;
    cout<<"\t\t 4. Exit " << endl;
    cin>>c;
    cout<<endl;

     switch(c)
     {
        case 1:
              login();
              break;
        case 2:
             registration();
             break;
        case 3:
             forgot();
             break;
        case 4:
             cout<<"\t\t\t     Thank you!      \n\n\n" ;
             break;
        default:
             cout<< "\t\t\t Please select from the above given options \n";
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

    ifstream input("records.text");

    while(input>>id>>pass)
    {
        if(id==userId && pass==password){
         count=1;
        }
    }
    input.close();

    if(count==1)
     {
        cout<<' '<<userId<<"\n You've logged in to 'GogS' successfully.\n";
        main();
     }
     else
     {
        cout<<"\n Invalid login \n Please check again."<<endl;
        main();
     }
   }
   void registration()
   {
     string ruserId, rpassword, rid, rpass;
     cout << "\t\t\t Enter the Username : ";
     cin >> ruserId;
     cout << "\t\t\t Enter the Password : ";
     cin >> rpassword;

     ofstream f1("records.text", ios::app);
     f1<<ruserId<<' '<< rpassword<< endl;
     cout << "\n\t\t\t  You've registered to 'GogS' successfully!" << endl;
     main();

   }
   void forgot()
   {
    int option;
    cout<<"\t\t\t Forgot the Password? Try again \n";
    cout<<"\t\t\t Press 1 to search your id by username " <<endl;
    cout<<"\t\t\t Press 2 to go back to the main menu " <<endl;
    cout<<"\t\t\t Enter your choice :  ";
    cin>>option;

    switch(option)
    {

        case 1:
        {
            int count=0;
            string suserId, sid, spass;
            cout <<"\n\t\t\t  Enter the username that you remembered : \n"<<endl;
            cin >> suserId;

            ifstream f2("records.text");
            while(f2>>sid>>spass)
            {
                if(sid==suserId)
                {
                    count=1;
                }
                f2.close();
                if(count==1)
                {
                    cout << "\n\n Your account is found! \n";
                    cout << "\n\n Your password is : "<<spass;
                    main();

                }
                else{
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
                forgot();
    }

  }





