# include<iostream>
# include<fstream>
# include<ctime>
# include<cstring>
using namespace std;
void mainmenu();
void itemmenu();
void customermenu();
class Receipt;
int t=0;
int c = 0;
float p=0;
class item 
{
	char **Item_SKU = new char* [10000];
	char **Description = new char* [10000];
	char **Price = new char*[10000];
	char **AvailableQuantity = new char*[10000];
	char **CreationDate = new char* [10000];
	int items=3;
    
public:
	/*item()
	{
		Item_SKU = nullptr;
		Description = nullptr;
		Price = nullptr;
		AvailableQuantity = nullptr;
		CreationDate = nullptr;
		items = 0;
	}
	item(char** _Item_sku, char** _des, char** _price,char **_Avaible,char** creation,int i)
	{
		Item_SKU = new char* [10000];
		this->Item_SKU = _Item_sku;
		Description = new char* [10000];
		this->Description = _des;
		Price = new char* [10000];
		this->Price = _price;
		AvailableQuantity = new char* [10000];
		this->AvailableQuantity = _Avaible;
		CreationDate = new char* [10000];
		this->CreationDate = creation;
		items = 3;
		i = items;

	}*/
	bool searchsku(char a[])
	{
		int index;
		for (int i = 0; i <items; i++)
		{
			char* a = Item_SKU[i];
			for (int j = 0; j < strlen(a); j++)
			{
				if (a[j] = !a[j])
					break;
				if (j == strlen(a) - 1)
				{
					t = i;
					return true;
				}
			}
			return false;
		}


	}
	void print(int i) {
		cout <<"Description :"<< *Description[i];
		cout << "Price :"<<*Price[i];
		p = *Price[i];
	}
	void readingflie()
	{
		ifstream file;
		file.open("Items.txt");

		if (file.is_open()) {
			char _Item_SKU[1000], _Description[1000], _CreationDate[10000];
			char pr[1000], ar[1000];
			for (int i = 0;i<items;i++)
			{
				
					
					file.getline(_Item_SKU, 1000, ';');
					Item_SKU[i] = new char[strlen(_Item_SKU)+1];
					strcpy_s(Item_SKU[i],strlen(Item_SKU[i]), _Item_SKU);
					file.getline(_Description, 1000, ';');
					Description[i] = new char[strlen(_Description)+1];
					strcpy_s(Description[i], strlen(Description[i]), _Description); 
					file.getline(pr, 1000, ';');
					Price[i] = new char[strlen(pr) + 1];
					strcpy_s(Price[i], strlen(Price[i]), pr);
					file.getline(ar, 1000, ';');
					AvailableQuantity[i] = new char [strlen(ar) + 1];
					strcpy_s(AvailableQuantity[i], strlen(AvailableQuantity[i]), ar);
					file.getline(_CreationDate, 12);
					CreationDate[i] = new char[strlen(_CreationDate)+1];
					strcpy_s(CreationDate[i],strlen(CreationDate[i]), _CreationDate);
					file.ignore();
					items++;
		
			}
		}
		file.close();
	}
	void AddNewItem()
	{
		ofstream file("Items.txt");
		if (file.is_open())
		{
			cout << "open";
			char arr[100];
			for (int i = items+1; i < 10000; i++)
			{
				file << ';';
				cout << "Enter the Sku :";
				file << arr;
				this->setitemsku(arr,i);
				file << ';';
				cout << endl << "Enter the decription :";
				file << arr;
				this->setDescription(arr,i);
				file << ';';
				cout << endl << "Enter the price :";
				file << arr;
				this->setprice(arr,i);
				file << ';';
				cout << endl << "Enter the Avaible quantity :";
				file << arr;
				this->setQuantity(arr,i);
				file << ';';
				_strdate_s(arr);
				file << arr;
				this->setdate(arr,i);
				items++;
			
			}
		}
	}
	void setitemsku(char arr[],int i)
	{
		strcpy_s(Item_SKU[i], strlen(arr), arr);	
	}
	void setDescription(char arr[], int i)
	{
		strcpy_s(Description[i], strlen(arr), arr);
	}
	void setdate(char arr[], int i)
	{
		strcpy_s(CreationDate[i], strlen(arr), arr);
	}
	void setprice(char pr[], int i)
	{
		strcpy_s(Price[i], strlen(pr), pr);
	}
	void setQuantity(char ar[], int i)
	{
		strcpy_s(CreationDate[i], strlen(ar), ar);
	}
	void ModifyItemDetails()
	{
		char arr[100];
		cout << "Enter the sku : ";
		cin >> arr;
		int index ;
		for (int i = 0; i < items; i++)
		{
			char *a = Item_SKU[i];
			for (int j = 0; j < strlen(arr); j++)
			{
				if (arr[j] = !a[j])
					break;
				if (j == strlen(arr) - 1)
					index = i;
			}
		}
		cout << "1-Item_SKU : "<< Item_SKU[index]<<endl;
		cout <<"2-Description"<< Description[index]<<endl;
		cout <<"3-Price"<< Price[index] << endl;
		cout <<"4-AvailableQuantity"<< AvailableQuantity[index] << endl;
		cout <<"CreationDate"<< CreationDate[index] << endl;
		cout << "which one you want to modify : ";
        int a;
		cin >> a;
		char temp[500];
		switch (a)
		{
		case 1:
			cout << "Enter the new Item_SKU : ";
			cin >> temp;
			setitemsku(temp, index);
			break;
		case 2:
			cout << "Enter the new Description : ";
			cin >> temp;
			setDescription(temp, index);
			break;
		case 3:
			cout << "Enter the new price : ";
			cin >> temp;
			setprice(temp, index);
		case 4:
			cout << "Enter the new Avaiblequantity : ";
			cin >> temp;
			setQuantity(temp, index);
		case 5:
			cout << "Enter the new CreationDate : ";
			cin >> temp;
			setdate(temp, index);
		}
		cout << "-----------------------------After modification---------------------------";
		cout << "1-Item_SKU : " << Item_SKU[index] << endl;
		cout << "2-Description" << Description[index] << endl;
		cout << "3-Price" << Price[index] << endl;
		cout << "4-AvailableQuantity" << AvailableQuantity[index] << endl;
		cout << "CreationDate" << CreationDate[index] << endl;
		int u ;
		cout << "If it is right then press 0 else 1 ";
		cin >> u;
		if (u == 0)
		{
			itemmenu();
		}
		else
		{
			this->ModifyItemDetails();
		}
		
	}
	void FindItem()
	{
		cout << "1-Item_SKU : " <<   endl;
		cout << "2-Description" <<  endl;
		cout << "3-Price" <<  endl;
		cout << "4-AvailableQuantity"  << endl;
		cout << "5-CreationDate" << endl;
		cout << "Enter the option from which you want to search the item : ";
		int q;
		cin >> q;
		char temp[500];
		int index = 0;
		switch (q)
		{
		case 1:
		 {
			cout << "Enter the Item_SKU : ";
			cin >> temp;
			for (int i = 0; i < items; i++)
			{
				char* a = Item_SKU[i];
				for (int j = 0; j < strlen(temp); j++)
				{
					if (temp[j] = !a[j])
						break;
					if (j == strlen(temp) - 1)
						index = i;
				}
			}
			cout << "Item_SKU : " << Item_SKU[index] << endl;
			cout << "Description" << Description[index] << endl;
			cout << "Price" << Price[index] << endl;
			cout << "AvailableQuantity" << AvailableQuantity[index] << endl;
			cout << "CreationDate" << CreationDate[index] << endl;
			index = 0;
			break;
		 }
		case 2:
		   {
			cout << "Enter the Description : ";
			cin >> temp;
			for (int i = 0; i < items; i++)
			{
				char* a = Description[i];
				for (int j = 0; j < strlen(temp); j++)
				{
					if (temp[j] = !a[j])
						break;
					if (j == strlen(temp) - 1)
						index = i;
				}
			}
			cout << "Item_SKU : " << Item_SKU[index] << endl;
			cout << "Description" << Description[index] << endl;
			cout << "Price" << Price[index] << endl;
			cout << "AvailableQuantity" << AvailableQuantity[index] << endl;
			cout << "CreationDate" << CreationDate[index] << endl;
			index = 0;
			break;
		   }
		case 3:
			cout << "Enter the price : ";
			cin >> temp;
			for (int i = 0; i < items; i++)
			{
				char* a = Price[i];
				for (int j = 0; j < strlen(temp); j++)
				{
					if (temp[j] = !a[j])
						break;
					if (j == strlen(temp) - 1)
						index = i;
				}
			}
			cout << "Item_SKU : " << Item_SKU[index] << endl;
			cout << "Description" << Description[index] << endl;
			cout << "Price" << Price[index] << endl;
			cout << "AvailableQuantity" << AvailableQuantity[index] << endl;
			cout << "CreationDate" << CreationDate[index] << endl;
			index = 0;
			break;
		case 4:
			cout << "Enter the Avaiblequantity : ";
			cin >> temp;
			for (int i = 0; i < items; i++)
			{
				char* a = AvailableQuantity[i];
				for (int j = 0; j < strlen(temp); j++)
				{
					if (temp[j] = !a[j])
						break;
					if (j == strlen(temp) - 1)
						index = i;
				}
				cout << "Item_SKU : " << Item_SKU[index] << endl;
				cout << "Description" << Description[index] << endl;
				cout << "Price" << Price[index] << endl;
				cout << "AvailableQuantity" << AvailableQuantity[index] << endl;
				cout << "CreationDate" << CreationDate[index] << endl;
			}
			index = 0;
			break;
		case 5:
			cout << "Enter the CreationDate : ";
			cin >> temp;
			for (int i = 0; i < items; i++)
			{
				char* a = CreationDate[i];
				for (int j = 0; j < strlen(temp); j++)
				{
					if (temp[j] = !a[j])
						break;
					if (j == strlen(temp) - 1)
						index = i;
				}
			}
			cout << "Item_SKU : " << Item_SKU[index] << endl;
			cout << "Description" << Description[index] << endl;
			cout << "Price" << Price[index] << endl;
			cout << "AvailableQuantity" << AvailableQuantity[index] << endl;
			cout << "CreationDate" << CreationDate[index] << endl;
			index = 0;
			break;
        }
	}
	void RemoveExistingItem()
	{
		char temp[500];
		cout << "Enter the item's SKU which you want to remove";
		cin >> temp;
		int index = 0;
		for (int i = 0; i < items; i++)
		{
			char* a = Item_SKU[i];
			for (int j = 0; j < strlen(temp); j++)
			{
				if (temp[j] = !a[j])
					break;
				if (j == strlen(temp) - 1)
					index = i;
			}
		}
		for (int i = index; i <= items; i++)
		{
			*Item_SKU[i] = *Item_SKU[i + 1];
			*Description[i] = *Description[i + 1];
			*Price[i] = *Price[i + 1];
			*AvailableQuantity[i] = *AvailableQuantity[i + 1];
			*CreationDate[i] = *CreationDate[i + 1];
		}
		items--;

	}
};
class Customer
{
	char** CNIC =new char* [10000];
	char** Name =new char* [10000];
	char** Address= new char* [10000];
	char** Phone =new char* [10000];
	char** Email =new char* [10000];
	char** Type =new char* [10000];
	char** AmountPayable= new char* [10000];
	char** SalesLimit =new char* [10000];
	int customers = 1;
public:
	bool searchcnic(char a[])
	{
		int index;
		for (int i = 0; i < customers; i++)
		{
			char* a = CNIC[i];
			for (int j = 0; j < strlen(a); j++)
			{
				if (a[j] = !a[j])
					break;
				if (j == strlen(a) - 1)
				{
					c = i;
					return true;
				}
			}
			return false;
		}
		

	}
	void readingflie()
	{
		ifstream file;
		file.open("Customers.txt");

		if (file.is_open()) {
			char _CNIC[15], _Name[40], _Address[100], _Phone[30], _Email[50], _Type[1], _AmountPayable[100], _saleslimit[100];
			for (int i = 0; i < customers; i++)
			{


				file.getline(_CNIC, 15, ';');
				CNIC[i]= new char[strlen(_CNIC) + 1];
				strcpy_s(CNIC[i], strlen(CNIC[i]), _CNIC);
				file.getline(_Name, 40, ';');
				Name[i] = new char[strlen(_Name) + 1];
				strcpy_s(Name[i], strlen(Name[i]), _Name);
				file.getline(_Address, 100, ';');
				Address[i] = new char[strlen(_Address) + 1];
				strcpy_s(Address[i], strlen(Address[i]),_Address);
				file.getline(_Phone, 30, ';');
				Phone[i] = new char[strlen(_Phone) + 1];
				strcpy_s(Phone[i], strlen(Phone[i]), _Phone);
				file.getline(_Email, 50, ';');
				Email[i] = new char[strlen(_Email) + 1];
				strcpy_s(Email[i], strlen(Email[i]), _Email);
				file.getline(_AmountPayable, 50, ';');
				AmountPayable[i] = new char[strlen(_AmountPayable) + 1];
				strcpy_s(AmountPayable[i], strlen(AmountPayable[i]), _AmountPayable);
				file.getline(_saleslimit, 50, ';');
				SalesLimit[i] = new char[strlen(_saleslimit) + 1];
				strcpy_s(SalesLimit[i], strlen(SalesLimit[i]), _saleslimit);
				file.ignore();
				customers++;
			}
		}
		file.close();
	}

