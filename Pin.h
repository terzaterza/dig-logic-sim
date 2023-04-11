#pragma once

#include "Net.h"
#include "EventQueue.h"

typedef unsigned int pin_id;

class Pin
{
public:
	const Net& GetNet() const;

	void SetNet(Net& net);

private:
	pin_id id; // globally unique id
	data_width _Width;

	Net* _Net;
};

class InputPin : public Pin
{
public:
	void OnInputEvent();
};

class OutputPin : public Pin
{
public:
	void DriveSignal(data_value value, time delay);
};