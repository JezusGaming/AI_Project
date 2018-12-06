#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"


//struct GridNode;
//class AStar;
class Grid;
class DecisionTree;
class Player;
class AIBehaviourTree;
class Enemy;
class ControlledPlayer;
class PathPlayer;
class DecisionPlayer;
class WanderPlayer;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	//Grid* m_pGrid;
	DecisionTree* m_pDecisionTree;
	Player* m_pPlayer;
	AIBehaviourTree* m_pBehaviourTree;
	Enemy* m_pEnemy;
	ControlledPlayer* m_pControlledPlayer;
	PathPlayer* m_pPathPlayer;
	DecisionPlayer* m_pDecPlayer;
	WanderPlayer* m_pWanderPlayer;

	float m_cameraX, m_cameraY;
	float m_timer;

	
	/*GridNode** m_ppGrid;*/
	/*AStar* m_pAStar;*/
};