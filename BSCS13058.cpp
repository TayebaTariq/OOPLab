#include<iostream>
#include<conio.h>

using namespace std;

class account
{
private:
	int number;
	int amount;
public:
	void setNum(int n){ number = n; }
	int getNum(){ return number; }

	void setAmount(int a){ amount = a; }
	int getAmmount(){ return amount; }
};

class user
{
private:
	char *name;
	account a;
public:
	void setName(char *name)
	{
		int len = strlen(name);
		this->name = new char[len];
		for (int i = 0; name[i] != '\0'; i++)
		{
			this->name[i] = name[i];
		}
		this->name[len] = '\0';
	}
	char* getName(){ return this->name; }

	void setAccNum(int an){ a.setNum(an); }
	int getAccNum(){ return a.getNum(); }

	void setAccAm(int am){ a.setAmount(am); }
	int getAccAm(){ return a.getAmmount(); }
};

class ATM
{
private:
	user u[3];
	int choice;
public:
	void setC(int c){ choice = c; }
	int getC(){ return choice; }

	void setu1Name(char* n){ u[0].setName(n); }
	void setu1AccNum(int n){ u[0].setAccNum(n); }
	void setu1AccAm(int am){ u[0].setAccAm(am); }
	char* getu1Name(){ return u[0].getName(); }
	int getu1AccNum(){ return u[0].getAccNum(); }
	int getu1AccAmount(){ return u[0].getAccAm(); }

	void setu2Name(char * n){ u[1].setName(n); }
	void setu2AccNum(int n){ u[1].setAccNum(n); }
	void setu2AccAm(int am){ u[1].setAccAm(am); }
	char* getu2Name(){ return u[1].getName(); }
	int getu2AccNum(){ return u[1].getAccNum(); }
	int getu2AccAmount(){ return u[1].getAccAm(); }

	void setu3Name(char * n){ u[2].setName(n); }
	void setu3AccNum(int n){ u[2].setAccNum(n); }
	void setu3AccAm(int am){ u[2].setAccAm(am); }
	char* getu3Name(){ return u[2].getName(); }
	int getu3AccNum(){ return u[2].getAccNum(); }
	int getu3AccAmount(){ return u[2].getAccAm(); }

	void menu()
	{
		cout << "1- Query your bank statement." << endl
			<< "2- Transfer ammount." << endl
			<< "3- Pay your bill." << endl
			<< "4- Withdraw money." << endl
			<< "Choice: ";
	}

	void queryStatement(int i)
	{
		cout << endl << "\tName: " << u[i].getName() << endl
			<< "\tAccount number: " << u[i].getAccNum() << endl
			<< "\tPresent amount: " << u[i].getAccAm() << endl;
	}
	void transferAmount(int i, int j, int amount)
	{
		u[i].setAccAm(u[i].getAccAm() - amount);
		u[j].setAccAm(u[j].getAccAm() + amount);
		cout << "\tAmount " << amount << " transferesd to account number " << j + 1 << endl;
		cout << "Your current amount is now " << u[i].getAccAm() << endl;
	}

	void payBill(int i, int billAmount)
	{
		u[i].setAccAm(u[i].getAccAm() - billAmount);
		cout << "\tBill payed.." << endl;
		cout << "Your current amount is now " << u[i].getAccAm() << endl;
	}

	void withdrawmoney(int i, int withdrawlAmount)
	{
		u[i].setAccAm(u[i].getAccAm() - withdrawlAmount);
		cout << "\tAmount withdrew.." << endl;
		cout << "Your current amount is now " << u[i].getAccAm() << endl;
	}
};

ATM a;

void functionAtm(int number)//, int number2, int bill, int amount, int ch)
{
	int number2, amount, bill, ch, withdraw;
	cout << endl << "   Menu" << endl;
	a.menu();
	cin >> ch; a.setC(ch);
	if (a.getC() == 1)
	{
		a.queryStatement(number);
	}
	else if (a.getC() == 2)
	{
		cout << "\tIn which account you want to transfer amount? ";
		cin >> number2;
		cout << "\tHow much amount? ";
		cin >> amount;
		if (amount <= a.getu1AccAmount())
		{
			if (number2 == a.getu1AccNum())
			{
				a.transferAmount(number, number2 - 1, amount);
			}
			else if (number2 == a.getu2AccNum())
			{
				a.transferAmount(number, number2 - 1, amount);
			}
			else if (number2 == a.getu3AccNum())
			{
				a.transferAmount(number, number2 - 1, amount);
			}
			else
			{
				cout << "The account does not exists." << endl;
			}
		}
		else
		{
			cout << "You don't have enough amount to transfer." << endl;
		}
	}
	else if (a.getC() == 3)
	{
		cout << "\tEnter the amount of bill you want to pay: ";
		cin >> bill;
		if (bill <= a.getu1AccAmount())
		{
			a.payBill(number, bill);
		}
		else
		{
			cout << "You don't have enough amount to pay your bill." << endl;
		}
	}
	else if (a.getC() == 4)
	{
		cout << "\tEnter the amount of withdrawl: ";
		cin >> withdraw;
		if (withdraw <= a.getu1AccAmount())
		{
			a.withdrawmoney(number, withdraw);
		}
		else
		{
			cout << "You don't have enough amount to withdraw." << endl;
		}
	}
	else
	{
		cout << "You have entered wrong choice. " << endl;
	}
}


int main()
{
	char name[50]; int number;


	a.setu1Name("ali"); a.setu1AccNum(1); a.setu1AccAm(10000);
	a.setu2Name("aliya"); a.setu2AccNum(2); a.setu2AccAm(50000);
	a.setu3Name("zahir"); a.setu3AccNum(3); a.setu3AccAm(20000);

	cout << "    Existing accounts are " << endl
		<< "Account 1: " << a.getu1AccNum() << "\tuser: " << a.getu1Name() << endl
		<< "Account 2: " << a.getu2AccNum() << "\tuser: " << a.getu2Name() << endl
		<< "Account 3: " << a.getu3AccNum() << "\tuser: " << a.getu3Name() << endl;

	while (true)
	{
		cout << "Enter your name: "; cin >> name;
		cout << "Enter your account number:  "; cin >> number;

		if ((strcmp(name, a.getu1Name()) == 0) && (number == a.getu1AccNum()))
		{
			functionAtm(number - 1);
		}
		else if ((strcmp(name, a.getu2Name()) == 0) && (number == a.getu2AccNum()))
		{
			functionAtm(number - 1);
		}
		else if ((strcmp(name, a.getu3Name()) == 0) && (number == a.getu3AccNum()))
		{
			functionAtm(number - 1);
		}
		else
		{
			cout << "Entered user name and account does not exist." << endl;
		}
		cout << "\tBye..." << endl << endl;
	}

	_getche();
	return 0;
}