/** @file   GUIManager.cpp
    @author Philip Abbet

    Implementation of the class 'Athena::GUI::GUIManager'
*/

#include <Athena-GUI/GUIManager.h>
#include <Athena-GUI/SystemInterface.h>
#include <Athena-Core/Log/LogManager.h>
#include <Rocket/Core.h>


using namespace Athena::GUI;
using namespace Athena::Utils;
using namespace Athena::Log;
using namespace Rocket::Core;
using namespace std;


/************************************** CONSTANTS ***************************************/

/// Context used for logging
static const char* __CONTEXT__ = "GUI manager";


/********************************** STATIC ATTRIBUTES ***********************************/

/// The instance of the singleton
template<> GUIManager* Singleton<GUIManager>::ms_Singleton = 0;



/****************************** CONSTRUCTION / DESTRUCTION ******************************/

GUIManager::GUIManager()
: m_pDefaultSystemInterface(0), m_pActiveContext(0)
{
    ATHENA_LOG_EVENT("Creation");

    if (!Rocket::Core::GetSystemInterface())
    {
        m_pDefaultSystemInterface = new SystemInterface();
        Rocket::Core::SetSystemInterface(m_pDefaultSystemInterface);
    }

    Rocket::Core::Initialise();
}

//-----------------------------------------------------------------------

GUIManager::~GUIManager()
{
    ATHENA_LOG_EVENT("Destruction");

    destroyAll();

    Rocket::Core::Shutdown();

    delete m_pDefaultSystemInterface;
}

//-----------------------------------------------------------------------

GUIManager& GUIManager::getSingleton()
{
    assert(ms_Singleton);
    return *ms_Singleton;
}

//-----------------------------------------------------------------------

GUIManager* GUIManager::getSingletonPtr()
{
    return ms_Singleton;
}


/******************************* MANAGEMENT OF THE CONTEXTS *****************************/

Rocket::Core::Context* GUIManager::create(const std::string& strName, unsigned int width,
                                          unsigned int height)
{
    // Assertions
    assert(!strName.empty() && "Invalid context name");

    Context* pContext = CreateContext(strName.c_str(), Vector2i(width, height));
    m_contexts.push_back(pContext);

    return pContext;
}

//-----------------------------------------------------------------------

Rocket::Core::Context* GUIManager::getContext(const std::string& strName)
{
    assert(!strName.empty() && "The name is empty");

    // Declarations
    tContextsNativeIterator iter, iterEnd;

    // Search the context
    for (iter = m_contexts.begin(), iterEnd = m_contexts.end(); iter != iterEnd; ++iter)
    {
        if (strName == (*iter)->GetName().CString())
        {
            // Return it
            return (*iter);
        }
    }

    // Not found
    return 0;
}

//-----------------------------------------------------------------------

void GUIManager::destroy(const std::string& strName)
{
    // Assertions
    assert(!strName.empty() && "The name is empty");

    // Declarations
    Context* pContext;

    // Search the context
    pContext = getContext(strName);
    if (pContext)
    {
        destroy(pContext);
    }
    else
    {
        ATHENA_LOG_ERROR("Failed to destroy the context '" + strName + "'");
        assert(false);  // A context not registered with this manager is not allowed
    }
}

//-----------------------------------------------------------------------

void GUIManager::destroy(Context* pContext)
{
    // Assertions
    assert(pContext && "Invalid context");

    // Declarations
    tContextsNativeIterator iter, iterEnd;

    // Search the context
    for (iter = m_contexts.begin(), iterEnd = m_contexts.end(); iter != iterEnd; ++iter)
    {
        if (*iter == pContext)
        {
            m_contexts.erase(iter);
            delete pContext;
            break;
        }
    }
}

//-----------------------------------------------------------------------

void GUIManager::destroyAll()
{
    while (!m_contexts.empty())
        destroy(m_contexts.front());
}
