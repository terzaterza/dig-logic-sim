#pragma once

#include <vector>
#include <map>
#include "Types.h"

class InputPort;

class Net
{
private:
	void NotifyListeners(ev_time time);

public:
	// Called only from event execution queue
	void DriveSignal(port_id portId, data_value value, ev_time time); // assert that port.width = width

	void RemoveDriver(port_id portId, ev_time time);

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
