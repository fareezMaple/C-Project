#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#define ROWS 30
#define COLS 30
void greetings(void);
void closing(void);
void about(void);
void OutRange(void);
void Colour(unsigned short colour);
void ReturnMenu(void);


int choi,p=0;
char str[20],c=' ';
int DVDCopy[77];
char ch, pass[10],ttlRent[20],ICRent[20];
char DVDgenre[ROWS][COLS], DVDtitle[ROWS][COLS],custName[ROWS][COLS], AddressCust[ROWS][COLS];
int ttlRC=0, ttlCust=0;
char ICcust[ROWS][COLS], FonCust[ROWS][COLS], WhoCust[ROWS][COLS], WhoDVD[ROWS][COLS];
char username[15], password[12]; //passwordnawi

int main()
{	
    int i,j=0;

	/*LOGIN TO THE PROGRAM*/
	for(i=0;i<=2;i++)
	{
		system("cls");
		printf("LOGIN\n");
		printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
		printf("\nEnter your username:\n");
		scanf("%s",username);
		printf("Enter your password:\n");
		
		while (j<=9)
		{
    		str[j]=getch();
    		c=str[j];
    		if(c==13) break;
    		else printf("*");
    		j++;
		}
		str[j]='\0';
		j=0;

		
		if(strcmp(username,"nawi")==0)
		{
		    if(strcmp(str,"1234")==0)
			{		    	
				greetings();
				Colour(7);
		    	break;
		    }
			else
			{
				printf("\nwrong password\n");
				Sleep(444);
			}
		}
		else
		{
			printf("\nUser doesn't exist\n");
			Sleep(592);
		}
	
	}
	
	if (i>2)		//if exceeds more than 2 times, program will be terminated.
	{
		system("cls");
		printf("Too many attempts!");
		Sleep(999);
		printf("\nProgram will be terminate! \n");
		Sleep(900);
		closing();
		return 0;
	}
		
	/*MAIN MENU*/
	
	do //do closing
	{ 
		
	do //main menu
	{
	system("cls");
	printf("DVD RENTAL SHOP\n========Main Menu========\n");
	printf("\t 1. CUSTOMER\n\t 2. DVD\n\t 3. RENTAL\n\t 4. ABOUT\n\t 5. EXIT\n"); //MAIN MENU OF THE PROGRAM
	
	printf("Enter your choice : ");
	scanf("%d", &choi);
	
	
	while((choi<0 || choi>5))
	{
		OutRange();
		scanf("%d", &choi);
	}

	system("cls");
	
	
	/*FIRST MENU*/
	//CUSTOMER MENU	
	
	if (choi == 1)
	//MAIN->CUSTOMERMENU
	{
		printf("DVD RENTAL SHOP\n========Customer Menu========\n");
		printf("\t 1. ADD NEW CUSTOMER\n\t 2. DISPLAY CUSTOMER INFORMATION\n\t 0. MAIN MENU\n\t 5. EXIT\n");
	
		printf("Enter your choice : ");
		scanf("%d", &choi);
	
		while((choi<0 || choi>2) && (choi!=5))
		{
			OutRange();
			scanf("%d", &choi);
		}
		system("cls");
		if(choi==1)
		//MAIN->CUSTOMERMENU->ADD_NEW_CUSTOMER
		{
			char dcs= 'y';
			while (dcs == 'y' || dcs == 'Y')
			{
				fflush(stdin);
				printf("===ADD NEW CUSTOMER===\n"); 
				printf("Customer #%d\n\n", ttlCust+1);
				printf("Customer name: ");	//get customer name
				gets(custName[ttlCust]);
				fflush(stdin);
				printf("IC Number: ");
				scanf("%s", ICcust[ttlCust]);	//get ic number
				fflush(stdin);
				printf("Address: ");
				gets(AddressCust[ttlCust]);	//get address
				fflush(stdin);
				printf("Telephone Number: ");
				scanf("%s", FonCust[ttlCust]);	//get telephone
				
				int sc;
				Colour(6);
				printf("data saving"); //saving animation . . .
				for(sc=0; sc<3; sc++)
				{
					printf(" . ");
					Sleep(500);
				}
				ttlCust=ttlCust+1; //add to TOTAL CUSTOMER
				system("cls");
		
				printf("Record saved!");
				Sleep(720);
				Colour(7);
				
				printf("\nAdd another customer? (y/n):"); //prompt add another?
				scanf(" %c", &dcs);
				system("cls");
				
				if (dcs == 'y' || dcs== 'Y')
					;
				else if (dcs == 'n' || dcs == 'N')
					{
						Colour(7);
						printf("\nReturning to main menu");
						Sleep(499);
						choi=0;
					}
				else if (dcs!='y'||dcs!='Y'||dcs!='n'||dcs!='N')
					{
						printf("Re-enter\n");
						scanf(" %c", &dcs);
						ReturnMenu();
						
					}
								
				Colour(7);	
			}
		}
		else if (choi==2)
		//MAIN->CUSTOMERMENU->DISPLAY_CUSTOMER_INFO
		{
			int xx,yy=0;
			char dcsn2;
			printf("===CUSTOMER INFORMATION===");
			printf("\n\tCustomer name\t\tIC Number\t\tTelephone Number\tAddress\n");
			
			for(xx=0; xx<ttlCust; xx++)
			{
				printf("%d\t%-20s\t%-20s\t%-20s\t%-30s\n",xx+1, custName[xx], ICcust[xx], FonCust[xx], AddressCust[xx]);
				//display name, ic, telephone, address
				
			}
			printf("\n\t---end-of-list---\n");
			
			fflush(stdin);
			printf("\nreturn to main menu?(y/n):"); //prompt return menu?
			scanf("%c", &dcsn2);
	
			if(dcsn2=='y'||dcsn2=='Y')
			{
				choi=0;
			}
			else if (dcsn2=='n'||dcsn2=='N')
			{
				return 0;
			}
			else if (dcsn2!='y'||dcsn2!='Y'||dcsn2!='n'||dcsn2!='N')
			{
				printf("Re-enter\n");
				scanf(" %c", &dcsn2);
				ReturnMenu();				
			}			
		}
	}
	
	else if (choi == 2)
	//MAIN->DVDMENU
	{
		{
			printf("DVD RENTAL SHOP\n========DVD Menu========\n");
			printf("\t 1. ADD NEW DVD\n\t 2. DISPLAY DVD STOCK\n\t 3. SEARCH GENRE\n\t 0. MAIN MENU\n\t 5. EXIT\n");
			
			printf("Enter your choice : ");
			scanf("%d", &choi);
	
			while((choi<0 || choi>3) && (choi!=5))
			{
				OutRange();
				scanf("%d", &choi);
			}
		}
		system("cls");
		if(choi==1)
		//MAIN->DVDMENU->ADD_NEW_DVD
		{ 
			char dcs= 'y';
			while (dcs == 'y' || dcs == 'Y')
			{
				fflush(stdin);
				printf("===ADD NEW DVD===\n");
				printf("DVD #%d\n\n", ttlRC+1);
				printf("DVD Title: ");
				gets(DVDtitle[ttlRC]); //get DVD Title
				fflush(stdin);
				printf("Genre: ");
				scanf("%s", DVDgenre[ttlRC]);	//get genre
				fflush(stdin);
				printf("No. of copies: ");
				scanf("%d", &DVDCopy[ttlRC]);	//get no. of copies
			
				int sc;
				Colour(6);
				printf("data saving");
				for(sc=0; sc<3; sc++)
				{
					printf(" . ");
					Sleep(570);
				}
				ttlRC=ttlRC+1;
				system("cls");
		
				printf("Record saved!");
				Sleep(720);
				Colour(7);
				printf("\nAdd another DVD? (y/n):");
				scanf(" %c", &dcs);
				system("cls");
				if (dcs == 'y' || dcs== 'Y')
					;
				else if (dcs == 'n' || dcs == 'N')
				{
					Colour(7);
					printf("\nReturning to main menu");
					Sleep(499);
					choi=0;
				}	
				else if (dcs!='y'||dcs!='Y'||dcs!='n'||dcs!='N')
				{
					printf("Re-enter\n");
					scanf(" %c", &dcs);
					ReturnMenu();				
				}
			}
			Colour(7);      // 7 PUTIH
	
		}
		else if (choi==2)
		//MAIN->DVDMENU->SHOW_DVD_INFO
		{
			int xx,yy=0;
			char dcsn2;
			printf("===DVD STOCK===");
			printf("\n\tDVD Title\t\t   No. Of Copies\n");
			printf("\t---------\t\t   -------------\n");
			
			for(xx=0; xx<ttlRC; xx++)
			{
				printf("%d\t%-20s\t\t%-20d\n",xx+1, DVDtitle[xx], DVDCopy[xx]);
				//display title, no. of copies
			}
			printf("\n\t\t---end-of-list---\n");
			Sleep(781);
			
			fflush(stdin);
			printf("\nreturn to main menu?(y/n):");
			scanf("%c", &dcsn2);
	
			if(dcsn2=='y'||dcsn2=='Y')
			{
				choi=0; //return to MAIN MENU
			}
			else if (dcsn2=='n'||dcsn2=='N')
			{
				return 0;
			}
			else if (dcsn2!='y'||dcsn2!='Y'||dcsn2!='n'||dcsn2!='N')
			{
				printf("Re-enter\n");
				scanf(" %c", &dcsn2);
				ReturnMenu();				
			}			
		}
		else if (choi==3)
		//MAIN->DVDMENU->SEARCH_GENRE
		{
			int j, MoviesFound=0;
			char search[20],dcs;
			
			printf("\tSEARCH MENU");
			printf("\t\n\nEnter genre that you would like to search : "); //get searchgenre
			fflush(stdin);
			gets(search);
			
			for(j=0;j<ttlRC;j++)
			{
				if(strcmp(DVDgenre[j],search)==0) //compare searchgenre with DVDgenre
				{
					MoviesFound=MoviesFound+1;
					//sum up the DVD with same genre
				}
			
			}
			
			if(MoviesFound==0)
			{
				printf("not found");
			}
			else
			{
				printf("Found %d movie(s)",MoviesFound); //print number of DVD found
			}
			fflush(stdin);
			
			printf("\nreturn to main menu?(y/n):");
			scanf("%c", &dcs);
	
			if(dcs=='y'||dcs=='Y')
			{
				printf("ok?");
				choi=0;
			}

			else if (dcs!='y'||dcs!='Y')  //||dcs!='n'||dcs!='N')
			{
				printf("Re-enter\n");
				scanf(" %c", &dcs);
				ReturnMenu();				
			}				
		}
	}
	else if (choi == 3)
	//MAINMENU->RENTAL_MENU
	{
		{
		printf("DVD RENTAL SHOP\n========Rental Menu========\n");
		printf("\t 1. ADD NEW RENTAL\n\t 2. DISPLAY DVD CURRENTLY IN RENTAL\n\t 0. MAIN MENU\n\t 5. EXIT\n");
			
		printf("Enter your choice : ");
		scanf("%d", &choi);
	
		while((choi<0 || choi>2) && (choi!=5))
		{
			OutRange();
			scanf("%d", &choi);
		}
		}
		system("cls");
		if (choi == 1)
		//MAINMENU->RENTAL_MENU->NEW_RENTAL
			{
				char  titleRented[20][20];
				int i,k,x, avai=0;
				char pilih, ICRent[20];
				int w=0;

				while(w==0)
				{
				printf("IC Number : ");
				fflush(stdin);
				gets(ICRent);	//get ICnumcust		
			
				for(x=0;x<ttlCust;x++)
				{
					if(strcmp(ICRent,ICcust[x])==0) //compare IC number cust
					{						
						w=w+1;		
					}
						
				}
				}

				printf("IC Number verified\n");
				printf("DVD title : ");
				fflush(stdin);
				gets(ttlRent);	//get DVD title to rent
				
				
				for(i=0;i<ttlRC;i++)
				{
					if(strcmp(DVDtitle[i],ttlRent)==0) //compare DVD title
					{
						if(DVDCopy[i]>0)
						{
							avai=avai+1; 
							k=i;
						}
					}
				}
				
					if(avai!=0) //found = nonzero
					{
						printf("DVD available, proceed to rent? \n"); //confirmation to rent DVD
						
						printf("Are you sure to rent '%s' (Y/N)? ", ttlRent);
						scanf("%c", &pilih);
						if (pilih == 'y' || pilih == 'Y')
						{
							DVDCopy[k]=DVDCopy[k]-1;
							printf("Customer %s sucessfully rent DVD '%s'\n", ICRent, ttlRent); 
							strcpy(WhoCust[p], ICRent);
							strcpy(WhoDVD[p], ttlRent);
							p=p+1;
							Sleep(2500);
							ReturnMenu();
						}
						

						else if (pilih=='n' || pilih=='N')
						{
							ReturnMenu();
						}
						else if (pilih!='y'||pilih!='Y'||pilih!='n'||pilih!='N')
						{	
							printf("Re-enter\n");
							scanf(" %c", &pilih);
							ReturnMenu();				
						}		
						
					}
					
					else
					{
						printf("DVD are out of stock!\n\n");
						printf("Return to main menu?(y/n):");
						
						char dcs;
						scanf("%c", &dcs);
	
						if(dcs=='y'||dcs=='Y')
							choi=0;
						else if (dcs=='n'||dcs=='N')
						{
							closing();
						}
						else if (dcs!='y'||dcs!='Y'||dcs!='n'||dcs!='N')
						{
							printf("Re-enter\n");
							scanf(" %c", &dcs);
							ReturnMenu();				
						}						
					}
				
				
			}
			else if (choi==2)
			//MAINMENU->RENTAL_MENU->DISPLAY_DVD_RENTED
			{
				int x;
				
				printf("===DVD RENTED===\n");
				printf("\tTitle\t\tCustomer\n");
				printf("-----\t\t------\n");
				
				for(x=0; x<=p; x++)
				{
					printf("%d\t%-20s\t\t%-20s\n",x+1, WhoDVD[x], WhoCust[x]);
				}
				printf("\n\t\t---end-of-list---\n");
				Sleep(781);
		
				printf("\nReturn to main menu? (y/n):");
				fflush(stdin);
				char dcs = 'y';
				scanf("%c", &dcs);

				if(dcs=='y'||dcs=='Y')
					choi=0;
				else if (dcs=='n'||dcs=='N')
				{
					closing();
				}
				else if (dcs!='y'||dcs!='Y'||dcs!='n'||dcs!='N')
				{
					printf("Re-enter\n");
					scanf(" %c", &dcs);
					ReturnMenu();				
				}
		
			}
			
	}
	
	if (choi == 4)
	//MAINMENU->ABOUT
	{
		about();
		printf("Returning to main menu");
		Sleep(555);
		choi=0;
		
	}
	if (choi == 5)
	////MAINMENU->EXIT
	{
		closing();
		
		return 0;
	}
	}while(choi == 0);	//to return to main menu
	}while(choi == 9);	//to exit the program
	
	return 0;
	
	
}

