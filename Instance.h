#pragma once

#include <vector>
#include "Types.h"

class InputPort;
class OutputPort;

class Circuit;
class Architecture;

class Instance
{
public:
	virtual void OnInputEvent(port_id portIndex, ev_time eventTime) = 0;

	const InputPort& GetInputPort(port_id index) const;

	const OutputPort& GetOutputPort(port_id index) const;

protected:
	std::vector<InputPort> _InputPorts; // could change to InputPort*
	std::vector<OutputPort> _OutputPorts;

	Circuit& _Circuit;

public:
	Instance(Circuit& circuit);
};

class BehavioralInstance : public Instance
{
public:
	void OnInputEvent(port_id portIndex, ev_time eventTime) override;

private:
	Architecture& _Arch;

public:
	BehavioralInstance(Architecture& arch, Circuit& circuit);
};

/*
class CircuitInstance : public Instance
{
private:
	Circuit _Circuit;
};
*/