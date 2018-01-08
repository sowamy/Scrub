#include <string>
#include <vector>

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
	vector<FunctionPtr> functions;
	FunctionPtr destructor;
};
typedef struct clas Clas;
typedef Clas *ClassPtr;
//------------------------------------------------------------------------------------------------------------
/* CLASS: CoreScript
 * DESCRIPTION: Stores all the attributes and comments from a script in a tree
 */
class CoreScript {

}; // END CLASS CoreScript
//------------------------------------------------------------------------------------------------------------
/* CLASS: C_Script
 * DESCRIPTION: Extracts comments and functionality from a c file.
 */
class C_Script : public CoreScript{
	private:
		string fileLocation;
	public:
		C_Script(string location){ fileLocation=location; }
		~C_Script() {};
}; // END CLASS C_Script
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