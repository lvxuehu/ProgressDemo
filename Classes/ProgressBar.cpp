//
//  ProgressBar.cpp
//  SampleFourteen
//
//  Created by jie on 14-2-24.
//
//

#include "ProgressBar.h"
#include "SecondScene.h"

bool ProgressBar::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    
    
    currentValue=0;
    maxValue=27;
    
    
    char picName[10]="";
    
    
    
    size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* background=CCSprite::create("background.jpg");
    background->setPosition(ccp(size.width*0.5, size.height*0.5));
    this->addChild(background);
    
    pLabel=CCLabelTTF::create("Loading0%", "", 30);
    pLabel->setPosition(ccp(size.width*0.5, size.height*0.5+100));
    pLabel->setAnchorPoint(ccp(0.5, 0.5));
    pLabel->setColor(ccc3(200, 130, 20));
    pLabel->setTag(pLabelTag);
    this->addChild(pLabel);
    
    CCSprite* pBar=CCSprite::create("progressbar.png");
    pBar->setPosition(ccp(size.width*0.5, size.height*0.5+50));
    this->addChild(pBar,1);
    
    CCSprite* progress=CCSprite::create("progress.png");//进度条的背景
    
    CCProgressTimer* timer=CCProgressTimer::create(progress);
    timer->setPosition(ccp(size.width*0.5, size.height*0.5+50));
    timer->setType(kCCProgressTimerTypeBar);
    timer->setBarChangeRate(ccp(1,0));
    timer->setMidpoint(ccp(0,0));
    timer->setTag(progressTag);
    timer->setPercentage(0);
    
    this->addChild(timer,2);
    
    
    
    for(int index=1;index<maxValue+1;index++)
    {
        sprintf(picName, "%d.png",index);
        CCTextureCache::sharedTextureCache()->addImageAsync(picName, this, callfuncO_selector(ProgressBar::refreshProgress));
        //png加入全局cache中
//        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("shoot_background4.plist");
    }
    
    return true;
}

void ProgressBar::refreshProgress(CCObject* object)
{
    currentValue++;
    
    CCProgressTimer* update=(CCProgressTimer*)this->getChildByTag(progressTag);
    float currentPercentage=update->getPercentage();
    CCLog("currentPercentage=%f",currentPercentage);
    
    currentPercentage=100.0/maxValue+currentPercentage;
    
    CCLog("currentPercentage=%f  set after",currentPercentage);
    update->setPercentage(currentPercentage);

    CCString* nValue=CCString::createWithFormat("Loading%.2f%%",currentPercentage);
    
    
//    CCLog("%s",nValue->getCString());
    CCLabelTTF* nLabel=(CCLabelTTF*)this->getChildByTag(pLabelTag);
    nLabel->setString(nValue->getCString());
    
    sprintf(picName, "%d.png",currentValue);
    
//    CCLog("%s",picName);
    
    
    
    CCTexture2D* texture=CCTextureCache::sharedTextureCache()->textureForKey(picName);
    CCSprite* sprite=CCSprite::createWithTexture(texture);
    sprite->setPosition(ccp(size.width*0.5,size.height*0.5-200));
    this->addChild(sprite);
    
    if (currentValue==maxValue)
    {
        CCScene* scene=CCScene::create();
        SecondScene* second=SecondScene::create();
        scene->addChild(second);
//        CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(2.0f, scene));
    }
}
