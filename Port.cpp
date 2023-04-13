#include "Port.h"
#include "Net.h"
#include "Circuit.h"
#include "Instance.h"

port_id GLOBAL_PIN_COUNT = 0;

void Port::SetNet(Net& net)
{
	_Net = &net;
}

data_value Port::GetValue() const
{
	return _Net->GetValue();
}

// This constructor should never be called as this class is virtual
// Possibly set = delete
Port::Port(port_id portIndex, data_width width)
	: _ID(GLOBAL_PIN_COUNT++), _PortIndex(portIndex), _Width(width), _Net(nullptr)
{
}

void InputPort::OnInputEvent(ev_time time)
{
	_Instance->OnInputEvent(_PortIndex, time);
}

InputPort::InputPort(port_id portIndex, data_width width, Instance* instance)
	: Port(portIndex, width), _Instance(instance)
{
}

void OutputPort::DriveSignal(data_value value, ev_time eventTime)
{
	_Circuit.AddSignalEvent(_Net, _ID, value, eventTime);
}

OutputPort::OutputPort(port_id portIndex, data_width width, Circuit& circuit)
	: Port(portIndex, width), _Circuit(circuit)
{
}
