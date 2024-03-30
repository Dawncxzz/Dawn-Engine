#pragma once

#ifdef DAWN_PLATFORM_WINDOWS
	#ifdef DAWN_BUILD_DLL
		#define	DAWN_API __declspec(dllexport)
	#else
		#define	DAWN_API __declspec(dllimport)
	#endif
#else
	#error Dawn only support Windows!
#endif
