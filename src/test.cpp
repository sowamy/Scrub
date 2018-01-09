//------------------------------------------------------------------------------------------------------------
/* FILE: test.cpp
 * DESCRIPTION: Contains functionality which tests each of the core modules and classes in the Scrub program
 */
//------------------------------------------------------------------------------------------------------------
#include "user_IO.h"
#include "tex.h"

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
		int menuChoice;
	public:
		TerminalView();
		~TerminalView(){};
}; // END CLASS TerminalView

/* CONSTRUCTOR: TerminalView
 * DESCRIPTION:
 * -- Displays the main (starting) menu
 */
TerminalView::TerminalView() {
	// TEST: Prints if and when a TerminalView object is created
	// cout << "TerminalView Object created" << endl;

	menuChoice = userInput.get_integer(1, 5, prompt.mainMenu);

	switch(menuChoice) {
		case 1:
			cout << "1 Chosen" << endl;
			break;
		case 2:
			cout << "2 Chosen" << endl;
			break;
		case 3:
			cout << "3 Chosen" << endl;
			break;
		case 4:
			cout << "4 Chosen" << endl;
			break;
		case 5:
			cout << "5 Chosen" << endl;
			break;
		default:
			cout << prompt.error_general << endl;
			break;
	}; // END SWITCH : Main menu choice

} // END CONSTRUCTOR TerminalView
//------------------------------------------------------------------------------------------------------------