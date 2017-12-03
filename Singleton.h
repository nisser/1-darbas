#include <string>

class Singleton {
public:
	static Singleton* Instance();
	void writeToLogFile();
	int getNext();
	void fillWithNull(int A[100][100]);
	void inputArray(int A[100][100], int n, int m);
	void tenFunction(int A[100][100], int n, int m);
	void negativeGrades(int A[100][100], int n, int m);
	void printArray(int A[100][100], int n, int m);

private:
	Singleton() {};  // Private so that it can  not be called
	Singleton(Singleton const&) {};             // copy constructor is private
	Singleton& operator=(Singleton const&) {};  // assignment operator is private
	static Singleton* m_pInstance;
};