/** @file   GUIManager.h
    @author Philip Abbet

    Declaration of the class 'Athena::GUI::GUIManager'
*/

#ifndef _ATHENA_GUI_GUIMANAGER_H_
#define _ATHENA_GUI_GUIMANAGER_H_

#include <Athena-GUI/Prerequisites.h>
#include <Athena-Core/Utils/Iterators.h>
#include <Rocket/Core/Context.h>


namespace Athena {
namespace GUI {


//----------------------------------------------------------------------------------------
/// @brief  Represents the manager of the GUI
///
/// This manager is responsible of the creation/destruction of the contexts.
///
/// At shutdown, the destruction of the remaining contexts is handled by the manager.
///
/// At any moment, there can only be one active context.
///
/// @remark This class is a singleton
//----------------------------------------------------------------------------------------
class ATHENA_GUI_SYMBOL GUIManager: public Utils::Singleton<GUIManager>
{
    //_____ Internal types __________
public:
    typedef std::vector<Rocket::Core::Context*>  tContextsList;
    typedef Utils::VectorIterator<tContextsList> tContextsIterator;
    typedef tContextsList::iterator              tContextsNativeIterator;


    //_____ Construction / Destruction __________
public:
    //------------------------------------------------------------------------------------
    /// @brief  Constructor
    //------------------------------------------------------------------------------------
    GUIManager();

    //------------------------------------------------------------------------------------
    /// @brief  Destructor
    //------------------------------------------------------------------------------------
    ~GUIManager();

    //------------------------------------------------------------------------------------
    /// @brief  Returns a reference to the instance of the GUI manager
    /// @return A reference to the manager
    //------------------------------------------------------------------------------------
    static GUIManager& getSingleton();

    //------------------------------------------------------------------------------------
    /// @brief  Returns a pointer to the instance of the GUI manager
    /// @return A pointer to the manager
    //------------------------------------------------------------------------------------
    static GUIManager* getSingletonPtr();


    //_____ Management of the contexts __________
public:
    //------------------------------------------------------------------------------------
    /// @brief  Create a new context
    ///
    /// @param  strName     Name of the context
    /// @param  width       Width of the context
    /// @param  height      Height of the context
    /// @return             The new context, 0 if failed
    //------------------------------------------------------------------------------------
    Rocket::Core::Context* create(const std::string& strName, unsigned int width,
                                  unsigned int height);

    //------------------------------------------------------------------------------------
    /// @brief  Returns a context
    ///
    /// @param  strName     Name of the context
    /// @return             The scene, 0 if not found
    //------------------------------------------------------------------------------------
    Rocket::Core::Context* getContext(const std::string& strName);

    //------------------------------------------------------------------------------------
    /// @brief  Returns a context
    ///
    /// @param  uiIndex     Index of the context
    /// @return             The context
    //------------------------------------------------------------------------------------
    inline Rocket::Core::Context* getContext(unsigned int uiIndex) const
    {
        assert(uiIndex < getNbContexts());
        return m_contexts[uiIndex];
    }

    //------------------------------------------------------------------------------------
    /// @brief  Destroy a context
    ///
    /// @param  strName     Name of the context
    //------------------------------------------------------------------------------------
    void destroy(const std::string& strName);

    //------------------------------------------------------------------------------------
    /// @brief  Destroy a context
    ///
    /// @param  pContext    The context
    //------------------------------------------------------------------------------------
    void destroy(Rocket::Core::Context* pContext);

    //------------------------------------------------------------------------------------
    /// @brief  Destroy all the contexts
    //------------------------------------------------------------------------------------
    void destroyAll();

    //------------------------------------------------------------------------------------
    /// @brief  Returns an iterator over the contexts
    //------------------------------------------------------------------------------------
    inline tContextsIterator getContextsIterator()
    {
        return tContextsIterator(m_contexts.begin(), m_contexts.end());
    }

    //------------------------------------------------------------------------------------
    /// @brief  Returns the number of contexts
    //------------------------------------------------------------------------------------
    inline unsigned int getNbContexts() const
    {
        return (unsigned int) m_contexts.size();
    }

    //------------------------------------------------------------------------------------
    /// @brief  Returns the currently active context
    //------------------------------------------------------------------------------------
    inline Rocket::Core::Context* getActiveContext()
    {
        return m_pActiveContext;
    }


    //_____ Attributes __________
private:
    SystemInterface*        m_pDefaultSystemInterface;  ///< Default System Interface
    tContextsList           m_contexts;                 ///< The contexts
    Rocket::Core::Context*  m_pActiveContext;           ///< The context currently shown
};

}
}

#endif
