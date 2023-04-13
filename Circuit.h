#pragma once

#include "Types.h"

class Net;
class EventQueue;

class Circuit
{
public:
	Circuit(EventQueue& queue);

	void AddSignalEvent(
		Net* net,
		port_id portIndex,
		data_value value,
		ev_time eventTime
	);

private:
	EventQueue& _EventQueue;

};