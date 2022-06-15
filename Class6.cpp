#include<iostream>
#include<string.h>
using namespace std;

class Car{
	private:
	float price; 
	public:  
	int model_no;
	const int msp; // Const Data member created
	char *name; // Now instead making an array we have pointer to dynamic array
	Car():msp(99) // Initialization List
	{
		name=NULL;
	}
	Car(float p, int m, char *n, int minprice):price(p),msp(minprice)
	{
		model_no = m;
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}
	Car(Car &X):msp(X.msp)
	{
		price = X.price;
		model_no = X.model_no;
		// deep copy 
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}
	void operator=(Car &X) // we do the same thing as deep copy constructor
	{
		//cout<<"Copy assignment operator";
		price = X.price;
		model_no = X.model_no;
		// deep copy 
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}
	~Car()
	{
		cout<<"Inside Destructor of Car "<<name<<endl;
		if(name!=NULL)
		{
			delete []name; 
		}
	}
	void setprice(float p)
	{
		price=p;
	}
	void print() const
	{
		cout<<"Name "<<name<<endl;
		cout<<"Model no "<<model_no<<endl;
		cout<<"Price "<<price<<endl;
	}
};


int main()
{
	#ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
     Car c(100,200,"BMW",78); // Calling Parameterised Constructor
     cout<<c.msp<<endl;
     Car d; 
     d=c; // Copy COnstructor will not be called
     d.setprice(400); // Changing this value works fine
     d.name[0]='A'; // Changing this value change both the objects value.
     c.print(); 
     d.print();
     //delete c; //statically created obj cannot be deleted using delete keyword
     Car *e =new Car(10,20,"Ferrari",100);
     e->print();
     // To delete dynamically created object we have to use delete keyword
     delete e;
	return 0;

}