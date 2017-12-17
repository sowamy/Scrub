#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

#define MAX_FILE_SIZE 100
//------------------------------------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------------------------------------
/* CLASS: FileOperations
 * DESCRIPTION: Controls the directories in which files are loaded and saved
 */
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

/* CLASS: FileOperations
 * CONSTRUCTOR: FileOperations
 * DESCRIPTION: Gets the current directory, and sets the target directory as the current working directory by 
 *				default
 */
FileOperations::FileOperations() {
	char buffer[MAX_FILE_SIZE];
	char *cwd = getcwd(buffer, sizeof(buffer));
	currentDirectory = cwd;
	targetDirectory = currentDirectory;
} // END CONSTRUCTOR FileOperations

/* CLASS: FileOperations
 * CONSTRUCTOR: FileOperations
 * DESCRIPTION: Gets the current directory, and sets the target directory to the custom inputted directory
 */
FileOperations::FileOperations( string customDir) {
	char buffer[MAX_FILE_SIZE];
	char *cwd = getcwd(buffer, sizeof(buffer));
	currentDirectory = cwd;
	targetDirectory = customDir;
} // END CONSTRUCTOR FileOperations

/* CLASS: FileOperations
 * METHOD: targetDirectoryBack
 * DESCRIPTION: Moves the target directory back a folder
 * TODO: Throw error or return invalid value if the operation is invalid
 */
void FileOperations::back() {
	size_t fileLocDot = targetDirectory.find_last_of('/');
	targetDirectory = targetDirectory.substr(0, fileLocDot);
} // END METHOD back

/* CLASS: FileOperations
 * METHOD: forward
 * DESCRIPTION: Moves target directory forward
 */
void FileOperations::forward( string newFolder ) {

	// If there is not a \ character at the end of folders, then append one
	if( newFolder[0] != '/' ) {
		targetDirectory.append("/");
	} // END IF : Ensures there is a / between folders

	targetDirectory.append( newFolder );
} // END METHOD forward
//------------------------------------------------------------------------------------------------------------
