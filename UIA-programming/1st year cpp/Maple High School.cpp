#include <iostream>
#include <string>
#include <fstream> //file
#include <iomanip> //setw
#include <windows.h> //bunyi beep

using namespace std;
const int ROW = 20;

void AddNew(fstream& data);
void SetColor(int);
void ViewStatus(fstream& data, int);
void read(fstream& data, int&);
void payFee(fstream& data, int);
int search(int[]);
void deleteRecord(fstream& data, int);

struct info {
	string name[ROW];
	int matno[ROW];
	string course[ROW];
	double fee[ROW];
	double notPaid[ROW];
	double paid[ROW];
	int bilangan;
};
info student;  //declare struct

int main()
{
	int choice = 0;
	fstream data;


	do
	{

		system("cls");
		cout << "Welcome To The Maple High School Finance Website" << endl;
		cout << "__________________________________________________" << endl;
		cout << "__________________________________________________" << endl;

		cout << "PLEASE SELECT THE OPTION BELOW" << endl;
		cout << "1. Registration" << endl;
		cout << "2. View Financial Statement" << endl;
		cout << "3. Make Payment " << endl;
		cout << "4. Delete record" << endl;
		cout << "5. Exit " << endl;

		cout << endl << "Input your Choice : " << endl;
		SetColor(11);
		cin >> choice;
		SetColor(7);

		for (choice; choice < 1 || choice > 5;)
		{
			cout << "Invalid.Please enter a valid choice : ";
			SetColor(11);
			cin >> choice;
			SetColor(7);
		}
		switch (choice)
		{
		case 1: AddNew(data); break;
		case 2: read(data, student.bilangan);
			ViewStatus(data, student.bilangan); break;
		case 3: read(data, student.bilangan);
			payFee(data, student.bilangan); break;
		case 4: read(data, student.bilangan);
			deleteRecord(data, student.bilangan); break;
		default: 
			system("cls");
			cout << "*****************************" << endl;
			cout << "*                           *" << endl;
			cout << "*       Thank You :)        *" << endl;
			cout << "*                           *" << endl;
			cout << "*****************************" << endl;
			Sleep(600);
		}

	} while (choice != 5);

	return 0;
}


void AddNew(fstream& data) //addnewname
{
	system("cls");
	cout << "---Add new student data---" << endl << endl;
	data.open("Database.txt", ios::out | ios::app);
	string name[ROW];
	int matricno[ROW], i = 0, select, j;
	double fee[ROW];
	double paid[ROW];
	double notPaid[ROW];
	string course[ROW];
	bool cont = false;
	char respond;


	do
	{
		cin.ignore();
		cout << "Please enter your name : ";
		SetColor(11);
		getline(cin, name[i]);
		SetColor(7);
		cout << endl;

		cout << "Please enter your matric number : ";
		SetColor(11);
		cin >> matricno[i];
		SetColor(7);
		cout << endl;

		cout << " Please select your course " << endl;
		cout << "  1. Engine (Fee = RM 2000) " << endl;
		cout << "  2. Law (Fee = RM 2500) " << endl;
		cout << "  3. Econs (Fee = RM 1500) " << endl;
		cout << "  4. ICT (Fee = RM 1000) " << endl;
		cout << "  5. Medic (Fee = RM 3000) " << endl;
		cout << "  6. Education (Fee = RM 2600) " << endl;

		SetColor(11);
		cin >> select;
		SetColor(7);
		while (select < 1 || select > 6)
		{
			cout << "The course that you entered does not exist! Please re-enter : " << endl;
			cout << " 1. Engine" << endl;
			cout << " 2. Law" << endl;
			cout << " 3. Econs" << endl;
			cout << " 4. Ict" << endl;
			cout << " 5. Medic" << endl;
			cout << " 6. Education" << endl;
			SetColor(11);
			cin >> select;
			SetColor(7);
		}

		if (select == 1) {

			fee[i] = 2000;
			course[i] = "Engin";
		}
		else if (select == 2) {

			fee[i] = 2500;
			course[i] = "Law";
		}
		else if (select == 3) {

			fee[i] = 2500;
			course[i] = "Econs";
		}
		else if (select == 4){

			fee[i] = 1000;
			course[i] = "ICT";
		}
		else if (select == 5){

			fee[i] = 3000;
			course[i] = "Medic";
		}
		else{

			fee[i] = 2600;
			course[i] = "Edu";
		}

		paid[i] = 0;
		notPaid[i] = fee[i] - paid[i];
		i++;

		cout << "Do you wish to add another student ? (Y/N)" << endl;
		SetColor(11);
		cin >> respond;
		SetColor(7);

		switch (respond)
		{
		case 'y':
		case 'Y': cont = true; break;
		case 'n':
		case 'N' or 'n': cont = false; break;
		}

	} while (cont && (i < ROW));

	j = i;



	for (i = 0; i < j; i++)
	{
		data << name[i] << '$' << matricno[i] << " " << course[i] << " " << fee[i] << " " << paid[i] << " " << notPaid[i] << endl;
	}
	SetColor(10);
	cout << "Data Successfully Recorded " << endl;
	SetColor(7);
	system("pause");
	data.close();

}

