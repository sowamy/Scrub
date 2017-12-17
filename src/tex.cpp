#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/* CLASS: texDocument
 * DESCRIPTION: A base class which contains all of the general information and functionality of
 *				a LaTeX document.
 */
class TEX {
	protected:
		string title;
		string fileName;
		string fileLocation;
		ifstream docIN;
		ofstream docOUT;

		// Parts of LaTeX document
		string documentClass = "article";
		vector<string> packages;
		string text;
		string bodyBEGIN = "\\begin{document}";
		string bodyEND = "\\end{document}";
	public:
		TEX(string documentName);
		~TEX();
		void createDocument();
		void compile();

		// Getters
		string getTitle() {return title;}
		string getDocClass(void) {return documentClass;}

		// Setters
		void setDocClass(string dc) {documentClass = dc;}
		void setText(string t) {text = t;}
}; // END CLASS texDocument

/* CLASS: texDocument
 * DESCRIPTION: Default constructor. Takes in the document name, parses the file location and opens the file
 				for editing.
 */
TEX::TEX(string documentName) {
	size_t fileExtDot = documentName.find_last_of('.');
	size_t fileLocDot = documentName.find_last_of('/');

	// Get title from <fileName> and ensure that the string ends with .tex
	if( documentName.substr(fileExtDot+1) != "tex" ) {
		title = documentName.substr(fileLocDot+1);
		documentName.append(".tex");
	} else {
		title = documentName.substr(fileLocDot+1, fileExtDot);
	} // END if...else

	fileLocation = documentName.substr(0, fileLocDot);

	// TEST: Print File Location
	cout << "File Location: " << fileLocation << endl;
	cout << "File Name: " << title << endl;

	fileName = documentName;

	docIN.open(fileName.c_str());
	docOUT.open(fileName.c_str());
} // END CONSTRUCTOR texDocument

/* CLASS: texDocument
 * METHOD: ~texDocument
 * DESCRIPTION: General destructor of base class <texDocument>. Closes both the input and output files.
 */
TEX::~TEX() {
	docIN.close();
	docOUT.close();
} // END DESTRUCTOR ~texDocument

/* CLASS: TEX
 * METHOD: Create .tex document
 */
void TEX::createDocument() {
	docOUT << "\\documentclass{" << documentClass << "}\n";
	docOUT << bodyBEGIN << endl;
	docOUT << text << endl;
	docOUT << bodyEND << endl;
} // END METHOD createDocument

void TEX::compile(){
	string systemCall = "pdflatex ";
	systemCall.append(fileName);

	// TEST: View system call
	cout << "System Call: " << systemCall << endl;

	system(systemCall.c_str());
} // END METHOD compile
//------------------------------------------------------------------------------------------------------------
