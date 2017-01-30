#ifndef __OVER_SCENE_H__
#define __OVER_SCENE_H__

#include "cocos2d.h"
#include "MenuScene.h"

USING_NS_CC;

class OverScene : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	void setScore(int score);

	// implement the "static create()" method manually
	CREATE_FUNC(OverScene);
private:
	void gotoMenuScene();
	void gotoPlayScene();
	int _score;
	Label* _scoreLabel;
	Label* _highScoreLabel;
};

#endif // __HELLOWORLD_SCENE_H__
