#include<iostream>									
#include<stdlib.h>
#include<string>
#include<fstream>
#include<cctype> 
#include<windows.h>
using namespace std;

//==================================  S T R U C T U R E S  =================================================================

struct create
{
	string student_id;				//	Attributes
	string student_name;			//     For
	string student_uni;				//	 Account
	string student_password;		//	 Creation

	string student_purpose;			//	Attributes 
	string student_timefrom;		//     For 
	string student_timeto;			//  Data Entry
	string student_department;		//     For
	string student_semester;		//   Outpass
	
	char decision;					//Used In WARDEN Function That Decides If The Outpass Is Approved Or Rejected
};


struct login
{
	string student_id;				//	Attributes Which Will Be Compared
	string student_name;			//	With The Account Creation Attributes 
	string student_password;		//	In Structure 'create' For Login
	
	string warden_name;				//	Attributes To Login As A Warden, There Is Only One Warden Programmed In The Program
	string warden_password;			//	Programmed Warden Name Is "ahsan" and Password Is "12345678"
};

int static application_number=0;		/*Global Variable Used In LOGIN Function To Keep Track Of The Number Of applications
										  And In WARDEN Function To Display no Of Applications */

//=========================  F U N C T I O N   P R O T O T Y P E S  ===============================================================

int CREATE(create[],int);			
void LOGIN(create[],login);		
void OUTPASS_INPUT(create[],int);
void WARDEN(create[],int,int);	
void FORGET(create[],login);
int static student_number=0;
	int const max_accounts=5;		//Constant Integer That Contains The Number Of Maximum Accounts That Can Be Made
																													
	
	create account[max_accounts];	


//===================================  I N T   M A I N   ==========================================================================
int main()
{
		//Used in Account Creation To Count Accounts Until 5 Accounts Have Been Created
	char main_option,		//Used To Choose Between Student,Admin And Exit Option, It Is In Char Data Type So That It Can Give Output If Characters Are Given
	student_option;			//Used To Choose Between Create Account, Login and Exit Option in Student Menu
			/*Global Variable Used In LOGIN Function To Keep Track Of The Number Of Applications
										  And In WARDEN Function To Display no Of Applications */;			//Used To Count The Number Of Total Applications And Show Them In The Warden's Menu

	/*      The Structure Identifier "create" Is Called With A Array Variable "account", We Could Have
									Simply Written 5 In The Array But We Used The Variable "max_accounts" Because It Would Be Compared 
									Later In The Program   																			*/
	login sign_in;					//The Structure Identifier "login" Is Called With A Array Variable "sign-in"
	
	
	main_again:						//Programmer Defined Identifier Used As Jump Statement Which Would Be Used Multiple Times During The Program
	
	
	
//_________  M A I N   M E N U  _________
	cout<<'\t'<<"-------------------------------------"<<endl;
	cout<<'\t'<<"--WELLCOME TO ONLINE OUTPASS PORTAL--"<<endl;
	cout<<'\t'<<"-------------------------------------"<<endl;
	cout<<'\t'<<endl<<endl<<'\t'<<'\t'<<"1.Student"<<endl<<endl<<'\t'<<'\t'<<"2.Warden"<<endl<<endl<<'\t'<<'\t'<<"0.Exit"<<endl;
	
	
		
	cin>>main_option;	
	
//\
//	______________  S T U D E N T  _______________
	
	
	switch(main_option)
	{
	case '1':		system("CLS");
				cout<<"1.Create Account"<<endl<<endl<<"2.Log-In"<<endl<<endl<<"0.Exit"<<endl;
			
				cin>>student_option;			
				switch(student_option)
				{
					
				//--------------------  f o r   a c c o u n t  c r e a t i o n  ----------------------
							
					case '1':	 	if(student_number<max_accounts)		//Checks If The Number Of Accounts Have Reached The Maximum Limit i.e. 5
									{
										student_number+=    CREATE(account,student_number);		/* CREATE Function Takes The Details For The Creation Of New Account and returns Value '1'
																								   Each Time An Account Is Created. Whenever An Account Is Created, An Increment Is Made
																								   To The Variable Student Number Until Is Reaches 5. '5' Is The Maximum Account Limit    */
										
										goto main_again;
									}
									else								//Displays 'Maximum Number Of Accounts Reached', When User Tries To Create More Than 5 Accounts 
									{
										system("CLS");
										cout<<"Maximum Number Of Accounts Reached, Cannot Create More Accounts..."<<endl<<endl;
										system("PAUSE");
										system("CLS");
										goto main_again;
									}
															
															
//-----------------------------------  f o r  l o g i n  ----------------------------------
				
					case '2' :			LOGIN(account,sign_in);		//LOGIN Function Takes Login Values From The User And Compares It To The Created Accounts
													
										system("CLS");
										goto main_again;
								
					case '0' :	    	system("CLS");
								   		goto main_again;
									    
					
					default:    		cout<<"Invalid Option Entered..."<<endl;
								    	system("PAUSE");
								    	system("CLS");
								    	goto main_again;
											
					}
				break;
//\
   _______________  W A R D E N  _________________
	
			
	case '2':	WARDEN(account,application_number,student_number);			/*WARDEN Function Takes Login Values From The User And Compares It To The Login Data Of Warden
																		  Which Is Fed Into The Program i.e. Name:ahsan Password:12345678 */
				system("CLS");
				
				goto main_again;
				
//\
	_____________  E X I T  P R O G R A M  _______________
	case '0':		exit (0);
				
					
					
	default:	cout<<"Invalid Option Entered..."<<endl;
				system("PAUSE");
				system("CLS");
				goto main_again;
				
		
	}





}





