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
	string mainMenu = "MAIN MENU (ENTER VALUE OF MODULE TO TEST AND PRESS ENTER):\n1. TEST\n2. FILE OPERATIONS"
						"\n3. TEX\n4. IEEE FORMAT\n5. SCRIPT EXTRACTION";
}prompt;

extern class Input {
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

}userInput;