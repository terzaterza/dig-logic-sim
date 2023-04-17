#include <iostream>

#include "Types.h"
#include "Architecture.h"
#include "Circuit.h"
#include "Port.h"
#include "Instance.h"
#include "EventQueue.h"

void and_p(const data_value* input, port_id index, port_drive_map& map)
{
	map[0] = std::make_pair(input[0] & input[1], 1);
}

Architecture and_a({ 1, 1 }, { 1 }, { {{0,1}, &and_p} });

int main()
{
	EventQueue eq;
	Circuit c(eq);
	BehavioralInstance and_i(and_a, c);
	std::cout << "Hello world!";
	return 0;
}