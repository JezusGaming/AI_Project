#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Defines.h"
#include "GridNode.h"
#include "AStar.h"
#include "DynamicArray.h"
#include "AStarNode.h"
#include "Grid.h"
#include "DecisionTree.h"
#include "Player.h"
#include "AIBehaviourTree.h"
#include "Enemy.h"
#include "ControlledPlayer.h"
#include "PathPlayer.h"
#include "DecisionPlayer.h"
#include "WanderPlayer.h"

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();

	m_shipTexture = new Texture("./textures/ship.png");

	m_font = new Font("./font/consolas.ttf", 32);

	m_audio = new Audio("./audio/powerup.wav");

	Grid::Create();

	m_pDecisionTree = new DecisionTree();

	m_pPlayer = new Player();

	m_pBehaviourTree = new AIBehaviourTree();

	m_pEnemy = new Enemy();

	m_pControlledPlayer = new ControlledPlayer();

	m_pPathPlayer = new PathPlayer();

	m_pDecPlayer = new DecisionPlayer();

	m_pWanderPlayer = new WanderPlayer();

	m_cameraX = -400;
	m_cameraY = -150;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	//delete m_pAStar;
	//for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	//{
	//	delete m_ppGrid[i];
	//}
	//delete[] m_ppGrid;

	delete m_pWanderPlayer;
	delete m_pDecPlayer;
	delete m_pPathPlayer;
	delete m_pControlledPlayer;
	delete m_pEnemy;
	delete m_pBehaviourTree;
	delete m_pPlayer;
	delete m_pDecisionTree;
	Grid::Destroy();

	delete m_audio;
	delete m_font;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	m_pDecisionTree->Update(nullptr, deltaTime);

	m_pPlayer->Update(deltaTime);

	m_pBehaviourTree->Update(deltaTime);

	m_pEnemy->Update(deltaTime);

	m_pControlledPlayer->Update(deltaTime);

	m_pPathPlayer->Update(deltaTime);

	m_pDecPlayer->Update(deltaTime);

	m_pWanderPlayer->Update(deltaTime);

	//// example of audio
	//if (input->wasKeyPressed(INPUT_KEY_SPACE))
	//	m_audio->play();

	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	//m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 500, 400, 2, 1);

	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	
	//for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	//{
	//	float x = m_ppGrid[i]->m_v2Pos.x;
	//	float y = m_ppGrid[i]->m_v2Pos.y;

	//	if (m_ppGrid[i]->m_bBlocked)
	//		m_2dRenderer->setRenderColour(0x303030FF);
	//	else
	//		m_2dRenderer->setRenderColour(0x808080FF);

	//	m_2dRenderer->drawBox(x, y, NODE_SIZE - GRID_SPACING, NODE_SIZE - GRID_SPACING);
	//	
	//	//draw adjacency
	//	for (int a = 0; a < m_ppGrid[i]->m_AdjacentList.Size(); ++a)
	//	{
	//		GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_pEndNode);

	//		float otherX = otherNode->m_v2Pos.x;
	//		float otherY = otherNode->m_v2Pos.y;
	//		m_2dRenderer->setRenderColour(0xFF0000FF);
	//		m_2dRenderer->drawLine(x, y, otherX, otherY, EDGE_THICKNESS);
	//		m_2dRenderer->setRenderColour(0xFFFFFFFF);
	//	}
	//}

	////draw path
	//DynamicArray<AStarNode*> path;
	//m_pAStar->CalculatePath(m_ppGrid[22], m_ppGrid[67], &path);

	//for (int i = 0; i < path.Size(); ++i)
	//{
	//	GridNode* pNode = (GridNode*)path[i];

	//	m_2dRenderer->setRenderColour(0x00FF00FF);
	//	m_2dRenderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 2, NODE_SIZE / 2);
	//	m_2dRenderer->setRenderColour(0xFFFFFFFF);
	//}

	Grid::GetInstance()->Draw(m_2dRenderer);

	m_pPathPlayer->Draw(m_2dRenderer);

	m_pPlayer->Draw(m_2dRenderer);

	m_pControlledPlayer->Draw(m_2dRenderer);

	m_pEnemy->Draw(m_2dRenderer);

	m_pDecPlayer->Draw(m_2dRenderer);
	
	m_pWanderPlayer->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press R to reset green square, WASD to move green thing", 0, 720 - 64);
	m_2dRenderer->drawText(m_font, "Hold space to make blue square to flee", 0, 690 - 64);
	// done drawing sprites
	m_2dRenderer->end();
}