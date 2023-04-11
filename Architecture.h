#pragma once

#include "Pin.h"

// unsigned int = pin_id (pin index)
typedef std::map<unsigned int, std::pair<data_value, time>> process_result;
typedef process_result (*process)(data_value*, unsigned int);

class Architecture
{
public:
	virtual void OnInputEvent() = 0;
};
