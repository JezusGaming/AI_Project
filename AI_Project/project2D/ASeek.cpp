#include "ASeek.h"
#include "Seek.h"
#include "Arrive.h"
#include "Agent.h"

ASeek::ASeek()
{
	m_behaviours.PushFront(new Seek(1.0f));
	m_behaviours.PushFront(new Arrive(1.5f));
}


ASeek::~ASeek()
{
	for (unsigned int i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

void ASeek::MakeDecision(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2TotalForce;

	for (int i = 0; i < m_behaviours.Size(); ++i)
	{
		Vector2 currentForce = m_behaviours[i]->Update(pAgent, fDeltaTime);
		currentForce = currentForce * m_behaviours[i]->m_fWeighting;

		v2TotalForce = v2TotalForce + currentForce;

		float fMagnitude = v2TotalForce.Magnitude();
		if (fMagnitude > 10.0f)
		{
			v2TotalForce.Normalise();
			v2TotalForce = v2TotalForce * 10.0f;
			break;
		}
	}

	pAgent->SetPos(pAgent->GetPos() + v2TotalForce);
}
