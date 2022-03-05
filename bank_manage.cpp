//Create a Bank management project.
//A bank can have many accounts.
//An account can be of many types (savings, SecureSaving, Demat, VIPSavings)
//A bank manager should be able to remove accounts from the bank, add some money to each account in the account
//A bank manager can also view all the account details of each account in the bank.
//A bank manager can also create account in the bank
//Account editing. (File handling is optional). I want class concepts here.

#include"bank_manage.h"
int main()
{
	char ch;
	
	do
	{	
		Menu m;
		cout<<"\nDo you want to continue?(y/n)";
		fflush(stdin);
		cin>>ch;
		
	}while(ch=='y'||ch=='Y');	
	
	return 0;
}
