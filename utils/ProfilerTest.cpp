#include "..\catch.hpp"
#include <utils\Profiler.h>
#include <utils\Log.h>

void testTrack() {
	ZoneTracker z1("FIRST");
	LOG << "Z1 started";
	{		
		ZoneTracker z2("SECOND");
		LOG << "Z2 started";
	}
	{
		ZoneTracker z3("Third");
		LOG << "Z3 started";
		{
			ZoneTracker z5("5TH");
			LOG << "Z5 started";
		}
	}
	ZoneTracker z4("4TH");
	LOG << "Z4 started";
	{
		ZoneTracker z5("5TH");
		LOG << "Z5 started";
		{
			ZoneTracker z5("5TH");
			LOG << "Z5 started";
		}
	}
}
TEST_CASE("perf::FirstTest", "[Perf]") {
	perf::init();
	perf::reset();
	testTrack();	
	perf::finalize();
	perf::debug();
	perf::shutdown();
}