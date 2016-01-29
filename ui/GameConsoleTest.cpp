#include "..\catch.hpp"
#include <ui\GameConsole.h>

class TestCommand : public ds::ConsoleCommand {

public:
	TestCommand() : _executed(0) {}
	virtual ~TestCommand() {}
	virtual bool execute(const ds::ConsoleVars& vars) {
		_executed += vars.values[0];
		_executed += vars.values[1];
		return true;
	}
	virtual const char* getCommand() const {
		return "test";
	}
	int getExecuted() const {
		return _executed;
	}
	virtual int getNumVars() const {
		return 2;
	}
private:
	int _executed;
};

TEST_CASE("GameConsole - FirstValidTest", "[GameConsole]") {
	ds::GameConsole console;
	TestCommand tc;
	console.add(&tc);
	bool ret = console.execute("test 12,4,6,8");
	REQUIRE(ret == true);
	REQUIRE(tc.getExecuted() == 16);
}

TEST_CASE("GameConsole - SecondInvalidTest", "[GameConsole]") {
	ds::GameConsole console;
	TestCommand tc;
	console.add(&tc);
	bool ret = console.execute("test");
	REQUIRE(ret == false);
}

TEST_CASE("GameConsole - ThirdValidTest", "[GameConsole]") {
	ds::GameConsole console;
	TestCommand tc;
	console.add(&tc);
	bool ret = console.execute("test 3,4");
	REQUIRE(ret == true);
	REQUIRE(tc.getExecuted() == 7);
}