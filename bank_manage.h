#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

FILE *p;
class Acc
{
	public: 
	
	char acctype[30];
	char at[30];
	double bala;
	char password[20];
}d;

FILE *q;
struct Accho
{
	char acch[50];
}i;
class Account
{	
	int flag=0, ch;
	
	protected:
	char acch[50],acctype[30],passwo[20];
	
	public:	
		Account()
		{	
				cout<<"\nEnter account holder full name (First Middle Last): ";
				fflush(stdin);
				gets(acch);
				 	
				p=fopen(acch ,"a+b");
				
				q=fopen("info" ,"a+b");
				
			while(fread(&i,sizeof(i),1,q)==1)
	      	{
	            if(strcmp(i.acch,acch)==0)
	
	            {
					cout<<"\n\t ACCOUNT EXISTS WITH THIS NAME.\n";
					flag=1;
	            }
	        }
			
	        if(flag==0)
	        {
	        	cout<<"\nSet a password!: ";
	        	fflush(stdin);
	        	gets(d.password);
	        	
	        	strcpy(acctype,d.at);
	        	
	        	strcpy(d.acctype,acctype);
	        	strcpy(i.acch,acch);
	      		fwrite(&i,sizeof(i),1,q);
	        	fwrite(&d,sizeof(d),1,p);
	        	cout<<"\nAccount Created\n";
			
			}
			fclose(p);
			fclose(q);
			
		}
   void Withdraw(double amt)
   {
	   	cout<<"\nEnter password: ";
	    fflush(stdin);
	    gets(passwo);
	    
	   	p=fopen(acch,"a+b");
	   	
	   	while(fread(&d,sizeof(d),1,p)==1)
	      	{
			   	if(strcmp(passwo,d.password)==0)
			   	{
			   	 d.bala-=amt;
			   	 cout<<"\n\tAmount withdrawn";
			   	}
			   	else
			   	{
			   		cout<<"Wrong Password";
				}
			}
			fwrite(&d,sizeof(d),1,p);
			   	 	fclose(p);
   	 
   }
   void Deposit(double amt)
   {
   	    cout<<"\nEnter password: ";
	    fflush(stdin);
	    gets(passwo);
	    
   	    p=fopen(acch,"a+b");

   	    while(fread(&d,sizeof(d),1,p)==1)
	      	{   	    
		   	    if(strcmp(passwo,d.password)==0)
			   	{
			   		d.bala+=amt;
			   		cout<<"\nBalance summary is: "<<d.bala;
			   	  
			   	  	cout<<"\n\tAmount Deposited";
			   	}
			}
				fwrite(&d,sizeof(d),1,p);
			   		fclose(p);
   }
   double CheckBalance()
   {
   		cout<<"\nEnter password: ";
	    fflush(stdin);
	    gets(passwo);
	    
   	    p=fopen(acch,"ab+");
   	    
   	    while(fread(&d,sizeof(d),1,p)==1)
	      	{
		   	    if(strcmp(passwo,d.password)==0)
			   	{
		   	 		cout<<"\nBalance is: "<<d.bala;
		   	 	}
		   	 	
		   	 	else
		   	 	{
		   	 		cout<<"\nWrong password";
				}
			}
		   	 	fclose(p);
		   	 	
   }
};
class SavingsAccount:public Account
{
	private:
	int t;
	protected: 
	int limit;
	public: 
	SavingsAccount()
	{
		t=0;
		limit=5;
	}
	void Withdraw(double amt)
	{
		if(t>=limit)
		{
			cout<<"\nTransactions exceeded";
		}
		
		else
		{
			Account::Withdraw(amt);
			t++;
		}
	}
	void Deposit(double amt)
	{
		if(t>=limit)
		{
			cout<<"\nTransactions exceeded";
		}
		else
		{
			Account::Deposit(amt);
			t++;
		}
	}
};

class VIPSavingsAccount:public SavingsAccount
{
	double minibalance;
	
	public:
		VIPSavingsAccount()
		{
			limit = 10;
			minibalance = 25000;
			//When VIPSavingsAccount is created, initiated balance will be 25000
		}
		void Withdraw(double amt) 
		{
			if(Account::CheckBalance() - amt < minibalance)
			{
				cout<<"\nCannot  withdraw due to minimum balance";
			}
			else
			{
				SavingsAccount::Withdraw(amt);
			}
		}
};

class SecureSavingsAccount:public SavingsAccount
{
	int pin;
	public:
		SecureSavingsAccount()
		{
			limit=15;
			pin=1234;
		}
		void Deposit(double amt)
		{
			int tpin;
			cout<<"\nEnter PIN: ";
			cin>>tpin;
			if(tpin== pin)
			{
				SavingsAccount::Deposit(amt);
			}
			else
			{
				cout<<"\nInvalid PIN";
			}
		}
		