void Colour(unsigned short colour) //colourf(x)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,colour);
}

//--------Greetings

void greetings(void)	//welcoming
{
    int i, sc;
    char e;
    Colour(2);
	printf("\nWelcome. Login Success!\n\n");
	Sleep(575);
	system("cls");
	Colour(7);
	printf("logging in\t");
	Sleep(150);
	for(sc=0; sc<10; sc++)
	{
		printf("| ");
		Sleep(99);
	}
    Colour(4);
    printf("%s\t%s\n",__TIME__,__DATE__);//display the computer's time and date
    Colour(6);
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*              WELCOME    WELCOME    WELCOME               *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    
    Colour(13);
    for (i=0; i<60; i++)
    {    
		printf ("|");
    	Sleep(35);
    }
}

void closing(void)	//to exit the program
{
   	int sc;
	Colour(6);
	printf("system closing");
	for(sc=0; sc<3; sc++)
		{
			printf(" . ");
			Sleep(499);
		}
	system("cls");
	printf("Succesfully save data to disk");
	Sleep(600);
	system("cls");			//to clear the screen
    Colour(7);
	printf("| G | O | O | D | B | Y | E |\n");
}

void about(void) //to show about
{
	printf("\tABOUT\n");
	printf("\t-----\n\n");
	printf("DVD RENTAL SOFTWARE 2019\n\n");
	printf("MUHAMMAD FAREEZ IQMAL\nMUHAMMAD AKMAL NASRULLAH\nMUHAMMAD AFIQ AHZA\nMUHAMMAD DANIEL NADZMI\nMUHAMMAD ASNAWI\n\n");
	printf("LECTURER: SIR NORHAEDIR");
	printf("\nCFS IIUM 2019");
	printf("\n\nICT PROGRAMMING PROJECT (^o^)\n\n");
	system("pause");
}

void OutRange(void)	//display message when out of range
{
	printf("Out of range!\n*Refer number to list above* ");
	Sleep(565);
	printf("Please re-enter : ");
		
}

void ReturnMenu(void) //to back to main menu
{
	printf("Returning to main menu...");
	Sleep(1000);
	choi=0;
}
//end >_<

