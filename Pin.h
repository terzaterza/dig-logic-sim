#pragma once

#include "Net.h"
#include "EventQueue.h"
#include "Instance.h"

typedef unsigned int pin_id;

class Pin
{
public:
	const Net& GetNet() const;

	void SetNet(Net& net);

protected:
	const pin_id _PinIndex; // index in instance input/output pin array

private:
	const pin_id _ID; // globally unique id
	const data_width _Width;

	Net* _Net;

public:
	Pin(pin_id pinIndex, data_width width);
};

class InputPin : public Pin
{
public:
	void OnInputEvent(time time);

private:
	Instance& _Instance;
};

class OutputPin : public Pin
{
public:
	void DriveSignal(data_value value, time delay);
};