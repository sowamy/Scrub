#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "tex.h"
#include "fileOperations.h"

#define MAX_FILE_SIZE 100

using namespace std;

int main( void )
{
	string astr;
	cout << "File: ";
	cin >> astr;
	File a(astr);
	cout << endl << "CWD: " << a.getCurrentDirectory() << endl;
	cout << "Location: " << a.getDirectory() << endl;
	cout << "Name: " << a.getName() << endl;
	cout << "Type: " << a.getType() << endl << endl;
	a.back();
	a.forward("src");
	cout << "New Location: " << a.getDirectory() << endl;
} // END FUNCTION main
