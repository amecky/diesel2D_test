#include "..\catch.hpp"
#include <sprites\SpriteTemplates.h>

TEST_CASE("BasicSpriteTemplatesTest", "[SpriteTemplates]") {
	ds::SpriteTemplates s;
	s.load();
	const ds::TemplateMap& map = s.getTemplates();
	REQUIRE(map.size() == 15);
	ds::Sprite& sp = s.get(0);
	REQUIRE(sp.position.x == 512.0f);
	REQUIRE(sp.position.y == 384.0f);
	ds::Rect r = sp.texture.rect;
	// 0,512,512,384
	REQUIRE(r.top == 0);
	REQUIRE(r.left == 512);
	REQUIRE(r.width() == 512);
	REQUIRE(r.height() == 384);
}
/*
	void test_save_templates() {
		SpriteTemplates s;
		s.load();
		SimpleJSONWriter jw;
		if (jw.open("test.json")) {
			s.saveData(jw);
		}
	}
}
*/