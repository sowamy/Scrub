class File {
	private:
		string cwd;
		string target;
		string fileLocation;
		string fileName = NULL;
		string fileType = NULL;
		ifstream docIN;
		ofstream docOUT;
	protected:
		void setTarget();
		void setTarget(string location, string name, string type);
	public:
		File();
		File(string custom);
		~File() {};
		void back();
		void forward(string folder);
		// void download(string contents);
		// string upload();

		string getCurrentDirectory(){return cwd;}
		string getDirectory(){return fileLocation;}
		string getName(){return fileName;}
		string getType(){return fileType;}

		// void setFile(string loc, string name);
}; // END CLASS File