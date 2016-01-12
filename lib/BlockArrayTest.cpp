#include "..\catch.hpp"
#include <lib\BlockArray.h>

/*
TEST_CASE("BlockArray - first test", "[BlockArray]") {
	BlockArray ar;
	int sz[] = { sizeof(float), sizeof(int), sizeof(float) };
	ar.init(sz, 3);
	ar.resize(20);
	float* first = (float*)ar.get_ptr(0);
	first[ar.size++] = 100.0f;
	ar.resize(40);
	float* nf = (float*)ar.get_ptr(0);
	REQUIRE(*nf == 100.0f);
}
*/