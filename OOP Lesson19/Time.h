#pragma once

namespace HeaderFiles::Helpers
{
	time_t* callLocalTime()
	{
		time_t local(time(0));
		return &local;
	}

	tm* currentDate = localtime(callLocalTime());
}

	
