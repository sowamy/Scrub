//------------------------------------------------------------------------------------------------------------
/* FILE: test.cpp
 * DESCRIPTION: Contains functionality which tests each of the core modules and classes in the Scrub program
 */
//------------------------------------------------------------------------------------------------------------
#include "user_IO.h"
#include "tex.h"

#define CLEARSCREEN system("clear")

using namespace std;
//------------------------------------------------------------------------------------------------------------
/* CLASS: Test
 * DESCRIPTION:
 * -- Contains the base functionality and variables in which are used for testing each module of the program.
 */
class Test {
	protected:
		File* cwd;
		File* testing_folder;
	public:
		Test();
		~Test(){};
}; // END CLASS TEST

/* CONSTRUCTOR: Test
 * DESCRIPTION:
 * -- Creates a default file location which features the current working directory of the program.
 */
Test::Test() {
	// TEST: Prints if and when a Test object is created
	// cout << "Test Object Created" << endl;

	cwd = new File();
	testing_folder = new File();
	testing_folder->back();
	testing_folder->forward("testing");
} // END CONSTRUCTOR Test
//------------------------------------------------------------------------------------------------------------
/* CLASS: File_Test
 * PARENT: Test
 * DESCRIPTION:
 * -- Tests the File class from the fileOperations module (.cpp & .h) of the Scrub software program.
 */
class File_Test : public Test {
	private:
	public:
		File_Test();
}; // END CLASS File_Test

/* CONSTRUCTOR: File_Test
 * DESCRIPTION:
 * -- 
 */
File_Test::File_Test() {
} // END CONSTRUCTOR File_Test
//------------------------------------------------------------------------------------------------------------
/* CLASS: TEX_Test
 * PARENT: Test
 */
//------------------------------------------------------------------------------------------------------------
/* CLASS: IEEE_Test
 * PARENT: Test
 */
//------------------------------------------------------------------------------------------------------------
/* CLASS: Extract_Test
 * PARENT: Test
 */
//------------------------------------------------------------------------------------------------------------
/* CLASS: TerminalView
 * DESCRIPTION: 
 * -- Class which contains functionality to test various modules of the Scrub program using terminal
 *		interactions. Allows the user to dynamically interact and test the functionality of Scrub during 
 *		runtime.
 */
class TerminalView : public Test {
	private:
		int on = 1;
		int menuChoice;
	public:
		TerminalView();
		~TerminalView(){};

		int test_Test();
		int test_FileOperations();
		// int test_TEX();
		// int test_IEEE();
		// int test_Extract();

		void printStats_FileOperations(File* testFile);
}; // END CLASS TerminalView

/* CONSTRUCTOR: TerminalView
 * DESCRIPTION:
 * -- Displays the main (starting) menu
 */
TerminalView::TerminalView() {
	// TEST: Prints if and when a TerminalView object is created
	// cout << "TerminalView Object created" << endl;

	CLEARSCREEN;
	
	while(on) {		
		
		menuChoice = userInput.get_integer(1, 9, prompt.test_mainMenu);
		
		switch(menuChoice) {
			case 1: // Test module itself
				on = test_Test();
				break;
			case 2: // File Operations module
				on = test_FileOperations();
				break;
			case 3: // TEX module
				cout << "3 Chosen" << endl;
				break;
			case 4: // IEEE Formation module
				cout << "4 Chosen" << endl;
				break;
			case 5: // Script Extraction module
				cout << "5 Chosen" << endl;
				break;
			case 9: // Exit
				on = 0;
				break;
			default:
				cout << prompt.error_general << endl;
				break;
		}; // END SWITCH : Main menu choice

		CLEARSCREEN;

	} // END WHILE : Main loop

} // END CONSTRUCTOR TerminalView

/* METHOD: test_Test
 * DESCRIPTION: Tests the test module, and the general functionality within Scrub
 */
