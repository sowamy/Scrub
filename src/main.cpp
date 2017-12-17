#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "tex.h"

#define MAX_FILE_SIZE 100
//------------------------------------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------------------------------------
class FileOperations {
	private:
		string currentDirectory;
		string targetDirectory;
	public:
		FileOperations();

		string getCWD(void){return currentDirectory;}
		string getTargetDirectory(void){return targetDirectory;}
		void targetDirectoryBack(void);

}; // END CLASS FileOperations

FileOperations::FileOperations() {
	char buffer[MAX_FILE_SIZE];
	char *cwd = getcwd(buffer, sizeof(buffer));
	currentDirectory = cwd;
	targetDirectory = currentDirectory;
}

void FileOperations::targetDirectoryBack() {
	size_t fileLocDot = targetDirectory.find_last_of('/');
	targetDirectory = targetDirectory.substr(0, fileLocDot);
}
//------------------------------------------------------------------------------------------------------------
int main( void )
{
	FileOperations a;
	cout << "CWD: " << a.getCWD() << endl;
	a.targetDirectoryBack();
	cout << "TDIR: " << a.getTargetDirectory() << endl;
} // END FUNCTION main
