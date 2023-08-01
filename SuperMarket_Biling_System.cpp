#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t          Supermarket Main Menu     \n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t____________________________________\n";
    cout << "\t\t\t\t                                    \n";
    cout << "\t\t\t\t|  1)Admimistrator   |  \n";
    cout << "\t\t\t\t|                    |  \n";
    cout << "\t\t\t\t|  2)Buyer           |  \n";
    cout << "\t\t\t\t|                    |  \n";
    cout << "\t\t\t\t|  3)Exit           |  \n";
    cout << "\t\t\t\t  Please Select! ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please login \n";
        cout << "\t\t\t Enter Email  \n";
        cin >> email;
        cout << "\t\t\t Password     \n";
        cin >> password;
        if (email == "sky@email.com" && password == "sky")
        {
            administrator();
            /* code */
        }

        else
        {

            cout << "Invalid Email/Password";
        }
        break;

    case 2:
    {
        buyer();
        break;
    }

    case 3:
    {
        exit(0);
        break;
    }

    default:

        cout << "Please select from the given options ";
    }
    goto m;
}

void shopping ::administrator()
{
Menu:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\t\t\t|____1)Add the product____|";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|____2)Modify the product |";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|____3)Delete the product |";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|____4)Back to main menu  |";
    cout << "\n\n\t Please enter your choice ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invlid choice ";
    }
    goto Menu;
}

void shopping ::buyer()
{
n:
    int choice;
    cout << "\t\t\t Buyer \n";
    cout << "\t\t\t_________________\n";
    cout << "\t\t\t                 \n";
    cout << "\t\t\t1) Buy Product   \n";
    cout << "\t\t\t                 \n";
    cout << "\t\t\t2) Go Back       \n";
    cout << "\t\t\t2) Enter your choice \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "Invalid choice ";
    }
    goto n;
}

void shopping ::add()
{

    fstream data;
    int c;
    int taken = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new project ";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;

    cout << "\n\n\t Name of the product ";
    cin >> pname;

    cout << "\n\n\t price of the product ";
    cin >> price;

    cout << "\n\n\t Discount of the product ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {

        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {

                taken++;
            }

            data >> c >> n >> p >> d;
        }
        data.close();

        if (taken == 1)
        {
            administrator();
        }

        else
        {

            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }

    cout << "\n\n\t\t Recode inserted ! ";
}

void shopping ::edit()
{

    fstream data, data1;
    int pkey;
    int tokon = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\nFile doesn`t exist !";
    }

    else
    {
        data1.open("database.txt", ios ::app | ios ::out);
        data >> pcode >> pname >> price >> dis;
        while (data.eof())
        {
            if (pkey == pcode)
            {

                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product : ";
                cin >> n;
                cout << "\n\t\t Price";
                cin >> p;
                cout << "\n\n\t Discount :";
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Recode edited ";
                tokon++;
            }

            else
            {
                data1 << " " << pcode << " " << pname << " " << price;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (tokon == 0)
        {
            cout << "\n\n Recode not found sorry!";
        }
    }
}

void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product ";
    cout << "\n\n\t product code ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesnot exist ";
    }
    else
    {
        data1.open("database.txt", ios::app | ios ::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\n\t Product deleted succesfully ";
                token++;
            }
            else
            {

                data1 << " " << pcode << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1", "database1.txt");

        if (token == 0)
        {
            cout << "\n\n Recode not found";
        }
    }
}
void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|________________________________________________________________________\n";
    cout << "proNO\t\tName\t\tprice\n";
    cout << "\n\n|________________________________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];

    int choice;
    int c = 0;

    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }

    else
    {

        data.close();

    m:
        list();
        cout << "\n_______________________________________________\n";
        cout << "\n                                               \n";
        cout << "\n       Please place the order                  \n";
        cout << "\n                                               \n";
        cout << "\n_______________________________________________\n";
        do
        {
            cout << "\n\n Enter product code : ";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity:";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code.please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? if yes then press 1 else 2";
            cin >> choice;

        } while (choice == 1);

        cout << "\n\n\t\t\t ___________________reseipt____________________\n";
        cout << "\n product No\t product name\t product quantity \t price \t amount\t amount with discount\n";
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while (!data.eof())
            {
                if (pcode==arrc[i])
                {
                    amount = price*arrq[i];
                    dis= amount-(amount*dis/100);
                    total = total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;

                }
                data>>pcode>>pname>>price>>dis;
            }
            
        }
        data.close();





    
    
    }
    cout<<"\n\n______________________________________________________________";
    cout<<"\n Total Amount : "<<total;
}
int main(){
shopping s;
s.menu();




    return 0;
}