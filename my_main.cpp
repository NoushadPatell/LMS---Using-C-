#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Book
{
	char bno[6];  // bookno.
	string bname; // bookname
	string aname; // authorname
public:
	void createbook()
	{
		ofstream outfile("book.txt", ios::app);
		if (!outfile.is_open())
		{
			cerr << "Error opening the file for wrting !" << endl;
		}
		else
		{
			cout << "NEW BOOK ENTRY... \n";
			cout << "Enter Book No : ";
			cin >> bno;
			outfile << bno << endl;
			cin.ignore();
			cout << "Enter Book Name : ";
			getline(cin, bname); // enables enter with space
			outfile << bname << endl;
			cout << "Enter Author Name : ";
			getline(cin, aname);
			outfile << aname << endl;
			cout << "Book Created.. \n\n";
		}

		outfile.close();
	}
	void showbook()
	{
		ifstream infile("book.txt");
		if (!infile.is_open())
		{
			cerr << "Error opening the file for reading." << endl;
			return;
		}

		cout << endl;
		cout << "------> Book Records <------\n\n";
		while (infile >> bno >> ws && getline(infile, bname) && getline(infile, aname))
		{
			cout << "Book Number: " << bno << endl;
			cout << "Book Name: " << bname << endl;
			cout << "Book Author Name: " << aname << endl;
			cout << endl;
		}

		infile.close();
	}

	void modifybook()
	{
		cout << "\nBook Number: " << bno;
		cout << "\nModify Book Name :";
		getline(cin, bname);
		cout << "\nModify Author's Name :";
		getline(cin, aname);
		cout << endl
			 << endl;
	}
};

class Student_Login : public Book
{
	string f_name;
	string l_name;
	string email;
	string password;

public:
	void new_register()
	{
		ofstream outfile("login.txt", ios::app);
		if (!outfile.is_open())
		{
			cerr << "Error encountered while opening login file " << endl;
		}
		else
		{
			cout << "New Student Registration Details : " << endl;
			cout << "Enter Your First Name : ";
			getline(cin, f_name);
			outfile << f_name << endl;
			cout << "Enter Your Last Name : ";
			getline(cin, l_name);
			outfile << l_name << endl;
			cout << "Enter Your Email Id : ";
			getline(cin, email);
			outfile << email << endl;
			cout << "Enter Your Enter Password : ";
			getline(cin, password);
			outfile << password << endl;

			cout << "Student Data Saved !! " << endl;
		}
		outfile.close();
	}

	void book_menu()
	{
		Book b1;
		while (true) {
		int book_choice;
		cout << "1) Create A Book Record \n";
		cout << "2) Show Book Records \n";
		cout << "Select an option from (1-2) :";
		cin >> book_choice;
		cout << endl;

		switch (book_choice)
		{
		case 1:
			b1.createbook();
			break;

		case 2:
			b1.showbook();
			break;

		default:
			cout << "Enter valid option from 1-2 ! \n";
			break;
		}
		}
	}

	bool login()
	{
		string input_mail, input_password;
		cout << "Enter your email id : ";
		cin >> input_mail;
		cout << "Enter your password : ";
		cin >> input_password;
		cout << endl;

		ifstream infile("login.txt");
		if (!infile.is_open())
		{
			cerr << "Error Encountered while opening the file !!~" << endl;
			return false;
		}
		else
		{
			string line;
			while (getline(infile, line))
			{
				if (line == input_mail)
				{
					if (getline(infile, line) && line == input_password)
					{
						cout << "Login Successfull ! Welcome, " << f_name << " " << l_name << endl;
						book_menu();
						return true;
					}
				}
			}
			cout << "Login failed. Incorrect email or password." << endl;
			infile.close();
		}
	}
};

int main()
{
	Student_Login s1;

	int login_choice;
	cout << "-------MAIN MENU -------" << endl;
	cout << "1) New Student Registration \n";
	cout << "2) Login For Already Resitered Students\n";
	cout << "Select an option from (1-2) : ";
	cin >> login_choice;
	cin.ignore();

	switch (login_choice)
	{
	case 1:
		s1.new_register();
		break;

	case 2:
		s1.login();
		break;

	default:
		break;
	}

	return 0;
}