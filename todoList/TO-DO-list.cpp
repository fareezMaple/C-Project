//TO-DO-LIST
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;
void setColor(int);
void addNewList(fstream&);
void showLists(fstream&);
int countItems(fstream&);
void glanceMessage(int);
bool exitFunc();
void deleteNotes(fstream&);
void searchTags(fstream&);
void archiMessage(fstream&, fstream&);

int main(){
	bool respond;
	fstream todoList;
	fstream archi;
	int respond_input;
	do{
		system("cls");
		setColor(15);
		cout << "============Your awesome TODO list buddy==================" << endl;
		cout << "\n";
		glanceMessage(countItems(todoList));
		cout << "Options:" << endl;
		cout << "\t1. Add new to do lists" << endl;
		cout << "\t2. View all your to do lists" << endl;
		cout << "\t3. Search by tags..." << endl;
		cout << "\t4. Delete message..." << endl;
		cout << "\t5. Archieve message..." << endl;
		cout << "\t6. Exit program..." << endl;
		
//		cin.ignore(respond_input);
		setColor(14);
		cout << "\nPlease enter your choice (1-6) and press ENTER: \n> ";
		setColor(11);
		cin >> respond_input; //nnti buat re-enter
		
		while(respond_input < 1 || respond_input > 6){
			setColor(12);
			cout << "Your input is invalid!\nPlease re-enter\n> ";
			setColor(11);
			cin >> respond_input;
		}
		setColor(15);
		switch (respond_input){
			case 1: addNewList(todoList); break;
			case 2: showLists(todoList); break;
			case 3: searchTags(todoList); break;
			case 4: deleteNotes(todoList); break;
			case 5: archiMessage(todoList, archi); break;
			default: if (exitFunc()){
				return 0;
			};break;
		}
	} while(true);
}

void addNewList(fstream& data){
	int response;
	bool writeNotes = true;
	setColor(15);
	system("cls");
	string message;
	string tags;
	cout << "-----------------Add New List--------------------" << endl;
	data.open("ToDoListUserData.txt", ios::out | ios::app);
//	cout << "\tAdd items no. " << toDoItems() << endl;
	setColor(14);
	cout << "Write your notes below. (Enter digit '0' to cancel and return to main menu).\n> ";
	setColor(11);
	cin.ignore(); //??
	getline(cin, message); //get line including whitespace

	if (message == "0"){
		setColor(12);
		cout << "No message added." << endl << endl;
		writeNotes = false; //if user enter 0, skip function below
	}
		
	if (writeNotes){
		setColor(14);
		cout << "\tAdd tags to your notes: " << endl;
		cout << "\t1. Urgent!  2. Important!  3. Bussiness  4. Personal  5. Others" << endl; //add tags to notes
		cout << "> ";
		setColor(11);
		cin >> response;
		while (response < 1 || response > 5){
			setColor(12);
			cout << "Please re-enter valid choice (1-4)\n> ";
			setColor(11);
			cin >> response;
		}
		switch(response){
			case 1: tags = "Urgent!"; break;
			case 2: tags = "Important!"; break;
			case 3: tags = "Bussiness"; break;
			case 4: tags = "Personal"; break;
			default: tags = "Others"; break;
		}
		data << message << '$' << tags << endl;
		setColor(10);
		cout << "Notes successfully saved\n\n";
	}
	data.close();
	setColor(15);
	system("pause");
}

bool exitFunc(){
	char respond;
	system("cls");
	setColor(14);
	cout << "Are you sure you want to quit? (Y/N)\n> ";
	setColor(11);
	cin >> respond;
	system("cls");
	setColor(9);
	
	switch (respond){
		case 'y': case 'Y': cout << "*****************************\n*******   Goodbye   *********\n*****************************" << endl << endl; return true;break;
		case 'n': case 'N': cout << "Returning to main menu..." << endl << endl; return false; break;
	}
	
}

