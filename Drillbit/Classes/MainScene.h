#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

#include "Universe.h"

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    void addEntitySubs(Entity* entity);

    void update(float) override;
    CREATE_FUNC(MainScene);
private:
    Universe universe;
};

#endif // __MAIN_SCENE_H__
