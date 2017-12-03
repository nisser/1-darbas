// SingletonJKM.cpp : Defines the entry point for the console application.
//

#include "Singleton.h"
#include <iostream>

using namespace std;

int main()
{
	Singleton::Instance()->writeToLogFile();
	system("pause");
    return 0;
}
