#include "EventQueue.h"

void EventQueue::AddEvent(const event_data& event)
{
	_Queue.push(event);
	if (!_QueueExecuting)
		ExecuteEvents();
}

void EventQueue::ExecuteEvents()
{
	_QueueExecuting = true;

	int timeout_count = 0;
	while (!_Queue.empty())
	{
		// could set max simulation time and when q.top.time > that end simulation

		time time = _Queue.top().first;
		driver_data event = _Queue.top().second;
		_Queue.pop();

		std::get<0>(event)->
			DriveSignal(std::get<2>(event), std::get<1>(event), time);

		if (timeout_count++ > EVENT_QUEUE_TIMEOUT)
			throw "Event execution timeout"; // TODO: replace with exception
	}

	_QueueExecuting = false;
}
