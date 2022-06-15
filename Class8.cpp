#include<iostream>
using namespace std;
// User Defined Vector Class
class Vector
{
   // Data Members and some functions
	int *arr;
	int cs;
	int maxSize;
public:
	Vector(int defaultSize=4)
	{
		maxSize = defaultSize;
		cs = 0;
		arr = new int[maxSize];
	}
	void push_back(int data)
	{
		if(cs==maxSize)
		{
			//Doubling Operations
			int *oldArr = arr; // arr is class member so it will not be destroyed
			arr =new int[2*maxSize];
			 maxSize *= 2;
			for(int i=0;i<cs;i++)
			{
				arr[i] = oldArr[i];
			}
			//delete the old arr
			delete [] oldArr;
		}
		arr[cs]=data;
		cs++;
	}
	bool empty()
	{
		return cs==0;
	}
	void pop_back()
	{
		if(!empty())
		{
			cs--;	
		}
	}
	void print()
	{
		for(int i=0;i<cs;i++) cout<<arr[i]<<endl;
	}
	int at(int i)
	{
		return arr[i];
	}
	int getSize()
	{
		return cs;
	}
	int getMaxSize()
	{
		return maxSize;
	}
	// we can define operators over user defined class
	void operator()(string s)
	{
		cout<<"() got overloaded"<<endl;
		cout<<s<<endl;
	}
	int& operator[](int i)
	{
		//these two work same but are different 
		//return at(i);
		return arr[i];
	}
	
};
ostream& operator<<(ostream &outer, Vector &x)
	{
		outer<<"In overloaded << operator"<<endl;
		x.print(); 
		return outer;
	}
// istream& operator>>(istream &inputer, Vector &x)
// 	{

// 	}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	
	Vector v(1000);
	
	for(int i=0;i<=3;i++)
	{
		v.push_back(i*i);
	}
	//v.print();
	//cout<<v.getMaxSize()<<endl;
	v.push_back(6);
	//cout<<v.getMaxSize()<<endl;
	//cout<<v[4]; // this will give error
	//v("Hello"); // Round brackets overloading, this is looking like a function, also known as Functor[Functional Objects]
	
	// Square bracker overloaded
	cout<<v[2];

	// cout<<v print the whole vector
	// so we overload the << operator
	//cout<<v;

	//Vector fun(v);
	//cout<<v<<fun;

	//now for v[2]=8;
	// v[2] += 6;
	// cout<<v[2];
	// return int& from the overloaded []
	cout<<v<<endl;
	v[2]+=6;
	cout<<v[2]<<endl;
	v[2]*=2;
	cout<<v[2]<<endl;
	v[2]>>=1;
	cout<<v[2]<<endl;
	return 0;

}