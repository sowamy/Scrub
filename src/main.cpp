#include <iostream>
#include <string>

#include "tex.h"
#include "fileOperations.h"

#define MAX_FILE_SIZE 100

using namespace std;

int main( void )
{
	string astr;
	cout << "File: ";
	cin >> astr;
	cin.ignore();
	File a(astr);
	a.connect();
	string raw;
	while(raw != "end" ) {
		cout << "Next Line: ";
		getline(cin, raw);
		a.downloadLine(raw);
	}
} // END FUNCTION main
