#pragma once

#include "Port.h"

// unsigned int = port_id (port index)
typedef std::map<unsigned int, std::pair<data_value, time>> process_result;
typedef process_result (*process)(data_value*, unsigned int);

class Architecture
{
public:
	virtual void OnInputEvent() = 0;

private:
	unsigned int _InputPortCount, _OutputPortCount;
	data_width* _InputWidths, * _OutputWidths;

public:
	Architecture()
};
