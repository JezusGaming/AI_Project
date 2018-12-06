#include "Agent.h"
#include "Patrol.h"
#include "Idle.h"

//----------------------------------------------------------------------------
// default constructor
//----------------------------------------------------------------------------
Agent::Agent()
{
}

//----------------------------------------------------------------------------
// default destructor
//----------------------------------------------------------------------------
Agent::~Agent()
{
}

//----------------------------------------------------------------------------
// it updates movement and functions used
//
// Param:
//      deltaTime: calls a timer every frame per second that holds the time
//		between now and last call
//----------------------------------------------------------------------------
void Agent::Update(float deltaTime)
{
		
}

//----------------------------------------------------------------------------
// draws textures for this class and sets camera
//
// param:
//		m_2dRenderer: pointer to all the render functions such as drawsprite
//----------------------------------------------------------------------------
void Agent::Draw(aie::Renderer2D * m_2dRenderer)
{
}

//----------------------------------------------------------------------------
// used to set the entities posiotion
//
// param:
//		Pos: is a vector2 which is used to set the position of the entity
//----------------------------------------------------------------------------
void Agent::SetPos(Vector2 Pos)
{
	m_pos = Pos;
}

//----------------------------------------------------------------------------
// used to set the entities velocity
//
// param:
//		Vel: is a vector2 which is used to set the vel of the entity
//----------------------------------------------------------------------------
void Agent::SetVel(Vector2 Vel)
{
	m_vel = Vel;
}

//----------------------------------------------------------------------------
// used to set the entities Acceleration
//
// param:
//		Accel: is a vector2 which is used to set the Accel of the entity
//----------------------------------------------------------------------------
void Agent::SetAccel(Vector2 Accel)
{
	m_accel = Accel;
}

//----------------------------------------------------------------------------
// used to set the entities Force
//
// param:
//		Force: is a vector2 which is used to set the Force of the entity
//----------------------------------------------------------------------------
void Agent::SetForce(Vector2 Force)
{
	m_force = Force;
}

//----------------------------------------------------------------------------
// used to set which way the entities faceing
//
// param:
//		faceing: is a vector2 which is used to set the dir of the entity
//----------------------------------------------------------------------------
void Agent::SetFacing(Vector2 Facing)
{
	m_facing = Facing;
}

//----------------------------------------------------------------------------
// used to set the entities start pos for pathfinding
//----------------------------------------------------------------------------
int Agent::SetStart()
{
	return m_nStart;
}

//----------------------------------------------------------------------------
// used to set the entities end pos for pathfinding
//----------------------------------------------------------------------------
int Agent::SetEnd()
{
	return m_nEnd;
}

//----------------------------------------------------------------------------
// used to get the entities posiotion
//
// Returns:
//			entities position
//----------------------------------------------------------------------------
Vector2 Agent::GetPos()
{
	return m_pos;
}

//----------------------------------------------------------------------------
// used to get the entities Velocity
//
// Returns:
//			entities Vel
//----------------------------------------------------------------------------
Vector2 Agent::GetVel()
{
	return m_vel;
}

//----------------------------------------------------------------------------
// used to get the entities Acceleration
//
// Returns:
//			entities Accel
//----------------------------------------------------------------------------
Vector2 Agent::GetAccel()
{
	return m_accel;
}

//----------------------------------------------------------------------------
// used to get the entities Force
//
// Returns:
//			entities Force
//----------------------------------------------------------------------------
Vector2 Agent::GetForce()
{
	return m_force;
}

//----------------------------------------------------------------------------
// used to get the way which the entities Faceing
//
// Returns:
//			entities faceing direction
//----------------------------------------------------------------------------
Vector2 Agent::GetFacing()
{
	return m_facing;
}
