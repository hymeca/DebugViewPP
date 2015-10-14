// (C) Copyright Gert-Jan de Vos and Jan Wilmans 2013.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)

// Repository at: https://github.com/djeedjay/DebugViewPP/

#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Win32/Win32Lib.h"

namespace fusion {
namespace debugviewpp {

class LogSource;

struct Line
{
	Line(double time, FILETIME systemTime, HANDLE handle, const std::string& message, const LogSource* pLogSource);
	Line(double time = 0.0, FILETIME systemTime = FILETIME(), DWORD pid = 0, const std::string& processName = std::string(), const std::string& message = std::string(), const LogSource* pLogSource = nullptr);

	double time;
	FILETIME systemTime;
	HANDLE handle;
	DWORD pid;
	std::string processName;
	std::string message;
	const LogSource* pLogSource;
};

typedef std::vector<Line> Lines;

} // namespace debugviewpp 
} // namespace fusion
