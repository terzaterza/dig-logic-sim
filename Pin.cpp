#include "Pin.h"

const Net& Pin::GetNet() const
{
	return *_Net;
}

void Pin::SetNet(Net& net)
{
	_Net = &net;
}

void OutputPin::DriveSignal(data_value value, time delay)
{
	// TODO - see how to pass the current time + delay to event queue
}