void setColor(int value){ //warna2 kehidupan
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}
void showLists(fstream& data){
	system("cls");
	char respond;
	int imCount, BusCount, persCount, OthCount, UrgeCount;
	imCount = BusCount = persCount = OthCount = UrgeCount = 0;
	int size = countItems(data);
	if (size > 0){
		string arrayNotes[size];
		string arrayTags[size];
		data.open("ToDoListUserData.txt", ios::in);
		if (data){
			int i = 0;
			getline(data, arrayNotes[i], '$');
			getline(data, arrayTags[i], '\n');
			while(data && i < size - 1){
				i++;
				getline(data, arrayNotes[i], '$');
				getline(data, arrayTags[i], '\n');
			}
		}
		cout << "----------Your To-Do Lists----------------" << endl << endl;
		cout << "No.\tYour To-Do\t\t\t\t\t    Tags" << endl;
		for (int i  = 0; i < size; i++){
			setColor(15);
			cout << (i+1) << ".   " << setw(50) << left << arrayNotes[i] << right << internal  << "  ";
			setColor(10);
			cout << arrayTags[i];
			cout << endl;
		}
		setColor(7); //default
		cout << endl << "~~~~~~~End of list~~~~~~~" << endl << endl;
		data.close();
		//tags counter
		for(int j = 0; j < size; j++){
			if(arrayTags[j] == "Urgent!")
				UrgeCount++;
			else if (arrayTags[j] == "Important!")
				imCount++;
			else if (arrayTags[j] == "Bussiness")
				BusCount++;
			else if (arrayTags[j] == "Personal")
				persCount++;
			else
				OthCount++;
		}
		//tukar2 warna dye
		setColor(15);
		cout <<"\tOverall you have ";
		setColor(10);
		cout << UrgeCount;
		setColor(15);
		cout << " Urgent, " ;
		setColor(10);
		cout << imCount;
		setColor(15);
		cout << " Important, ";
		setColor(10);
		cout << BusCount;
		setColor(15);
		cout << " Bussiness, " ;
		setColor(10);
		cout << persCount;
		setColor(15);
		cout << " Personal and ";
		setColor(10);
		cout << OthCount;
		setColor(15);
		cout << " Others." << endl << endl;
		system("pause");
	}
	else{
		setColor(15);
		cout << endl;
		cout << "Nothing to show :(" << endl;
		cout << "\tYour to-do lists is empty :( " << endl;
		setColor(14);
		cout << "\n\tDo you want to add your first item? \n" ;
		setColor(10);
		cout << "\t( [Y]es, please,";
		setColor(12);
		cout << " [N]o, thanks )";
		setColor(11);
		cout << "\n\t> ";
		cin >> respond;
		
		switch(respond){
			case 'Y': case 'y': addNewList(data); break;
			default: break;
	}
	}
}

int countItems(fstream& data){
	int i = 0;
	string temp;
	data.open("ToDoListUserData.txt", ios::in);
	while (getline(data, temp, '\n')){
		i++;
	}
//	cout << i << endl;
	data.close();
	return i;
}

void glanceMessage(int x){
	if (x == 0)
		cout << ":) Add some notes to your list" << endl << endl;
	else if (x == 1)
		cout << "Currently you has " << x << " thing to do!" << endl << endl;
	else
		cout << "Currently you have " << x << " things to do!" << endl << endl;
}

