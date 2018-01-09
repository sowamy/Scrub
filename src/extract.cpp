#include <string>
#include <vector>

#include "fileOperations.h"

using namespace std;
//------------------------------------------------------------------------------------------------------------
struct variable{
	string name;
	string type;
};
typedef struct variable Variable;
typedef Variable *VariablePtr;
//------------------------------------------------------------------------------------------------------------
struct function{
	string name;
	string description;
	vector<VariablePtr> arguments;
	vector<VariablePtr> intermediateVariables;
	vector<string> formulae;
	VariablePtr returnVariable;
};
typedef struct function Function;
typedef Function *FunctionPtr;
//------------------------------------------------------------------------------------------------------------
struct clas{
	string name;
	string description;
	vector<FunctionPtr> constructors;
	vector<FunctionPtr> methods;
	FunctionPtr destructor;
};
typedef struct clas Clas;
typedef Clas *ClassPtr;
//------------------------------------------------------------------------------------------------------------
/* CLASS: CoreScript
 * DESCRIPTION: Stores all the attributes and comments from a script in a tree
 */
class CoreScript {
	private:
		vector<ClassPtr> classes;
		vector<FunctionPtr> functions;
		vector<VariablePtr> variables;

		int classIndex = 0;
		int methodIndex = 0;
		int functionIndex = 0;
	protected:
		File* scriptSource;		
	public:
		CoreScript() {};

		void pushClass(ClassPtr newClass){ classes.push_back(newClass); }
		// void pushClass(string name, string description);

		void pushFunction(FunctionPtr newFunction){ functions.push_back(newFunction); }
		// void pushFunction(string functionName, string functionDescription);

		// int pushMethod(string className, FunctionPtr newMethod);
		// int pushMethod(string className, string functionName, string functionDescription);

		// ClassPtr popClass();
		// FunctionPtr popFunction();

		// string getClassTitle();
		// string getClassDescription();

		// string getFunctionTitle();
		// string getFunctionDescription();

		// string getMethodTitle(string class);
		// string getMethodDescription(string class);
		
		// int nextClass();
		// int nextFunction();
		// int nextMethod(string class);
}; // END CLASS CoreScript
//------------------------------------------------------------------------------------------------------------
/* CLASS: C_Script
 * DESCRIPTION: Extracts comments and functionality from a c file.
 */
class C_Script : public CoreScript{
	private:
	public:
		C_Script(string location);
		~C_Script() {};
}; // END CLASS C_Script

C_Script::C_Script(string location) {
	scriptSource = new File(location);
	scriptSource->connect();
}
//------------------------------------------------------------------------------------------------------------
/* CLASS: Cpp_Script
 * DESCRIPTION: Extracts comments and functionality from a c++ file.
 */
class Cpp_Script : public CoreScript{
	private:
		string fileLocation;
	public:
		Cpp_Script(string location){ fileLocation=location; } 
		~Cpp_Script() {};
}; // END CLASS Cpp_Script
//------------------------------------------------------------------------------------------------------------