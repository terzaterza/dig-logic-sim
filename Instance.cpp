#include "Instance.h"
#include "Architecture.h"
#include "Port.h"

BehavioralInstance::BehavioralInstance(Architecture& arch, Circuit& circuit)
	: Instance(circuit), _Arch(arch)
{
	int inputPortCount = arch._InputPortWidths.size();
	int outputPortCount = arch._OutputPortWidths.size();

	_InputPorts.reserve(inputPortCount);
	_OutputPorts.reserve(outputPortCount);
	
	for (unsigned int i = 0; i < inputPortCount; i++)
		_InputPorts.emplace_back(i, arch._InputPortWidths[i], this);
	for (unsigned int i = 0; i < outputPortCount; i++)
		_OutputPorts.emplace_back(i, arch._OutputPortWidths[i], _Circuit);
}

void BehavioralInstance::OnInputEvent(port_id portIndex, ev_time eventTime)
{
	port_drive_map output;
	
	unsigned int inputSize = _InputPorts.size();
	data_value* input = new data_value[inputSize];
	for (unsigned int i = 0; i < inputSize; i++)
	{
		input[i] = _InputPorts[i].GetValue();
	}
	
	for (const process& p : _Arch._Processes[portIndex])
	{
		p(input, portIndex, output);
	}

	delete[] input;

	for (auto& i : output)
	{
		ev_time delay = i.second.second;
		data_value new_value = i.second.first; // & with output mask here
		_OutputPorts[i.first].DriveSignal(new_value, eventTime + delay);
	}
}

const InputPort& Instance::GetInputPort(port_id index) const
{
	return _InputPorts[index];
}

const OutputPort& Instance::GetOutputPort(port_id index) const
{
	return _OutputPorts[index];
}

Instance::Instance(Circuit& circuit)
	: _Circuit(circuit)
{
}
