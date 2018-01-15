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
	cout << "File_Test Initiated" << endl;
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
		// int test_FileOperations();
		// int test_TEX();
		// int test_IEEE();
		// int test_Extract();
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
				cout << "2 Chosen" << endl;
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

	CLEARSCREEN;

	while(test_on) {

		menuChoice = userInput.get_integer(1, 9, prompt.test_testMenu);
		
		switch(menuChoice) {
			case 1: // Test user input

				CLEARSCREEN;

				while(userInput_on) {

					menuChoice = userInput.get_integer(1, 9, prompt.sub_test_input);

					switch(menuChoice){
						case 1: // Test get string (basic)
							CLEARSCREEN;
							cout << "1" << endl;
							break;
						case 2: // Test get string (prompt)
							CLEARSCREEN;
							cout << "2" << endl;
							break;
						case 3: // Test get integer (basic)
							CLEARSCREEN;
							cout << "3" << endl;
							break;
						case 4: // Test get integer (prompt)
							CLEARSCREEN;
							cout << "4" << endl;
							break;
						case 5: // Test get float (basic)
							CLEARSCREEN;
							cout << "5" << endl;
							break;
						case 6: // Test get float (prompt)
							CLEARSCREEN;
							cout << "6" << endl;
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
}
//------------------------------------------------------------------------------------------------------------