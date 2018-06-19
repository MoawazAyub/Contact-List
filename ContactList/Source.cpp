# include < iostream >
# include  < string >

using namespace std;

class CONTRACTS
{
private:
	string name;
	char* office_no;
	char* home_no;
	char* mobile_no;

public:
	CONTRACTS();

	CONTRACTS(string nam, int off[], int mob[], int hom[]);
	void input_contract();
	void print_contract();

	CONTRACTS(const CONTRACTS &);
	const CONTRACTS & operator= (const CONTRACTS &);

	string getnam()
	{
		return name;
	}

	void setname(string nam)
	{
		name = nam;
	}

	char* getmobile()
	{
		return mobile_no;

	}

	void setmobile(char* mobile)
	{
		mobile_no = mobile;
	}

	char* getoffice()
	{
		return office_no;

	}

	void setoffice(char* office)
	{
		office_no = office;
	}

	char* gethome()
	{
		return home_no;

	}

	void sethome(char* home)
	{
		home_no = home;
	}

	~CONTRACTS()
	{
		delete[] mobile_no;
		delete[] home_no;
		delete[] office_no;


	}

};

class LIST
{
private:
	int listsize;
	CONTRACTS *C;
	int no_of_records;

public:
	LIST();
	LIST(int, int);
	LIST(const LIST &);
	void inputlist(const CONTRACTS &);
	//void printlist();

	const LIST & operator= (const LIST &);
	LIST operator+(const CONTRACTS &);
	friend LIST operator+(const CONTRACTS & C1, LIST & F)
	{
		F + C1;
		return F;
	}

	LIST operator-(const CONTRACTS &);
	friend LIST operator-(const CONTRACTS & C1, LIST & F)
	{
		F - C1;
		return F;
	}

	void serchcontracts();

	/*int gets()
	{
	return listsize;
	}*/

	void printlist()
	{
		for (int i = 0; i < no_of_records; i++)
		{
			C[i].print_contract();
		}

	}

	~LIST()
	{
		delete[] C;
	}

};




void main()
{
	LIST L;
	CONTRACTS C;
	int n = -1;



	while (n != 0)
	{

		cout << " ENTER 1 TO ADD A CONTRACT    " << endl;
		cout << " ENTER 2 TO DELETE A CONTRACT " << endl;
		cout << " ENTER 3 TO SERCH A CONTRACT  " << endl;
		cout << " ENTER 4 TO PRINT LIST        " << endl;
		cout << " ENTER 0 TO QUIT              " << endl;

		cin >> n;

		if (n == 1)
		{
			L + C;
		}

		else if (n == 2)
		{
			L - C;
		}

		else if (n == 3)
		{
			L.serchcontracts();
		}

		else if (n == 4)
		{
			L.printlist();
		}




	}



	/*for(int i = 0 ; i < 3 ; i++)
	{
	C + L;

	}


	L.printlist();

	L.serchcontracts();*/

	//	L.printlist();

}


CONTRACTS::CONTRACTS()
{
	office_no = new char[11];
	mobile_no = new char[11];
	home_no = new char[11];

	for (int i = 0; i < 11; i++)
	{
		office_no[i] = 0;
	}

	for (int i = 0; i < 11; i++)
	{
		mobile_no[i] = 0;
	}

	for (int i = 0; i < 11; i++)
	{
		home_no[i] = 0;
	}

}



CONTRACTS::CONTRACTS(string nam, int off[], int mob[], int hom[])
{
	name = nam;
	office_no = new char[11];
	mobile_no = new char[11];
	home_no = new char[11];


	for (int i = 0; i < 11; i++)
	{
		office_no[i] = off[i];
	}

	for (int i = 0; i < 11; i++)
	{
		mobile_no[i] = mob[i];
	}

	for (int i = 0; i < 11; i++)
	{
		home_no[i] = hom[i];
	}

}

LIST::LIST()
{

	listsize = 2;
	C = new CONTRACTS[listsize];
	no_of_records = 0;

}

LIST::LIST(int list_s, int no_r)
{

	listsize = list_s;
	no_of_records = no_r;

}

LIST::LIST(const LIST & L)
{

	listsize = L.listsize;
	no_of_records = L.no_of_records;
	C = new CONTRACTS[listsize];
	for (int i = 0; i < listsize; i++)
	{
		C[i] = L.C[i];
	}
}



void CONTRACTS::input_contract()
{
	cout << " ENTER NAME " << endl;
	cin >> name;

	cout << "ENTER office NUMBER" << endl;
	for (int i = 0; i < 11; i++)
	{
		cin >> office_no[i];
	}

	cout << "ENTER mobile NUMBER" << endl;

	for (int i = 0; i < 11; i++)
	{
		cin >> mobile_no[i];
	}

	cout << "ENTER home NUMBER" << endl;

	for (int i = 0; i < 11; i++)
	{
		cin >> home_no[i];
	}
}

