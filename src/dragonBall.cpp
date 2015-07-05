/*
-----------------------------------------------------------------------------
Filename:    dragonBall.cpp
-----------------------------------------------------------------------------


-----------------------------------------------------------------------------
*/
#include "dragonBall.h"

//-------------------------------------------------------------------------------------
DragonBall::DragonBall(void)
{
}
//-------------------------------------------------------------------------------------
DragonBall::~DragonBall(void)
{
}

//-------------------------------------------------------------------------------------
void DragonBall::createScene(void)
{
	// Luz ambiente de la escena
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));

    // Creación de Entidad
    Ogre::Entity* goku = mSceneMgr->createEntity("bodyGoku", "goku.mesh");

    // Creación de SceneNode y enlaza la Entidad
    Ogre::SceneNode* gokuNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NodoBodyGoku");
    gokuNode->attachObject(goku);

	gokuNode->yaw(Ogre::Degree( 90 ) );
	gokuNode->setPosition(0,-5,-10);

    // Creación de Bubu
    Ogre::Entity* bubu = mSceneMgr->createEntity("bodyBubu", "bubu2.mesh");


    // Creación de SceneNode y enlaza la Entidad
    Ogre::SceneNode* bubuNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NodoBodyBubu");
    bubuNode->attachObject(bubu);
	bubuNode->setScale(1, 1, 1);

	bubuNode->setPosition(0,0,-60);

    // Creación de Trunks
    Ogre::Entity* trunks = mSceneMgr->createEntity("bodyTrunks", "trunks.mesh");

    // Creación de SceneNode y enlaza la Entidad
    Ogre::SceneNode* trunksNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NodoBodyTrunks");
    trunksNode->attachObject(trunks);

	trunksNode->yaw(Ogre::Degree( 90 ) );

	trunksNode->setPosition(-30,0,-30);
	trunksNode->setScale(2, 2, 2);


    // Creación de Nappa
    Ogre::Entity* nappa = mSceneMgr->createEntity("bodyNappa", "nappa.mesh");

    // Creación de SceneNode y enlaza la Entidad
    Ogre::SceneNode* nappaNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NodoBodyNappa");
    nappaNode->attachObject(nappa);

	
	nappaNode->yaw(Ogre::Degree( -90 ) );
	nappaNode->setPosition(30,0,-60);
	nappaNode->setScale(22, 22, 22);


    // Creación de Cell3
    Ogre::Entity* cell3 = mSceneMgr->createEntity("bodyCell3", "cell3.mesh");

    // Creación de SceneNode y enlaza la Entidad
    Ogre::SceneNode* cell3Node = mSceneMgr->getRootSceneNode()->createChildSceneNode("NodoBodyCell3");
    cell3Node->attachObject(cell3);
	
	cell3Node->yaw(Ogre::Degree( -90 ) );
	cell3Node->setPosition(-20,0,-30);
	cell3Node->setScale(2.4, 2.4, 2.4);

    // Creación de Entidad
    Ogre::Entity* kameHouse = mSceneMgr->createEntity("bodyKame", "KameHouse.mesh");

    // Creación de SceneNode y enlaza la Entidad
    Ogre::SceneNode* kameNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NodoBodyKame");
    kameNode->attachObject(kameHouse);

	kameNode->setPosition(30, 0, 0);
	kameNode->setScale(8, 8, 8);


    // Create una luz y establece su posición
    Ogre::Light* light = mSceneMgr->createLight("LuzPrincipal");
    light->setPosition(20.0f, 80.0f, 50.0f);

  // Create ground
  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
 
  Ogre::MeshManager::getSingleton().createPlane(
    "ground",
  Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
  plane, 500, 500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);
 
  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
 
  groundEntity->setMaterialName("IG/Sand");
  groundEntity->setCastShadows(false);
 
  // Spotlight
  Ogre::Light* spotLight = mSceneMgr->createLight("Spotlight");
  spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
 
  spotLight->setDiffuseColour(Ogre::ColourValue(0, 0, 1));
  spotLight->setSpecularColour(Ogre::ColourValue(0, 0, 1));
 
  spotLight->setDirection(-1, -1, 0);
  spotLight->setPosition(Ogre::Vector3(200, 200, 0));
 
  spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));
 
  // Directional light
  Ogre::Light* directionalLight = mSceneMgr->createLight("DirectionalLight");
  directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
 
  directionalLight->setDiffuseColour(Ogre::ColourValue(.4, 0, 0));
  directionalLight->setSpecularColour(Ogre::ColourValue(.4, 0, 0));
 
  directionalLight->setDirection(Ogre::Vector3(0, -1, 1));

}


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        DragonBall app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
