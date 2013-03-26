#ifndef _GUITESTENVIRONMENT_H_
#define _GUITESTENVIRONMENT_H_

#include <Athena-GUI/GUIManager.h>
#include <Rocket/Core/Core.h>
#include "../mocks/MockRenderInterface.h"


struct GUITestEnvironment
{
    Rocket::Core::Context*   pDefaultContext;
    Athena::GUI::GUIManager* pGUIManager;
    MockRenderInterface      renderInterface;

    GUITestEnvironment()
    : pDefaultContext(0)
    {
        Rocket::Core::SetRenderInterface(&renderInterface);

        pGUIManager = new Athena::GUI::GUIManager();
        pDefaultContext = pGUIManager->create("default", 800, 600);
    }

    ~GUITestEnvironment()
    {
        delete pGUIManager;
    }
};


#endif
