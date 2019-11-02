#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdlib.h> 
#include <Windows.h>
using namespace std;
class users{
	char username[30];
	char password[10];
public:
	void setdata(){
		cout << setw(20) << "Username: "; cin >> username;
		cout << setw(20) << "Password: "; cin >> password;
		cout << endl;
	}

	void display(){
		cout << ".*. Username: " << username << setw(20);
		cout << "\tPassword: " << password << endl;
	}

	char* getname()    { return username; } 
	char* getpassword(){ return password; }
};

class Register:public users{
protected:
	users u;
	fstream file;
	bool check = 0;
	char temp_username[30];
	char temp_password[10];

public:
	void registration(){
		file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
		file.seekg(0, ios::beg); 	file.clear();
		cout << setw(30) << "Registration Page\n" << endl;
			u.setdata(); 
			file.write((char *)&u, sizeof(u));
		cout << "You have successfully registered. \nThank you for registration!" << endl;
		file.close();
	}

	bool login(){
		file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
		file.seekg(0, ios::beg); 	file.clear();
		
		cout << setw(30) << "Login Page\n" << endl;
		cout << setw(20) << "Username: ";	 cin >> temp_username;
		cout << setw(20) << "Password: ";	 cin >> temp_password;
		
		while (file.read((char *)&u, sizeof(u))){
			if (strcmp(u.getname(), temp_username) == 0){
				check = 1;
				if (strcmp(u.getpassword(), temp_password) == 0){
					
					if (strcmp(u.getname(), "admin")==0){
						file.seekg(0, ios::beg); file.clear();
						cout << setw(20) << "users:" << endl;
						while (file.read((char *)&u, sizeof(u))){
							u.display();
						}
						file.close();
						return true;
					}
					else{
						cout << "welcome " << u.getname() << endl;
						return true;
					}
				}
				else{
					cout << "incorrect password" << endl;
					break; 	return false;
				}
			}
		}

		if (check == 0){
			cout << "No account with this username" << endl;
			return false;
		}
		file.close();
	}
	
	void deleteUser(){
		fstream temp_file("temp_file.txt", ios::app | ios::out | ios::in | ios::ate);
		file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
		file.seekg(0, ios::beg); 		file.clear();
		cout << "enter a username of a user to be deleted: "; cin >> temp_username;

		while (file.read((char *)&u, sizeof(u))){
			if (strcmp(u.getname(), temp_username) != 0){
				temp_file.write((char*)&u, sizeof(u));
			}
		}
		file.close();				temp_file.close();
		remove("users.txt");		rename("temp_file.txt", "users.txt");
		cout << "user has been successfully deleted!" << endl;
	}

	void admin(){
		cout << "\t ---------- Admin Page ----------" << endl;
		cout << "enter your password [Hint: the same as username]" << endl;
		cout << "\n\t.*. password = ";		cin >> temp_password;	cout << endl;
		int i=1;
		if (strcmp(temp_password, "admin") == 0){
			file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
			file.seekg(0, ios::beg);		file.clear();
			cout <<"\t.*. 1. Display users" << endl;
			cout <<"\t.*. 2. Delete a user" << endl;
			cout <<"\t.*. 3. Go to main menu" << endl;
			file.seekg(0, ios::beg);		file.clear();
			int a = 1;
			while (a != 3){
				cout << "[admin] your choice = "; cin >> a;
				switch (a){
					case 1:
						i = 1;		cout << setw(40) << "users:" << endl;
						while (file.read((char *)&u, sizeof(u))){
							cout << setw(10) << i; 
							u.display(); 	i++;
						}

						file.close();
						file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
						file.seekg(0, ios::beg);	file.clear(); 	break;
					case 2:
						deleteUser();
						file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
						file.seekg(0, ios::beg);	file.clear();	break;
					case 3:
						cout << "you have left admin page" << endl; break;
					default: cout << "invalid choice" << endl;		break;
						}
				}
			}
			else{	cout << "incorrect password" << endl; 	}
	}

};

class MainMenu:public Register{
protected:
	int n, value=1;
	Register R;

public:
	void menu(){
		while (value){
			cout << "\t\t\tMain Menu" << endl;
			cout << ".*. Already have account?	1. Login" << endl;
			cout << ".*. Don't have account?		2. Register now" << endl;
			cout << ".*. Login as an administrator	3. Admin" << endl;
			cout << ".*. Do you wanna leave?		4. EXIT" << endl;
			cout << "your choice = "; 	cin >> n;

			switch (n)
			{
				case 1:
					system("cls");
					if (R.login()){
						cout << "\tenter 0 to buy a ticket\n\t1 to go to main menu \nvalue = "; cin >> value;
					}
					else{
						cout << "\tenter 1 to go to main menu \nvalue = ";		cin >> value;
					}
					system("cls"); 	break;
				case 2:
					system("cls"); 	R.registration();
					cout << "\tenter 0 to buy a ticket\n\t1 to go to main menu \nvalue = "; cin >> value;
					if (!value){
						cout << "Login now" << endl;
						R.login();
					}
					system("cls");	break;
				case 3:
					system("cls");	R.admin();
					system("cls"); 	break;
				case 4:
					exit(0);		break;
				default: cout << "invalid input" << endl; 	break;
			}
		}
	}

};

