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
		TerminalView* tv;
	public:
		Test();
		void runInTerminal(){ tv = new TerminalView; }
}; // END CLASS TEST

/* CONSTRUCTOR: Test
 * DESCRIPTION:
 * -- Creates a default file location which features the current working directory of the program.
 */
Test::Test() {
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