void deleteNotes(fstream& data){
//	copied from showLists(), then modified
	system("cls");	
	setColor(15);
	char respond;
	cout << "--------------Delete message in your list----------------------" << endl;
	cout << "Once deleted, its gone forever. You can also choose 'archieve' feature in main menu\n\n";
	string temp;
	int numNotes;
	int size = countItems(data);
	if (size > 0){
		string arrayNotes[size];
		string arrayTags[size];
		data.open("ToDoListUserData.txt", ios::in);
		if (data){
			int i = 0;
			getline(data, arrayNotes[i], '$');
			getline(data, arrayTags[i], '\n');
			while(data && i < size - 1){
				i++;
				getline(data, arrayNotes[i], '$');
				getline(data, arrayTags[i], '\n');
			}
		
		}
		data.close();
		cout << "Below shown a glance from your current To-Do Lists" << endl << endl;
		cout << "No. \tYour To-Do" << endl;
		for (int i  = 0; i < size; i++){
			temp = arrayNotes[i];
			if (temp.size() < 20){
				setColor(14);
				cout << (i+1) << ".  ";
				setColor(15);
				cout << temp << endl;
			}
			else{
				setColor(14);
				cout << (i+1) << ".  ";
				setColor(15);
				cout << temp.substr(0,15) << "..." << endl;
			}
		}
		setColor(7);
		cout << endl << "~~~~End of list~~~~" << endl << endl;
		setColor(14);
		cout << "\tEnter which number of notes you want to delete \n\t> ";
		setColor(11);
		cin >> numNotes;
		while(numNotes < 1 || numNotes > size){ //check validity
			setColor(12);
			cout << "\tThe number is invalid! Please re-enter valid number from list above\n\t> ";
			setColor(11);
			cin >> numNotes;
		}
		setColor(15);
		cout << "Notes choosen : " ;
		setColor(10);
		cout << numNotes << endl;
		setColor(14);
		cout << "Are you sure you want to proceed? Your chosen message will deleted and no way to recover it! (Y/N)\n> ";
		setColor(11);
		cin >> respond;
		
		switch (respond){
			case 'y': case 'Y': setColor(12); cout << "Deleting message..." << endl;
			data.open("ToDoListUserData.txt", ios::out);
			for(int i = 0; i < size; i++){
				if (i != numNotes  -1){
					data << arrayNotes[i] << '$' << arrayTags[i] << endl;
				}
				else{
					continue;
				}
			}
			setColor(10);
			cout << "Message successfully deleled." << endl << endl;
			data.close();
			case 'n': case 'N': ;break;
		}
	}
	else{
		setColor(12);
		cout << "\n- - - NO ITEM IN YOUR LIST - - -\n\n";
	}
	setColor(7);
	system("pause");
}

void searchTags(fstream& data){
	system("cls");
	char respond;
	int choice, c=0;
	string tags;
	int size = countItems(data);
	if (size > 0){
		string arrayNotes[size];
		string arrayTags[size];
		data.open("ToDoListUserData.txt", ios::in);
		if (data){
			int i = 0;
			getline(data, arrayNotes[i], '$');
			getline(data, arrayTags[i], '\n');
			while(data && i < size - 1){
				i++;
				getline(data, arrayNotes[i], '$');
				getline(data, arrayTags[i], '\n');
			}
		}
		setColor(15);
		cout << "--------------Search by tags----------------------" << endl;
		cout << "\nSelect tags you want to search:" << endl;
		setColor(14);
		cout << "\t1. Urgent!\n\t2. Important!\n\t3. Bussiness\n\t4. Personal\n\t5. Others" << endl;
		cout << "\nEnter your choice: (1-5)\n\t> ";
		setColor(11);
		cin >> choice;
		
		while(choice < 1 || choice > 5){
			setColor(12);
			cout << "\tYour entered choice is out of range" << endl;
			cout << "\t Re-enter again\n\t> ";
			setColor(11);
			cin >> choice;
		}
		switch(choice){
			case 1: tags = "Urgent!"; break;
			case 2: tags = "Important!"; break;
			case 3: tags = "Bussiness"; break;
			case 4: tags = "Personal"; break;
			default: tags = "Others"; break;
		}
		setColor(15);
		cout << "\n---------- " << tags << "----------------" << endl << endl;
		cout << "No.\t    Your To-Do" << endl;
		for (int i  = 0; i < size; i++){
			if (arrayTags[i] == tags){
				cout << (++c) << ".   " << setw(50) << left << arrayNotes[i];
				cout << endl;
			}
		}
		if (c == 0){
			cout << "\n\t-Sorry. Didn't find any message tagged with ";
			setColor(10);
			cout << "'" << tags << "'";
			setColor(15);
			cout << "." << endl << endl;
		}
		else
			cout << endl << "~~~~~~~End of list~~~~~~~" << endl << endl;
		
		data.close();
		system("pause");
	}
	else{
		setColor(15);
		cout << endl;
		cout << "Nothing to show :(" << endl;
		cout << "\tYour to-do lists is empty :( " << endl;
		setColor(14);
		cout << "\n\tDo you want to add your first item? \n" ;
		setColor(10);
		cout << "\t( [Y]es, please,";
		setColor(12);
		cout << " [N]o, thanks )";
		setColor(11);
		cout << "\n\t> ";
		cin >> respond;
		
		switch(respond){
			case 'Y': case 'y': addNewList(data); break;
			default: break;
	}
	}
}

