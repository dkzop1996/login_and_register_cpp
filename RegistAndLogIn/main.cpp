#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw;
	cout << "Enter Username \n"; cin >> username;
	cout << "Enter Password \n"; cin >> password;

	ifstream read("data" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	un.replace(0, 10, "");
	pw.replace(0, 10, "");

	return un == username && pw == password ? true : false;
}

int main()
{
	int choice;

	cout << "1: Register\n2: Login\n Your choice: \n"; cin >> choice; 
	if(choice == 1)
	{
		string username, password;

		cout << "Select a Username \n"; cin >> username;
		cout << "Select a Password \n"; cin >> password;

		ofstream file;
		file.open("data" + username + ".txt");
		file << "Username: " + username << endl << "Password: " + password;
		file.close();
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn();

		if (!status)
		{
			cout << "\nLogin Failed" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "\nSuccesfull Logged In" << endl;
			system("PAUSE");
			return 1;
		}
	}
}