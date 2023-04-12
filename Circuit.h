#pragma once

#include "EventQueue.h"

class Circuit
{
public:
	Circuit(EventQueue& queue);

	void AddSignalEvent(
		Net* net,
		port_id portIndex,
		data_value value,
		time eventTime
	);

private:
	EventQueue& _EventQueue;

};