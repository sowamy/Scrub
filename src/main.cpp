#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//------------------------------------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------------------------------------
/* CLASS: texDocument
 * DESCRIPTION: A base class which contains all of the general information and functionality of
 *				a LaTeX document.
 */
class texDocument {
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
		texDocument(string documentName);
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

texDocument::texDocument(string documentName) {
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
}

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
int main( void )
{
	texDocument a("./Scrub/texFiles/new.tex");
	a.setText("Test text\n\nTesting");
	a.createDocument();
	a.compileDocument();
} // END FUNCTION main
