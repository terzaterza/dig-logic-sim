#pragma once

#include <tuple>
#include <queue>
#include "Net.h"

#define EVENT_QUEUE_TIMEOUT 500

typedef unsigned int time;
typedef std::tuple<Net*, data_value, port_id> driver_data;
typedef std::pair<time, driver_data> event_data;

class EventQueue
{
public:
	void AddEvent(const event_data& event);
private:
	std::priority_queue<event_data> _Queue;
	bool _QueueExecuting;

	void ExecuteEvents();
};