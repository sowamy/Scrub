#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Program control constants
#define RESTART "***RESTART***"
#define EXIT "***EXIT***"
#define INPUT_PROMPT "\n--> "

using namespace std;
//------------------------------------------------------------------------------------------------------------
/* STRUCTURE: promptMessages
 * DESCRIPTION:
 * -- Stores all of the messages which are to be printed onto the screen for the user to see, prompting
 *		targeted communication between the program and the user during runtime.
 */
struct promptMessages {
	// Menu Prompts
	string mainMenu = "MAIN MENU (ENTER VALUE OF MODULE TO TEST AND PRESS ENTER):\n1. TEST\n2. FILE OPERATIONS"
						"\n3. TEX\n4. IEEE FORMAT\n5. SCRIPT EXTRACTION";
	
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
//------------------------------------------------------------------------------------------------------------
/* CLASS: Input
 * DESCRIPTION: Used to obtain valid input from the user.
 */
class Input {
	private:
	public:
		Input() {};
		~Input() {};
		string get_string(int maxLength);
		string get_string(int maxLength, string prompt);
		int get_integer(int min, int max);
		int get_integer(int min, int max, string prompt);
		float get_float(float min, float max);
		float get_float(float min, float max, string prompt);

}userInput; // END CLASS Input

/* CLASS: Input
 * METHOD: getString
 * DESCRIPTION: Gets valid string from user with a number of characters less than <maxLength>.
 *				If error has occurred:
 *					Returns "false" to repeat process/prompt which called this method.
 *					Returns "exit" to end process/prompt which called this method.
 */
string Input::get_string(int maxLength) {
	string raw;
	cout << INPUT_PROMPT;

	try {
		getline(cin,raw);
		if( raw.size() > maxLength )
			throw length_error( prompt.error_characterOverflow );
		if( raw == "exit" )
			return EXIT;
	} catch (length_error x) {
		string cont;

		cout << endl << x.what();
		cout << endl << prompt.try_again;

		cont = get_string(maxLength);

		if( cont == "yes" ) {
			return RESTART;
		} else {
			return EXIT;
		} // END if...else
	} catch(...) {
		string cont;

		cout << prompt.error_input;
		cout << endl << prompt.try_again;

		cont = get_string(maxLength);

		if( cont == "yes" ) {
			return RESTART;
		} else {
			return EXIT;
		}
	}// END try...catch

	return raw;
} // END METHOD getString

/* CLASS: Input
 * METHOD: get_string (overload)
 * DESCRIPTION: Gets valid string from user, repeats prompt which calls for the user input automatically.
 */
string Input::get_string(int maxLength, string prompt) {
	string raw;

	try {
		cout << endl << prompt;
		raw = get_string(maxLength);
		if( raw == RESTART ) {
			raw = get_string(maxLength, prompt);
		}
	} catch (...) {
		cout << "ERROR";
	} // END try...catch

	return raw;
} // END METHOD get_string

/* CLASS: Input
 * METHOD: get_integer
 * DESCRIPTION: Gets a valid integer value from the user within the range <min> to <max>
 				Returns -1 if invalid input
 */
int Input::get_integer(int min, int max) {
	string raw;
	int newValue;
	cout << INPUT_PROMPT;

	try {
		getline(cin,raw);
		try {
			newValue = stoi(raw);
		} catch (...) {
			cout << prompt.error_input << endl;
		}
		if(newValue > max)
			throw out_of_range(prompt.soft_above);
		if(newValue < min)
			throw out_of_range(prompt.soft_below);
	} catch (out_of_range x) {
		string cont;

		cout << endl << x.what();
		cout << endl << prompt.try_again;

		cont = get_string(3);

		if( cont == "yes" ) {
			throw invalid_argument(RESTART);
		} else {
			throw domain_error(EXIT);
		} // END if...else
	} catch(...) {
		string cont;

		cout << prompt.soft_input;
		cout << endl << prompt.try_again;

		cont = get_string(3);

		if( cont == "yes" ) {
			newValue = get_integer(min, max);
		} else {
			throw domain_error(EXIT);
		}
	}// END try...catch

	return newValue;
} // END METHOD getInteger

/* CLASS: Input
 * METHOD: get_int (overload)
 * DESCRIPTION: Gets valid integer from user, repeats prompt which calls for the user input automatically.
 */
int Input::get_integer(int min, int max, string prompt) {
	int raw;

	try {
		cout << endl << prompt;
		raw = get_integer(min, max);
	} catch (domain_error x) {
		cout << x.what();
	} catch (invalid_argument x) {
		raw = get_integer(min, max, prompt);
	} catch (...) {
		cout << "ERROR";
	} // END try...catch

	return raw;
} // END METHOD get_integer

/* CLASS: Input
 * METHOD: get_float
 * DESCRIPTION: Gets a valid float value from the user within the range <min> to <max>
 				Returns -1 if invalid input
 */
float Input::get_float(float min, float max) {
	string raw;
	float newValue;
	cout << INPUT_PROMPT;

	try {
		getline(cin,raw);
		try {
			newValue = stof(raw);
		} catch (...) {
			cout << prompt.error_input << endl;
			throw invalid_argument(RESTART);
		}
		if(newValue > max)
			throw out_of_range(prompt.soft_above);
		if(newValue < min)
			throw out_of_range(prompt.soft_below);
	} catch (out_of_range x) {
		string cont;

		cout << endl << x.what();
		cout << endl << prompt.try_again;

		cont = get_string(3);

		if( cont == "yes" ) {
			throw invalid_argument(RESTART);
		} else {
			throw domain_error(EXIT);
		} // END if...else
	} catch(...) {
		string cont;

		cout << prompt.soft_input;
		cout << endl << prompt.try_again;

		cont = get_string(3);

		if( cont == "yes" ) {
			throw invalid_argument(RESTART);
		} else {
			throw domain_error(EXIT);
		}
	}// END try...catch

	return newValue;
} // END METHOD get_float

/* CLASS: Input
 * METHOD: get_float (overload)
 * DESCRIPTION: Gets valid float from user, repeats prompt which calls for the user input automatically.
 */
float Input::get_float(float min, float max, string prompt) {
	float raw;

	try {
		cout << endl << prompt;
		raw = get_float(min, max);
	} catch (domain_error x) {
		cout << x.what();
	} catch (invalid_argument x) {
		raw = get_float(min, max, prompt);
	} catch (...) {
		cout << "ERROR";
	} // END try...catch

	return raw;
} // END METHOD get_float
//------------------------------------------------------------------------------------------------------------