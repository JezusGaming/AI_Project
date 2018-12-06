#include "AFlee.h"
#include "Flee.h"
#include "Agent.h"

AFlee::AFlee()
{
	m_behaviours.PushFront(new Flee(1.0f));
}

AFlee::~AFlee()
{
	for (unsigned int i = 0; i < m_behaviours.Size(); ++i)
	{
		delete m_behaviours[i];
	}
}

void AFlee::MakeDecision(Agent * pAgent, float fDeltaTime)
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
