#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bg = Sprite::create("moles_bg.png");
    bg->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(bg);

    ///get ratio

    mySprite = Sprite::create("CloseNormal.png");
    mySprite->setPosition(Point((visibleSize.width/2  )+ origin.x, (visibleSize.height/2  )+ origin.y));
    this->addChild(mySprite);



/*    ccBezierConfig bezier;
    bezier.controlPoint_1= Point(0,visibleSize.height/2);
    bezier.controlPoint_2= Point(300,-visibleSize.height/2);
    bezier.endPosition=Point(200,100);

    auto action = BezierTo::create(8,bezier);
    mySprite->runAction(action);*/

    /*auto action = Place::create(Point(100,100));
    mySprite->runAction(action);*/


    auto action = SkewBy::create(4,100,50);
    mySprite->runAction(action);

    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("moles_ouch.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("moles_ouch.wav", true);


    float rX= visibleSize.width / (bg->getTexture()->getContentSize().width);
    float rY= visibleSize.height / (bg->getTexture()->getContentSize().height);

    bg->setScaleX(rX);
    bg->setScaleY(rY);


    return true;
}

void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{

}


void HelloWorld::menuCloseCallback(Ref* pSender)
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
