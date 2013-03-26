/** @file   SystemInterface.h
    @author Philip Abbet

    Declaration of the class 'Athena::GUI::SystemInterface'
*/

#ifndef _ATHENA_GUI_SYSTEMINTERFACE_H_
#define _ATHENA_GUI_SYSTEMINTERFACE_H_

#include <Athena-GUI/Prerequisites.h>
#include <Athena-Core/Utils/Timer.h>
#include <Rocket/Core/SystemInterface.h>


namespace Athena {
namespace GUI {


//----------------------------------------------------------------------------------------
/// @brief  System Interface implementation for libRocket
///
/// This class provides interfaces for Time and Logging.
//----------------------------------------------------------------------------------------
class ATHENA_GUI_SYMBOL SystemInterface: public Rocket::Core::SystemInterface
{
    //_____ Construction / Destruction __________
public:
    //------------------------------------------------------------------------------------
    /// @brief  Constructor
    //------------------------------------------------------------------------------------
    SystemInterface();

    //------------------------------------------------------------------------------------
    /// @brief  Destructor
    //------------------------------------------------------------------------------------
    virtual ~SystemInterface();


    //_____ Implementation of the libRocket's System Interface API __________
public:
    //------------------------------------------------------------------------------------
    /// @brief  Get the number of seconds elapsed since the start of the application
    ///
    /// @return Elapsed time, in seconds
    //------------------------------------------------------------------------------------
    virtual float GetElapsedTime();

    //------------------------------------------------------------------------------------
    /// @brief  Log the specified message
    ///
    /// @param[in] type     Type of log message, ERROR, WARNING, etc
    /// @param[in] message  Message to log
    /// @return             True to continue execution, false to break into the debugger
    //------------------------------------------------------------------------------------
    virtual bool LogMessage(Rocket::Core::Log::Type type, const Rocket::Core::String& message);


    //_____ Attributes __________
protected:
    Athena::Utils::Timer m_timer;
};

}
}

#endif