			void Withdraw(double amt)
		{
			int tpin;
			cout<<"\nEnter PIN: ";
			cin>>tpin;
			if(tpin== pin)
			{
				SavingsAccount::Withdraw(amt);
			}
			else
			{
				cout<<"\nInvalid PIN";
			}
		}
};

class DematAccount:public Account
{
	public:
		void Deposit(double amt)
		{
			amt=amt-(amt*0.01);
			Account::Deposit(amt);
			
		}
		void Withdraw(double amt)
		{
			amt=amt+(amt*0.001);
			Account::Withdraw(amt);
		}
};



class Menu
{
	public:
	Menu()
	{
		system("cls");
			int num,n;
			double amt;
			char acch[50],ch,pass[10],at[30];
			char pin[10]="Jack@12";
			
		cout<<"\t\t***WELCOME TO BANK***\n ";
			
		cout<<"\nAre u a bank manager? (y or n)";
		cin>>ch;
		
		cout<<"\n\n\n\t********************************";
		cout<<"\n\t   Choose your Option:(1-to-6)\n"<<endl;
		cout<<"\t     1.Create An Account\n";
		cout<<"\t     2.Deposite Money\n";
		cout<<"\t     3.Check the Balance\n";
		cout<<"\t     4.Withdraw Money\n";
		cout<<"\t     5.See All Information\n";
		cout<<"\t     6.Remove Account\n";
		cout<<"\t     7.Quit";
		cout<<"\n\t********************************";
		cout<<"\t\n\t";cin>>num;
		switch(num)
		{
			case 1:
			{
				system("cls");
				
				cout<<"\n\n\n\t********************************";
				cout<<"\n\t   Choose your Option:(1-to-4)\n"<<endl;
				cout<<"\t     1.SavingsAccount\n";
				cout<<"\t     2.VIPSavingsAccount\n";
				cout<<"\t     3.SecureSavingsAccount\n";
				cout<<"\t     4.DematAccount\n";
				cout<<"\n\t********************************";
				cout<<"\t\n\t";cin>>n;
				
				p = fopen (acch, "ab+" ) ;
				
				switch(n)
				{
					case 1:
						{
							strcpy(d.at,"SavingsAccount");
							fwrite(&d,sizeof(d),1,p) ;
								fclose(p);
						 SavingsAccount sa;
						
						break;
					}
					case 2:
						{
							strcpy(d.at,"VIPSavingsAccount");
							fwrite(&d,sizeof(d),1,p) ;
								fclose(p);
						VIPSavingsAccount vsa;
						cout<<"\nRs.25000 needs to be deposited as minimum balance";
						vsa.Deposit(25000);
						
						break;
						}
					case 3:
						{
							strcpy(d.at,"SecureSavingsAccount");
							fwrite(&d,sizeof(d),1,p) ;
								fclose(p);
						 SecureSavingsAccount ssa;
						break;
						}
					case 4:
						{
							strcpy(d.at,"DematAccount");
							fwrite(&d,sizeof(d),1,p) ;
								fclose(p);
						 DematAccount da;
						break;
						}
				}
			
			}
				break;
				
			case 2:
			{
			   system("cls");
			   
				cout<<"\n\n\n\t********************************";
				cout<<"\n\t   Choose your Option:(1-to-4)\n"<<endl;
				cout<<"\t     1.SavingsAccount\n";
				cout<<"\t     2.VIPSavingsAccount\n";
				cout<<"\t     3.SecureSavingsAccount\n";
				cout<<"\t     4.DematAccount\n";
				cout<<"\n\t********************************";
				cout<<"\t\n\t";cin>>n;
				p = fopen (acch, "ab+" ) ;
				switch(n)
				{
					case 1:
						
						{
							cout<<"Enter the amount to be deposited: ";
							cin>>amt;
							strcpy(d.at,"SavingsAccount");
							fwrite(&d,sizeof(d),1,p) ;
								fclose(p);
							SavingsAccount sa;
							sa.Deposit(amt);
						}
						break;
					
					case 2:
						{
							cout<<"Enter the amount to be deposited: ";
							cin>>amt;
							strcpy(d.at,"VIPSavingsAccount");
							fwrite(&d,sizeof(d),1,p) ;
								fclose(p);
							VIPSavingsAccount vsa;
							vsa.Deposit(amt);
						}
						break;
						
					case 3:
						{
							cout<<"Enter the amount to be deposited: ";
							cin>>amt;
							strcpy(d.at,"SecureSavingsAccount");
							fwrite(&d,sizeof(d),1,p) ;
								fclose(p);
							SecureSavingsAccount ssa;
							ssa.Deposit(amt);
						}
						break;
						
					case 4:
						{
							cout<<"Enter the amount to be deposited: ";
							cin>>amt;
							strcpy(d.at,"DematAccount");
							fwrite(&d,sizeof(d),1,p) ;
								fclose(p);
							DematAccount da;
							da.Deposit(amt);
						}
						break;
				}
			}
				break;
			
			case 3:	
			{	
			system("cls");
				Account a;
				a.CheckBalance();
			
			}
				break;
				
			case 4:	
			{
			
			    system("cls");
			    
			    if(ch=='n')
			    {
					cout<<"\n\n\n\t********************************";
					cout<<"\n\t   Choose your Option:(1-to-4)\n"<<endl;
					cout<<"\t     1.SavingsAccount\n";
					cout<<"\t     2.VIPSavingsAccount\n";
					cout<<"\t     3.SecureSavingsAccount\n";
					cout<<"\t     4.DematAccount\n";
					cout<<"\n\t********************************";
					cout<<"\t\n\t";cin>>n;
					p = fopen (acch, "ab+" ) ;
					switch(n)
					{
						case 1:
							
							{
								cout<<"Enter the amount to withdraw: ";
								cin>>amt;
								strcpy(d.at,"SavingsAccount");
								fwrite(&d,sizeof(d),1,p) ;
									fclose(p);
								SavingsAccount sa;
								sa.Withdraw(amt);
								
							}
							break;
						
						case 2:
							{
								cout<<"Enter the amount to withdraw: ";
								cin>>amt;
								strcpy(d.at,"VIPSavingsAccount");
								fwrite(&d,sizeof(d),1,p) ;
									fclose(p);
								VIPSavingsAccount vsa;
								vsa.Withdraw(amt);
							}
							break;
							
						case 3:
							{
								cout<<"Enter the amount to withdraw: ";
								cin>>amt;
								strcpy(d.at,"SecureSavingsAccount");
								fwrite(&d,sizeof(d),1,p) ;
									fclose(p);
								SecureSavingsAccount ssa;
								ssa.Withdraw(amt);
							
							}
							break;
							
						case 4:
							{
								cout<<"Enter the amount to withdraw: ";
								cin>>amt;
								strcpy(d.at,"DematAccount");
								fwrite(&d,sizeof(d),1,p) ;
									fclose(p);
								DematAccount da;
								da.Withdraw(amt);
							}
						break;
					}
				}
				else
				{
					cout<<"\nPermission denied";
				}
			}
				break;
			
			case 5:
				{
				system("cls");
				
                if(ch=='y')
                {
                	cout<<"Enter password: ";
                	fflush(stdin);
                	gets(pass);
                	if(strcmp(pass,pin)==0)
                	{
                		cout<<"\nAll records: \n";
                		q=fopen("info","rb");
                		while(fread(&i,sizeof(i),1,q)==1)
                		{
                			cout<<i.acch;
                			cout<<"\n";
						}
				
						cout<<"\n\nEnter account holder name: ";
						fflush(stdin);
						gets(acch);
						
						p=fopen(acch,"rb");
						
							if( p == NULL)
							{
								cout<<"RECORD DOES NOT EXIST!!\n\n";
								return ;
							}
						
						while (fread(&d,sizeof(d),1,p) == 1 )
						{
							cout<<"\nAccount type is: "<<d.acctype;
							cout<<"\nBalance summary is: "<<d.bala;
							cout<<"\nPassword is: "<<d.password;
						}
						fclose(p);
						fclose(q);
					}
					else
					{
						cout<<"\nWrong Password!!"; 
					}
				}
				
				else
				{
					cout<<"\nAccess denied";
				}
				break;
			}
			
			case 6:
			{
				system("cls");
				
                if(ch=='y')
                {
                	cout<<"Enter password: ";
                	fflush(stdin);
                	gets(pass);
                	if(strcmp(pass,pin)==0)
                	{
						printf("\nEnter account holder name: ");
						fflush(stdin);
						gets(acch);
						
		                p = fopen (acch, "wb" ) ;
		
		                if ( p == NULL )
		
		                {
		                    printf("\nRECORD DOES NOT EXISTS");
		                    
		                    return ;
		
		                }
		
		                fclose(p);
		
		                remove(acch);
		
		                printf("\nDELETED SUCCESFULLY...");
		        	}
		        	else
		        	{
		        		cout<<"\nWRONG PASSWORD";
					}
				}
				else
				{
					cout<<"\nACCESS DENIED!!";
				}
			}
			    break;
					
			default:
				break;
		}
	}
};
