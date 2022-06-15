#include<iostream>
using namespace std;


//defining a new datatype
class Car{

	private:
	float price; // imp stuff so make it private i.e no read or write outside of class

	public:   // making data members public
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
		if(p>0) price=p;
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
	Car c;
	c.model_no=112;
	c.name[0]='B';	c.name[1]='M';	c.name[2]='W';	c.name[3]='\0';

	c.set_price(-10); //calling the member function to access private data member

	c.print();
	return 0;

}