#include <log4cxx/logger.h>

#include "include/posixCpp11ThreadWrapper.h"

using namespace std;

PosixCpp11ThreadWrapper::PosixCpp11ThreadWrapper(thread&& t, RAIIAction action)
    : Cpp11ThreadWrapper(move(t), action)
{
    auto rootLogger = log4cxx::Logger::getRootLogger();
    // TODO:  add  // << this->GetThreadId to the log below!
    LOG4CXX_INFO(rootLogger, "created thread with thread ID:");
}

PosixCpp11ThreadWrapper::~PosixCpp11ThreadWrapper()
{
    // TODO:  add  // << this->GetThreadId to the log below!
    auto rootLogger = log4cxx::Logger::getRootLogger();
    LOG4CXX_INFO(rootLogger, "destroyed thread with thread ID:");
}

void PosixCpp11ThreadWrapper::SetScheduling(int priority, int policy)
{
/*
void Cpp11ThreadWrapper::SetScheduling(int policy, int priority)
{
        sch_params.sched_priority = priority;
        if (pthread_setschedparam(th.native_handle(), policy, &sch_params))
		{
            std::cerr << "Failed to set Thread scheduling : " << std::strerror(errno) << std::endl;
        }
}
*/
}