void CONTRACTS::print_contract()
{
	cout << "NAME = " << name << endl;
	cout << "OFFICE NUMBER = ";
	for (int i = 0; i < 11; i++)
	{
		cout << office_no[i];
	}

	cout << endl;

	cout << "MOBILE NUMBER = ";



	for (int i = 0; i < 11; i++)
	{
		cout << mobile_no[i];
	}

	cout << endl;

	cout << "HOME NUMBER = ";


	for (int i = 0; i < 11; i++)
	{
		cout << home_no[i];
	}

	cout << endl;

}

void LIST::inputlist(const CONTRACTS & C1)
{
	CONTRACTS * TEMP = nullptr;
	no_of_records = no_of_records + 1;
	if (no_of_records < listsize)
	{
		C[no_of_records - 1].input_contract();

	}

	else
	{
		TEMP = new CONTRACTS[listsize + listsize];

		for (int i = 0; i < listsize; i++)
		{
			TEMP[i] = C[i];

		}



		delete[] C;
		C = TEMP;
		listsize = listsize + listsize;

		C[no_of_records - 1].input_contract();

	}



}



const LIST & LIST::operator=(const LIST & L)
{
	if (C != NULL)
	{
		delete[] C;

	}

	listsize = L.listsize;
	no_of_records = L.no_of_records;
	C = new CONTRACTS[listsize];
	for (int i = 0; i < listsize; i++)
	{
		C[i] = L.C[i];
	}
	return *this;

}

LIST LIST::operator+(const CONTRACTS & C1)
{
	CONTRACTS * TEMP = nullptr;
	no_of_records = no_of_records + 1;
	if (no_of_records < listsize)
	{
		C[no_of_records - 1].input_contract();

	}

	else
	{
		TEMP = new CONTRACTS[listsize + listsize];

		for (int i = 0; i < listsize; i++)
		{
			TEMP[i] = C[i];

		}



		delete[] C;
		C = TEMP;
		listsize = listsize + listsize;

		C[no_of_records - 1].input_contract();

	}

	return *this;

}

bool exactmatch(char* a, char* b)
{
	for (int i = 0; i < 11; i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}

	}


	return true;
}


LIST LIST::operator-(const CONTRACTS & C1)
{
	CONTRACTS * TEMP = nullptr;
	int n = 0;
	string nam;
	cin.ignore();
	cout << " PRESS 1 TO REMOVE CONTRACT BY NAME " << endl;
	cout << " PRESS 2 TO REMOVE CONTRACT BY NUMBER " << endl;
	cin >> n;

	if (n == 1)
	{
		cout << " ENTER THE NAME OF CONTRACT " << endl;
		cin >> nam;

		for (int i = 0; i < listsize; i++)
		{
			if (nam == C[i].getnam())
			{
				C[i].setname("FFFF");
				no_of_records = no_of_records - 1;
			}

		}

		//===================
		int j = 0;


		if (no_of_records >= (listsize / 2))
		{
			CONTRACTS *TEMP1 = new CONTRACTS[listsize];

			for (int i = 0; i< listsize; i++)
			{
				if (C[i].getnam() != "FFFF")
				{
					TEMP1[j] = C[i];
					j++;
				}
			}

			delete[] C;
			C = TEMP1;

		}

		else
		{
			j = 0;


			if (no_of_records < (listsize / 2))
			{
				CONTRACTS *TEMP2 = new CONTRACTS[listsize / 2];

				for (int i = 0; i < no_of_records + 1; i++)
				{
					if (C[i].getnam() != "FFFF")
					{
						TEMP2[j] = C[i];
						j++;
					}
				}

				listsize = listsize / 2;
				delete[] C;
				C = TEMP2;
			}


		}
		//===================
	}
	//---------------------------------------------------------
	else if (n == 2)
	{
		int option = 0;
		char * number = new char[11];

		cin.ignore();
		cout << " ENTER 1 TO REMOVE BY MOBILE NO " << endl;
		cout << " ENTER 2 TO REMOVE BY OFFICE NO " << endl;
		cout << " ENTER 3 TO REMOVE BY HOME   NO " << endl;
		cin >> option;

		if (option == 1)
		{
			cout << " ENTER MOBILE NUMBER " << endl;
			for (int i = 0; i < 11; i++)
			{
				cin >> number[i];
			}

			for (int i = 0; i < listsize; i++)
			{

				if (exactmatch(C->getmobile(), number))
				{
					C->setmobile("00000000000");

				}

			}

		}

		else if (option == 2)
		{
			cout << " ENTER office NUMBER " << endl;
			for (int i = 0; i < 11; i++)
			{
				cin >> number[i];
			}

			for (int i = 0; i < listsize; i++)
			{

				if (exactmatch(C->getoffice(), number))
				{
					C->setoffice("00000000000");

				}

			}

		}

		else if (option == 3)
		{
			cout << " ENTER home NUMBER " << endl;
			for (int i = 0; i < 11; i++)
			{
				cin >> number[i];
			}

			for (int i = 0; i < listsize; i++)
			{

				if (exactmatch(C->gethome(), number))
				{
					C->sethome("00000000000");

				}

			}

		}


		//++++++++++++++++++++++++++++++++++++++++++++++++++
		for (int i = 0; i < listsize; i++)
		{
			if (exactmatch(C[i].getmobile(), "00000000000") && exactmatch(C[i].getoffice(), "00000000000") && exactmatch(C[i].gethome(), "00000000000"))
			{
				C[i].setname("FFFF");
				no_of_records = no_of_records - 1;
			}

		}

		//===================
		int j = 0;


		if (no_of_records >= (listsize / 2))
		{
			CONTRACTS *TEMP1 = new CONTRACTS[listsize];

			for (int i = 0; i< listsize; i++)
			{
				if (C[i].getnam() != "FFFF")
				{
					TEMP1[j] = C[i];
					j++;
				}
			}

			delete[] C;
			C = TEMP1;

		}

		else
		{
			j = 0;


			if (no_of_records < (listsize / 2))
			{
				CONTRACTS *TEMP2 = new CONTRACTS[listsize / 2];

				for (int i = 0; i < listsize; i++)
				{
					if (C[i].getnam() != "FFFF")
					{
						TEMP2[j] = C[i];
						j++;
					}
				}

				listsize = listsize / 2;
				delete[] C;
				C = TEMP2;
			}


		}
		//===================

		//++++++++++++++++++++++++++++++++++++++++++++++++++

	}
	//----------------------------------------------------------
	LIST L;
	return L;

}

