#include "PlayScene.h"
#include "OverScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

struct NodeColors {

	std::string color;
	int R;
	int B;
	int G;
};

auto audio = CocosDenshion::SimpleAudioEngine::getInstance();

NodeColors ArrayColor[5];
int flag = 0;
Scene* PlayScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PlayScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PlayScene::init()
{

	

	audio->preloadEffect("false.wav");
	audio->preloadEffect("true.mp3");



	
	ArrayColor[0].color = "DarkRed";
	ArrayColor[0].R = 139 ;
	ArrayColor[0].G = 0 ;
	ArrayColor[0].B = 0 ;


	ArrayColor[1].color = "White";
	ArrayColor[1].R = 255;
	ArrayColor[1].G = 255;
	ArrayColor[1].B = 255;


	ArrayColor[2].color = "Black";
	ArrayColor[2].R = 0;
	ArrayColor[2].G = 0;
	ArrayColor[2].B = 0;


	ArrayColor[3].color = "NavyBlue";
	ArrayColor[3].R = 0;
	ArrayColor[3].G = 0;
	ArrayColor[3].B = 128;


	ArrayColor[4].color = "Green";
	ArrayColor[4].R = 0;
	ArrayColor[4].G = 238;
	ArrayColor[4].B = 0;
    //////////////////////////////
    // 1. super init first
	if (!LayerColor::initWithColor(Color4B(random(1, 255), random(1, 255), random(1, 255), 255)))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	

	_score = 0;
	_time = 5;

	 m_photo1 = MenuItemImage::create("photo1.png","photo1.png", CC_CALLBACK_0(PlayScene::RightTouch ,this));
	 m_photo2 = MenuItemImage::create("photo2.png", "photo2.png", CC_CALLBACK_0(PlayScene::LeftTouch, this));
	 m_photo3 = MenuItemImage::create("photo3.png", "photo3.png", CC_CALLBACK_0(PlayScene::MidTouch, this));
	
	int b = random(0, 4);
	auto fake1 = Color3B(ArrayColor[b].R, 0, 0);
	auto fake2 = Color3B(0, ArrayColor[b].G, 0);
	auto colorTrue = Color3B(ArrayColor[b].R, ArrayColor[b].G, ArrayColor[b].B);
	
	auto ran = random(1, 3);

	if (ran == 1)
	{
		m_photo1->setColor(colorTrue);
		m_photo2->setColor(fake1);
		m_photo3->setColor(fake2);
		
		flag = 1;
	}
	else
	{
		if (ran == 2)
		{
			m_photo2->setColor(colorTrue);
			m_photo1->setColor(fake1);
			m_photo3->setColor(fake2);

			flag = 2;
		}
		else
		{
			m_photo3->setColor(colorTrue);
			m_photo1->setColor(fake1);
			m_photo2->setColor(fake2);

			flag = 3;
		}
	}
	_colorPho = Menu::create(m_photo2, m_photo1, m_photo3, nullptr);
	_colorPho->alignItemsHorizontallyWithPadding(20.0f);
	_colorPho->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + m_photo1->getContentSize().height / 2 + 10));
	this->addChild(_colorPho);

	

	
	_whatColor = Label::createWithTTF(ArrayColor[b].color, "fonts/Square.ttf", 100);
	_whatColor->setAlignment(TextHAlignment::CENTER);
	_whatColor->setLineHeight(80);
	_whatColor->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + (visibleSize.height / 3) * 2));
	this->addChild(_whatColor);


	//TIME LABEL
	_timeLabel = Label::createWithTTF("3", "fonts/Square.ttf", 40);
	_timeLabel->setAnchorPoint(Point(0.0f, 0.5f));
	_timeLabel->setPosition(Point(origin.x + 20, origin.y + visibleSize.height - 40));
	this->addChild(_timeLabel);

	//SCORE LABEL
	_scoreLabel = Label::createWithTTF("0", "fonts/Square.ttf", 40);
	_scoreLabel->setAnchorPoint(Point(1.0f, 0.5f));
	_scoreLabel->setPosition(Point(origin.x + visibleSize.width - 20, origin.y + visibleSize.height - 40));

	this->addChild(_scoreLabel);
	
	//randomColor();

	//Update
	this->scheduleUpdate();

	return true;
}

