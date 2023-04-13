#pragma once

#include "Types.h"

class Architecture
{
private:
	const unsigned int _InputPortCount, _OutputPortCount; // could be of port_id type
	const data_width* _InputPortWidths, * _OutputPortWidths;

	std::vector<process>* _Processes;

public:
	Architecture(
		unsigned int inCount,
		data_width* inWidths,
		unsigned int outCount,
		data_width* outWidths,
		const std::vector<sensitive_process>& processes
	);

	~Architecture();

	friend class BehavioralInstance;
};
