//
//  SecondScene.cpp
//  SampleFourteen
//
//  Created by jie on 14-2-24.
//
//

#include "SecondScene.h"

bool SecondScene::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* background=CCSprite::create("background.jpg");
    background->setPosition(ccp(size.width*0.5, size.height*0.5));
    this->addChild(background);
    
    CCLabelTTF* label=CCLabelTTF::create("This is the second scene", "", 30);
    label->setPosition(ccp(size.width*0.5, size.height*0.5));
    label->setColor(ccc3(100, 80, 70));
    this->addChild(label);
    
    return true;
}
