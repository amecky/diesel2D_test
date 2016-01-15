#include "..\catch.hpp"
#include <lib\collection_types.h>
#include <Vector.h>
#include <utils\Log.h>
#include <dxstdafx.h>

TEST_CASE("Array - Remove", "[Array]") {
	ds::Array<int> ar;
	ar.push_back(1);
	ar.push_back(2);
	ar.push_back(3);
	REQUIRE(ar.size() == 3);
	ar.remove(ar.begin() + 1);
	REQUIRE(ar.size() == 2);
	ds::Array<int>::iterator it = ar.begin();
	while (it != ar.end()) {
		LOG << (*it);
		++it;
	}
}

TEST_CASE("Array - RemoveAll", "[Array]") {
	ds::Array<int> ar;
	ar.push_back(1);
	ar.push_back(2);
	ar.push_back(3);
	ar.push_back(1);
	ar.push_back(2);
	ar.push_back(3);
	REQUIRE(ar.size() == 6);
	int num = ar.remove_all(2);
	REQUIRE(num == 2);
	REQUIRE(ar.size() == 4);
}

TEST_CASE("Array - RemoveAllWhileOne", "[Array]") {
	ds::Array<int> ar;
	ar.push_back(1);
	ar.push_back(2);
	ar.push_back(3);
	ar.push_back(1);
	ar.push_back(2);
	ar.push_back(3);
	REQUIRE(ar.size() == 6);
	ds::Array<int>::iterator it = ar.begin();
	while (it != ar.end()) {
		it = ar.remove(it);
	}
	//ar.clear();
	REQUIRE(ar.size() == 0);
}

TEST_CASE("Array - DestroyAll", "[Array]") {
	ds::Array<v2*> ar;
	ar.push_back(new v2(1));
	ar.push_back(new v2(2));
	ar.push_back(new v2(3));
	ar.push_back(new v2(1));
	ar.push_back(new v2(2));
	ar.push_back(new v2(3));
	REQUIRE(ar.size() == 6);
	ar.destroy_all();
	REQUIRE(ar.size() == 0);
}
