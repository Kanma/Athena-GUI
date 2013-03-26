#include <UnitTest++.h>
#include <Athena-GUI/GUIManager.h>
#include "../environments/GUITestEnvironment.h"


using namespace Athena::GUI;
using namespace Rocket::Core;


TEST(GUIManager_Singleton)
{
    CHECK(!GUIManager::getSingletonPtr());

    GUIManager* pGUIManager = new GUIManager();
    CHECK(pGUIManager);
    CHECK(pGUIManager == GUIManager::getSingletonPtr());

    delete pGUIManager;
    CHECK(!GUIManager::getSingletonPtr());
}


SUITE(GUIManagerTests)
{
    TEST_FIXTURE(GUITestEnvironment, TestFixture)
    {
        CHECK(pGUIManager);
    }


    TEST_FIXTURE(GUITestEnvironment, ContextRetrieval)
    {
        Context* pContext          = pGUIManager->create("test", 800, 600);
        Context* pRetrievedContext = pGUIManager->getContext("test");

        CHECK(pRetrievedContext);
        CHECK(pRetrievedContext == pContext);
    }


    TEST_FIXTURE(GUITestEnvironment, ContextRetrievalFailure)
    {
        Context* pRetrievedContext = pGUIManager->getContext("test");

        CHECK(!pRetrievedContext);
    }


    TEST_FIXTURE(GUITestEnvironment, ContextDestructionFromManager)
    {
        Context* pContext = pGUIManager->create("test", 800, 600);
        pGUIManager->destroy(pContext);

        Context* pRetrievedContext = pGUIManager->getContext("test");
        CHECK(!pRetrievedContext);
    }


    TEST_FIXTURE(GUITestEnvironment, ContextDestructionFromManagerWithName)
    {
        pGUIManager->create("test", 800, 600);
        pGUIManager->destroy("test");

        Context* pRetrievedContext = pGUIManager->getContext("test");
        CHECK(!pRetrievedContext);
    }
}
