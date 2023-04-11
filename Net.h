#pragma once

#include <vector>
#include <map>

#include "Port.h"

typedef unsigned int data_width; // should be < sizeof(data_value)
typedef unsigned int data_value;

class Net
{
private:
	void NotifyListeners(time time);

public:
	// Called only from event execution queue
	void DriveSignal(port_id portId, data_value value, time time); // assert that port.width = width

	void RemoveDriver(port_id portId, time time);

	void SetPull(data_value value);

	data_value GetValue();

private:
	data_width _Width;

	// bool _HighZ; - not used for now
	bool _Pull;

	data_value _PullValue;
	data_value _Value;

	std::map<port_id, data_value> _Drivers;
	std::vector<InputPort*> _Listeners;

public:
	Net(data_width width);
};