int CREATE(create account[],int i)		//This Function Takes Account Creation Data From The User
{
	
	    system("CLS");
		
		cout<<"Enter Name: "<<endl;
		cin.ignore();
		getline(cin,account[i].student_name);
		cout<<"Enter Student ID (In Capital Letters): "<<endl;
		getline(cin,account[i].student_id);
		cout<<"Create Password: "<<endl;
		getline(cin,account[i].student_password);
		cout<<"\nYour Account is Creating-";
		for(int i=0;i<=3
		
		;i++)
		{
			cout<<"-";
			Sleep(1000);
		}
		cout<<endl;
		cout<<"Your Account Has Been Created"<<endl;
		system("PAUSE");
		system("CLS");
		
		return 1;
	
}



void LOGIN(create account[],login sign_in)	//Compares Login Credentials Given By The User With Number Of Accounts Created. OUTPASS Function Is Also Called In It
{
	login:
	char login_option;				//Used To Navigate Inside Login Menu
	system("CLS");
	cout<<"1. Login\n2. Forget Password"<<endl;
	cin>>login_option;
	system("CLS");
	switch(login_option)
	{
		case '1':
	{
	student_login:
	cout<<"Student ID (In Capital Letters): "<<endl;
	cin>>sign_in.student_id;
	cin.ignore();
	cout<<"Enter Password: "<<endl;
	getline(cin,sign_in.student_password);
	

		
		for(int i=0;i<5;i++)		//Two Loops Are Used because The Program Was Giving 4 'Invalid Credentials' Statements If Only 1 Account Is Made
		{	
			for(int j=0;j<5;j++)	//Used To Go Through All Index Values Of Structure 'account' Array
			{
				if(sign_in.student_id==account[j].student_id && sign_in.student_password==account[j].student_password)
					//Compares The Student Id And Password Given During Login To The Student Id And Password Of All The Created Accounts
				{																										
					student_ag:		//Identifier Used For Goto Jump Statement
					system("CLS");
					
			//		--------------------------Login menu-----------------
			
					cout<<'\t'<<'\t'<<"HELLO "<<account[j].student_name<<" !!"<<endl<<endl;		
					cout<<"1.Request Outpass"<<endl<<"2.Outpass Status"<<endl<<"3.Log Out"<<endl;
					
					cin>>login_option;
					switch(login_option)
					{
			//-----------------------------  request outpass  ------------------------			
					case '1':	OUTPASS_INPUT(account,j);		//OUTPASS_INPUT Function Is Called Here Which Enters Outpass Details
								application_number++;			//Increment Is Made In This Variable Every Time Outpass Is Created
								goto student_login;
									
			//-------------------------  checks outpass status  ---------------------------
					case '2':	if(account[j].student_uni=="PAF-IAST")
								{
								
									cout<<"Name: "<<account[j].student_name<<endl;
									cout<<"Student Id: "<<account[j].student_id<<endl;
									cout<<"Department: "<<account[j].student_department<<endl;
									cout<<"Semester: "<<account[j].student_semester<<endl;
									cout<<"Purpose: "<<account[j].student_purpose<<endl;
									cout<<"From: "<<account[j].student_timefrom<<" To: "<<account[j].student_timeto<<endl<<endl;
									
									if(account[j].decision=='1')			//Shows Approved If Outpass Is Approved By The Warden
										cout<<"Status: Approved"<<endl;
									else if(account[j].decision=='2')		//Shows Approvede If Outpass Is Rejected By The Admin
										cout<<"Status: Rejected"<<endl;
									else								
										cout<<"Status: Pending"<<endl;    //shows the pending status of the outpass
									
									system("PAUSE");
									goto student_login;
								}
								else
								{
								cout<<"No Applications Yet"<<endl<<endl;     //When no application is recived to warden 
								system("PAUSE");
								goto student_login;          
								}
								break;
								
					case '3':	
								{
								system("CLS");
								main();
								}
								break;
					default:                                             //These statements are when all of the above are incoorrect
					
								cout<<"Invalid Credentials"<<endl
								<<"Please try again"<<endl;
								system("pause");
								goto student_ag;
										
										
										
					}
					
				}
			
				
					if(sign_in.student_id!=account[i].student_id && sign_in.student_password!=account[i].student_password)        
					//This condition is true if the entered user id or 
		//password does not match the user id or passwrod of any account
					{
						cout<<"Invalid Credentials"<<endl;
						system("PAUSE");
						goto student_login;
					}
			}
		}
	}
		break;
		case '2':
			{
				FORGET(account,sign_in);
			}
	
	}

}

