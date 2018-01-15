#include <iostream>
#include <vector>

#include "user_IO.h"
#include "tex.h"

#define CLEARSCREEN system("clear")

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
		int on = 0;
		int menuChoice;
	public:
		TerminalView();
		~TerminalView(){};

		int test_Test();
		// int test_FileOperations();
		// int test_TEX();
		// int test_IEEE();
		// int test_Extract();
};