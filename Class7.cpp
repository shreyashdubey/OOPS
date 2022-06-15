// Operator Overloading
#include<iostream>
using namespace std;

class Complex
{
	int real;
	int img;
public:
	Complex()
	{
		real=0;
		img=0;
	}
	//Parameterised Constructor
	Complex(int r,int i)
	{
		real=r;
		img=i;
	}
	// Copy Constructor
	// It exists by default
	void setReal(const int r)
	{
		real = r;
	}
	void setImg(const int i)
	{
		img = i;
	}
	int getReal() const
	{
		return real;
	}
	int getImg() const
	{
		return img;
	}
	void print()
	{
		if(img>0)
		{
			cout<<real<<" +"<<img<<"i"<<endl;
		}
		else
		{
			cout<<real<<" "<<img<<"i"<<endl;
		}
	}
	void add(const Complex &x)
	{
		real+=x.real;
		img+=x.img;
	}
	void operator+(const Complex &x)
	{
		real+=x.real;
		img+=x.img;
	}
	void operator!()
	{
		img*=-1;
	}
	int operator[](string s)
	{
		if(s == "real")
		{
			return real;
		}
		else 
		{
			return img;
		}
	}
};

// void operator>>(istream& inputobj, Complex &c)
// {
// 	int r1,i1; 
// 	inputobj>>r1>>i1;
// 	c.setReal(r1);
// 	c.setImg(i1);
// }
// void operator<<(ostream& outputobj, Complex &c)
// {
// 	c.print();
// }
istream& operator>>(istream& inputobj, Complex &c)
{
	int r1,i1; 
	inputobj>>r1>>i1;
	c.setReal(r1);
	c.setImg(i1);
	return inputobj; // we input the object of the istream class as reference and return it also as reference because we don't want to make any changes.
}
ostream& operator<<(ostream& outputobj, Complex &c)
{
	c.print();
	return outputobj;
}

int main()
{
	#ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
	Complex c1(5,3);
	Complex c2;
	c2.setReal(4);
	c2.setImg(-2);

	c1.print();
	c2.print();

	//c1.add(c2);
	//c1.print();
	

	// Now if you want to add without a function
	// like c1 + c2;
	//c1+c2; // c1 becomes the calling object and c2 becomes the parameter
	//c1.print();
	
	//!c1;
	//c1.print();

	//[]
	//cout<<c1["real"]; // here "real" is the parameter;

	//<<,>>
	//we will use these to go with our cin and cout
	// cin and cout are special objects in iostream library

	// ok to implement the normal way we learned till now
	// we'll have to write the code like this
	// cin >> d; here d of complex type is passed as parameter to cin of istream type
	// and to make that work we'll have to edit the header file which is not a good idea
	// Now what we'll do is fn << (first parameter, second parameter)
	// new function with << operator and accepts cin as first operator and complex object as 2nd parameter
	// by this we are eliminating the concept of calling object and we're passing both the objects as parameters 
	// we can simply define a function which is outside of both the classes, it is simply a function in our code.
	//Complex C1;
	//cin>>C1;
	//cout<<C1;


	// Now if you want to input 2 complex number
	//Complex D1,D2;
	//cin>>D1>>D2;
	//cout<<D1<<D2;
	// No the above code will not work
	// because the return type of the function is void
	// but if we make the return type of the function as cin and cout respectively then it will work, this is also called cascading of operator;
	// same can be done for +,-,*,etc operators
	Complex D1,D2;
	cin>>D1>>D2;
	cout<<D1<<D2;
}