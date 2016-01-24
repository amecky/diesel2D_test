#include "..\catch.hpp"
#include <math\GameMath.h>
#include <utils\Log.h>

TEST_CASE("GameMath - sincos", "[GameMath]") {
	float s = 0.0f;
	float c = 0.0f;
	ds::math::sincos(DEGTORAD(90.0f), &s, &c);
	REQUIRE(s == Approx(1.0f).epsilon(0.0001f));
	REQUIRE(c == Approx(0.0f).epsilon(0.0001f));

	for (int i = 0; i < 360; ++i) {
		//ds::math::sincos(DEGTORAD(i), &s, &c);
		s = ds::math::fastSin(DEGTORAD(i));
		//s = ds::math::f_sin(DEGTORAD(i));
		c = ds::math::cos_f(DEGTORAD(i));
		float fs = std::sin(DEGTORAD(i));
		float fc = ds::math::fastCos(DEGTORAD(i));
		//LOG << i << " s: " << s << " c: " << c << " fs: " << fs << " fc: " << fc;
		//LOG << i << " s: " << s << " fs: " << fs;
		REQUIRE(s == Approx(fs).epsilon(0.01f));
		//REQUIRE(c == Approx(fc).epsilon(0.0001f));
	}
}