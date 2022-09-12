#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

void menu();

class ManageMenu
{
protected:
    string userName;

public:
    ManageMenu()
    {
        cout << "Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        menu();
    }
    ~ManageMenu() {}
}; // end of class

class Customers
{
public:
    string name, gender, address;
    int age, phoneNumber, menuBack;
    static int CustomerID;
    char all[999];

    void getDetails()
    {
        ofstream out("Customerss.txt", ios::app);
        {
            cout << "\nEnter Customers ID: ";
            cin >> CustomerID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> phoneNumber;
            cout << "Address: ";
            cin >> address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << CustomerID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << phoneNumber << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n" << endl;
    }
    void showDetails()
    {
        ifstream in("Customers.txt");
        {
            if(!in) cout << "File Error!" << endl;

            while(!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
}; // end of class

int Customers::CustomerID;

class Cars
{
public:
    int taxiChoice;
    int kilometers;
    float taxiCost;
    static float lasttaxiCost;

    void taxiDetails()
    {
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country" << endl;
        cout << "-----------Trap Trip -----------\n" << endl;
        cout << "1. Book a Bus - Rs.15 for 1KM" << endl;
        cout << "2. Rent a Taxi - Rs.25 per 1KM" << endl;
        cout << "--------------------------------------" << endl;

        cout << "\nEnter another key to back or," << endl;

        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> taxiChoice;
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers;

        int bookTaxi;

        if(taxiChoice == 1)
        {
            taxiCost = kilometers * 15;
            cout << "\nYour tour will cost " << taxiCost << " EGP for a Bus" << endl;
            cout << "Press 1 to Book this Bus: " << endl;
            cout << "Press 2 to select another Bus or Taxi: " << endl;
            cin >> bookTaxi;
            system("CLS");
            if (bookTaxi == 1)
            {
                lasttaxiCost = taxiCost;
                cout << "\nYou have successfully booked bus" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(bookTaxi == 2)
            {
                taxiDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                system("CLS");
                taxiDetails();
            }
        }
        else if(taxiChoice == 2)
        {
            taxiCost = kilometers * 25;
            cout << "\nYour tour will cost " << taxiCost << " EGP for a Taxi" << endl;
            cout << "Press 1 to hire this Taxi: " << endl;
            cout << "Press 2 to select another Bus or Taxi: " << endl;
            cin >> bookTaxi;
            system("CLS");
            if (bookTaxi == 1)
            {
                lasttaxiCost = taxiCost;
                cout << "\nYou have successfully booked taxi" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(bookTaxi == 2)
            {
                taxiDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                system("CLS");
                taxiDetails();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> bookTaxi;
        system("CLS");
        if(bookTaxi == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
}; // end of class

float Cars::lasttaxiCost;

class Booking
{
public:
    int hotelChoice;
    int packChoice1;
    int gotoMenu;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = {"Kempinski", "ChoiceYou", "ElephantBay"};
        for(int a = 0; a < 3; a++)
        {
            cout << (a+1) <<". Hotel " << hotelNo[a] << endl;
        }

        cout << "\nCurrently we collaborated with above hotels!" << endl;
        cout << "Press any key to back or\nEnter Number of the hotel you want to book or see details: ";
        cin >> hotelChoice;

        system("CLS");

        if(hotelChoice == 1)
        {
            cout << "-------WELCOME TO HOTEL KEMPINSKI-------\n" << endl;
            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;
            cout << "Packages offered by Avendra:\n" << endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Avendra: Rs.15000.00" << endl;
            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Kempinski" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Kempinski" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Kempinski" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if(hotelChoice == 2)
        {
            cout << "-------WELCOME TO HOTEL SONESTA-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by Sonesta:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 15000.00;
                cout << "You have successfully booked Family Pack at Sonesta" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "You have successfully booked Couple Pack at Sonesta" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked Single Pack at Sonesta" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if(hotelChoice == 3)
        {
            cout << "-------WELCOME TO HOTEL Al-MASA-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for a one day!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked Al Masa Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            system("CLS");
            menu();
        }
    }
}; // end of class

float Booking::hotelCost;

class Chargers : public Booking, Cars, Customers
{

public:

    void printReceipt()
    {
        ofstream outf("receipt.txt"); //receipt for bought items
        {
            outf << "-------- Trap Trip---------------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customers ID: " << Customers::CustomerID << endl << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (Car) cost:\t " << fixed << setprecision(2) << Cars::lasttaxiCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cars::lasttaxiCost << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
    }

    void showReceipt()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout << "File Error!" << endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
}; // end of class

void menu()
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * ABC Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomers Management -> 1\t|" << endl;
    cout << "\t|\tCars Management      -> 2\t|" << endl;
    cout << "\t|\tBookings Management  -> 3\t|" << endl;
    cout << "\t|\tCharges & Receipt    -> 4\t|" << endl;
    cout << "\t|\tExit                 -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customers Customer;
    Cars car;
    Booking book;
    Chargers charger;

    if(mainChoice == 1)
    {
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customers"<< endl;
        cout << "2. See Old Customers"<< endl;
        cout << "\nEnter choice: ";
        cin >> inChoice;
        system("CLS");
        if(inChoice == 1)
        {
            Customer.getDetails();
        }
        else if(inChoice == 2)
        {
            Customer.showDetails();
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if(mainChoice == 2)
    {
        car.taxiDetails();
    }
    else if(mainChoice == 3)
    {
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        book.hotels();
    }
    else if(mainChoice == 4)
    {
        cout << "-->Get your receipt<--\n" << endl;
        charger.printReceipt();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1)
        {
            system("CLS");
            charger.showReceipt();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5)
    {
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        system("CLS");
        ManageMenu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu start;

    return 0;
}