void LIST::serchcontracts()
{
	int n = 0;
	cin.ignore();
	string nam;
	char* number = new char[11];
	cout << " ENTER 1 TO SERCH CONTRACTS BY NAME   " << endl;
	cout << " ENTER 2 TO SERCH CONTRACTS BY NUMBER " << endl;
	cin >> n;

	if (n == 1)
	{
		cin.ignore();
		cout << " ENTER NAME OF THE CONTRACT " << endl;
		cin >> nam;

		for (int i = 0; i < listsize; i++)
		{
			if (nam == C[i].getnam())
			{
				cout << "              ------------------CONTRACT FOUND----------------------" << endl;
				C[i].print_contract();

			}

		}


	}


	else if (n == 2)
	{
		int option = 0;
		cin.ignore();
		cout << " ENTER 1 to serch contract by mobile number " << endl;
		cout << " ENTER 2 to serch contract by office number " << endl;
		cout << " ENTER 3 to serch contract by home number   " << endl;

		cin >> option;

		if (option == 1)
		{

			cout << " ENTER MOBILE NUMBER " << endl;
			for (int i = 0; i < 11; i++)
			{
				cin >> number[i];
			}

			for (int i = 0; i < listsize; i++)
			{
				if (exactmatch(number, C[i].getmobile()))
				{
					cout << "              ------------------CONTRACT FOUND----------------------" << endl;
					C[i].print_contract();

				}

			}

		}

		else if (option == 2)
		{

			cout << " ENTER office NUMBER " << endl;
			for (int i = 0; i < 11; i++)
			{
				cin >> number[i];
			}

			for (int i = 0; i < listsize; i++)
			{
				if (exactmatch(number, C[i].getoffice()))
				{
					cout << "              ------------------CONTRACT FOUND----------------------" << endl;
					C[i].print_contract();

				}

			}

		}

		else if (option == 3)
		{

			cout << " ENTER home NUMBER " << endl;
			for (int i = 0; i < 11; i++)
			{
				cin >> number[i];
			}

			for (int i = 0; i < listsize; i++)
			{
				if (exactmatch(number, C[i].gethome()))
				{
					cout << "              ------------------CONTRACT FOUND----------------------" << endl;
					C[i].print_contract();

				}

			}

		}


	}



}

CONTRACTS::CONTRACTS(const CONTRACTS & c1)
{
	name = c1.name;

	office_no = new char[11];
	mobile_no = new char[11];
	home_no = new char[11];


	for (int i = 0; i < 11; i++)
	{
		office_no[i] = c1.office_no[i];
	}

	for (int i = 0; i < 11; i++)
	{
		mobile_no[i] = c1.mobile_no[i];
	}

	for (int i = 0; i < 11; i++)
	{
		home_no[i] = c1.home_no[i];
	}


}

const CONTRACTS & CONTRACTS::operator=(const CONTRACTS & c1)
{
	name = c1.name;

	office_no = new char[11];
	mobile_no = new char[11];
	home_no = new char[11];


	for (int i = 0; i < 11; i++)
	{
		office_no[i] = c1.office_no[i];
	}

	for (int i = 0; i < 11; i++)
	{
		mobile_no[i] = c1.mobile_no[i];
	}

	for (int i = 0; i < 11; i++)
	{
		home_no[i] = c1.home_no[i];
	}

	return *this;

}
