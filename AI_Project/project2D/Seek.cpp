#include "Seek.h"
#include "Input.h"
#include "Agent.h"
using namespace aie;

//----------------------------------------------------------------------------
// default constructor which sets a wieght for the behaviour, inherited from 
// Ibehaviour
//----------------------------------------------------------------------------
Seek::Seek(float fWieghting) : IBehaviour(fWieghting)
{
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Seek::~Seek()
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
Vector2 Seek::Update(Agent * agent, float deltaTime)
{
	// creates an int which holds mouse x and y
	int nMouseX;
	int nMouseY;
	// sets the mouse pos
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2MousePos(nMouseX, nMouseY);
	// sets the dir
	Vector2 v2Dir = v2MousePos - agent->GetPos();
	v2Dir.Normalise();
	// returns seek movement
	return v2Dir * 100.0f * deltaTime;
}
