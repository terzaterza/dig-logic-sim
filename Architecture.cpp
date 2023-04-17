#include "Architecture.h"

Architecture::Architecture(
	std::vector<data_width> inWidths,
	std::vector<data_width> outWidths,
	const std::vector<sensitive_process>& processes
) :
	_InputPortWidths(inWidths),
	_OutputPortWidths(outWidths),
	_Processes(new std::vector<process>[inWidths.size()])
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
