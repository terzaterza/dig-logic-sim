#include "Net.h"

void Net::NotifyListeners(time time)
{
	for (InputPort* p : _Listeners)
	{
		p->OnInputEvent(time);
	}
}

void Net::DriveSignal(port_id portId, data_value value, time time)
{
	_Drivers[portId] = value;

	if (value == _Value)
		return;

	if (_Drivers.size() == 1)
		_Value = value;
	else
		throw "Short circuit exception"; // replace with new exception

	NotifyListeners(time);
}

void Net::RemoveDriver(port_id portId, time time)
{
	_Drivers.erase(portId);

	if (_Drivers.size() == 0)
	{
		data_value tempVal = _Value;
		if (_Pull)
			_Value = _PullValue;
		// else _Value = random
		if (_Value != tempVal)
			NotifyListeners(time);
	}
}

void Net::SetPull(data_value value)
{
	_Pull = true;
	_PullValue = value;
	
	if (_Drivers.size() == 0)
		_Value = value;
}

data_value Net::GetValue()
{
	return _Value;
}

Net::Net(data_width width)
{
	_Width = width;
	_Pull = false;

	// init values with random and & with data_width

	// check if _Drivers and _Listeners should be instantiated
}
