/** @file   Prerequisites.h
    @author Philip Abbet

    Declaration of the types of the Athena-GUI module
*/

#ifndef _ATHENA_GUI_PREREQUISITES_H_
#define _ATHENA_GUI_PREREQUISITES_H_

#include <Athena-Core/Prerequisites.h>
#include <Athena-GUI/Config.h>


/// Used to export symbols from the library
#if (ATHENA_PLATFORM == ATHENA_PLATFORM_WIN32)
#    ifdef ATHENA_GUI_EXPORTS
#        define ATHENA_GUI_SYMBOL __declspec(dllexport)
#    else
#        define ATHENA_GUI_SYMBOL __declspec(dllimport)
#    endif
#else
#    define ATHENA_GUI_SYMBOL
#endif


//---------------------------------------------------------------------------------------
/// @brief  Main namespace. All the components of the Athena engine belongs to this
///         namespace
//---------------------------------------------------------------------------------------
namespace Athena
{
    //-----------------------------------------------------------------------------------
    /// @brief  Contains all the GUI-related classes
    //-----------------------------------------------------------------------------------
    namespace GUI
    {
        class GUIManager;
        class SystemInterface;

        ATHENA_GUI_SYMBOL extern const char* VERSION;
    }
}

#endif
