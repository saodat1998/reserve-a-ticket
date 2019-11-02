#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h> 
using namespace std;
class users{
protected:
	static int coach, place;
	string lastname, firstname;
	string day, month, year;
	char gender;
	char username[30];
	char password[10];
	static int id_user;
	ofstream out;
public:
	void setdata(){
		cout << setw(20) << "Username: "; cin >> username;
		cout << setw(20) << "Password: "; cin >> password;
		cout << endl;
		cout << "Firstname: "; cin >> firstname;
		cout << "Lastname: "; cin >> lastname;
		cout << "Gender: " << endl;
		cout << "\t'M' - (for male)" << endl;
		cout << "\t'F' - (for female)" << endl;
		cout << "Gender: "; cin >> gender;
		if (place < 3)
			place++;
		else{
			coach++;
			place = 1;
		}
		cout << "enter birthday details: " << endl;
		cout << "day: "; cin >> day;
		cout << "month: "; cin >> month;
		cout << "year: "; cin >> year;

		out.open("users.txt", ios::app);
		id_user++;
		out << id_user;
		out.close();
	}

	int id(){
		return id_user;
	}

	void display(){
		cout << ".*. Username: " << username << setw(20);
		cout << "\tPassword: " << password << endl;
	}
	
	void getFullname(){
		cout << firstname << " " << lastname << setw(30 - firstname.length() - lastname.length());
	}

	string getFirstname(){
		return firstname;
	}

	string getLastname(){
		return lastname;
	}

	char getGender(){
		return gender;
	}

	char* getname(){
		return username;
	}

	char* getpassword(){
		return password;
	}
};
int users::coach = 1;
int users::place = 0;
int users::id_user = 0;
class Register :public users{
protected:
	bool check = 0;
	users u;
	char temp_username[30];
	char temp_password[10];
	fstream file;
	bool valid = false;
	int chosen_id;
public:
	void registration(){
		file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
		file.seekg(0, ios::beg);
		file.clear();
		cout << setw(30) << "Registration Page\n" << endl;
		u.setdata();
		file.write((char *)&u, sizeof(u));
		cout << "You have successfully registered. \nThank you for registration!" << endl;
		file.close();
	}

	void login(){
		file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
		file.seekg(0, ios::beg);
		file.clear();

		cout << setw(30) << "Login Page\n" << endl;
		cout << setw(20) << "Username: "; cin >> temp_username;
		cout << setw(20) << "Password: "; cin >> temp_password;

		//login1();

		while (file.read((char *)&u, sizeof(u))){
			if (strcmp(u.getname(), temp_username) == 0){
				check = 1;
				if (strcmp(u.getpassword(), temp_password) == 0){
					cout << "welcome " << u.getname() << endl;
					cout << "welcome " << u.id() << endl;

					//		valid = true;
				}
				else{
					cout << "incorrect password" << endl;
					break;
				}
			}
		}

		if (check == 0){
			cout << "No account with this username" << endl;
		}
		file.close();
		//return valid;
	}

	string login1(){
		return string(temp_username);
	}
	
	void deleteUser(){
		fstream temp_file("temp_file.txt", ios::app | ios::out | ios::in | ios::ate);
		file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
		file.seekg(0, ios::beg);
		file.clear();
		cout << "enter a username of a user to be deleted: "; cin >> temp_username;

		while (file.read((char *)&u, sizeof(u))){
			if (strcmp(u.getname(), temp_username) != 0){
				temp_file.write((char*)&u, sizeof(u));
			}
		}
		file.close();
		temp_file.close();
		remove("users.txt");
		rename("temp_file.txt", "users.txt");
		cout << "user has been successfully deleted!" << endl;
	}

	void admin(){
		cout << "enter your password [Hint: the same as username]" << endl;
		cout << "\n.*. password = ";		cin >> temp_password;
		cout << endl;
		int i = 1;
		if (strcmp(temp_password, "admin") == 0){
			file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
			file.seekg(0, ios::beg);
			file.clear();
			cout << "\t.*. 1. Display users" << endl;
			cout << "\t.*. 2. Delete a user" << endl;
			cout << "\t.*. 3. EXIT" << endl;

			int a = 1;
			while (a != 3){
				cout << "your choice = "; cin >> a;
				switch (a){
				case 1:
					i = 1;
					cout << setw(40) << "users:" << endl;
					while (file.read((char *)&u, sizeof(u))){
						cout << setw(10) << i;
						u.display();
						i++;
					}
					file.close();
					file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
					file.seekg(0, ios::beg);
					file.clear();
					break;
				case 2:
					deleteUser();
					file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
					file.seekg(0, ios::beg);
					file.clear();
					break;
				case 3:
					exit(0);
					break;
				default:
					cout << "invalid choice" << endl;
					break;
				}

			}
		}
		else{
			cout << "incorrect password" << endl;
		}

	}

};

class MainMenu :public Register{
protected:
	int n;
	Register R;

public:
	void menu(){
		cout << ".*. Already have account?	1. Login" << endl;
		cout << ".*. Don't have account?		2. Register now" << endl;
		cout << ".*. Login as an administrator	3. Admin" << endl;
		cout << ".*. 4. EXIT" << endl;
		cout << "your choice = "; 	cin >> n;

		switch (n)
		{
		case 1:
			R.login();
			break;
		case 2:
			R.registration();
			cout << "Login now" << endl;
			R.login();
			break;
		case 3:
			R.admin();
			break;
		case 4:
			exit(0);
		default: cout << "invalid input" << endl;
			break;
		}

	}

};

