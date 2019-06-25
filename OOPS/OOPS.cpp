// OOPS
#include <iostream>
#include <string.h>
using namespace std;

//-------------------BLUEPRINT/CLASS-------------

class Car{
private: //Access qualifiers
	int price;
public:
	static int count;
	char *name;
	int model;
	int seats;
	const int tyres;

	// Default Constructor
	Car():tyres(4){   //tyres are in initialisation list
		name = NULL;
		cout<<"Default Constructor"<<endl;
		count++;
	}

	// Parameterised Constructor

	Car(char *n,int p,int s,int m):tyres(4){
		cout<<"Parameterised Constructor"<<endl;
		name = new char[strlen(n)+1];
		strcpy(name,n);
		price = p;
		seats = s;
		model = m;
		count++;
	}

	// Copy Constructor

	Car(Car &x):tyres(4){ //&x bcoz Car x = a; calls copy constructor but it is not made
		cout<<"Copy Constructor"<<endl;
		price = x.price;
		model = x.model;
		seats = x.seats;
		name = new char[strlen(x.name)+1]; // deep copy
		strcpy(name,x.name); //If name = x.name values will change in all
		count++;
	}

	// Copy Assignment

	void operator=(Car X){
		cout<<"Copy Assignment"<<endl;
		price = X.price;
		seats = X.seats;
		model = X.model;
		if(name!=NULL){
			delete []name;
			name = NULL;
		}
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}

	// Copy Assignment Append

	void operator+=(Car X){
		cout<<"copy Assignment Append"<<endl;
		price += X.price;
		seats += X.seats;
		model += X.model;
		char *temp = name;
		name = new char[strlen(X.name)+strlen(name)+1];
		strcpy(name,temp);
		strcat(name,X.name);
		delete []temp;
	}

	void print()const{
			cout<<"Name: "<<name<<endl;
			cout<<"Price: "<<price<<endl;
			cout<<"Model: "<<model<<endl;
			cout<<"Tyres: "<<tyres<<endl;
			cout<<"seats: "<<seats<<endl<<endl;

	}
	void SetPrice(int p){
		if(p>=100 && p<=200) //condition in private
		price = p;
		else
			price = 110;
	}
	void GetPrice()const{
		cout<<price<<endl;
	}
	void SetName(char *n){
		if(name!=NULL){
		delete []name;
		name = NULL;
		}
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}

	//Destructor

	~Car(){
		cout<<"Deleting Car : "<<name<<endl;
		count--;
	}
};

//------------------------------------------------

int Car::count = 0;

int main(int argc, char const *argv[])
{
	Car a;
	a.SetPrice(-100);
	a.model = 200;
	a.seats = 4;
	a.SetName("BMW");
	//strcpy(a.name,"BMW");
	//a.GetPrice();

	/*To call copy constructor 
	ways:
	1. Car c(a);
	2. Car c = a;*/

	Car b("Audi",150,2,3000);


	Car d(a); //Copy

	Car e;
	e = d; //copy assignment
	e.name[0]='T';

	a += b; //Append operator

	Car *f = new Car("Farrari",200,2,5555); //Dynamic object

	a.print();
	b.print();
	d.print();
	e.print();
	(*f).print();
	cout<<"No. of cars: "<<Car::count<<endl;
	delete f; //Deleting 

	cout<<"No. of cars: "<<Car::count<<endl;
	return 0;
}