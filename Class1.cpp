#include<iostream>
using namespace std;


//defining a new datatype
class Car{
	public:   // making data members public
	float price;
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
};


int main()
{
	#ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
	Car c;
	//cout<<sizeof(c);
	c.price=100;
	c.model_no=112;
	c.name[0]='B';
	c.name[1]='M';
	c.name[2]='W';
	c.name[3]='\0';

	//cout<<c.name<<" "<<c.model_no<<" "<<c.price<<endl;

	//Using Member Functions
	cout<<"Enter the discount you want to give ";
	float discount; cin>>discount;
	cout<<c.apply_discount(discount)<<endl;
	c.print();
	return 0;

}