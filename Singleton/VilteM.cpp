#include "Singleton.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Ivedimas(int A[], int & n)
{
	ifstream f1 ("Autobusai.txt");

	f1>>n;

	for(int i=0; i<n; i++)
	{
		f1>>A[i];
	}
}

void Vidurkis(int A[], int n, double & vid)
{
	int sum=0;
	int kiek=0;
	for(int i=0; i<n; i++)
	{
		sum+=A[i];
		kiek++;
	}

	vid=(double)sum/kiek;
}

void Spausdinimas(int A[], int n, ofstream & rez)
{

	rez<<"Autobuso nr      Autobuso marsruto ilgis"<<endl;
	rez<<"----------------------------------------"<<endl;

    for(int i=0; i<n; i++)
	{  
		rez<<left<<setw(5)<<i+1<< "            "<<A[i]<<endl;
	}
}



int main()
{
	Singleton::Instance()->writeToLogFile();

	ifstream f1 ("Autobusai.txt");
	ofstream f2 ("Rezultatai.txt");

	int A[100];
	double vid1;
	int n;

	Ivedimas(A, n);
	Vidurkis(A, n, vid1);
	Spausdinimas(A, n, f2);

	f2<<"Vidutinis autobusu marsrutu ilgis yra "<<vid1;

	return 0;
}



	


