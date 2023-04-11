#include "Pin.h"

pin_id GLOBAL_PIN_COUNT = 0;

const Net& Pin::GetNet() const
{
	return *_Net;
}

void Pin::SetNet(Net& net)
{
	_Net = &net;
}

// This constructor should never be called as this class is virtual
// Possibly set = delete
Pin::Pin(pin_id pinIndex, data_width width)
	: _ID(GLOBAL_PIN_COUNT++), _PinIndex(pinIndex), _Width(width)
{

}

void OutputPin::DriveSignal(data_value value, time delay)
{
	// TODO - see how to pass the current time + delay to event queue
}

void InputPin::OnInputEvent(time time)
{
	_Instance.OnInputEvent(_PinIndex, time);
}
