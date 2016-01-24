#include "..\..\catch.hpp"
#include <world\actions\WaitAction.h>

TEST_CASE("BasicWaitActionTest", "[WaitAction]") {
	ds::WaitAction action;
	ds::SpriteArray ar;
	ds::sar::allocate(ar, 20);
	ds::ActionEventBuffer buffer;
	ds::SID sid = ds::sar::create(ar, v2(200,200), ds::math::buildTexture(0,0,100,100));
	action.attach(sid, 0.5f);
	action.update(ar, 1.0f, buffer);
	REQUIRE(buffer.events.size() == 1);
	const ds::ActionEvent& event = buffer.events[0];
	REQUIRE(event.sid == sid);
	REQUIRE(event.type == ds::AT_WAIT);
	//delete[] ar.buffer;
}

