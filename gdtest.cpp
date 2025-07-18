#include "gdtest.h"
#include <core/object/class_db.h>
#include <iostream>

void GDTest::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_amplitude"), &GDTest::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &GDTest::set_amplitude);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

	ClassDB::bind_method(D_METHOD("get_speed"), &GDTest::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &GDTest::set_speed);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "set_speed", "get_speed");
}

GDTest::GDTest() {
	// Initialize any variables here.
	time_passed = 0.0;
	amplitude = 10.0;
	speed = 1.0;
	OS::get_singleton()->print("GDTest: Constructor called!\n");
	set_process(true);
	if (Engine::get_singleton()->is_editor_hint()) {
		std::cout << "editor hint detect" << std::endl;
	}
}

GDTest::~GDTest() {
	OS::get_singleton()->print("GDTest: Destructor called!\n");
}

void GDTest::_ready() {
	OS::get_singleton()->print("hello from custom editor c++\n");
}

void GDTest::_process(double delta) {

	time_passed += speed * delta;

	Vector2 new_position = Vector2( amplitude + (amplitude * sin(time_passed * 2.0)), amplitude + (amplitude * cos(time_passed * 1.5)));

	set_position(new_position);
}

void GDTest::set_amplitude(const double p_amplitude) {
	amplitude = p_amplitude;
}

double GDTest::get_amplitude() const {
	return amplitude;
}
void GDTest::set_speed(const double p_speed) {
	OS::get_singleton()->print("set speed\n");
	speed = p_speed;
}
double GDTest::get_speed() const {
	OS::get_singleton()->print("get speed\n");
	return speed;
}
void GDTest::_notification(int p_what)
{
	if (p_what != 17)
	{
		std::cout << "p_what var = " << p_what << std::endl;

	}

	switch (p_what)
	{
		case NOTIFICATION_READY:
			// std::cout << "hello from custom c++ module" << std::endl;
			GDTest::_ready();
			break;
		case NOTIFICATION_PROCESS:
			// std::cout << "hello from custom c++ module process" << std::endl;
			GDTest::_process(get_process_delta_time());
			break;
		case NOTIFICATION_ENTER_TREE:
			std::cout << "NOTIFICATION_ENTER_TREE" << std::endl;
			GDTest::_process(get_process_delta_time());
		default:
			Sprite2D::_notification(p_what);
	}

}
