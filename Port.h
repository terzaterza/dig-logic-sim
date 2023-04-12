#pragma once

#include "Net.h"
#include "EventQueue.h"
#include "Instance.h"

typedef unsigned int port_id;

class Port
{
public:
	void SetNet(Net& net);

	inline data_value GetValue() const;

protected:
	const port_id _PortIndex; // index in instance input/output port array
	const port_id _ID; // globally unique id
	const data_width _Width;

	Net* _Net;

public:
	Port(port_id portIndex, data_width width);
};

class InputPort : public Port
{
public:
	void OnInputEvent(time time);

private:
	Instance* _Instance;

public:
	InputPort(port_id portIndex, data_width width, Instance* instance);
};

class OutputPort : public Port
{
public:
	void DriveSignal(data_value value, time eventTime);

	OutputPort(port_id portIndex, data_width width, Circuit& circuit);

private:
	Circuit& _Circuit;
};