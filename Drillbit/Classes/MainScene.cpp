#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    __android_log_print(ANDROID_LOG_INFO, "tag here", "start");


    universe.generateEntities();
    std::vector<Entity*> entities = universe.getEntities();
    for (std::vector<Entity*>::const_iterator iterator = entities.begin(); iterator != entities.end(); ++iterator) {
    	this->addChild((*iterator)->getUpdateSprite(), 1);
    }
    this->scheduleUpdate();

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}

void MainScene::update(float delta){
	universe.applyGravity();
	universe.step(delta);
	universe.render();
}

bool MainScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	__android_log_print(ANDROID_LOG_INFO, "tag here", "onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);//("onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
	universe.moveShip(touch->getLocation().x,touch->getLocation().y);
    return true;
}

void MainScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	__android_log_print(ANDROID_LOG_INFO, "tag here", "onTouchMoved x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);//("onTouchMoved x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
	universe.moveShip(touch->getLocation().x,touch->getLocation().y);
}

void MainScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	__android_log_print(ANDROID_LOG_INFO, "tag here", "onTouchEnded x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);//("onTouchEnded x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
}

void MainScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
