#pragma once
#include <string>
#include <iostream>

#define DELCPY(a)	a(const a&) = delete;\
					a(a&&) = delete;\
					a operator=(const a&) = delete;\
					a operator=(a&&) = delete;