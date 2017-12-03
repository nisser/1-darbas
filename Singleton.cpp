#include "Singleton.h"
#include "iostream"
#include <fstream>

using namespace std;

ifstream in ("dalykai.txt");
ofstream out ("rezultatai.txt");

// Global static pointer used to ensure a single instance of the class.
Singleton* Singleton::m_pInstance = NULL;

/** This function is called to create an instance of the class.
Calling the constructor publicly is not allowed. The constructor
is private and is only called by this Instance function.
*/

Singleton* Singleton::Instance()
{
	if (!Singleton::m_pInstance)   // Only allow one instance of class to be generated.
		Singleton::m_pInstance = new Singleton;

	return Singleton::m_pInstance;
}

int Singleton::getNext()
{
	// Jei failas baiges, grazina NULL
	if (in.eof())
		return NULL;

	// Pasiima a
	int a;
	if (!(in >> a) || in.fail() || a<0 || a>10) {
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		return 0;
	}

	// Jei viskas ok, grazina a
	else
		return a;
}

void Singleton::printArray(int A[100][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		out << i << ") ";
		for (int y = 0; y < m; y++)
		{
			// Jei elementas nera NULL, ji spausdina, kitaip spausdintu 0
			if (A[i][y] != NULL)
				out << A[i][y] << ' ';
		}
		out << endl;
	}
	out << endl;
}

void Singleton::fillWithNull(int A[100][100])
{
	for (int i = 0; i < 100; i++)
	{
		for (int y = 0; y < 100; y++)
		{
			A[i][y] = NULL;
		}
	}
}

void Singleton::inputArray(int A[100][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < m; y++)
		{
			A[i][y] = Singleton::getNext();
		}
	}
}

void Singleton::tenFunction(int A[100][100], int n, int m){
	int tenCount=0, TOPtencount=0, num=0;
	
	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < m; y++)
		{
			if(A[i][y]==10){
				tenCount++;
			}
		}

		if (TOPtencount<tenCount){
			TOPtencount = tenCount;
			num = i;
		}

		tenCount=0;
	}

	cout << "Daugiausiai 10-uku turi: " << ++num << "-as mokinys;" << endl;
}

void Singleton::negativeGrades(int A[100][100], int n, int m){
	int notNegative = 0;
	bool negative = false;

	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < m; y++)
		{
			if(A[i][y]<4){
				negative = true;
			}
		}

		if (negative==false){
			notNegative++;
		}

		negative = false;
	}

	cout << notNegative << " mokiniai(-iu) neturi neigiamu ivertinimu;" << endl;
}

void Singleton::writeToLogFile()
{
	int A[100][100];
	int n=getNext(), m=getNext();

	fillWithNull(A);
	inputArray(A, n, m);
	tenFunction(A, n, m);
	negativeGrades(A, n, m);
	printArray(A, n, m);
}

