#pragma once

#include "Types.h"

class Architecture
{
private:
	std::vector<data_width> _InputPortWidths, _OutputPortWidths;
	std::vector<process>* _Processes;

public:
	Architecture(
		std::vector<data_width> inWidths,
		std::vector<data_width> outWidths,
		const std::vector<sensitive_process>& processes // can use variadic arguments instead of vector
	);

	~Architecture();

	friend class BehavioralInstance;
};
