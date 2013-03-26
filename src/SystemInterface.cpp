/** @file   SystemInterface.cpp
    @author Philip Abbet

    Implementation of the class 'Athena::GUI::SystemInterface'
*/

#include <Athena-GUI/SystemInterface.h>
#include <Athena-Core/Log/LogManager.h>


using namespace Athena::GUI;
using namespace Athena::Log;
using namespace std;


/****************************** CONSTRUCTION / DESTRUCTION ******************************/

SystemInterface::SystemInterface()
{
}

//-----------------------------------------------------------------------

SystemInterface::~SystemInterface()
{
}


/***************** IMPLEMENTATION OF THE libRocket's System Interface API ***************/

float SystemInterface::GetElapsedTime()
{
    return float(m_timer.getMilliseconds()) * 0.001f;
}

//-----------------------------------------------------------------------

bool SystemInterface::LogMessage(Rocket::Core::Log::Type type, const Rocket::Core::String& message)
{
    switch (type)
    {
        case Rocket::Core::Log::LT_ERROR:   LogManager::Log(LOG_ERROR, "libRocket", message.CString(), "", "", 0); break;
        case Rocket::Core::Log::LT_DEBUG:
        case Rocket::Core::Log::LT_ASSERT:  LogManager::Log(LOG_DEBUG, "libRocket", message.CString(), "", "", 0); break;
        case Rocket::Core::Log::LT_WARNING: LogManager::Log(LOG_WARNING, "libRocket", message.CString(), "", "", 0); break;
        case Rocket::Core::Log::LT_INFO:    LogManager::Log(LOG_EVENT, "libRocket", message.CString(), "", "", 0); break;
        default:                            LogManager::Log(LOG_COMMENT, "libRocket", message.CString(), "", "", 0); break;
    }

    return true;
}
