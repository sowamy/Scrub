#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

class File {
	private:
		string cwd;
		string target;
		string fileLocation;
		string fileName;
		string fileType;
		ifstream docIN;
		ofstream docOUT;
	protected:
		void setTarget();
		void setTarget(string location, string name, string type);
	public:
		File();
		File(string custom);
		File(string loc, string n, string t){ setTarget(loc, n, t); }
		~File();
		void back();
		void forward(string folder);
		void createFile(string fileN);
		void createFile(string fileN, string fileT);
		void connect();
		void downloadLine(string content){ docOUT << content << endl; }
		string uploadLine();

		string getCurrentDirectory(){return cwd;}
		string getDirectory(){return fileLocation;}
		string getName(){return fileName;}
		string getType(){return fileType;}
		string getTarget();
}; // END CLASS File