#include "Port.h"

port_id GLOBAL_PIN_COUNT = 0;

const Net& Port::GetNet() const
{
	return *_Net;
}

void Port::SetNet(Net& net)
{
	_Net = &net;
}

// This constructor should never be called as this class is virtual
// Possibly set = delete
Port::Port(port_id portIndex, data_width width)
	: _ID(GLOBAL_PIN_COUNT++), _PortIndex(portIndex), _Width(width)
{

}

void OutputPort::DriveSignal(data_value value, time delay)
{
	// TODO - see how to pass the current time + delay to event queue
}

void InputPort::OnInputEvent(time time)
{
	_Instance.OnInputEvent(_PortIndex, time);
}