void PlayScene::RightTouch()
{
	if (flag == 1)
	{
	audio->playEffect("right.mp3");
		_time = 3.0f;

		
		int b = random(0, 4);
		auto fake1 = Color3B(ArrayColor[b].R, 0, 0);
		auto fake2 = Color3B(0, ArrayColor[b].G, 0);
		auto colorTrue = Color3B(ArrayColor[b].R, ArrayColor[b].G, ArrayColor[b].B);



		_whatColor->setString(ArrayColor[b].color);
		_whatColor->setColor(fake1);

		int ran = random(1, 3);

		if (ran == 1)
		{
			m_photo1->setColor(colorTrue);
			m_photo2->setColor(fake1);
			m_photo3->setColor(fake2);

			flag = 1;
		}
		else
		{
			if (ran == 2)
			{
				m_photo2->setColor(colorTrue);
				m_photo1->setColor(fake1);
				m_photo3->setColor(fake2);

				flag = 2;
			}
			else
			{
				m_photo3->setColor(colorTrue);
				m_photo1->setColor(fake1);
				m_photo2->setColor(fake2);

				flag = 3;
			}
		}

		_score++;
		_scoreLabel->setString(String::createWithFormat("%d", _score)->getCString());
	}
	else
	{
		audio->playEffect("false.wav");
		showOverLayer();
	}
}

void PlayScene::MidTouch()
{
	if (flag == 3)
	{
		audio->playEffect("right.mp3");
		_time = 3.0f;
		 
		int b = random(0, 4);
		auto fake1 = Color3B(ArrayColor[b].R, 0, 0);
		auto fake2 = Color3B(0, ArrayColor[b].G, 0);
		auto colorTrue = Color3B(ArrayColor[b].R, ArrayColor[b].G, ArrayColor[b].B);

		_whatColor->setString(ArrayColor[b].color);
		_whatColor->setColor(fake2);

		int ran = random(1, 3);

		if (ran == 1)
		{
			m_photo1->setColor(colorTrue);
			m_photo2->setColor(fake1);
			m_photo3->setColor(fake2);

			flag = 1;
		}
		else
		{
			if (ran == 2)
			{
				m_photo2->setColor(colorTrue);
				m_photo1->setColor(fake1);
				m_photo3->setColor(fake2);

				flag = 2;
			}
			else
			{
				m_photo3->setColor(colorTrue);
				m_photo1->setColor(fake1);
				m_photo2->setColor(fake2);

				flag = 3;
			}
		}

		_score++;
		_scoreLabel->setString(String::createWithFormat("%d", _score)->getCString());
	}
	else
	{
		audio->playEffect("false.wav");
		showOverLayer();
	}
}
void PlayScene::LeftTouch()
{

	if (flag == 2)
	{
		audio->playEffect("right.mp3");
		_time = 3.0f;

		int b = random(0, 4);
		
		auto fake1 = Color3B(ArrayColor[b].R, 0, 0);
		auto fake2 = Color3B(0, ArrayColor[b].G, 0);
		auto colorTrue = Color3B(ArrayColor[b].R, ArrayColor[b].G, ArrayColor[b].B);

		_whatColor->setString(ArrayColor[b].color);
		_whatColor->setColor(fake1);

		int ran = random(1, 3);

		if (ran == 1)
		{
			m_photo1->setColor(colorTrue);
			m_photo2->setColor(fake1);
			m_photo3->setColor(fake2);

			flag = 1;
		}
		else
		{
			if (ran == 2)
			{
				m_photo2->setColor(colorTrue);
				m_photo1->setColor(fake1);
				m_photo3->setColor(fake2);

				flag = 2;
			}
			else
			{
				m_photo3->setColor(colorTrue);
				m_photo1->setColor(fake1);
				m_photo2->setColor(fake2);

				flag = 3;
			}
		}

		_score++;
		_scoreLabel->setString(String::createWithFormat("%d", _score)->getCString());
	}
	else
	{
		audio->playEffect("false.wav");
		showOverLayer();
	}
}

void PlayScene::update(float dt)
{
	
	_time -= dt;
	_timeLabel->setString(String::createWithFormat("%.2f", _time)->getCString());

	if (_time < 0.0f)
	{
		_time = 0.0f;
		_timeLabel->setString(String::createWithFormat("%.2f", _time)->getCString());

		showOverLayer();
	}
}

void PlayScene::showOverLayer()
{
	this->pause();
	_colorPho->setEnabled(false);

	auto overlayer = OverScene::create();
	overlayer->setPosition(Point(0, 0));
	//overlayer->setScore(_score);

	this->addChild(overlayer);
}

void PlayScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
