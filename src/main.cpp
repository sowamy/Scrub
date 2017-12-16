#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//------------------------------------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------------------------------------
/* CLASS: texDocument
 * DESCRIPTION: An abstract base class which contains all of the general information and functionality of
 *				a LaTeX document.
 */
class texDocument {
	protected:
		string title;
		string fileName;
		ifstream docIN;
		ofstream docOUT;

		// Parts of LaTeX document
		string documentClass = "article";
		vector<string> packages;
		string text;
		string bodyBEGIN = "\\begin{document}";
		string bodyEND = "\\end{document}";
	public:
		texDocument() {};
		~texDocument();
		void createDocument();
		void compileDocument();

		// Getters
		string getTitle() {return title;}
		string getDocClass(void) {return documentClass;}

		// Setters
		void setDocClass(string dc) {documentClass = dc;}
		void setText(string t) {text = t;}
}; // END CLASS texDocument

/* CLASS: texDocument
 * METHOD: ~texDocument
 * DESCRIPTION: General destructor of base class <texDocument>. Closes both the input and output files.
 */
texDocument::~texDocument() {
	docIN.close();
	docOUT.close();
} // END DESTRUCTOR ~texDocument

/* CLASS: texDocument
 * METHOD:
 */
void texDocument::createDocument() {
	docOUT << "\\documentclass{" << documentClass << "}\n";
	docOUT << bodyBEGIN << endl;
	docOUT << text << endl;
	docOUT << bodyEND << endl;
} // END METHOD createDocument

void texDocument::compileDocument(){
	string systemCall = "pdflatex ";
	systemCall.append(fileName);

	// TEST: View system call
	cout << "System Call: " << systemCall << endl;

	system(systemCall.c_str());
}
//------------------------------------------------------------------------------------------------------------
/* CLASS: newDocument
 * PARENT: texDocument
 * DESCRIPTION: A derived class of <texDocument> which gererates a new document from scratch.
 */
class newDocument : public texDocument {
	public:
		newDocument( string fileName );
		~newDocument() {};
}; // END CLASS newDocument

/* CLASS: newDocument
 * PARENT: texDocument
 * DESCRIPTION: Constructor of the <newDocument> class. Creates a new
 */
newDocument::newDocument( string file ) {

	size_t fileExtDot = file.find_last_of('.');

	// Get title from <fileName> and ensure that the string ends with .tex
	if( file.substr(fileExtDot+1) != "tex" ) {
		title = file;
		file.append(".tex");
	} else {
		title = file.substr(0, fileExtDot);
	} // END if...else

	fileName = file;
	// TEST: Print <fileName> before opening
	// cout << "File Name: " << fileName << endl;

	docOUT.open(fileName.c_str());
} // END CONSTRUCTOR : newDocument
//------------------------------------------------------------------------------------------------------------
int main( void )
{
	newDocument a("newDocument.tex");
	a.setText("Test text\n\nTesting");
	a.createDocument();
	a.compileDocument();
} // END FUNCTION main