void read(fstream& data, int& totalist) {  //read from file
	data.open("Database.txt", ios::in);
	system("cls");
	string name[ROW];
	int matno[ROW];
	double fee[ROW];
	string course[ROW];

	int i = 0;

	getline(data, student.name[i], '$');
	data >> student.matno[i] >> student.course[i] >> student.fee[i] >> student.paid[i] >> student.notPaid[i];

	while (data) {
		i++;
		data.ignore();
		getline(data, student.name[i], '$');
		data >> student.matno[i] >> student.course[i] >> student.fee[i] >> student.paid[i] >> student.notPaid[i];
	}
	totalist = i;
	data.close();
}

void ViewStatus(fstream& data, int i) { //financial statement

	cout << "---Financial status for all students---" << endl << endl;
	cout << setprecision(2) << showpoint << fixed;
	cout << setw(15) << "Name" << setw(23) << "Matric Number" << setw(13) << "Course" << setw(15) << "Fee" << setw(19) << "Amount Paid" << setw(19) << "\tAmount Not Paid" << endl;
	for (int j = 0; j < i; j++) { //print
		cout << endl;
		cout << (j + 1) << ". ";
		cout << setw(23) << left << student.name[j] << setw(15) << left << student.matno[j] << setw(13) << left << student.course[j] ;
		SetColor(11);
		cout << "RM " << setw(14) << left << student.fee[j];
		SetColor(10);
		cout << "RM " << setw(18) << left << student.paid[j];
		SetColor(12);
		cout<<  "RM " << setw(13) << left << student.notPaid[j];
		SetColor(7);
	}
	cout << endl;
	SetColor(9);
	cout << "\n-------------------------------------------------END OF THE LIST--------------------------------------------" << endl << endl;
	SetColor(7);
	system("pause");
}


