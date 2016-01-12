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
	ds::gDefaultMemory = new ds::DefaultAllocator();
	ds::repository::initialize(ds::repository::RM_DEBUG);

	//ds::test_simple_load();
	int result = Catch::Session().run(argc, argv);


	ds::repository::shutdown();
	ds::gDefaultMemory->debug();
	return 0;
}

