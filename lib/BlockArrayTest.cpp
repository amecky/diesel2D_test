#include "..\catch.hpp"
#include <lib\BlockArray.h>
#include <Vector.h>
#include <utils\Log.h>
#include <dxstdafx.h>

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

TEST_CASE("BlockArray - Remove", "[BlockArray]") {
	BlockArray ar;
	int sz[] = { sizeof(float), sizeof(v2), sizeof(int) };
	ar.init(sz, 3);
	ar.resize(20);
	float* first = (float*)ar.get_ptr(0);
	v2* second = (v2*)ar.get_ptr(1);
	int* third = (int*)ar.get_ptr(2);
	for (int i = 0; i < 20; ++i) {
		first[i] = i * 5.0f;
		second[i] = v2(i, 10 + i);
		third[i] = 20 + 4 * i;
		++ar.size;
	}	
	ar.remove(5);
	REQUIRE(ar.size == 19);
	REQUIRE(first[5] == 95.0f);
	REQUIRE(third[5] == 96);
	REQUIRE(second[5].x == 19.0f);
	REQUIRE(second[5].y == 29.0f);
}