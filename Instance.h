#pragma once

#include "Architecture.h"
#include "Circuit.h"
#include "Port.h"

class Instance
{
public:
	virtual void OnInputEvent(port_id portIndex, time time) = 0;

protected:
	std::vector<InputPort> _InputPorts; // could change to InputPort*
	std::vector<OutputPort> _OutputPorts;
};

class BehavioralInstance : public Instance
{
public:
	void OnInputEvent(port_id portIndex, time eventTime) override;

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