#include<iostream>
#include<string.h>
using namespace std;


//defining a new datatype
class Car{
	private:
	float price; // imp stuff so make it private i.e no read or write outside of class

	public:   // making data members public
	Car() // Constructor
	{
		cout<<"Inside Car Constructor"<<endl;
	}
	Car(float p,int m,char *n) //Parameterised Constructor
	{ 
		price=p; model_no=m; strcpy(name,n);
	}
	Car(Car &x) // only pass by reference 
	{
		cout<<"Copy Constructor"<<endl;
		price=x.price;
		model_no=x.model_no;
		strcpy(name,x.name);
	}
	int model_no;
	char name[20];

	// Making Member functions
	float get_discounted_price(float x)
	{
		return price*(1.0-x);
	}
	void print()
	{
		cout<<"Name "<<name<<endl;
		cout<<"Price "<<price<<endl;
		cout<<"Model No "<<model_no<<endl;
	}
	float apply_discount(float x)
	{
		price=price*(1.0-x);
		return price;
	}
	void set_price(float p) //Setters
	{
		float minimum_selling_price=111;
		if(p>minimum_selling_price) price=p;
		else price=minimum_selling_price;
	}
	float get_price() // Getters
	{
		return price; 
	}
};


int main()
{
	#ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
	//Car c;
	//c.model_no=112;
	//c.name[0]='B';	c.name[1]='M';	c.name[2]='W';	c.name[3]='\0';

	//c.set_price(-10); //calling the member function to access private data member
	
	//c.print();

  
 	cout<<"Car D"<<endl;
	Car d(222,333,"Audi");
	d.print();

	cout<<"Car E"<<endl;
	Car e(d); // Copy Constructor is called, but it is invisible, so if we want to see it we'll have to overwrite the default one.
	Car f= e; // Another way of calling Copy Constructor;
	e.set_price(256);
	e.print();
	return 0;

}