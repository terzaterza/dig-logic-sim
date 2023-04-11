#pragma once

#include <vector>
#include <map>

#include "Pin.h"

typedef unsigned int data_width; // should be < sizeof(data_value)
typedef unsigned int data_value;

class Net
{
private:
	void NotifyListeners(time time);

public:
	// Called only from event execution queue
	void DriveSignal(pin_id pinId, data_value value, time time); // assert that pin.width = width

	void RemoveDriver(pin_id pinId, time time);

	void SetPull(data_value value);

	data_value GetValue();

private:
	data_width _Width;

	// bool _HighZ; - not used for now
	bool _Pull;

	data_value _PullValue;
	data_value _Value;

	std::map<pin_id, data_value> _Drivers;
	std::vector<InputPin*> _Listeners;

public:
	Net(data_width width);
};
