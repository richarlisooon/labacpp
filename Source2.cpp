#include "list.h"
#include <iostream>
#include <fstream>

using namespace std;
List::~List() {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}
void List::create(MiTech* arr, int n) {
	if (n < 1)
		return;
	for (int i = 0; i < n; i++) {
		cout << "type= ";
		string type;
		cin >> type;
		arr[i].settype(type);
		cout << "country= ";
		string country;
		cin >> country;
		arr[i].setcountry(country);

		int amount;
		while (true) {
			cout << "amount= ";
			if (!(cin >> amount)) {
				cout << "Error: Amount must be an integer. Please try again." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				arr[i].setamount(amount);
				break;
			}
		}
	}

	cout << "created arr:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i].type() << " " << arr[i].country() << " " << arr[i].amount() << endl;
}
void List::write(MiTech* arr, int n) {
	ofstream in("mt.txt");
	if (!in.is_open())
		return;
	in << n << endl;
	for (int i = 0; i < n; i++)
		in << arr[i].type() << " " << arr[i].country()<< " " << arr[i].amount() << endl;
	in.close();
	cout << "wrote arr:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i].type() << " " << arr[i].country() << " " << arr[i].amount() << endl;
}
MiTech* List::load(int n) {
	ifstream out("mt.txt");
	if (!out.is_open())
		return nullptr;

	out >> n;
	if (n <= 0)
		return nullptr;

	MiTech* arr = new MiTech[n];
	for (int i = 0; i < n; i++) {
		string type;
		string country;
		int amount;
		out >> type >> country >> amount;
		arr[i].settype(type);
		arr[i].setcountry(country);
		arr[i].setamount(amount);
	}

	out.close();

	cout << "loaded:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i].type() << " " << arr[i].country() << " " << arr[i].amount() << endl;

	return arr;
}
void List::add(MiTech* arr, int n) {
	ifstream out("mt.txt");
	if (!out.is_open())
		return;
	int n1;
	out >> n1;
	MiTech* arr1 = new MiTech[n1];
	for (int i = 0; i < n1; i++) {
		string type;
		string country;
		int amount;
		out >> type >> country >> amount;
		arr1[i].settype(type);
		arr1[i].setcountry(country);
		arr1[i].setamount(amount);
	}
	out.close();
	ofstream in1("mt.txt", ios::trunc);
	in1.close();
	ofstream in("mt.txt");
	if (!in.is_open())
		return;
	in << n+n1 << endl;
	for (int i = 0; i < n1; i++)
		in << arr1[i].type() << " " << arr1[i].country() << " " << arr1[i].amount() << endl;
	in.close();
	ofstream addmt("mt.txt", ios_base::app);
	if (!addmt.is_open())
		return;
	for (int i = 0; i < n; i++)
		addmt << arr[i].type() << " " << arr[i].country() << " " << arr[i].amount() << endl;
	addmt.close();
}

void List::remove(int id) {
	ifstream in("mt.txt"); 
	if (!in.is_open()) 
		return;
	int n;
	in >> n;
	if (n <= 0)
		return;
	MiTech* arr = new MiTech[n];
	for (int i = 0; i < n; i++) {
		string type;
		string country;
		int amount;
		in >> type >> country >> amount; 
		arr[i].settype(type); 
		arr[i].setcountry(country); 
		arr[i].setamount(amount); 
	}
	in.close(); 

	for (int i = id; i < n - 1; i++) 
	{
		arr[i] = arr[i + 1];
	}

	n--; 

	write(arr, n);
}
void List::edit(int id) {
	ifstream in("mt.txt");
	if (!in.is_open())
		return;
	int n;
	in >> n;
	if (n <= 0)
		return;

	MiTech* arr = new MiTech[n];
	for (int i = 0; i < n; i++) {
		string type;
		string country;
		int amount;
		in >> type >> country >> amount;
		arr[i].settype(type);
		arr[i].setcountry(country);
		arr[i].setamount(amount);
	}

	in.close();

	for (int i = 0; i < n; i++) {
		if (i == id) { 
			cout << "Edit data for index " << id << ":\n";
			cout << "type= ";
			string type;
			cin >> type;
			arr[i].settype(type);
			cout << "country= ";
			string country;
			cin >> country;
			arr[i].setcountry(country);
			int amount;
			while (true) {
				cout << "amount= ";
				if (!(cin >> amount)) {
					cout << "Error: Amount must be an integer. Please try again." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					arr[i].setamount(amount);
					break;
				}
			}
		}
	}

	write(arr, n);

	delete[] arr; 
}
void List::search(int k) {
	ifstream out("mt.txt");
	if (!out.is_open())
		return;

	int n;
	out>>n;
	MiTech* arr = new MiTech[n];
	for (int i = 0; i < n; i++) {
		string type;
		string country;
		int amount;
		out >> type >> country >> amount;
		arr[i].settype(type);
		arr[i].setcountry(country);
		arr[i].setamount(amount);
	}
	if (k == 1) {
		string type;
		cin >> type;
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (arr[i].type() == type) {
				cout << arr[i].type() << " " << arr[i].country() << " " << arr[i].amount() << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "not found" << endl;
		}
	}

	if (k == 2) {
		string country;
		cin >> country;
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (arr[i].country() == country) {
				cout << arr[i].type() << " " << arr[i].country() << " " << arr[i].amount() << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "not found" << endl;
		}
	}

	if (k == 3) {
		int amount;
		while (true) {
			cout << "amount= ";
			if (!(cin >> amount)) {
				cout << "Error: Amount must be an integer. Please try again." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				break;
			}
		}
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (arr[i].amount() == amount) {
				cout << arr[i].type() << " " << arr[i].country() << " " << arr[i].amount() << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "not found" << endl;
		}
	}

	delete[] arr;
}
