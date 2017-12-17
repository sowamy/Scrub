#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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
