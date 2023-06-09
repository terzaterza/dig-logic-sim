#include "Circuit.h"
#include "EventQueue.h"

Circuit::Circuit(EventQueue& queue)
	: _EventQueue(queue)
{
}

void Circuit::AddSignalEvent(Net* net, port_id portIndex, data_value value, ev_time eventTime)
{
	_EventQueue.AddEvent(std::make_pair(eventTime, std::make_tuple(net, value, portIndex)));
}