int TerminalView::test_Test() {
	int test_on = 1;
	int userInput_on = 1;
	
	int min;
	int max;

	float minF;
	float maxF;

	string testPrompt;

	int testInt;
	float testFloat;
	string testString;

	CLEARSCREEN;

	while(test_on) {

		menuChoice = userInput.get_integer(1, 9, prompt.test_testMenu);
		
		switch(menuChoice) {
			case 1: // Test user input

				CLEARSCREEN;

				while(userInput_on) {

					menuChoice = userInput.get_integer(1, 9, prompt.sub_test_input);

					switch(menuChoice){
						case 1: // Test get string 
							CLEARSCREEN;

							menuChoice = userInput.get_integer(1, 3, prompt.sub_test_userInput);
							CLEARSCREEN;

							switch(menuChoice){
								case 1: // Basic input		
									cout << "ENTER STRING: ";
									testString = userInput.get_string();
									cout << "STRING: " << testString << endl;;
									break;
								case 2: // Default input
									cout << "MAX NUMBER OF CHARACTERS: ";
									max = userInput.get_integer();
									cout << "ENTER STRING: ";
									testString = userInput.get_string(max);
									cout << "STRING: " << testString << endl;
									break;
								case 3: // Prompted input
									cout << "MAX NUMBER OF CHARACTERS: ";
									max = userInput.get_integer();
									cout << "PROMPT: ";
									testPrompt = userInput.get_string();
									testString = userInput.get_string(max, testPrompt);
									cout << "STRING: " << testString << endl;
									break;
								default:
									cout << "ERROR TRY AGAIN" << endl;
							} // END SWITCH : Type of string input
							break;
						case 2: // Test get integer
							CLEARSCREEN;
							
							menuChoice = userInput.get_integer(1, 3, prompt.sub_test_userInput);
							CLEARSCREEN;

							switch(menuChoice){
								case 1: // Basic input		
									cout << "ENTER INTEGER: ";
									testInt = userInput.get_integer();
									cout << "INTEGER: " << testInt << endl;;
									break;
								case 2: // Default input
									cout << "MIN VALUE OF INTEGER: ";
									min = userInput.get_integer();
									cout << "MAX VALUE OF INTEGER: ";
									max = userInput.get_integer();
									cout << "ENTER INTEGER: ";
									testInt = userInput.get_integer(min, max);
									cout << "INTEGER: " << testInt << endl;
									break;
								case 3: // Prompted input
									cout << "MIN VALUE OF INTEGER: ";
									min = userInput.get_integer();
									cout << "MAX VALUE OF INTEGER: ";
									max = userInput.get_integer();
									cout << "PROMPT: ";
									testPrompt = userInput.get_string();
									testInt = userInput.get_integer(min, max, testPrompt);
									cout << "INTEGER: " << testInt << endl;
									break;
								default:
									cout << "ERROR TRY AGAIN" << endl;
							} // END SWITCH : Type of string input
							break;
						case 3: // Test get float
							CLEARSCREEN;

							menuChoice = userInput.get_integer(1, 3, prompt.sub_test_userInput);
							CLEARSCREEN;

							switch(menuChoice){
								case 1: // Basic input		
									cout << "ENTER FLOAT: ";
									testFloat = userInput.get_float();
									cout << "FLOAT: " << testFloat << endl;;
									break;
								case 2: // Default input
									cout << "MIN VALUE OF FLOAT: ";
									minF = userInput.get_float();
									cout << "MAX VALUE OF FLOAT: ";
									maxF = userInput.get_float();
									cout << "ENTER FLOAT: ";
									testFloat = userInput.get_float(min, max);
									cout << "FLOAT: " << testFloat << endl;
									break;
								case 3: // Prompted input
									cout << "MIN VALUE OF FLOAT: ";
									minF = userInput.get_float();
									cout << "MAX VALUE OF FLOAT: ";
									maxF = userInput.get_float();
									cout << "PROMPT: ";
									testPrompt = userInput.get_string();
									testFloat = userInput.get_float(minF, maxF, testPrompt);
									cout << "FLOAT: " << testFloat << endl;
									break;
								default:
									cout << "ERROR TRY AGAIN" << endl;
							} // END SWITCH : Type of string input
							break;
						case 8: // Back
							CLEARSCREEN;
							userInput_on = 0;
							break;
						case 9: // Exit
							return 0;
						default:
							cout << prompt.error_general << endl;
							break;
					}; // END SWITCH : Test user input
				} // END WHILE : User Input test loop

				break;
			case 8:
				return 1;
			case 9:
				return 0;
			default:
				cout << prompt.error_general << endl;
				break;
		}; // END SWITCH : Test menu choice
	} // END WHILE : Test loop
} // END METHOD test_Test

/* METHOD: test_FileOperations
 * DESCRIPTION: Offers a way for the user to interact with the file operations test module through the terminal
 */
int TerminalView::test_FileOperations() {
	int on = 1;

	File* testFile;

	// File initialization selection
	while(on) {
		CLEARSCREEN;

		string customFile;
		string location;
		string name;
		string type;

		menuChoice = userInput.get_integer(1, 9, prompt.test_fileOperationsMenu);

		switch(menuChoice) {
			case 1: // Default file initialization
				testFile = new File();
				on = 0;
				break;
			case 2: // Custom file initialization
				CLEARSCREEN;
				cout << "FILE: ";
				customFile = userInput.get_string();
				testFile = new File(customFile);
				on = 0;
				break;
			case 3: // Descriptive file initialization
				CLEARSCREEN;
				cout << "FILE LOCATION:\t";
				location = userInput.get_string();
				cout << "NAME:\t";
				name = userInput.get_string();
				cout << "TYPE:\t";
				type = userInput.get_string();
				testFile = new File(location, name, type);
				on = 0;
				break;
			case 8: // Back
				return 1;
				break;
			case 9: // Exit
				return 0;
				break;
		}; // END SWITCH : File Operations menu selection
	} // END WHILE : FileOperations loop

	on = 1;

	// File operations functionality testing
	while(on) {
		menuChoice = userInput.get_integer(1, 9, prompt.sub_test_fileOperationsMenu);

		switch(menuChoice) {
			case 1: // Print status
				CLEARSCREEN;
				printStats_FileOperations(testFile);
				break;
			case 8: // Back
				return 1;
				break;
			case 9: // Exit
				return 0;
				break;
		}; // END SWITCH : File operations functionality testing menu selection
	} // END WHILE : File Operations functionality testing loop
} // END METHOD test_FileOperations

/* METHOD: print_FileOperations
 * DESCRIPTION: Prints all status attributes affiliated with the fileOperations module
 */
void TerminalView::printStats_FileOperations(File* testFile) {
	cout << "CURRENT WORKING DIRECTORY:\t" << testFile->getCurrentDirectory() << endl;
	cout << "TARGET:\t\t\t\t" << testFile->getTarget() << endl;
	cout << "DIRECTORY:\t\t\t" << testFile->getDirectory() << endl;
	cout << "TYPE:\t\t\t\t" << testFile->getType() << endl;
	cout << "NAME:\t\t\t\t" << testFile->getName() << endl;
} // END METHOD print_FileOperations
//------------------------------------------------------------------------------------------------------------
