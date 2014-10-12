//
//  ProgressBar.h
//  SampleFourteen
//
//  Created by jie on 14-2-24.
//
//

#ifndef __SampleFourteen__ProgressBar__
#define __SampleFourteen__ProgressBar__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

typedef enum
{
    pLabelTag=20,
    progressTag=21,
}Tag;


class ProgressBar:public CCLayer
{
public:
    CREATE_FUNC(ProgressBar);
    virtual bool init();
public:
    CCSize size;
    CCLabelTTF* pLabel;
    int currentValue;
    int maxValue;
    char picName[10];
    
    
public:
    void refreshProgress(CCObject* object);
};

#endif /* defined(__SampleFourteen__ProgressBar__) */
