#include <iostream>
using namespace std;

// class
class Bank {
private:
    int acno;
    char name[30];
    char add[30];
    int pin;
    char acc[30];
    long balance;

public:
    void OpenAccount()
    {
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter your Name: ";
        cin >> name;
        cout << "Enter your address: ";
        cin >> add;
        cout << "Enter the Pincode: ";
        cin >> pin;
        cout << "Enter the type of account [SAVINGS OR CURRENT]: ";
        cin >> acc;
        cout << "Enter initial amount to open account: ";
        cin >> balance;
        cout << "Account created successfully....\n";
    }
    void ShowAccount()
    {
        cout << "Account Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << add << endl;
        cout << "Pincode: " << pin << endl;
        cout << "Type of account: " << acc << endl;
        cout << "Balance: " << balance << endl;
    }
    void Deposit()
    {
        long amt;
        cout << "\n\n\t******* TO DEPOSITE AMOUNT *******";
        cout << "\n\nEnter Amount you want to deposit: ";
        cin >> amt;
        balance = balance + amt;
    }
    void Withdrawal()
    {
        long amt;
        cout << "\n\n\t******* TO WITHDRAW AMOUNT *******";
        cout << "\n\nEnter Amount you want to withdraw: ";
        cin >> amt;
        balance = balance - amt;
        if (balance<amt)
        {
           cout << "***.....INSUFFICIENT BALANCE.....***" << endl;
        }
            //balance = balance - amt;
        else
           cout <<"**......YOU have successfully withdrawn the amount......**\n";

    }
    int Search(int);
};

int Bank::Search(int a)
{
    if (acno == a) {
        ShowAccount();
        return (1);
    }
    return (0);
}

// main code
int main()
{
    Bank C[3];

    int found = 0, a, ch, i;
    for (i = 0; i <= 2; i++) {
        C[i].OpenAccount();
    }

    do {
        // display options
        //cout << "===================== MAIN MENU =============================";
        cout << "======================= MAIN MENU =========================";
        cout << "\n=1. DISPLAY ALL:                                     ";
        cout << "\n=2. BY ACCOUNT NO:                                   ";
        cout << "\n=3. DEPOSIT:                                         ";
        cout << "\n=4. WITHDRAW:                                        ";
        cout << "\n=5. EXIT:                                            ";
        cout << "\n=======================================================\n";
        //cout << "\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit" << endl;

        // user input
        cout << "Please Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1: // displating account info
            cout <<"\n\t\t**********************************************************";
            cout <<"\n\t\t******* DISPLAYING PASSBOOK DETAILS OF ALL ACCOUNT *******";
            cout <<"\n\t\t**********************************************************"<<endl;
            for (i = 0; i <= 2; i++) {
                C[i].ShowAccount();
            }
            break;
        case 2: // searching the record
            cout <<"\n\t\t********************************************************************";
            cout <<"\n\t\t******* DISPLAYING PASSBOOK DETAILS OF A PARTICULAR  ACCOUNT *******";
            cout <<"\n\t\t********************************************************************"<<endl;
            cout << "Enter the account number to search: ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found)
                    break;
            }
            if (!found)
                cout << "ACCOUNT NUMBER DOES NOT EXITS......[CHECK THE ACCOUNT NUMBER YOU HAVE ENTERED]" << endl;
            break;
        case 3: // deposit operation
            cout <<"\n\t\t******************************";
            cout <<"\n\t\t******* DEPOSIT AMOUNT *******";
            cout <<"\n\t\t******************************"<<endl;
            cout << "Enter the Account Number To Deposit Amount: ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Deposit();
                    cout <<"**......YOU have successfully deposited the amount.....**\n";
                    break;
                }
            }
            if (!found)
                cout << "ACCOUNT NUMBER DOES NOT EXITS......[CHECK THE ACCOUNT NUMBER YOU HAVE ENTERED]" << endl;
                //cout << "Record Not Found" << endl;
            break;
        case 4: // withdraw operation
            cout <<"\n\t\t*******************************";
            cout <<"\n\t\t******* WITHDRAW AMOUNT *******";
            cout <<"\n\t\t*******************************"<<endl;
            cout << "Enter the Account Number To Withdraw Amount: ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Withdrawal();
                    //cout <<"**......YOU have successfully withdrawn the amount......**\n";
                    break;
                }
            }
            if (!found)
                cout << "ACCOUNT NUMBER DOES NOT EXITS......[CHECK THE ACCOUNT NUMBER YOU HAVE ENTERED]" << endl;
                //cout << "Record Not Found" << endl;
            break;
        case 5: // exit
            cout << "THANK YOU.....Have a nice day" << endl;
            break;
default:
            cout << "Wrong Option" << endl;
        }
    } while (ch != 5);
    return 0;
}
