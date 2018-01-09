#include <iostream>
#include <vector>

#include "tex.h"

class TerminalView {
	private:
	public:
		TerminalView();
}; // END CLASS TerminalView

class Test {
	protected:
		File* cwd;
		File* testing_folder;
		TerminalView* tv;
	public:
		Test();
		void runInTerminal(){ tv = new TerminalView; }
}; // END CLASS TEST

class File_Test : public Test {
	private:
	public:
		File_Test();
}; // END CLASS File_Test