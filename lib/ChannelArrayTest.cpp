#include "..\catch.hpp"
#include <lib\BlockArray.h>
#include <utils\Log.h>

TEST_CASE("ChannelArray - first test", "[ChannelArray]") {
	ds::ChannelArray ar;
	int sz[] = { sizeof(float), sizeof(int), sizeof(float) };
	ar.init(sz, 3);
	ID id = ar.add();
	REQUIRE(ar.size == 1);
	REQUIRE(ar.capacity == 8);
	REQUIRE(ar.contains(id));
	ar.set<float>(id, 0, 123.45f);
	float f = ar.get<float>(id, 0);
	REQUIRE(f == 123.45f);
	float* fa = (float*)ar.get_ptr(0);
	//for (int i = 0; i < ar.size; ++i) {
		//LOG << i << " = " << fa[i];
	//}
	//LOG << "-----------------------------------";
	ID ids[20];
	for (int i = 0; i < 20; ++i) {
		ids[i] = ar.add();
		ar.set<float>(ids[i], 0, 2.0f * i);
		ar.set<int>(ids[i], 1, i * 2);
		ar.set<float>(ids[i], 2, i * 4.0f);
	}
	fa = (float*)ar.get_ptr(0);
	//for (int i = 0; i < ar.size; ++i) {
		//LOG << i << " id: " << ar._data_indices[i].id << " index: " << ar._data_indices[i].index << " = " << " = " << fa[i];
	//}
	REQUIRE(ar.size == 21);
	REQUIRE(ar.capacity == 24);
	f = ar.get<float>(ids[5], 0);
	REQUIRE(f == 10.0f);
	REQUIRE(ar.contains(id));
}
