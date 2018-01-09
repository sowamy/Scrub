#include <iostream>

/* CLASS: TerminalView
 * DESCRIPTION: 
 * -- Class which contains functionality to test various modules of the Scrub program using terminal
 *		interactions. Allows the user to dynamically interact and test the functionality of Scrub during 
 *		runtime.
 */
class TerminalView {
	private:
		int menuChoice;
		Test* testObject;
	public:
		TerminalView();
}; // END CLASS TerminalView

/* CONSTRUCTOR: TerminalView
 * DESCRIPTION:
 * -- Displays the main (starting) menu
 */
TerminalView::TerminalView() {
	menuChoice = userInput.get_integer(1, 5, prompt.mainMenu);

	switch(menuChoice) {
		case 1: // Test
			testObject = new Test;
		case 2: // File Operations
			testObject = new File_Test;
	} // END SWITCH : Main Menu Choice
} // END CONSTRUCTOR TerminalView