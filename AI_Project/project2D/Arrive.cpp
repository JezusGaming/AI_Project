#include "Arrive.h"
#include "Input.h"
#include "Agent.h"
using namespace aie;

//----------------------------------------------------------------------------
// default constructor which sets a wieght for the behaviour, inherited from 
// Ibehaviour
//----------------------------------------------------------------------------
Arrive::Arrive(float fWieghting) : IBehaviour(fWieghting)
{
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Arrive::~Arrive()
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
//		has to return a vector2 so it is returning a default vector
//----------------------------------------------------------------------------
Vector2 Arrive::Update(Agent * agent, float deltaTime)
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
	// calculates the distance of mouse pos to the target
	Vector2 Target = v2MousePos - agent->GetPos();
	float dist = Target.CalculateDist(v2MousePos, agent->GetPos());
	// if distance is greater then 0 it slows done to the mouse
	if (dist > 0)
	{
		const double DecelerationTweaker = 0.3;

		float fSpeed = dist / ((double)2.0f * DecelerationTweaker);

		if (fSpeed > 200.0f)
		{
			fSpeed = 200.0f;
		}

		return Target * (fSpeed / dist) * deltaTime;
	}

	return Vector2();

}
