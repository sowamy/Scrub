#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "fileOperations.h"

using namespace std;

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