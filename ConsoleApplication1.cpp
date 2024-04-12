// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "list.h"

using namespace std;

int main()
{
    List list;
    int stop = 0;
    int n{};
    
    
    
    while (stop != 1) {

        int key;
        cout << "1-create and write, 2-load, 3-add, 4-delete, 5-edit,6-search,7-stop" << endl;
        cin >> key;
        if (key == 1) {
            while (true) {
                cout << "n= ";
                if (!(cin >> n)) {
                    cout << "Error: n must be an integer. Please try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                    break;
            }
            MiTech* arr = new MiTech[n];
            list.create(arr, n);
            list.write(arr, n);
            delete[]arr;

        }
        if (key == 2) {

            list.load(n);

        }
        if (key==3) {
            cout << "n= ";
            int n;
            cin >> n;
            MiTech* arr1 = new MiTech[n];
            if (n < 1)
                return 0;
            for (int i = 0; i < n; i++) {
                cout << "type= ";
                string type;
                cin >> type;
                arr1[i].settype(type);
                cout << "country= ";
                string country;
                cin >> country;
                arr1[i].setcountry(country);

                int amount;
                while (true) {
                    cout << "amount= ";
                    if (!(cin >> amount)) {
                        cout << "Error: Amount must be an integer. Please try again." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else {
                        arr1[i].setamount(amount);
                        break;
                    }
                }
            }
            list.add(arr1, n);
            cout << "added arr:" << endl;
            for (int i = 0; i < n; i++)
                cout << arr1[i].type() << " " << arr1[i].country() << " " << arr1[i].amount() << endl;
            delete[]arr1;

        }
        if (key==4) {
            cout << "enter id: ";
            int id;
            cin >> id;
            if (id > n)
                return 0;
            list.remove(id);
            
        }
        if (key == 5) {
            cout << "enter id: ";
            int id;
            cin >> id;
            if (id > n)
                return 0;
            list.edit(id);
            
        }
        if (key == 6) {
            cout << "what do you need to search" << endl;
            cout << "1-type, 2-country, 3-amount" << endl;
            int k;
            cin >> k;

            list.search(k);
        }
        if (key == 7)
            stop = 1;
    }
    return 0;
}