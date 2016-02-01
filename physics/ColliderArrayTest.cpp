#include "..\catch.hpp"
#include <physics\ColliderArray.h>
#include <utils\Log.h>

TEST_CASE("ColliderArray - IsInsideBox", "[ColliderArray]") {
	bool ret = ds::physics::isInsideBox(v2(100, 100), v2(10, 10), v2(10, 10));
	REQUIRE(ret == false);
	ret = ds::physics::isInsideBox(v2(100, 100), v2(80, 80), v2(25, 25));
	REQUIRE(ret == true);
}

TEST_CASE("ColliderArray - Line2Line", "[ColliderArray]") {
	bool ret = ds::physics::testLineIntersections(v2(100, 100), v2(200, 200), v2(150, 100), v2(150, 250));
	REQUIRE(ret == true);
	ret = ds::physics::testLineIntersections(v2(100, 100), v2(200, 100), v2(150, 150), v2(250, 250));
	REQUIRE(ret == false);
	ret = ds::physics::testLineIntersections(v2(100, 100), v2(200, 200), v2(150, 150), v2(200, 200));
	REQUIRE(ret == true);
	ret = ds::physics::testLineIntersections(v2(100, 100), v2(200, 200), v2(100, 100), v2(300, 300));
	REQUIRE(ret == true);
}

TEST_CASE("ColliderArray - Line2Box", "[ColliderArray]") {
	int ret = ds::physics::testLineBox(v2(100, 100), v2(200, 50), v2(120, 120));
	REQUIRE(ret == 8);
	ret = ds::physics::testLineBox(v2(100, 100), v2(100, 150), v2(20, 20));
	REQUIRE(ret == 4);
}