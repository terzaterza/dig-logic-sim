#pragma once

#include "Instance.h"
#include "Port.h"

typedef std::map<port_id, std::pair<data_value, time>> port_drive_map;
typedef void (*process)(const data_value*, port_id, port_drive_map&);

typedef std::pair<std::vector<port_id>&, process> sensitive_process;

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
