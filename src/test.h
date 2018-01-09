#include <iostream>
#include <vector>

#include "user_IO.h"

#include "tex.h"

class Test {
	protected:
		File* cwd;
		File* testing_folder;
	public:
		Test();
		~Test(){};
}; 

class File_Test : public Test {
	private:
	public:
		File_Test();
}; 

class TerminalView : public Test {
	private:
		int menuChoice;
	public:
		TerminalView();
		~TerminalView(){};
};