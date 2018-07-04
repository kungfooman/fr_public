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

class Car { public:

	int refCount = 0;
	Car() {
		refCount = 1;
	}
	void start() {
		imgui_log("start car\n");
	};
	void stop() {
		imgui_log("stop car\n");
	};

	void AddRef() {
		// Increase the reference counter
		refCount++;
	}
	void Release() {
		// Decrease ref count and delete if it reaches 0
		if (--refCount == 0)
			delete this;
	}
};

Car *Car_Factory()
{
	// The class constructor is initializing the reference counter to 1
	return new Car();
}


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

class HurrScript { public:
	asIScriptModule *mod = NULL;
	asIScriptContext *ctx = NULL;
	asIScriptFunction *func_main = NULL;
	asIScriptFunction *func_imgui = NULL;
	int r = 0;

	HurrScript() {
	
		mod = as_scriptengine->GetModule("MyModule", asGM_ONLY_IF_EXISTS);
		ctx = as_scriptengine->CreateContext();

		func_main = mod->GetFunctionByDecl("void main(int a, int b)");
		if (func_main == 0) {
			imgui_log("missing: void main(int a, int b)\n");
		}

		func_imgui = mod->GetFunctionByDecl("void imgui()");
		if (func_main == 0) {
			imgui_log("missing: void imgui()\n");
		}

	}

	void main(int a, int b) {
		if (func_main == NULL)
			return;
		ctx->Prepare(func_main);
		ctx->SetArgDWord(0, a);
		ctx->SetArgDWord(1, b);
		r = ctx->Execute();
		if (r != asEXECUTION_FINISHED) {
			if (r == asEXECUTION_EXCEPTION) {
				imgui_log("hurr.main(%d, %d)> %s\n", a, b, ctx->GetExceptionString());
			} else {
				imgui_log("some fuckshit happened r=%d\n", r);
			}
		}
	}

	void imgui() {
		if (func_imgui == NULL)
			return;
		ctx->Prepare(func_imgui);
		r = ctx->Execute();
		if (r != asEXECUTION_FINISHED) {
			if (r == asEXECUTION_EXCEPTION) {
				imgui_log("hurr.imgui()> %s\n", ctx->GetExceptionString());
			}
			else {
				imgui_log("some fuckshit happened r=%d\n", r);
			}
		}
	}
};

HurrScript *hurr = NULL;

void hurr_eval(char *code) {
	imgui_log("try to eval code: %s\n", code);
}

bool igButton(std::string &msg) {
	return ImGui::Button(msg.c_str());
}

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
		int r = 0;

		as_scriptengine = (asCScriptEngine *)asCreateScriptEngine(ANGELSCRIPT_VERSION);

		r = as_scriptengine->RegisterObjectType(     "Car", 0, asOBJ_REF);
		r = as_scriptengine->RegisterObjectMethod(   "Car",                   "void start()", asMETHOD(Car, start   ), asCALL_THISCALL); assert(r >= 0);
		r = as_scriptengine->RegisterObjectMethod(   "Car",                   "void stop()" , asMETHOD(Car, stop    ), asCALL_THISCALL); assert(r >= 0);
		r = as_scriptengine->RegisterObjectBehaviour("Car", asBEHAVE_ADDREF,  "void f()"    , asMETHOD(Car, AddRef  ), asCALL_THISCALL); assert(r >= 0);
		r = as_scriptengine->RegisterObjectBehaviour("Car", asBEHAVE_RELEASE, "void f()"    , asMETHOD(Car, Release ), asCALL_THISCALL); assert(r >= 0);
		r = as_scriptengine->RegisterObjectBehaviour("Car", asBEHAVE_FACTORY, "Car@ f()"    , asFUNCTION(Car_Factory), asCALL_CDECL   ); assert(r >= 0);

		// Create the script engine
		//asIScriptEngine *engine = asCreateScriptEngine();
		// Set the message callback to receive information on errors in human readable form.
		r = as_scriptengine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL); assert(r >= 0);
		// AngelScript doesn't have a built-in string type, as there is no definite standard 
		// string type for C++ applications. Every developer is free to register its own string type.
		// The SDK do however provide a standard add-on for registering a string type, so it's not
		// necessary to implement the registration yourself if you don't want to.
		RegisterStdString(as_scriptengine);
		// Register the function that we want the scripts to call 
		r = as_scriptengine->RegisterGlobalFunction("void print(const string &in)", asFUNCTION(printz), asCALL_CDECL); assert(r >= 0);
		r = as_scriptengine->RegisterGlobalFunction("bool igButton(const string &in)", asFUNCTION(igButton), asCALL_CDECL); assert(r >= 0);
		


			

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


		hurr = new HurrScript();
		
		hurr->main(100, 200);
	}

	if (hurr) {
		hurr->imgui();
	}
}
