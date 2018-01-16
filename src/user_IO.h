#include <iostream>
#include <string>
#include <stdexcept>

// Program control constants
#define RESTART "***RESTART***"
#define EXIT "***EXIT***"
#define INPUT_PROMPT "\n--> "

using namespace std;

extern struct promptMessages {
	// Menu Prompts
	string test_mainMenu = 	"MAIN MENU (ENTER VALUE OF MODULE TO TEST AND PRESS ENTER):\n"
							"1. TEST\n"
							"2. FILE OPERATIONS\n"
							"3. TEX\n"
							"4. IEEE FORMAT\n"
							"5. SCRIPT EXTRACTION\n"
							"9. EXIT\n"
							"--> ";

	string test_testMenu = 	"TEST MENU (ENTER VALUE OF FUNCTION TO TEST AND PRESS ENTER):\n"
							"1. USER INPUT\n"
							"8. BACK\n"
							"9. EXIT\n"
							"--> ";

	string test_fileOperationsMenu = 	"FILE OPERATIONS MENU (ENTER VALUE OF FUNCTION TO TEST AND PRESS ENTER):\n"
										"1. DEFAULT FILE INITIALIZATION\n"
										"2. CUSTOM FILE INITIALIZATION\n"
										"3. DESCRIPTIVE FILE INITIALIZATION\n"
										"8. BACK\n"
										"9. EXIT\n"
										"--> ";

	// SubMenu Prompts
	string sub_test_input = "USER INPUT (ENTER VALUE OF FUNCTION TO TEST AND PRESS ENTER):\n"
							"1. GET STRING\n"
							"2. GET INTEGER\n"
							"3. GET FLOAT\n"
							"8. BACK\n"
							"9. EXIT\n"
							"--> ";

	string sub_test_userInput = 	"USER INPUT (ENTER VALUE OF FUNCTION TO TEST AND PRESS ENTER):\n"
									"1. BASIC USER INPUT\n"
									"2. DEFAULT USER INPUT\n"
									"3. PROMPTED USER INPUT\n"
									"--> ";

	string sub_test_fileOperationsMenu =	"FILE OPERATIONS (ENTER VALUE OF FUNCTION TO TEST AND PRESS ENTER):\n"
											"1. PRINT STATUS\n"
											"2. FILE FORWARD\n"
											"3. FILE BACK\n"
											"4. NEW FILE\n"
											"5. FILE I/O\n"
											"8. BACK\n"
											"9. EXIT\n"
											"--> ";

	string sub_test_fileInputOutputMenu = 	"FILE I/O (ENTER VALUE OF FUNCTION TO TEST AND PRESS ENTER):\n"
											"1. DOWNLOAD LINE\n"
											"2. LOAD NEXT LINE\n"
											"8. BACK\n"
											"9. EXIT\n"
											"--> ";

	string sub_test_newFileMenu = 	"FILE CREATION (ENTER VALUE OF FUNCTION TO TEST AND PRESS ENTER): \n"
									"1. FILE NAME AND TYPE TOGETHER\n"
									"2. FILE NAME AND TYPE SEPARATED\n"
									"--> ";

	// Error Handling Messages (Soft Errors)
	string soft_input = "INVALID INPUT";
	string soft_above = "INPUT IS ABOVE ACCEPTABLE VALUE";
	string soft_below = "INPUT IS BELOW ACCEPTABLE VALUE";
	string try_again = "WOULD YOU LIKE TO TRY AGAIN? (YES) -OR- (NO): ";
	string try_again_please = "PLEASE TRY AGAIN";

	// Error Messages
	string error_general = "ERROR";
	string error_characterOverflow = "ERROR: TOO MANY CHARACTERS";
	string error_input = "ERROR: INVALID INPUT";
}prompt;


extern class Input {
	private:
	public:
		Input() {};
		~Input() {};
		string get_string();
		string get_string(int maxLength);
		string get_string(int maxLength, string prompt);
		int get_integer();
		int get_integer(int min, int max);
		int get_integer(int min, int max, string prompt);
		float get_float();
		float get_float(float min, float max);
		float get_float(float min, float max, string prompt);
}userInput; // END CLASS Input