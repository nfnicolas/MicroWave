#include "stove.h"
#include<iostream>
#include<conio.h>

using namespace std;

void stove::take_door()
{
	if (current_door == open)
	{
		current_door = close;
		current_lamp = off;
		cout << "Door is closing\n";
		return;
	}
	else
	{
		current_door = open;
		current_lamp = on;
		time = -1;
		cout << "Door is opening\n";
		if (current_power == on)
			cout << "Food reading interrupted\n";
		current_power = off;
		return;
	}
}

void stove::take_button()
{
	if (current_door == open)
	{
		cout << "Pressing the button has no effect when the door is open\n";
		return;
	}
	else
		if (current_power == on)
		{
			time += 60;
			cout << "Added 1 minute\n";
		}
		else
		{
			current_lamp = light_on;
			current_power = on;
			time = 60;
			cout << "The reading food\n";
		}
	return;
}

void stove::food_ready()
{
	current_lamp = light_on;
	current_power = off;
	time = -1;
	cout << "Food is ready\n";
	return;
}

stove::stove()
{
	current_lamp = light_on;
	current_door = open;
	current_power = off;
	time = -1;
}

void stove::run()
{
	int i{0};
	enum keys{b=98,d=100,ESC=27};
	while (true)
	{
		while (!_kbhit())  
		{
			if (time > 0)
				--time;
			if (time == 0)
				food_ready();
		}
		i = _getch();
		switch (i)
		{
		case b:take_button(); break;
		case d:take_door(); break;
		case ESC:return; break;
		}
	}
}


stove::~stove()
{
}
