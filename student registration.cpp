//   Student Information System
//   Header files
#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>


//  Main function


int main() {
    FILE *fp, *ft;
    char another, choice;

// structure variables declaration


struct student {
	char first_name[50], last_name[50];
	char course[100];
	int section;
	int rollnumber;
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    int xrollnumber;
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL) {
	fp = fopen("users.txt","wb+");

	if (fp==NULL)
	{
	     puts("Cannot open file");
	     return 0;
	}
    }

 // Variable assigned with the size of record

 recsize = sizeof(e);

 while(1) {
     system("cls");
     cout<<"\t************************************************************\n";

     cout << "\t\t====== STUDENT INFORMATION SYSTEM ====== \n";
     cout<<"\t************************************************************\n";
     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout << "\n \t\t\t 1. ADD RECORDS";
     cout << "\n \t\t\t 2. LIST  RECORDS";
     cout << "\n \t\t\t 3. MODIFY RECORDS";
     cout << "\n \t\t\t 4. DELETE RECORDS";
     cout << "\n \t\t\t 5. EXIT PROGRAM";
     cout << "\n\n";
     cout<<"\t************************************************************\n";

     cout << "\t\t\t SELECT YOUR CHOICE FROM THE ABOVE :=> ";

     fflush(stdin);

     choice = getche();
     switch(choice)
     {
      case '1' :
		// ADDING RECORDS

	    fseek(fp,0,SEEK_END);
	    another ='Y';
	    while(another == 'Y' || another == 'y')
	    {
		  system("cls");
     cout<<"-------------------------------------------------------------------------------"<<endl;

		cout << "\n\nENTER THE FIRST NAME : ";
		cin >> e.first_name;
		cout << "\n\nENTER THE MIDDLE NAME : ";
		cin >> e.last_name;
		cout<<"\n\nENTER THE ROLL NUMBER : ";
		cin>> e.rollnumber;
		cout << "\n\nENTER THE COURSE : ";
		cin >> e.course;
		cout << "\n\nENTER THE SECTION IN NUMBER FORM   : ";
		cin >> e.section;

		fwrite(&e,recsize,1,fp);
		cout << "\n ADD ANOTHER RECORD (Y/N) ";


		fflush(stdin);
		another = getchar();
	    }
	    break;
   case '2':
	//LISTING THE RECORD WE WANTED TO SEE
	    system("cls");
	   rewind(fp);
    cout<<"-------------------------------------------------------------------------------"<<endl;
	   cout << "\t\t\t===VIEW THE RECORD PRESENT IN THE DATABASE==="<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
	   cout << "\n";
	    cout<<"ENTER THE ROLL NUMBER :";
	   cin>>xrollnumber;
	   while (fread(&e,recsize,1,fp) == 1){

	   if(e.rollnumber==xrollnumber){
	   cout << "\n";
	   cout <<"\n" <<"ROLL NUMBER :"<< e.rollnumber<<endl;
	   cout <<"\n" <<"FIRST NAME :"<< e.first_name<<endl;

	   cout <<"\n" <<"LAST NAME :"<< e.last_name<<endl;
	   cout <<"\n" <<"COURSE     :" <<e.course <<endl;
	   cout<<"\n"<< "SECTION     :"<< e.section;
	   }
	   }
	   cout << "\n\n";
	   system("pause");
	   break;

   case '3' :
	      //TO MODIFY THE RECORD PRESENT IN THE DATABASE
	       system("cls");
	   cout<<"-------------------------------------------------------------------------------"<<endl;
	   cout<<" \t\t MODIFYING THE RECORDS PRESENT IN DATABASE"<<endl;
	   cout<<"-------------------------------------------------------------------------------"<<endl;

	  another = 'Y';
	 while (another == 'Y'|| another == 'y')
	  {
	      cout << "\n ENTER THE LAST NAME WHICH IS PRESENT IN DATABASE : ";
	      cin >> xlast_name;
	      cout<<"\n ENTER THE ROLL NUMBER WHICH IS PRESENT IN DATABASE :";
	      cin>>xrollnumber;

	    rewind(fp);
	    int flag=0;
	    while (fread(&e,recsize,1,fp) == 1)
	    {
		 if(e.rollnumber==xrollnumber){
		 flag=1;
		 break;
		 }
	    }
		if(flag==1){
	       cout << "ENTER THE NEW FIRST NAME : ";
		cin >> e.first_name;
		cout << "ENTER THE NEW LAST NAME : ";
		cin >> e.last_name;
		cout << "ENTER THE NEW COURSE   : ";
		cin >> e.course;
		cout << "ENTER THE NEW SECTION  : ";
		cin >> e.section;
		cout<<"\n\n";
		fseek(fp, - recsize, SEEK_CUR);
		fwrite(&e,recsize,1,fp);
		cout<<"\n YOUR RECORD HAS BEEN MODIFIED SUCCESFULLY";
		}
		else{
			cout<<"RECORD NOT FOUND";
		}


	    cout << "\n MODIFY ANOTHER RECORD (Y/N) ";
		fflush(stdin);
		another = getchar();
	    }
	    break;


     case '4':
		   //DELETE THE RECORD FROM THE DATABASE
       system("cls");
       cout<<"-------------------------------------------------------------------------------"<<endl;
       cout<<"\t\t DELETING THE RECORDS FROM THE DATABASE"<<endl;
       cout<<"-------------------------------------------------------------------------------"<<endl;
	   another = 'Y';
	  while (another == 'Y'|| another == 'y')
	  {
	      cout << "\n ENTER THE LAST NAME OF THE STUDENT TO DELETE : ";
	      cin >> xlast_name;
	      cout <<"\n ENTER THE ROLL NUMBER:";
	      cin >>xrollnumber;

	      ft = fopen("temp.dat", "wb");

	      rewind(fp);
	      while (fread (&e, recsize,1,fp) == 1)

		if(e.rollnumber!=xrollnumber)
			{
		    fwrite(&e,recsize,1,ft);
			}



		fclose(fp);
		fclose(ft);
		remove("users.txt");
		rename("temp.dat","users.txt");

		fp=fopen("users.txt","rb+");

		cout <<"\n YOUR DETAILS ARE DELETED SUCCESFULLY";

		cout << "\n IF YOU WANT TO DELETE ANOTHER RECORD PRESS (Y/N) ";
		fflush(stdin);
		another = getchar();
	      }

	      break;

	      case '5':
	      // SAYING THANK YOU FOR USING THIS


	      fclose(fp);
	      cout << "\n\n";
	      cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
	      cout << "\n\n";
	      getch();
	      exit(0);
	  }
     }



return 0;

}
