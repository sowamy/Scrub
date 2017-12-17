#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

#define MAX_FILE_SIZE 100

using namespace std;
//------------------------------------------------------------------------------------------------------------
/* CLASS: File
 * DESCRIPTION: Controls the directories in which files are loaded and saved
 * VARIABLES:
 * -- cwd				:= The current working directory (cwd), where the program is being ran
 * -- target			:= The <target> is the file where all file operations will be pointed when ran
 * -- fileLocation		:= The path to the directory of the <target> file
 * -- fileName			:= The name of the <target> file
 * -- docIN				:= The file pointer which will control the input stream FROM the file
 * -- docOUT			:= The file pointer which will control the output stream TO the file
 */
class File {
	private:
		string cwd;
		string target;
		string fileLocation;
		string fileName;
		string fileType;
		ifstream docIN;
		ofstream docOUT;
	protected:
		void setTarget();
		void setTarget(string location, string name, string type);
	public:
		File();
		File(string custom);
		~File();
		void back();
		void forward(string folder);
		void connect();
		void downloadLine(string content){ docOUT << content << endl; }
		// string upload();

		string getCurrentDirectory(){return cwd;}
		string getDirectory(){return fileLocation;}
		string getName(){return fileName;}
		string getType(){return fileType;}
		// void setFile(string loc, string name);
}; // END CLASS File

/* CONSTRUCTOR: File
 * DESCRIPTION: Gets the current directory, and sets the target directory as the current working directory by 
 *				default
 */
File::File() {
	// Get <cwd>
	char buffer[MAX_FILE_SIZE];
	char *current = getcwd(buffer, sizeof(buffer));
	cwd = current;
	fileLocation = cwd;
} // END CONSTRUCTOR File

/* CONSTRUCTOR: File
 * DESCRIPTION: Gets the current directory, and sets the <target> to the custom inputted directory
 */
File::File(string custom) {
	// Get <cwd>
	char buffer[MAX_FILE_SIZE];
	char *current = getcwd(buffer, sizeof(buffer));
	cwd = current;

	// Check if the file is attacted to the end of <custom>. If it is, assign <fileLocation> and <fileName> appropriately.
	if( custom.find(".") < custom.size() ) {
		size_t fileLoc = custom.find_last_of('/');
		size_t fileDot = custom.find_last_of('.');

		fileLocation = custom.substr(0, fileLoc);
		size_t nameLen = fileDot - fileLoc - 1;
		fileName = custom.substr(fileLoc+1, nameLen);
		fileType = custom.substr(fileDot+1);
	} else {
		fileLocation = custom;
	}// END IF : Check for file

	setTarget();
} // END CONSTRUCTOR File

File::~File() {
	docIN.close();
	docOUT.close();
}

/* METHOD: setTarget
 * DESCRIPTION: Sets the value for <target> using <fileLocation>, <fileName>, and <fileType>
 */
void File::setTarget(){
	target = fileLocation;
	target.append("/");
	target.append(fileName);
	target.append(".");
	target.append(fileType);
}

/* METHOD: setTarget (overload)
 * DESCRIPTION: Sets the <target> using custom inputted values.
 *				Also changes <fileLocation>, <fileName>, and <fileType> based on the input.
 */
void File::setTarget(string location, string name, string type){
	// Checks if <location> ends with /
	if( (location.size()-1) == '/')
		fileLocation = location.substr(0, location.find_last_of('/'));
	else
		fileLocation = location;

	// Checks if <location> ends with /, or if name starts with /. Otherwise, adds / between the two in <target>
	if( name[0] == '/' )
		fileName = name.substr(1);
	else
		fileName = name;

	fileType = type;

	setTarget();
} // END METHOD setTarget

/* METHOD: back
 * DESCRIPTION: Moves the target directory back a folder
 * TODO: Throw error or return invalid value if the operation is invalid
 */
void File::back() {
	size_t fileLoc = fileLocation.find_last_of('/');
	fileLocation = fileLocation.substr(0, fileLoc);
	setTarget();
} // END METHOD back

/* METHOD: forward
 * DESCRIPTION: Moves target directory forward
 */
void File::forward( string folder ) {

	// If there is not a \ character at the end of folders, then append one
	if( folder[0] != '/' ) {
		fileLocation.append("/");
		fileLocation.append(folder);
	} // END IF : Ensures there is a / between folders

	setTarget();
} // END METHOD forward

/* METHOD: connect
 * DESCRIPTION: Connect file pointers to the target file
 */
void File::connect() {
	docIN.open(target.c_str());
	docOUT.open(target.c_str());
} // END METHOD connect