#include <iostream>

#include "tex.h"

#define MAX_FILE_SIZE 100

using namespace std;

int main( int argc, char *argv[] )
{
	if(argc == 2) {
		TEX* document = new TEX("article", argv[1]);
		document->beginBody();
		document->newSection("One");
		document->pushLine("Chapter one");
		document->newSection("Two");
		document->pushLine("Chapter Two");
		document->newLine();
		document->pushLine("Stuff");
		document->endBody();
		document->makeTexFile();
		document->compile();
	} else {
		cerr << "INCORRECT NUMBER OF ARGUMENTS" << endl;
		return 1;
	}

	return 0;
} // END FUNCTION main
