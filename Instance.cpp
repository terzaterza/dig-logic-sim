#include "Instance.h"

BehavioralInstance::BehavioralInstance(Architecture& arch)
	: _Arch(arch)
{
	_InputPorts.reserve(arch._InputPortCount);
	_OutputPorts.reserve(arch._OutputPortCount);
	
	for (int i = 0; i < arch._InputPortCount; i++)
		_InputPorts.emplace_back(i, arch._InputPortWidths[i], this);
	for (int i = 0; i < arch._OutputPortCount; i++)
		_OutputPorts.emplace_back(i, arch._OutputPortWidths[i]);
}

void BehavioralInstance::OnInputEvent(port_id portIndex, time eventTime)
{
	port_drive_map output;
	
	unsigned int inputSize = _InputPorts.size();
	data_value* input = new data_value[inputSize];
	for (int i = 0; i < inputSize; i++)
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
		time delay = i.second.second;
		data_value new_value = i.second.first;
		_OutputPorts[i.first].DriveSignal(new_value, eventTime + delay);
	}
}
