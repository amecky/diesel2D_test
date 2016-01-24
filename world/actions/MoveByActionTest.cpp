#include "..\..\catch.hpp"
#include <world\actions\MoveByAction.h>

TEST_CASE("BasicMoveByActionTest", "[MoveByAction]") {
	ds::MoveByAction action;
	ds::Rect r;
	r.top = 1024;
	r.bottom = 0;
	r.left = 0;
	r.right = 1024;
	action.setBoundingRect(r);
	ds::SpriteArray ar;
	ds::sar::allocate(ar, 20);
	ds::ActionEventBuffer buffer;
	ds::SID sid = ds::sar::create(ar, v2(200,200), ds::math::buildTexture(0,0,100,100));
	action.attach(sid, v2(100, 100), true);
	action.update(ar, 1.0f, buffer);
	v2 p = ar.getPosition(sid);
	REQUIRE(p.x == 300.0f);
	REQUIRE(p.y == 300.0f);
	REQUIRE(buffer.events.size() == 0);
	//delete[] ar.buffer;
}

TEST_CASE("MoveByActionBounceTest", "[MoveByAction]") {
	ds::MoveByAction action;
	ds::Rect r;
	r.top = 250;
	r.bottom = 0;
	r.left = 0;
	r.right = 250;
	action.setBoundingRect(r);
	ds::SpriteArray ar;
	ds::sar::allocate(ar, 20);
	ds::ActionEventBuffer buffer;
	ds::SID sid = ds::sar::create(ar, v2(200, 200), ds::math::buildTexture(0, 0, 100, 100));
	action.attach(sid, v2(75, 75), false);
	action.update(ar, 1.0f, buffer);
	v2 p = ar.getPosition(sid);
	REQUIRE(p.x == 200.0f);
	REQUIRE(p.y == 200.0f);
	REQUIRE(buffer.events.size() == 1);
	const ds::ActionEvent& event = buffer.events[0];
	REQUIRE(event.sid == sid);
	REQUIRE(event.type == ds::AT_MOVE_BY);
	//delete[] ar.buffer;
}
