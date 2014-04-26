#define LOG_DEBUG
#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

#ifndef LOG_DEBUG
#define LOG_DEBUG(format,...) printf(""__FILE__"(%04d): [DEBUG]"format"\n", __LINE__, ##__VA_ARGS__)
#endif

#ifndef LOG_INFO
#define LOG_INFO(format,...) printf(""__FILE__"(%04d): [INFO]"format"\n", __LINE__, ##__VA_ARGS__)
#endif

#ifndef LOG_ERROR
#define LOG_ERROR(format,...) printf(""__FILE__"(%04d): [ERROR]"format"\n", __LINE__, ##__VA_ARGS__)
#endif

#endif

/*
	LOG_DEBUG("Helo");
	LOG_DEBUG("%d", int_value);
*/