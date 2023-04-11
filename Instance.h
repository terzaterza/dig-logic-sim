#pragma once

#include "Architecture.h"
#include "Circuit.h"
#include "Pin.h"

class Instance
{
public:
	virtual void OnInputEvent(unsigned int pinIndex, time time) = 0; // could replace pinIndex type to pin_id

private:
	InputPin* _InputPins;
	OutputPin* _OutputPins;
};

class BehavioralInstance : public Instance
{
public:
	void OnInputEvent(unsigned int pinIndex, time time) override;

private:
	Architecture& _Arch;

public:
	BehavioralInstance(Architecture& arch);
};

/*
class CircuitInstance : public Instance
{
private:
	Circuit _Circuit;
};
*/