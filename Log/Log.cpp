#include "Log.h"

void Log::error(std::string message) {
	printf("\033[31m%s\033[0m\n", message.c_str());
}

void Log::info(std::string message) {
	printf("\033[32m%s\033[0m\n", message.c_str());
}

void Log::debug(std::string message) {
	printf("\033[34m%s\033[0m\n", message.c_str());
}

void Log::warnning(std::string message) {
	printf("\033[33m%s\033[0m\n", message.c_str());
}