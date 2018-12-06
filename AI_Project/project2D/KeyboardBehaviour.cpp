#include "KeyboardBehaviour.h"
#include "input.h"
#include "Vector2.h"
#include "Matrix3.h"
using namespace aie;

//----------------------------------------------------------------------------
	// default constructor which sets a wieght for the behaviour, inherited from 
	// Ibehaviour
	//----------------------------------------------------------------------------
KeyboardBehaviour::KeyboardBehaviour(float fWieghting) : IBehaviour(fWieghting)
{
	// sets variables
	speed = 500.0f;
	mass = 1.5f;
	drag = 0.5f;
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
KeyboardBehaviour::~KeyboardBehaviour()
{
}

//----------------------------------------------------------------------------
// it updates movement and functions used
//
// Param:
//      deltaTime: calls a timer every frame per second that holds the time
//		between now and last call
//		Agent: is a pointer to the agent which will use this function
//
// Return:
//		Returns a Vector2
//----------------------------------------------------------------------------
Vector2 KeyboardBehaviour::Update(Agent* agent, float deltaTime)
{
	Input* input = Input::getInstance();
	// sets dir to 0
	dir = Vector2(0, 0);
	// sets a respawn point
	Vector2 StartPos(625, 375);

	// lets the player move forwards, backwards, left, and right
	if (input->isKeyDown(INPUT_KEY_W))
		dir = Vector2(0, 1);
	if (input->isKeyDown(INPUT_KEY_S))
		dir = Vector2(0, -1);
	if (input->isKeyDown(INPUT_KEY_D))
		dir = Vector2(1, 0);
	if (input->isKeyDown(INPUT_KEY_A))
		dir = Vector2(-1, 0);
	if (input->isKeyDown(INPUT_KEY_R))
		agent->SetPos(StartPos);
	// adds velocity and drag to the player so it does not just take off, also
	// so it can slow down and stop
	Vector2 forceSum = dir * speed;
	Vector2 acceleration = forceSum / mass;
	Vector2 dampening = -(vel * drag);
	vel += (acceleration + dampening) * deltaTime;
	agent->SetPos(agent->GetPos() + vel * deltaTime);

	return Vector2(0,0);
}