	void setcinc(char cinc[],int i)
	{
		strcpy_s(CNIC[i], strlen(cinc), cinc);

	}
	void setname(char name[],int i)
	{
		strcpy_s(Name[i], strlen(name), name);

	}
	void setaddress(char address[], int i)
	{

		strcpy_s(Address[i], strlen(address), address);
	}
	void setphone(char phone[], int i)
	{
		strcpy_s(Phone[i], strlen(phone), phone);
	}
	void setemail(char email[], int i)
	{
		strcpy_s(Email[i], strlen(email), email);
	}
	void settype(char type[], int i)
	{
		strcpy_s(Type[i], strlen(type), type);
	}
	void setAmountPay(char am[], int i)
	{
		strcpy_s(AmountPayable[i], strlen(am), am);
	}
	void setsalesperlimit(char Sales[], int i)
	{
		strcpy_s(SalesLimit[i], strlen(Sales), Sales);
	}
	int getcusomers()
	{
		return customers;
	}
	char getcinc(int i)
	{
		return *CNIC[i];
	}
	char getname(int i)
	{
		return *Name[i];
	}
	char getaddress(int i)
	{
		return *Address[i];
	}
	char getphone(int i)
	{
		return *Phone[i];
	}
	char getemail(int i)
	{
		return *Email[i];
	}
	char gettype(int i)
	{
		return *Type[i];
	}
	void AddNewCustomer()
	{
		ofstream file("Customers.txt");
		if (file.is_open())
		{
			cout << "open";
			char arr[100];
			for (int i = customers + 1; i < 10000; i++)
			{
				file << ';';
				cout << "Enter the CINC :";
				file << arr;
				this->setcinc(arr, i);
				file << ';';
				cout << endl << "Enter the Name :";
				file << arr;
				this->setname(arr, i);
				file << ';';
				cout << endl << "Enter the Address :";
				file << arr;
				this->setaddress(arr, i);
				file << ';';
				cout << endl << "Enter the Phone :";
				file << arr;
				this->setphone(arr, i);
				file << ';';
				cout << endl << "Enter the email :";
				file << arr;
				this->setemail(arr, i);
				file << ';';
				cout << endl << "Enter the type :";
				file << arr;
				this->settype(arr, i);
				file << ';';
				cout << endl << "Enter the Amount Payable :";
				file << arr;
				this->setAmountPay(arr, i);
				file << ';';
				cout << endl << "Enter the Sales limit :";
				file << arr;
				this->setsalesperlimit(arr, i);
				customers++;
			}
		}
	}
	void ModifyCustomerDetails()
	{
		
		char arr[100];
		cout << "Enter the CNIC : ";
		cin >> arr;
		int index ;
		for (int i = 0; i < customers; i++)
		{
			char *a = CNIC[i];
			for (int j = 0; j < strlen(arr); j++)
			{
				if (arr[j] = !a[j])
					break;
				if (j == strlen(arr) - 1)
					index = i;
			}
		}
		cout << "1-CNIC : "<< CNIC[index]<<endl;
		cout <<"2-Name : "<< Name[index]<<endl;
		cout <<"3-Address : "<< Address[index] << endl;
		cout <<"4-Phone : "<< Phone[index] << endl;
		cout <<"5-Email : "<< Email[index] << endl;
		cout << "6-Type : " << Type[index] << endl;
		cout << "7-Amount Payable : " << AmountPayable[index] << endl;
		cout << "8-Sales Limit : " << SalesLimit[index] << endl;
		cout << "Which one you want to modify : ";
        int a;
		cin >> a;
		char temp[500];
		switch (a)
		{
		case 1:
			cout << "Enter the new CNIC : ";
			cin >> temp;
			setcinc(temp, index);
			break;
		case 2:
			cout << "Enter the new NAME : ";
			cin >> temp;
			setname(temp, index);
			break;
		case 3:
			cout << "Enter the new Address : ";
			cin >> temp;
			setaddress(temp, index);
			break;
		case 4:
			cout << "Enter the new Phone : ";
			cin >> temp;
			setphone(temp, index);
			break;
		case 5:
			cout << "Enter the new Email : ";
			cin >> temp;
			setemail(temp, index);
			break;
		case 6:
			cout << "Enter the new type : ";
			cin >> temp;
			settype(temp, index);
			break;
		case 7:
			cout << "Enter the new Amouny Payable : ";
			cin >> temp;
			setAmountPay(temp, index);
			break;
		case 9:
			cout << "Enter the new Sales Limit : ";
			cin >> temp;
			setsalesperlimit(temp, index);
			break;

		}
		cout << "-----------------------------After modification---------------------------";
		cout << "1-CNIC : " << CNIC[index] << endl;
		cout << "2-Name : " << Name[index] << endl;
		cout << "3-Address : " << Address[index] << endl;
		cout << "4-Phone : " << Phone[index] << endl;
		cout << "5-Email : " << Email[index] << endl;
		cout << "6-Type : " << Type[index] << endl;
		cout << "7-Amount Payable : " << AmountPayable[index] << endl;
		cout << "8-Sales Limit : " << SalesLimit[index] << endl;

		int u ;
		cout << "If it is right then press 0 else 1 ";
		cin >> u;
		if (u == 0)
		{
		    customermenu();
		}
		else
		{
			this->ModifyCustomerDetails();
		}

	}
	void FindCustomer()
	{
		cout << "1-CNIC : " <<  endl;
		cout << "2-Name : "<< endl;
		cout << "3-Address : "  << endl;
		cout << "4-Phone : " << endl;
		cout << "5-Email : "  << endl;
		cout << "6-Type : "  << endl;
		cout << "7-Amount Payable : "  << endl;
		cout << "8-Sales Limit : "<< endl;
		cout << "Enter the option from which you want to search the customer : ";
		int q;
		cin >> q;
		char temp[500];
		int index = 0;
		switch (q)
		{
		case 1:
			char ar[100];
			cout << "Enter the CNIC : ";
			cin >> ar;
			for (int i = 0; i < customers; i++)
			{
				char* a = CNIC[i];
				for (int j = 0; j < strlen(ar); j++)
				{
					if (ar[j] = !a[j])
						break;
					if (j == strlen(ar) - 1)
						index = i;
				}
			}
			cout << "1-CNIC : " << CNIC[index] << endl;
			cout << "2-Name : " << Name[index] << endl;
			cout << "3-Address : " << Address[index] << endl;
			cout << "4-Phone : " << Phone[index] << endl;
			cout << "5-Email : " << Email[index] << endl;
			cout << "6-Type : " << Type[index] << endl;
			cout << "7-Amount Payable : " << AmountPayable[index] << endl;
			cout << "8-Sales Limit : " << SalesLimit[index] << endl;
			index = 0;
			break;
		case 2:
			char arr[100];
			cout << "Enter the Name : ";
			cin >> arr;
			for (int i = 0; i < customers; i++)
			{
				char* a = Name[i];
				for (int j = 0; j < strlen(arr); j++)
				{
					if (arr[j] = !a[j])
						break;
					if (j == strlen(arr) - 1)
						index = i;
				}
			}
			cout << "1-CNIC : " << CNIC[index] << endl;
			cout << "2-Name : " << Name[index] << endl;
			cout << "3-Address : " << Address[index] << endl;
			cout << "4-Phone : " << Phone[index] << endl;
			cout << "5-Email : " << Email[index] << endl;
			cout << "6-Type : " << Type[index] << endl;
			cout << "7-Amount Payable : " << AmountPayable[index] << endl;
			cout << "8-Sales Limit : " << SalesLimit[index] << endl;
			index = 0;
			break;
		case 3:
			char arrr[100];
			cout << "Enter the Address : ";
			cin >> arrr;
			for (int i = 0; i < customers; i++)
			{
				char* a = Address[i];
				for (int j = 0; j < strlen(arrr); j++)
				{
					if (arrr[j] = !a[j])
						break;
					if (j == strlen(arrr) - 1)
						index = i;
				}
			}
			cout << "1-CNIC : " << CNIC[index] << endl;
			cout << "2-Name : " << Name[index] << endl;
			cout << "3-Address : " << Address[index] << endl;
			cout << "4-Phone : " << Phone[index] << endl;
			cout << "5-Email : " << Email[index] << endl;
			cout << "6-Type : " << Type[index] << endl;
			cout << "7-Amount Payable : " << AmountPayable[index] << endl;
			cout << "8-Sales Limit : " << SalesLimit[index] << endl;
			index = 0;
			break;
		case 4:
			char arrrr[100];
			cout << "Enter the Phone : ";
			cin >> arrrr;
			for (int i = 0; i < customers; i++)
			{
				char* a = Phone[i];
				for (int j = 0; j < strlen(arrrr); j++)
				{
					if (arrrr[j] = !a[j])
						break;
					if (j == strlen(arrrr) - 1)
						index = i;
				}
			}
			cout << "1-CNIC : " << CNIC[index] << endl;
			cout << "2-Name : " << Name[index] << endl;
			cout << "3-Address : " << Address[index] << endl;
			cout << "4-Phone : " << Phone[index] << endl;
			cout << "5-Email : " << Email[index] << endl;
			cout << "6-Type : " << Type[index] << endl;
			cout << "7-Amount Payable : " << AmountPayable[index] << endl;
			cout << "8-Sales Limit : " << SalesLimit[index] << endl;
			index = 0;
			break;
		case 5:
			char r[100];
			cout << "Enter the email : ";
			cin >> r;
			for (int i = 0; i < customers; i++)
			{
				char* a = Email[i];
				for (int j = 0; j < strlen(r); j++)
				{
					if (r[j] = !a[j])
						break;
					if (j == strlen(r) - 1)
						index = i;
				}
			}
			cout << "1-CNIC : " << CNIC[index] << endl;
			cout << "2-Name : " << Name[index] << endl;
			cout << "3-Address : " << Address[index] << endl;
			cout << "4-Phone : " << Phone[index] << endl;
			cout << "5-Email : " << Email[index] << endl;
			cout << "6-Type : " << Type[index] << endl;
			cout << "7-Amount Payable : " << AmountPayable[index] << endl;
			cout << "8-Sales Limit : " << SalesLimit[index] << endl;
			index = 0;
			break;
		case 6:
			char rr[100];
			cout << "Enter the Type : ";
			cin >> rr;
			for (int i = 0; i < customers; i++)
			{
				char* a = Type[i];
				for (int j = 0; j < strlen(rr); j++)
				{
					if (rr[j] = !a[j])
						break;
					if (j == strlen(rr) - 1)
						index = i;
					cout << "1-CNIC : " << CNIC[index] << endl;
					cout << "2-Name : " << Name[index] << endl;
					cout << "3-Address : " << Address[index] << endl;
					cout << "4-Phone : " << Phone[index] << endl;
					cout << "5-Email : " << Email[index] << endl;
					cout << "6-Type : " << Type[index] << endl;
					cout << "7-Amount Payable : " << AmountPayable[index] << endl;
					cout << "8-Sales Limit : " << SalesLimit[index] << endl;
				}
			}
			index = 0;
			break;
		case 7:
			char rrr[100];
			cout << "Enter the Amountpayable : ";
			cin >> rrr;
			for (int i = 0; i < customers; i++)
			{
				char* a = AmountPayable[i];
				for (int j = 0; j < strlen(rrr); j++)
				{
					if (rrr[j] = !a[j])
						break;
					if (j == strlen(rrr) - 1)
						index = i;
					cout << "1-CNIC : " << CNIC[index] << endl;
					cout << "2-Name : " << Name[index] << endl;
					cout << "3-Address : " << Address[index] << endl;
					cout << "4-Phone : " << Phone[index] << endl;
					cout << "5-Email : " << Email[index] << endl;
					cout << "6-Type : " << Type[index] << endl;
					cout << "7-Amount Payable : " << AmountPayable[index] << endl;
					cout << "8-Sales Limit : " << SalesLimit[index] << endl;
				}
			}
			index = 0;
			break;
		case 8:
			char rrrr[100];
			cout << "Enter the SalesLimit : ";
			cin >> rrrr;
			for (int i = 0; i < customers; i++)
			{
				char* a = SalesLimit[i];
				for (int j = 0; j < strlen(rrrr); j++)
				{
					if (rrrr[j] = !a[j])
						break;
					if (j == strlen(rrrr) - 1)
						index = i;
					cout << "1-CNIC : " << CNIC[index] << endl;
					cout << "2-Name : " << Name[index] << endl;
					cout << "3-Address : " << Address[index] << endl;
					cout << "4-Phone : " << Phone[index] << endl;
					cout << "5-Email : " << Email[index] << endl;
					cout << "6-Type : " << Type[index] << endl;
					cout << "7-Amount Payable : " << AmountPayable[index] << endl;
					cout << "8-Sales Limit : " << SalesLimit[index] << endl;
				}
			}
			index = 0;
			break;
			
		}

	}
	void RemoveExistingCustomer()
	{
		char temp[500];
		cout << "Enter the Customer's CNIC which you want to remove";
		cin >> temp;
		int index = 0;
		for (int i = 0; i < customers; i++)
		{
			char* a = CNIC[i];
			for (int j = 0; j < strlen(temp); j++)
			{
				if (temp[j] = !a[j])
					break;
				if (j == strlen(temp) - 1)
					index = i;
			}
		}
		for (int i = index; i < customers; i++)
		{
			*CNIC[i] = *CNIC[i + 1];
			*Name[i] = *Name[i + 1];
			*Address[i] = *Address[i + 1];
			*Phone[i] = *Phone[i + 1];
			*Email[i] = *Email[i + 1];
			*Type[i] = *Type[i + 1];
			*AmountPayable[i] = *AmountPayable[i + 1];
			*SalesLimit[i] = *SalesLimit[i + 1];
		}
		customers--;

	}
};
class Sales
{
	static int *SaleID;
	Customer **_cstomer;
	Receipt **_rceipt;
	item **_item;
	char **date[11];
	char **status;
public:
	void makenewsales()
	{
		int i = 0;
		SaleID =  new int[10000];
		SaleID[i] = 1;
		char date[9];
		char arr[15];
		char arrr[100];
		cout << "Sales ID :" << SaleID << endl;
		cout << "Sales Date :" << _strdate_s(date)<<endl;
		cout << "Enter CNIC :";
		cin >> arr;

		if ((*_cstomer)->searchcnic(arr) == true)
		{
			cout << endl << "Enter the item_sku :";
			cin >> arrr;
			(*_item)->searchsku(arr);
			(*_item)->print(t);
			cout << "Quantity :";
			int q;
			cin >> q;
			float Sub_total = p * q;
			cout << "Sub-Total :Rs." << Sub_total;
		}
		else
		{
			cout << "You are not a customer or rewrite the cinc";
			makenewsales();
		}

		



	}





};
class SalesLineItem
{
	static int Lineno;
	Sales* _s;
	item* _i;
	int* quantity;
public:

};
class Receipt
{
	int ReceiptNo;
	int ReceiptDate;
	Sales** _Sales;
	float Amount;
public:




};
	void itemmenu()
	{
		int n;
		cout << "----------------------Item Menu------------------------------" << endl;
		cout << endl;
		cout << "1-Add new item" << endl << "2-Update item details" << endl << "3-Find item" << endl << "4-Remove Existing Item" << endl << "5-Back to Main Menu";
		cout << endl << "Press the number :";
		cin >> n;
		item a;
		a.readingflie();
		switch (n)
		{
		    case 1:
			   a.AddNewItem();
			   break;
			case 2:
				a.ModifyItemDetails();
				break;
			case 3:
				a.FindItem();
				break;
			case 4:
				a.RemoveExistingItem();
				break;
			case 5:
				mainmenu();
				break;

		}
	}
	void customermenu()
	{
		int n;
		cout << "----------------------Customer Menu------------------------------" << endl;
		cout << endl;
		cout << "1-Add new customer" << endl << "2-Update customer details" << endl << "3-Find customer" << endl << "4-Remove Existing customer" << endl << "5-Back to Main Menu";
		cout <<endl<< "Press the number :";
		cin >> n;
		Customer b;
		switch (n)
		{
		case 1:
			b.AddNewCustomer();
			break;
		case 2:
			b.ModifyCustomerDetails();
			break;
		case 3:
			b.FindCustomer();
			break;
		case 4:
			b.RemoveExistingCustomer();
			break;
		case 5:
			mainmenu();
			break;
	
		}
	
	}
	void mainmenu()
	{
		int n;
		cout << "----------------------Main Menu------------------------------" << endl;
		cout << endl;
		cout << "1-Manage items" << endl << "2-Manage Customers" << endl << "3-Make New Sale" << endl << "4-Make Payments" << endl << "5-Exit";
		cout << endl << "Press the number :";
		cin >> n;
		switch (n)
		{
		case 1:
			itemmenu();
			break;
		case 2:
			customermenu();
			break;
		case 3:
			Sales s;

			break;
		case 4:
			break;
		case 5:
			system("cls");
			break;
		}

	}
	int main()
	{
		mainmenu();
	}