void archiMessage(fstream& data, fstream& archi){
	system("cls");	
	setColor(15);
	char respond;
	cout << "--------------Move to archieve----------------------" << endl;
	cout << "Message from your main list will be move to text file in your hard disk.\n";
	cout << "To permanently remove your message, choose 'Delete' feature in main menu instead\n\n";
	string temp;
	int numNotes;
	int size = countItems(data);
	if (size > 0){
		string arrayNotes[size];
		string arrayTags[size];
		data.open("ToDoListUserData.txt", ios::in);
		if (data){
			int i = 0;
			getline(data, arrayNotes[i], '$');
			getline(data, arrayTags[i], '\n');
			while(data && i < size - 1){
				i++;
				getline(data, arrayNotes[i], '$');
				getline(data, arrayTags[i], '\n');
			}
		
		}
		data.close();
		cout << "Below shown a glance from your current To-Do Lists" << endl << endl;
		cout << "No. \tYour To-Do" << endl;
		for (int i  = 0; i < size; i++){
			temp = arrayNotes[i];
			if (temp.size() < 20){
				setColor(14);
				cout << (i+1) << ".  ";
				setColor(15);
				cout << temp << endl;
			}
			else{
				setColor(14);
				cout << (i+1) << ".  ";
				setColor(15);
				cout << temp.substr(0,15) << "..." << endl;
			}
		}
		setColor(7);
		cout << endl << "~~~~End of list~~~~" << endl << endl;
		setColor(14);
		cout << "\tEnter which number of notes you want to archieve \n\t> ";
		setColor(11);
		cin >> numNotes;
		while(numNotes < 1 || numNotes > size){ //check validity
			setColor(12);
			cout << "\tThe number is invalid! Please re-enter valid number from list above\n\t> ";
			setColor(11);
			cin >> numNotes;
		}
		setColor(15);
		cout << "Notes choosen : " ;
		setColor(10);
		cout << numNotes << endl;
		setColor(14);
		cout << "Are you sure you want to proceed? (Y/N)\n> ";
		setColor(11);
		cin >> respond;
		
		switch (respond){
			case 'y': case 'Y': setColor(12); cout << "Archieving message..." << endl;
			data.open("ToDoListUserData.txt", ios::out);
			archi.open("ArchievedUserMessageData.txt", ios::out | ios::app);
			for(int i = 0; i < size; i++){
				if (i != numNotes  -1){
					data << arrayNotes[i] << '$' << arrayTags[i] << endl;
				}
				else{
					//archieve file txt
					archi << "--> '" << arrayNotes[numNotes - 1] << "' , tags:" << arrayTags[numNotes - 1] << endl;
				}
				
			}
			setColor(10);
			cout << "Message successfully archieved." << endl;
			cout << "Your archieves message will be available on 'Archieved messages.txt'." << endl << endl;
			data.close();
			archi.close();
			case 'n': case 'N': ;break;
		}
	}
	else{
		setColor(12);
		cout << "\n- - - NO ITEM IN YOUR LIST - - -\n\n";
	}
	setColor(7);
	system("pause");
}