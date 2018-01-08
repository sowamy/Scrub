#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "fileOperations.h"
//------------------------------------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------------------------------------
/* CLASS: texDocument
 * DESCRIPTION: A base class which contains all of the general information and functionality of
 *				a LaTeX document.
 * VARIABLES:
 * -- directory 		:= Stores the file location where the .tex file is, or is to be created
 * -- outputDirectory 	:= Stores the file location where the .tex file is compiled, and the pdf document is 
 							created
 * -- title				:= Title of the document
 * -- bodyBEGIN 		:= String appended to <entireDocument> which begins the body of the document
 * -- bodyEND			:= String appended to <entireDocument> which ends the body of the document
 * -- entireDocument	:= Container of strings, used to store and traverse the entire .tex document during
 							editing (before the document is compiled)
 */
class TEX {
	private:
		// Document location
		File* fileLocation;
		File* fileSaveLocation;

		// Parts of LaTeX document
		string title;
		string bodyBEGIN = "\\begin{document}";
		string bodyEND = "\\end{document}";

		// Document control and indexing
		vector<string> entireDocument;

	public:
		TEX(string docClass, string direct);
		TEX(string docClass, string direct, string outputDirect);
		~TEX() {};
		void beginBody() { entireDocument.push_back(bodyBEGIN); }
		void endBody() { entireDocument.push_back(bodyEND); }
		void newSection(string title);
		void newSubSection(string title);
		void newLine() { entireDocument.push_back("\n"); }
		void makeTexFile() { for(int i = 0; i < entireDocument.size(); i++) { fileLocation->downloadLine(entireDocument[i]); } }
		void compile();
		void pushLine(string line) { entireDocument.push_back(line); }
}; // END CLASS TEX

/* METHOD: Constructor
 * DESCRIPTION: 
 * -- Gets where the document is, and is to be compiled. 
 * -- Sets the documentClass and adds it to <entireDocument>
 */
TEX::TEX(string docClass, string direct) {
	string writer = "\\documentclass{";
	writer.append(docClass);
	writer.append("}");

	entireDocument.push_back(writer);

	fileLocation = new File(direct);
	fileSaveLocation = new File(direct);

	// TODO: Ensure that the target file is of type .tex
	// TODO: Ensure that the folder given is valid

	fileLocation->connect();
	fileSaveLocation->connect();

} // END CONSTRUCTOR TEX

/* METHOD: Constructor
 * DESCRIPTION:
 * -- Gets where the .tex document is to be created
 * -- Sets where the .tex document is to be compiled and the .pdf file is to be created
 * -- Sets the documentClass and adds it to <entireDocument>
 */
TEX::TEX(string docClass, string direct, string outputDirect) {
	string writer = "\\documentclass{";
	writer.append(docClass);
	writer.append("}");

	entireDocument.push_back(writer);

	fileLocation = new File(direct);
	fileSaveLocation = new File(outputDirect, fileLocation->getName(), "pdf");
	
	// TODO: Ensure that the target file is of type .tex
	// TODO: Ensure that the folder given is valid

	fileLocation->connect();
	fileSaveLocation->connect();

} // END CONSTRUCTOR TEX

/* METHOD: newSection
 * DESCRIPTION:
 * -- Creates a new section in the .tex document
 */
void TEX::newSection(string title) {
	string writer = "\\section{";
	writer.append(title);
	writer.append("}");

	entireDocument.push_back(writer);
} // END METHOD newSection

/* METHOD: newSubSection
 * DESCRIPTION:
 * -- Creates a new subsection in the .tex document
 */
void TEX::newSubSection(string title) {
	string writer = "\\subsection{";
	writer.append(title);
	writer.append("}");

	entireDocument.push_back(writer);
} // END METHOD newSubSection

/* METHOD: compile
 * DESCRIPTION:
 * -- Compiles a .tex document into a .pdf document
 */
void TEX::compile() {
	string systemCall = "pdflatex ";
	systemCall.append("-output-directory=");
	systemCall.append(fileSaveLocation->getDirectory());
	systemCall.append(" ");
	systemCall.append(fileLocation->getTarget());
	system(systemCall.c_str());
} // END METHOD compile
//------------------------------------------------------------------------------------------------------------