void FORGET(create account[],login sign_in)
{
	system("CLS");
	string student_id;
	cout<<"Enter Student ID: ";
	cin>>student_id;
	
	for(int i=0;i<=5;i++)
	{
		for(int j=0;j<=5;j++)
		{
			if(student_id==account[j].student_id)
			{
				cout<<"Hello! "<<account[j].student_name<<endl;
				cin.ignore();
				cout<<"Create New Passsword: ";
				getline(cin,account[j].student_password);
				LOGIN(account,sign_in);
			}
		}
	}
}

void OUTPASS_INPUT(create account[],int j)
{	
	cout<<"Name: "<<account[j].student_name<<endl;
	cout<<"Student Id: "<<account[j].student_id<<endl;
	cout<<"Uni Name (Capital): ";
	cin>>account[j].student_uni;
	cout<<"Department: ";
	cin>>account[j].student_department;
	cout<<"Semester: ";
	cin>>account[j].student_semester;
	cout<<"Purpose: ";
	cin>>account[j].student_purpose;
	cout<<"Time:"<<endl<<"From: ";
	cin>>account[j].student_timefrom;
	cout<<"To: ";
	cin>>account[j].student_timeto;
	cout<<endl;
	
	system("PAUSE");	
		
}


void WARDEN(create account[], int application_number, int student_number)
{
		
		system("CLS");
		login sign_in;
		warden_again:
		cout<<"Enter Warden Name:      //Fixed As 'ahsan' "<<endl;
		cin>>sign_in.warden_name;
		cout<<"Enter Password          //Fixed As '12345678': "<<endl;
		cin>>sign_in.warden_password;
		
		
			if(sign_in.warden_name=="ahsan" && sign_in.warden_password=="12345678")
			{
				int n=0;
				system("CLS");
				cout<<'\t'<<"Welcome Ahsan!!"<<endl<<endl;
				cout<<"You have received "<<application_number<<" New Application(s)."<<endl<<endl;
				system("PAUSE");
			
			
					for(int x=0;x<5;x++)
					{
						
						if(account[x].student_uni=="PAF-IAST")
						{
						cout<<"Application # "<<++n<<endl<<endl;
						
						cout<<"Name: "<<account[x].student_name<<endl;
						cout<<"Student Id: "<<account[x].student_id<<endl;
						cout<<"Department: "<<account[x].student_department<<endl;
						cout<<"Semester: "<<account[x].student_semester<<endl;
						cout<<"Purpose: "<<account[x].student_purpose<<endl;
						cout<<"From: "<<account[x].student_timefrom<<" To: "<<account[x].student_timeto<<endl<<endl;
					
						cout<<"1. Approve"<<'\t'<<'\t'<<"2. Reject"<<endl;
						cin>>account[x].decision;
						system("PAUSE");
						system("CLS");
						
						}
					}
			}
			else
			{
				cout<<"Invalid Credentials, Enter Details Again: "<<endl;
				goto warden_again;
			}
			
}
