#include <iostream>
#include <string>
#include <stdexcept>

// Program control constants
#define RESTART "***RESTART***"
#define EXIT "***EXIT***"

using namespace std;

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

}userInput;