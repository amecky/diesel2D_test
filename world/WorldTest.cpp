#include "..\catch.hpp"
#include <world\World.h>

struct MyTestData {
	int v;
	float vv;
};

TEST_CASE("WorldAdditionalDataTest", "[World]") {
	ds::World w;
	ds::SID sid = w.create(v2(100, 100), ds::math::buildTexture(0, 0, 100, 100), 0);
	REQUIRE(w.size() == 1);
	MyTestData* d = (MyTestData*)w.attach_data(sid, sizeof(MyTestData));
	REQUIRE(d != 0);
	d->v = 100;
	d->vv = 123.45f;
	MyTestData* dd = (MyTestData*)w.get_data(sid);
	REQUIRE(dd != 0);
	REQUIRE(dd->v == 100);
	REQUIRE(dd->vv == 123.45f);
	w.remove(sid);
	REQUIRE(w.size() == 0);
}