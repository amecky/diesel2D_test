// Diesel2DTest.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#pragma comment(lib, "Diesel2D.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxerr.lib")

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <dialogs\DialogManager.h>
#include <io\FileRepository.h>

int main(int argc, char* argv[]) {
	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG); // Get current flag
	flag |= _CRTDBG_LEAK_CHECK_DF; // Turn on leak-checking bit
	flag |= _CRTDBG_CHECK_ALWAYS_DF; // Turn on CrtCheckMemory
	//flag |= _CRTDBG_DELAY_FREE_MEM_DF;
	_CrtSetDbgFlag(flag); // Set flag to the new value
	ds::gDefaultMemory = new ds::DefaultAllocator();
	ds::repository::initialize(ds::repository::RM_DEBUG);

	//ds::test_simple_load();
	int result = Catch::Session().run(argc, argv);


	ds::repository::shutdown();
	ds::gDefaultMemory->debug();
	delete ds::gDefaultMemory;
	return 0;
}

