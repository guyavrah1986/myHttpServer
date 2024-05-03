#include <thread> 						// applicble since C++11
#include <gperftools/heap-checker.h> 	// for tcmalloc heap checking
#include <log4cxx/logger.h>

#include "../infra/include/posixCpp11ThreadWrapper.h"

TEST(posixCpp11ThreadWrapperTest, createSingleThreadAndRunTillCompletion)
{ 
	auto rootLogger = log4cxx::Logger::getRootLogger();
    LOG4CXX_INFO(rootLogger, "about to create single posixCpp11ThreadWrapperTest object \
		and check for leaks");

	
	HeapLeakChecker heap_checker("test_posixCpp11ThreadWrapper");
    {
	    std::thread sampleThread;
		Cpp11ThreadWrapper::RAIIAction action;
		PosixCpp11ThreadWrapper sampleWrappedThread(std::move(sampleThread), action);
    }
    if (!heap_checker.NoLeaks()) assert(NULL == "heap memory leak");
	
	LOG4CXX_INFO(rootLogger, "test ended successfully");
}