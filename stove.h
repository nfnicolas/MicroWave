#pragma once

enum lamp{light_on,light_off};
enum door{open,close};
enum power{on,off};
class stove
{
	int current_lamp;
	int current_door;
	int current_power;
	int time;
	void take_door();
	void take_button();
	void food_ready();
public:
	stove();
	void run();  //dispatcher

	~stove();
};

