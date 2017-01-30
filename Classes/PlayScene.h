#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
class PlayScene : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    

	void RightTouch();
	void LeftTouch();
	void MidTouch();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void showOverLayer();
	void update(float dt);
	//void randomColor();
    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
	
private:

	int _score;
	float _time;

	CocosDenshion::SimpleAudioEngine *Au;



	Label* _whatColor;
	Label* _scoreLabel;
	Label* _timeLabel;
	std::string color;
	MenuItemImage* m_photo1;
	MenuItemImage* m_photo2;
	MenuItemImage* m_photo3;
	Menu* _colorPho;

};

#endif // __HELLOWORLD_SCENE_H__