void payFee(fstream& data, int j) {
	data.open("Database.txt", ios::out); //rewrite the file
	double payment;
	cout << "----Make Payment----\n" << endl;
	int pos = search(student.matno);

	if (pos > -1) {
		cout << "Initiating payment for student...\n" << endl;
		cout << "\tName: " << student.name[pos] << endl;
		cout << "\tCourse: " << student.course[pos] << endl << endl;
		cout << setprecision(2) << showpoint << fixed;
		cout << "Total fee:       RM " << student.fee[pos] << endl;
		cout << "Outstanding fee: ";
		SetColor(12);
		cout << "RM " << student.notPaid[pos] << endl;
		SetColor(14);
		cout << "Amount to pay?:  RM ";
		cin >> payment;
		SetColor(7);

		while ((payment > student.notPaid[pos]) || (payment < 0)) { //reject nilai terlebih or negative
			SetColor(12);
			cout << "\nError! " << endl;
			if (payment > student.notPaid[pos]){
				cout << "The amount you entered is higher than the amount you need to pay." << endl;
			}
			else
				cout << "You entered a negative value! Only a positive number can be accepted." << endl;
			SetColor(14);
			cout << "\nPlease re-enter amount: ";
			cin >> payment;
			SetColor(7);
		}
		
		char respond;
		cout << endl <<"You have entered RM " << payment << "\tConfirm? (Y/N)";
		SetColor(11);
		cin >> respond;
		SetColor(7);
		switch (respond) {
		case 'Y':
		case 'y':
			student.paid[pos] = student.paid[pos] + payment;
			student.notPaid[pos] = student.notPaid[pos] - payment;
			Beep(500,500);
			SetColor(10);
			cout << "\nPayment successfully recorded" << endl << endl; 
			SetColor(7);
			break;
		case 'n':
		case 'N': 
				Beep(800,510);
				SetColor(12);
				cout << "Payment cancelled." << endl; 
				SetColor(7);
				break;
		}
	}
	
	else{
		Beep(310, 660);
		SetColor(12);
		cout << "\nSorry. Matric number entered not matching with any students." << endl << endl;
		SetColor(7);
	}

	for (int i = 0; i < j; i++)
	{
		data << student.name[i] << '$' << student.matno[i] << " " << student.course[i] << " " << student.fee[i] << " " << student.paid[i] << " " << student.notPaid[i] << endl;
	}

	system("pause");
	data.close();
}

int search(int arrayMatricNum[]) { //return position of array
	int index = 0;
	int position = -1;
	bool found = false;
	int value;

	cout << "Please enter matric number of the student: ";
	SetColor(11);
	cin >> value;
	SetColor(7);
	while (index < ROW && !found) {
		if (arrayMatricNum[index] == value) {
			found = true;
			position = index;
			cout << "Record found!\n" << endl;
		}
		index++;
	}
	return position;
}

void deleteRecord(fstream& data, int z) {
	cout << "---Delete student record from the system---" << endl << endl;
	cout << "Note: This is applicable to student that had complete \n      their fee payment" << endl << endl;
	char respond;
	int pos = search(student.matno);

	if (pos > -1) {
		cout << endl;
		cout << "\tName: " << student.name[pos] << endl;
		cout << "\tCourse: " << student.course[pos] << endl << endl;

		if (student.notPaid[pos] == 0) {
			cout << "This student has pay full fees" << endl;
			cout << "Confirm to delete this student record? (Y/N): ";
			SetColor(11);
			cin >> respond;
			SetColor(7);
			switch (respond) {
			case 'Y': case 'y': {
				data.open("Database.txt", ios::out); //rewrite the file without satu array
				for (int i = 0; i < z; i++)
				{
					if (i != pos) {
						data << student.name[i] << '$' << student.matno[i] << " " << student.course[i] << " " << student.fee[i] << " " << student.paid[i] << " " << student.notPaid[i] << endl;
					}
					else
						continue;	//<- debugging
				}
				Beep(2000,350);
				SetColor(10);
				cout << "\nSuccess.\nRecord deleted." << endl;
				SetColor(7);
				data.close();
				student.bilangan = student.bilangan - 1; //tolak total students tu
			}break;

			case 'N': case 'n': 
				SetColor(12);
				Beep(450, 600);
				cout << "Operation cancelled." << endl;
				SetColor(7);
				break;
			}
		}
		else {
			SetColor(12);
			cout << "Cannot delete student data" << endl;
			Beep(310, 660);
			cout << "This student still has outstanding fees. (RM "<< student.notPaid[pos] << " )" << endl;
			SetColor(7);
		}

	}
	else {
		cout << endl;
		SetColor(12);
		Beep(310, 660);
		cout << "Sorry. Matric number entered not matching with any students." << endl;
		SetColor(7);
	}

	cout << endl;
	system("pause");
}

void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

/*
changelog:
-ltk colour
-takboleh bayar negative value
-Letak brp jumlah yg perlu dibayar lg dlm delete record
-SIZE tukar jdi ROW (sbb conflict "windows.h")
-bunyi beep
*/
