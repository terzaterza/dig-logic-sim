#pragma once

#include <tuple>
#include <map>
#include <utility>
#include <vector>

typedef unsigned int port_id;

typedef unsigned int data_width; // should be <= sizeof(data_value)
typedef unsigned int data_value;

typedef unsigned int ev_time;

typedef std::map<port_id, std::pair<data_value, ev_time>> port_drive_map;
typedef void (*process)(const data_value*, port_id, port_drive_map&);
typedef std::pair<std::vector<port_id>, process> sensitive_process;
