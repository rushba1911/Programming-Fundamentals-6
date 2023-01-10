#include<iostream>
using namespace std;
float taxcalculator(char type, int price);

main()
{
	int price;
	char type;
	float result;

	cout<<"Enter the price of vehicle ";
	cin>>price;
	cout<<"Enter the type of vehicle: "<<endl<<"M for Motorcycle"<<endl<<"E for Electric"<<endl<<"S for Sedan"<<endl<<"V for Van"<<endl<<"T for Truck "<<endl<<"Enter here please: ";
	cin>>type;

	result=taxcalculator(type, price);
	cout<<"Final price of the vehicle is: "<<result<<endl;
}

float taxcalculator(char type, int price)
{
	
	float taxamount;
	float taxrate;
	float finalprice;

	if (type = 'M')
	{
	taxrate=0.06;
	}
	if (type = 'E')
	{
	taxrate=0.08;
	}
	if (type = 'S')
	{
	taxrate=0.1;
	}
	if (type = 'V')
	{
	taxrate=0.12;
	}
	if (type = 'T')
	{
	taxrate=0.15;
	}
	taxamount=price*(taxrate/100);
	finalprice=price+taxamount;

	return finalprice;
}
	