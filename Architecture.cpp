#include "Architecture.h"

Architecture::Architecture(
	unsigned int inCount,
	data_width* inWidths,
	unsigned int outCount,
	data_width* outWidths,
	const std::vector<sensitive_process>& processes
) :
	_InputPortCount(inCount),
	_InputPortWidths(inWidths),
	_OutputPortCount(outCount),
	_OutputPortWidths(outWidths),
	_Processes(new std::vector<process>[inCount])
{
	for (const sensitive_process& p : processes)
	{
		for (const port_id sensitivePort : p.first)
		{
			_Processes[sensitivePort].push_back(p.second);
		}
	}
}

Architecture::~Architecture()
{
	delete[] _Processes;
	// maybe delete port widths here
}
