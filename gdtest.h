#ifndef GDTest_H
#define GDTest_H

#include <scene/2d/sprite_2d.h>

#define TOOLS_ENABLED 1

class GDTest : public Sprite2D {
	GDCLASS(GDTest, Sprite2D);


private:
	double time_passed;
	double amplitude;
	double speed;

protected:
	static void _bind_methods();

public:
	GDTest();
	~GDTest();

	void _ready();
	void _process(double delta);
	void set_amplitude(const double p_amplitude);
	double get_amplitude() const;
	void set_speed(const double p_speed);
	double get_speed() const;



	void _notification(int p_what);

};



#endif
