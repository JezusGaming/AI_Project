#pragma once

template <typename T>
class ListNode
{
public:
	ListNode() {};
	~ListNode() {};
	
	T m_pData;
	ListNode* next;
	ListNode* prev;
};

