#include "../imgui/include_imgui.h"
#include "all_wz4.h"

// custom docks
#include "dock_angelscript.h"
#include "../imgui_docks/dock_console.h"
#include <portaudio.h>

DockAngelscript::DockAngelscript() {}


#include <angelscript.h>
#include <scriptstdstring/scriptstdstring.h>
#include <scriptbuilder/scriptbuilder.h>
#include <as_module.h>
#include <as_typeinfo.h>
#include <as_scriptengine.h>

class Auto { public:
	void starten() {};
	void bremsen() {};
};

const char *DockAngelscript::label() {
	return "Angelscript";
}

// Implement a simple message callback function
void MessageCallback(const asSMessageInfo *msg, void *param)
{
	const char *type = "ERR ";
	if (msg->type == asMSGTYPE_WARNING)
		type = "WARN";
	else if (msg->type == asMSGTYPE_INFORMATION)
		type = "INFO";
	imgui_log("%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col, type, msg->message);
}

#include <string>

//// Print the script string to the standard output stream
void printz(std::string &msg)
{
	imgui_log("%s", msg.c_str());
}


asCScriptEngine *as_scriptengine = NULL;



void DockAngelscript::imgui() {
	ImGui::Text("asd");

	if (as_scriptengine) {
		asIScriptModule *mod = as_scriptengine->GetModule("MyModule", asGM_ONLY_IF_EXISTS);
		asCModule *cmod = (asCModule *)mod;
		if (mod) {

			int n;

			n = cmod->funcDefs.GetLength();
			ImGui::Text("funcDefs (%d)", n);
			for (int i = 0; i < n; i++) {
				asCFuncdefType *funcDef = cmod->funcDefs[i];
				ImGui::Text("Name: %s", funcDef->name.AddressOf());

			}

			n = cmod->scriptFunctions.GetLength();
			ImGui::Text("scriptFunctions (%d)", n);
			for (int i = 0; i < n; i++) {
				asCScriptFunction *scriptFunction = cmod->scriptFunctions[i];
				ImGui::Text("Name: %s", scriptFunction->name.AddressOf());

			}
		}
		else {
			ImGui::Text("mod == NULL");
		}
	}
	

	if (ImGui::Button("test some shit")) {


		as_scriptengine = (asCScriptEngine *)asCreateScriptEngine(ANGELSCRIPT_VERSION);

		//engine->RegisterObjectType("Auto", 0, asOBJ_REF);
		//engine->RegisterObjectMethod("Auto", "void starten()", asMETHOD(Auto, starten), asCALL_THISCALL);
		//engine->RegisterObjectMethod("Auto", "void bremsen()", asMETHOD(Auto, bremsen), asCALL_THISCALL);

		// Create the script engine
		//asIScriptEngine *engine = asCreateScriptEngine();
		// Set the message callback to receive information on errors in human readable form.
		int r = as_scriptengine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL); assert(r >= 0);
		// AngelScript doesn't have a built-in string type, as there is no definite standard 
		// string type for C++ applications. Every developer is free to register its own string type.
		// The SDK do however provide a standard add-on for registering a string type, so it's not
		// necessary to implement the registration yourself if you don't want to.
		RegisterStdString(as_scriptengine);
		// Register the function that we want the scripts to call 
		r = as_scriptengine->RegisterGlobalFunction("void print(const string &in)", asFUNCTION(printz), asCALL_CDECL); assert(r >= 0);
		




		// The CScriptBuilder helper is an add-on that loads the file,
		// performs a pre-processing pass if necessary, and then tells
		// the engine to build a script module.
		CScriptBuilder builder;
		r = builder.StartNewModule(as_scriptengine, "MyModule");
		if (r < 0)
		{
			// If the code fails here it is usually because there
			// is no more memory to allocate the module
			imgui_log("Unrecoverable error while starting a new module.\n");
			return;
		}
		r = builder.AddSectionFromFile("c:\\DATA\\hello.as");
		if (r < 0)
		{
			// The builder wasn't able to load the file. Maybe the file
			// has been removed, or the wrong name was given, or some
			// preprocessing commands are incorrectly written.
			imgui_log("Please correct the errors in the script and try again.\n");
			return;
		}
		r = builder.BuildModule();
		if (r < 0)
		{
			// An error occurred. Instruct the script writer to fix the 
			// compilation errors that were listed in the output stream.
			imgui_log("Please correct the errors in the script and try again.\n");
			return;
		}



		// Find the function that is to be called. 
		asIScriptModule *mod = as_scriptengine->GetModule("MyModule", asGM_ONLY_IF_EXISTS);
		asIScriptFunction *func = mod->GetFunctionByDecl("void main()");
		if (func == 0)
		{
			// The function couldn't be found. Instruct the script writer
			// to include the expected function in the script.
			imgui_log("The script must have the function 'void main()'. Please add it and try again.\n");
			return;
		}
		// Create our context, prepare it, and then execute
		asIScriptContext *ctx = as_scriptengine->CreateContext();
		ctx->Prepare(func);
		r = ctx->Execute();
		if (r != asEXECUTION_FINISHED)
		{
			// The execution didn't complete as expected. Determine what happened.
			if (r == asEXECUTION_EXCEPTION)
			{
				// An exception occurred, let the script writer know what happened so it can be corrected.
				imgui_log("An exception '%s' occurred. Please correct the code and try again.\n", ctx->GetExceptionString());
			}
		}
	}
}
