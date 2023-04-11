#pragma once

#include "Net.h"
#include "EventQueue.h"
#include "Instance.h"

typedef unsigned int port_id;

class Port
{
public:
	const Net& GetNet() const;

	void SetNet(Net& net);

protected:
	const port_id _PortIndex; // index in instance input/output port array

private:
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
	Instance& _Instance;
};

class OutputPort : public Port
{
public:
	void DriveSignal(data_value value, time delay);
};