//#include <iostream>
//#include <string>
//#include <iomanip>
//#include <Windows.h>
//#include "Admin1.h"
//using namespace std;
//
//class Person:public MainMenu{
////protected:
////	static int coach, place;
////	string lastname, firstname;
////	string day, month, year;
////	char gender;
//public:
//	//void setname(){
//	//	file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
//	//	file.seekg(0, ios::beg);
//	//	file.clear();
//	//	while (file.read((char *)&u, sizeof(u))){
//	//		if (R.login()){
//	//			firstname = u.getFirstname();
//	//			lastname = u.getLastname();
//	//			gender = u.getGender();
//	//		}
//	//	}
//	//	file.close();
//	//}
//
//	void getname(){
//		file.open("users.txt", ios::app | ios::out | ios::in | ios::ate);
//		file.seekg(0, ios::beg);
//		file.clear();
//		cout << R.login1() << endl;
//		while (file.read((char *)&u, sizeof(u))){
//			if (strcmp(u.getname(), temp_username) == 0){
//				//cout << firstname << " " << lastname << setw(30 - firstname.length() - lastname.length());
//				u.getFullname();
//			}
//		}
//		file.close();
//	}
//	char getGender(){
//		return gender;
//	}
//
//	void setbirthday(){
//		cout << "enter birthday details: " << endl;
//		cout << "day: "; cin >> day;
//		cout << "month: "; cin >> month;
//		cout << "year: "; cin >> year;
//	}
//
//	void getbirthday(){
//		cout << day << "/" << month << "/" << year << setw(17 - (day.length() + month.length() + year.length())) << " |" << endl;
//	}
//
//	int getcoach(){
//		return coach;
//	}
//
//	int getplace(){
//		return place;
//	}
//};
//
////int Person::coach = 1;
////int Person::place = 0;
//
//class Ticket{
//protected:
//	double seat_coach;
//	double reserved_coach;
//	double compartment;
//	string day;
//	int chosen_date = 1;
//	int n, c, p;
//	string status;
//	double cost;
//
//public:
//	int setdate(){
//		int i, j;
//		int d = 1;
//		cout << "\n\tMo Tu We Th Fr Sa Su" << endl;
//		for (i = 0; i < 5; i++){
//			cout << setw(10);
//			for (j = 0; j < 7; j++){
//				if (j == 0 && i == 0)
//					cout << setw(12);
//				else
//				if (d>31)
//					continue;
//				else{
//					cout << d << " ";
//					d++;
//				}
//				if (d < 10){
//					cout << " ";
//				}
//			}
//			cout << endl << "\t--------------------" << endl;
//		}
//		cout << "\nMonth: MAY\t  Year: 2018" << endl;
//		cout << "Please enter date [from 1 to 31]\nDate = ";
//		cin >> chosen_date;
//		cout << "--------------------------------------------------------------------------\n";
//		return chosen_date;
//	}
//
//};
//
//class Nukus :public Ticket{
//public:
//	void costN(){
//		seat_coach = 70119;
//		reserved_coach = 111189;
//		compartment = 170951;
//		day = "[thu] [sun]";
//		cout << setw(15) << seat_coach << setw(15) << reserved_coach << setw(16) << compartment << setw(19) << day << endl;
//	}
//
//	double menu_Nukus(){
//		cout << "\t\t NUKUS" << endl;
//		cout << "available days are: Thursday and Sunday" << endl;
//		chosen_date = setdate();
//		cout << "\n\t1. seat\n\t2. reserved\n\t3. compartment" << endl;
//		cout << "choose your coach type = ";
//		cin >> c;
//		switch (c)
//		{
//		case 1:
//			cost = getNseat();
//			break;
//		case 2:
//			cost = getNres();
//			break;
//		case 3:
//			cost = getNcom();
//			break;
//		default: cout << "this coach type isn't available" << endl;
//			break;
//		}
//		return cost;
//	}
//
//	double getNseat(){
//		return seat_coach;
//	}
//	double getNres(){
//		return reserved_coach;
//	}
//
//	double getNcom(){
//		return compartment;
//	}
//
//	int getNdate(){
//		return chosen_date;
//	}
//};
//
//class Samarkand :public Ticket{
//public:
//	void costS(){
//		seat_coach = 42275;
//		reserved_coach = NULL;
//		compartment = 161150;
//		day = "[fri] [sat] [sun]";
//		cout << setw(11) << seat_coach << setw(13) << reserved_coach << setw(18) << compartment << setw(25) << day << endl;
//	}
//
//	double menu_Samarkand(){
//		cout << "\t\t Samarkand" << endl;
//		cout << "available days are: Friday, Saturday and Sunday" << endl;
//		chosen_date = setdate();
//		cout << "1. seat\n2. compartment" << endl;
//		cout << "choose your coach type = ";
//		cin >> c;
//		switch (c)
//		{
//		case 1:
//			cost = getSseat();
//			break;
//		case 2:
//			cost = getScom();
//			break;
//		default: cout << "this coach type isn't available" << endl;
//			break;
//		}
//		return cost;
//	}
//	double getSseat(){
//		return seat_coach;
//	}
//
//	double getScom(){
//		return compartment;
//	}
//	int getSdate(){
//		return chosen_date;
//	}
//
//};
//
//class Bukhara :public Ticket{
//public:
//	void costB(){
//		seat_coach = 62564;
//		reserved_coach = NULL;
//		compartment = 225072;
//		day = "[mon] [wed] [fri] [sat]";
//		cout << setw(13) << seat_coach << setw(13) << reserved_coach << setw(18) << compartment << setw(31) << day << endl;
//	}
//
//	double menu_Bukhara(){
//		cout << "\t\t Bukhara" << endl;
//		cout << "available days are: Monday, Wednesday, Friday, Saturday" << endl;
//		chosen_date = setdate();
//		cout << "1. seat\n2. compartment" << endl;
//		cout << "choose your coach type = ";
//		cin >> c;
//		switch (c)
//		{
//		case 1:
//			cost = getBseat();
//			break;
//		case 2:
//			cost = getBcom();
//			break;
//		default: cout << "this coach type isn't available" << endl;
//			break;
//		}
//		return cost;
//	}
//
//	double getBseat(){
//		return seat_coach;
//	}
//
//	double getBcom(){
//		return compartment;
//	}
//	int getBdate(){
//		return chosen_date;
//	}
//
//};
//
//
//class City : public virtual Nukus, Samarkand, Bukhara{
//protected:
//	int n, c, p;
//	string status;
//	double cost;
//	int chosen_date;
//public:
//
//	void Citymenu(){
//		cout << "-----------------------------------------------------------------------------------------------------" << endl;
//		cout << "[menu]" << "\t  city" << setw(25) << "seat_coach" << setw(17) << "reserved_coach" << setw(15) << "compartment" << setw(15) << "day" << endl;
//		cout << "-----------------------------------------------------------------------------------------------------" << endl;
//
//		cout << "[ 1  ] Tashkent->Nukus"; costN();
//		cout << "[ 2  ] Tashkent->Samarkand"; costS();
//		cout << "[ 3  ] Tashkent->Bukhara"; costB();
//		cout << "-----------------------------------------------------------------------------------------------------" << endl;
//	}
//	void TicketBooking(){
//		cout << "\tchoose your destination from menu \n\tenter number = "; cin >> n;
//
//		switch (n){
//		case 1:
//			cost = menu_Nukus();
//			chosen_date = getNdate();
//			break;
//		case 2:
//			cost = menu_Samarkand();
//			chosen_date = getSdate();
//			break;
//		case 3:
//			cost = menu_Bukhara();
//			chosen_date = getBdate();
//			break;
//		default: cout << "this destination is not availbale" << endl;
//			break;
//		}
//		cout << "your ticket costs = " << cost << endl;
//		setStatus();
//	}
//
//	void setStatus(){
//		cout << "------------------------------------------------------------" << endl;
//		cout << "Please tel me if you have any privilege to get discount" << endl;
//		cout << "\n\t1. student \n\t2. pensioner\n\t3. none" << endl;
//		cout << "------------------------------------------------------------" << endl;
//
//		cout << "\tchoose your privilege status from menu \n\tenter number = "; cin >> p;
//		if (p == 1){
//			cost = cost * 0.4;
//			status = "Student";
//		}
//		if (p == 2){
//			cost = cost * 0.6;
//			status = "Pensioner";
//		}
//		if (p == 3){
//			status = "none";
//		}
//	}
//
//	string getStatus(){
//		return status;
//	}
//
//	double Ticketcost(){
//		return cost;
//	}
//
//	void cityName(){
//		if (n == 1){
//			cout << "Tashkent -> Nukus" << setw(13);
//		}
//		if (n == 2){
//			cout << "Tashkent -> Samarkand" << setw(9);
//		}
//		if (n == 3){
//			cout << "Tashkent -> Bukhara" << setw(11);
//		}
//	}
//
//	int getdate(){
//		return chosen_date;
//	}
//};
//
//
//int main(){
//	HWND console = GetConsoleWindow();
//	RECT r;
//	GetWindowRect(console, &r);
//	MoveWindow(console, r.left, r.top, 500, 500, TRUE);
//	system("Color F9");
//	MainMenu m;
//	m.menu();
////	cout << m.validate() << endl;
//	//system("cls");
//	//m.getname();
////	MoveWindow(console, r.left, r.top, 850, 500, TRUE);
////	system("Color F9");
//	Person p1; 
//	//p1.setname();
//	//cout << p1.getGender() << endl;
//	
//	//p1.getname();
////	p1.getbirthday();
//	//	p1.setname();  p1.setbirthday(); 	system("cls");
////
//////	system("Color F9");
////	City c1; //	c1.Citymenu();  c1.TicketBooking(); 	system("cls");
////
//////	MoveWindow(console, r.left, r.top, 710, 300, TRUE);
//////	system("Color 3F");
////	cout << endl;
////	cout << " ---------------------------------------------------------------------------------" << endl;
////
////	cout << " | ";	cout << setw(50) << " UZBEKISTAN RAILWAYS TICKET";							cout << "\t\t\t\t |" << endl;												cout << endl;
////
////	cout << " | ";  cout << "date: " << c1.getdate() << ".05.2018 14:32"; cout << "\tcoach: " << p1.getcoach();		cout << "\tprivilege: " << c1.getStatus() << "\t\t |" << endl;				cout << endl;
////
////	cout << " | ";  cout << "city: "; c1.cityName();  cout << "\tplace: " << p1.getplace();		cout << "\tcost: " << c1.Ticketcost() << "+(service)+(sheet)  |" << endl;	cout << endl;
////
////	cout << " | ";  cout << "name: "; p1.getname();	  cout << "\tgender: " << p1.getGender();	cout << "\tdate of birth: "; p1.getbirthday();								cout << endl;
////
////	cout << " | ";  cout << "arrivel time: " << c1.getdate() + 1 << ".05.2018 09:32";			cout << "\t\t\t\t\t\t |" << endl;
////
////	cout << " ---------------------------------------------------------------------------------" << endl;
////
////
//	system("pause");
//	return 0;
//}