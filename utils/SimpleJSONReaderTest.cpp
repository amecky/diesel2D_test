#include "..\catch.hpp"
#include <io\json.h>

TEST_CASE("Basic loading", "[JSONReader]") {
	ds::JSONReader reader;
	bool ret = reader.parse("content\\test\\simpletest_1.json");
	REQUIRE(ret == true);
	int cats[128];
	int num = reader.get_categories(cats, 128);
	REQUIRE(num == 4);
	int cid = reader.find_category("Credits");
	REQUIRE(cid == 2);
	cid = reader.find_category("Hello");
	REQUIRE(cid == -1);
	const char* name = reader.get_category_name(2);
	REQUIRE(strcmp(name, "Credits") == 0);
	bool found = reader.contains_property(2, "id");
	REQUIRE(found == true);
	int id = -1;
	reader.get_int(2, "id", &id);
	REQUIRE(id == 2);
	const char* file = reader.get_string(2, "file");
	REQUIRE(strcmp(file, "Credits") == 0);
	id = -1;
	reader.get_int(3, "iv", &id);
	REQUIRE(id == -4);
}

TEST_CASE("Nested categories test", "[JSONReader]") {
	ds::JSONReader reader;
	bool ret = reader.parse("content\\test\\simpletest_2.json");
	REQUIRE(ret == true);
	int cats[128];
	int num = reader.get_categories(cats, 128);
	REQUIRE(num == 1);
	int cid = reader.find_category("Test1");
	REQUIRE(cid == 0);
	int sub_id = reader.find_category("Test2", cid);
	REQUIRE(sub_id == 1);
	num = reader.get_categories(cats, 128, sub_id);
	REQUIRE(num == 4);
	int v;
	reader.get_int(cats[0], "int", &v);
	REQUIRE(v == 100);
	float fv;
	reader.get_float(cats[0], "float", &fv);
	REQUIRE(fv == 200.0f);
	v2 vv;
	reader.get_vec2(cats[0], "v2", &vv);
	REQUIRE(vv.x == 200.0f);
	REQUIRE(vv.y == 300.0f);
	//v3 : 1, 2, 3
	ds::Color clr;
	reader.get_color(cats[0], "color", &clr);
	REQUIRE(clr.r == Approx(0.5f).epsilon(0.01f));
	REQUIRE(clr.g == Approx(0.75f).epsilon(0.01f));
	REQUIRE(clr.b == Approx(0.25f).epsilon(0.01f));
	REQUIRE(clr.a == Approx(0.125f).epsilon(0.01f));
	ds::Rect r;
	reader.get_rect(cats[0], "rect", &r);
	REQUIRE(r.top == 10);
	REQUIRE(r.left == 20);
	REQUIRE(r.width() == 30);
	REQUIRE(r.height() == 40);
	ds::ColorPath cp;
	reader.get_color_path(cats[1], "color_path", &cp);
	REQUIRE(cp.size() == 4);
	const ds::Color& firstColor = cp.value(0);
	REQUIRE(firstColor.r == Approx(1.0f).epsilon(0.01f));
	REQUIRE(firstColor.g == Approx(0.75f).epsilon(0.01f));
	REQUIRE(firstColor.b == Approx(0.5f).epsilon(0.01f));
	REQUIRE(firstColor.a == Approx(0.25f).epsilon(0.01f));
	ds::Vector2fPath vp;
	reader.get_vec2_path(cats[1], "v2_path", &vp);
	REQUIRE(vp.size() == 4);
	const v2& ffp = vp.value(0);
	REQUIRE(ffp.x == 200.0f);
	REQUIRE(ffp.y == 300.0f);

	float arr[32];
	int ar_num = reader.get_array(cats[2], "array", arr, 32);
	REQUIRE(ar_num == 9);
	REQUIRE(arr[8] == 123.45f);
	int i_arr[32];
	int i_ar_num = reader.get_array(cats[3], "array", i_arr, 32);
	REQUIRE(i_ar_num == 5);
	REQUIRE(i_arr[2] == 5);
}

TEST_CASE("Game Settings loading", "[JSONReader]") {
	ds::JSONReader reader;
	bool ret = reader.parse("content\\test\\engine_settings.json");
	REQUIRE(ret == true);
	int root = reader.find_category("init_actions");
	REQUIRE(root != -1);
	REQUIRE(reader.contains_property(root, "textures") == true);
	const char* textureNames = reader.get_string(root, "textures");
	REQUIRE(strcmp(textureNames, "TextureArray") == 0);
}

TEST_CASE("TokenizerParse", "[Tokenizer]") {
	ds::Tokenizer t;
	t.parse("Hello 12 { 40 } :");
	REQUIRE(t.size() == 6);
	REQUIRE(t.get(0).type == ds::Token::NAME);
	REQUIRE(t.get(1).type == ds::Token::NUMBER);
	REQUIRE(t.get(2).type == ds::Token::OPEN_BRACES);
	REQUIRE(t.get(3).type == ds::Token::NUMBER);
	REQUIRE(t.get(4).type == ds::Token::CLOSE_BRACES);
	REQUIRE(t.get(5).type == ds::Token::SEPARATOR);
}