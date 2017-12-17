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
	FileOperations a;
	cout << "CWD: " << a.getCWD() << endl;
	a.back();
	cout << "TDIR: " << a.getTargetDirectory() << endl;
	a.forward( "texFiles" );
	cout << "TDIR: " << a.getTargetDirectory() << endl;
	FileOperations b("/home/sowamy/Desktop");
	cout << "TDIR: " << b.getTargetDirectory() << endl;
} // END FUNCTION main
