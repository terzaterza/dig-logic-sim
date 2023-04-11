#pragma once

#include "Architecture.h"
#include "Circuit.h"
#include "Port.h"

class Instance
{
public:
	virtual void OnInputEvent(unsigned int portIndex, time time) = 0; // could replace portIndex type to port_id

private:
	InputPort* _InputPorts;
	OutputPort* _OutputPorts;
};

class BehavioralInstance : public Instance
{
public:
	void OnInputEvent(unsigned int portIndex, time time) override;

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