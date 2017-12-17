#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

#define MAX_FILE_SIZE 100

using namespace std;

class FileOperations {
	private:
		string currentDirectory;
		string targetDirectory;
	public:
		FileOperations();
		FileOperations( string customDir );
		string getCWD(void){return currentDirectory;}
		string getTargetDirectory(void){return targetDirectory;}
		void back(void);
		void forward(string newFolder);

}; // END CLASS FileOperations