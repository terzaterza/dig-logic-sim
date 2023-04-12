#include "Circuit.h"

Circuit::Circuit(EventQueue& queue)
	: _EventQueue(queue)
{
}

void Circuit::AddSignalEvent(Net* net, port_id portIndex, data_value value, time eventTime)
{
	_EventQueue.AddEvent(std::make_pair(eventTime, std::make_tuple(net, value, portIndex)));
}
