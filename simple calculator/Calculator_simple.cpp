//Calculator//
#include <iostream>
#include <cmath>
using namespace std;

void calcAdd();
void calcAdd2();
//void calcSub();
//void calcMtp();

int main(){
	int choice;
	
	cout << "Calculator HAHAHAHA\n" << endl;
	
	cout << "Choose operation :" << endl;
	cout << "\t1. Addition (+)" << endl;
	cout << "\t2. Substraction (-)" << endl;
	cout << "\t3. Multiplication (x)" << endl;
	cout << "\t4. Division (/)" << endl;
	cout << "\t5. Find remainder (%)" << endl;
	cout << "\t6. Power (^)" << endl;
	
	cout << "Your choice: " ;
	cin >> choice;
	system("cls");
	
	switch (choice){
		case 1: calcAdd2();break;
		default: cout << "Invalid!" << endl;
	}
	
	return 0;
}

void calcAdd(){
	double firstNum, secondNum;
	cout << "This operation will add two number:" << endl << endl; //next time buat user boleh pilih brp number dy nk. Boleh guna array
	cout << "\tEnter first number: ";
	cin >> firstNum;
	cout << "\tEnter second number: ";
	cin >> secondNum;
	
	cout << "\n\tThe answer of " << firstNum << " + " << secondNum << " is " << firstNum+secondNum << endl;
}

void calcAdd2(){
	int size;
	cout << "How many numbers you want to add? :";
	cin >> size;
	double sum;
	double num[size];
	for (int i = 0; i < size; i++){
		cout << "\tEnter num " << i+1 << " : " ;
		cin >> num[i];
		sum += num[i];
	}
	cout << "\n\tThe answer of ";
	for (int i = 0; i < size; i++){
		cout << num[i] ;
		while (i < size - 1){
			cout << " + ";
			break; //letak (+) symbol
		}
	}
	cout << " is " << sum;
}
