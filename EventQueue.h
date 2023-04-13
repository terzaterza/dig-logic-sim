#pragma once

#include <tuple>
#include <queue>
#include "Types.h"

#define EVENT_QUEUE_TIMEOUT 500

class Net;

typedef std::tuple<Net*, data_value, port_id> driver_data;
typedef std::pair<ev_time, driver_data> event_data;

class EventQueue
{
public:
	void AddEvent(const event_data& event);
private:
	std::priority_queue<event_data> _Queue;
	bool _QueueExecuting = false;

	void ExecuteEvents();
};