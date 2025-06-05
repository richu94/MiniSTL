#pragma once
#include <iostream>

class Log {
public:
	static void error(std::string message);
	static void info(std::string message);
	static void debug(std::string message);
	static void warnning(std::string message);
};

