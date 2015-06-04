#include "Start_Layer.h"
#include "View/Play_Scene.h"
#include "Utility/Config.h"
#include "ui/CocosGUI.h"
using namespace ui;

Start_Layer::Start_Layer()
{
}

Start_Layer::~Start_Layer()
{
}

bool Start_Layer::init()
{
	if (!Layer::init()) return false;

	Button * play_Button = Button::create("Button/play.png", "Button/play.png", "Button/play.png");
	play_Button->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	play_Button->setPosition(Config::centerPoint);
	play_Button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, Play_Scene::create_Play_Scene(), Color3B::WHITE));
			break;
		default:
			break;
		}
	});
	this->addChild(play_Button, 1);

	return true;
}

Start_Layer * Start_Layer::create_Start_Layer()
{
	Start_Layer * layer = new Start_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}