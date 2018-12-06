#pragma once
#include "Renderer2D.h"
#include "Vector2.h"
#include "DynamicArray.h"
#include "AIStateMachine.h"

class Agent
{
public:
	//----------------------------------------------------------------------------
	// default constructor
	//----------------------------------------------------------------------------
	Agent();

	//----------------------------------------------------------------------------
	// default destructor
	//----------------------------------------------------------------------------
	virtual ~Agent();

	//----------------------------------------------------------------------------
	// it updates movement and functions used
	//
	// Param:
	//      deltaTime: calls a timer every frame per second that holds the time
	//		between now and last call
	//----------------------------------------------------------------------------
	virtual void Update(float deltaTime);

	//----------------------------------------------------------------------------
	// draws textures for this class and sets camera
	//
	// param:
	//		m_2dRenderer: pointer to all the render functions such as drawsprite
	//----------------------------------------------------------------------------
	virtual void Draw(aie::Renderer2D*	m_2dRenderer);

	//----------------------------------------------------------------------------
	// used to set the entities posiotion
	//
	// param:
	//		Pos: is a vector2 which is used to set the position of the entity
	//----------------------------------------------------------------------------
	virtual void SetPos(Vector2 Pos);

	//----------------------------------------------------------------------------
	// used to set the entities velocity
	//
	// param:
	//		Vel: is a vector2 which is used to set the vel of the entity
	//----------------------------------------------------------------------------
	virtual void SetVel(Vector2 Vel);

	//----------------------------------------------------------------------------
	// used to set the entities Acceleration
	//
	// param:
	//		Accel: is a vector2 which is used to set the Accel of the entity
	//----------------------------------------------------------------------------
	virtual void SetAccel(Vector2 Accel);

	//----------------------------------------------------------------------------
	// used to set the entities Force
	//
	// param:
	//		Force: is a vector2 which is used to set the Force of the entity
	//----------------------------------------------------------------------------
	virtual void SetForce(Vector2 Forece);

	//----------------------------------------------------------------------------
	// used to set which way the entities faceing
	//
	// param:
	//		faceing: is a vector2 which is used to set the dir of the entity
	//----------------------------------------------------------------------------
	virtual void SetFacing(Vector2 Facing);

	//----------------------------------------------------------------------------
	// used to set the entities start pos for pathfinding
	//----------------------------------------------------------------------------
	virtual int SetStart();

	//----------------------------------------------------------------------------
	// used to set the entities end pos for pathfinding
	//----------------------------------------------------------------------------
	virtual int SetEnd();

	//----------------------------------------------------------------------------
	// used to get the entities posiotion
	//
	// Returns:
	//			entities position
	//----------------------------------------------------------------------------
	Vector2 GetPos();

	//----------------------------------------------------------------------------
	// used to get the entities Velocity
	//
	// Returns:
	//			entities Vel
	//----------------------------------------------------------------------------
	Vector2 GetVel();

	//----------------------------------------------------------------------------
	// used to get the entities Acceleration
	//
	// Returns:
	//			entities Accel
	//----------------------------------------------------------------------------
	Vector2 GetAccel();

	//----------------------------------------------------------------------------
	// used to get the entities Force
	//
	// Returns:
	//			entities Force
	//----------------------------------------------------------------------------
	Vector2 GetForce();

	//----------------------------------------------------------------------------
	// used to get the way which the entities Faceing
	//
	// Returns:
	//			entities faceing direction
	//----------------------------------------------------------------------------
	Vector2 GetFacing();

protected:

	int m_nStart;
	int m_nEnd;

	Vector2 m_facing;
	Vector2 m_force;
	Vector2 m_accel;
	Vector2 m_vel;
	Vector2 m_pos;

};

