#pragma once
#pragma once
#include <iostream>
using namespace std;
#include <assert.h>


template <typename T>
struct tListNode
{
public:
	T iData; //노드에 들어갈 데이터
	tListNode<T>* pPrev; // 노드의 이전주소 
	tListNode<T>* pNext; // 다음 노드의 주소 pNextNode라는 포인터변수  tNode 자료형가진

public:
	tListNode()
		:iData(0)
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}
	//생성자 오버로딩
	tListNode(const T& _iData, tListNode* _pPrev, tListNode* _pNext)
		:iData(_iData)
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}

};

template <typename T>
class CList
{
private:
	tListNode<T>* m_pHead; //리스트 본인은 리스트의 첫번째 노드의 주소를 알아야 한다.
	tListNode<T>* m_pTail;
	int m_iCount;  // 몇개 넣어줘야하는지에 대한 기록

public:
	CList();
	~CList();

public:
	void push_back(const T& iData);
	void push_front(const T& iData);
	int size() { return m_iCount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator insert(const iterator& _iter, const T& _data); //받는인자 : _iter 들어갈위치 , data 들어갈 값 
	iterator erase(iterator& _iter);

	class iterator
	{

	private:
		CList<T>*       m_pList;
		tListNode<T>*  m_pNode;
		bool   m_bValid;

	
	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{
		}
		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}

	public:
		//* 연산자 오버로딩
		T& operator* ()
		{
		
			return 	m_pNode->iData;
		}

		// ==연산자 오버로딩
		bool operator ==(const iterator& _otheriter)
		{
			if (_otheriter.m_pList == m_pList && _otheriter.m_pNode == m_pNode && true == m_bValid)
			{
				return true;
			}
			return false;
		 }
		
		//!= 연산자 오버로딩
		
		bool operator !=(const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}
		
		//++연산자 오버로딩

		iterator& operator++ ()
		{
			if (nullptr == m_pNode || false == m_bValid) //end이터레이터거나 유효성이 어긋날때 
			{
				assert(nullptr);
			}
			m_pNode = m_pNode->pNext;

			return *this;
		}
		//++후위 연산자 오버로딩
		iterator operator++(int)
		{
			iterator temp = *this;
			++(*this);
			return temp;
		}


		friend class CList;

	};
};



//리스트 클래스 디폴트 생성자
template <typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount()
{
}
template <typename T>
//리스트 클래스 디폴트 소멸자
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead; //첫번째 헤드 지역변수로 저장시키기 

	while (pDeleteNode) //pDeleteNode가 Null일때 == 연결형 리스트가 더이상 아무런 노드를 가리키지 않을때까지
	{

		tListNode<T>* pNext = pDeleteNode->pNext; //다음주소를 임시로 지역변수로 받아놓기 

		delete (pDeleteNode);


		pDeleteNode = pNext; //삭제시킬노드를 다시 다음 노드로 갱신시키기 
	}

}

template <typename T>
void CList<T>::push_back(const T& _iData)
{
	tListNode<T>* pNode = new tListNode<T>(_iData, nullptr, nullptr); //새 노드만큼 동적할당하되 생성자 오버로딩으로 초기화 (데이터/prev/next)

	//노드가 1개도 없었으면 리스트의 헤드와 꼬리를 갱신
	if (0 == m_iCount)
	{
		m_pHead = pNode;
		m_pTail = pNode;
	}

	//pNode가 첫번째 노드가 아닐경우 tail에 접근  
	else
	{
		m_pTail->pNext = pNode; // 꼬리노드의 다음을 동적할당한 새 노드로 갱신 
		pNode->pPrev = m_pTail; // 동적할당한 새노드의 이전파트를 기존에있던 꼬리로 갱신 

		m_pTail = pNode; //리스트의 꼬리를 동적할당한 새 노드로 갱신 

	}

	
	//카운트 갱신
	m_iCount++;
}

template <typename T>
void CList<T>::push_front(const T& _iData)
{
	tListNode<T>* pNode = new tListNode<T>(_iData, nullptr, m_pHead);
	//앞으로 들어가도 아무런 노드가 없다는 상황을 가정
	if (0 == m_iCount)
	{
		m_pHead = pNode;  //리스트의 헤드를 나로 갱신 
		m_pTail = pNode;   //리스트의 꼬리를 나로 갱신 
	}
	else
	{
		m_pHead->pPrev = pNode; // 기존에 앞에있었던 노드의 이전노드를 나로 갱신
		m_pHead = pNode; // 이제 진짜 헤드노드를 내 자신으로 설정 
		//꼬리는 건들필요 없음 
	}

	++m_iCount; //카운트 갱신 

}


template<typename T>
typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead); // m_phead 는 시작노드 
}

template<typename T>
typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr); // 노드가 null일때를 
}

template<typename T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{ //받는 인자로 들어갈 위치와 데이터 값이 필요함 
//삽입 로직에 대한 예외처리

// valid true일때만 가능 
// 노드가 1개밖에 없었을때? : 3번의 포인터 갱신
// 본 로직 : 4번의 포인터 갱신(나의 앞이 나를/ 내가 앞을 / 내 뒤가 나를 / 내가 뒤를)

	//end일 경우
	if (end() == _iter || _iter.m_bValid == false )
	{
		assert(nullptr);
	}
	//불가능한 예외처리 이후에 새 노드객체 생성 (이때 데이터는 그대로 받되 노드의 앞 뒤는 일단 null)
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	if (_iter.m_pNode == m_pHead) // 지금 가리키고 있는 노드가 헤드노드일경우
	{
		//내가 기존노드의 앞이되게
		
		_iter.m_pNode->pPrev = pNode;
		// 내가 리스트의 헤드노드가 되게
		m_pHead = pNode;
		// 나의 넥스트가 기존노드가 되게
		pNode->pNext = _iter.m_pNode;

	}
	else //중간에 진짜 삽입이 될경우 
	{
		//내가 내 이전노드의 넥스트가 되게
		_iter.m_pNode->pPrev->pNext = pNode;
		//나의 이전이 내 이전노드가 되게
		pNode->pPrev = _iter.m_pNode->pPrev;
		//내 뒤의 노드가 나를 가르키게
		_iter.m_pNode->pPrev = pNode;
		// 나의 넥스트를 내 뒤의 노드로  
		pNode->pNext = _iter.m_pNode;
	}





	++m_iCount;




	return iterator(this, pNode);
}

template<typename T>
typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	// 1. end일 경우 예외 처리 (노드가 아무것도 없을 때)
	if (_iter == end())
	{
		assert(false); // 삭제할 노드가 없으므로 예외 발생
	}

		// 2. 지울 노드가 헤드 노드인 경우
	else if (_iter.m_pNode == m_pHead)
	{
		m_pHead = m_pHead->pNext; // 헤드를 다음 노드로 변경
		m_pHead->pPrev = nullptr; // 새 헤드의 이전 포인터를 nullptr로 설정

	}

	// 현재 노드가 꼬리인 경우 처리
	else if (_iter.m_pNode == m_pTail)
	{
		m_pTail = m_pTail->pPrev; // 꼬리를 이전 노드로 변경
		m_pTail->pNext = nullptr; // 새 꼬리의 다음 포인터를 nullptr로 설정

	}

	// 3. 중간 노드일 경우 
	else
	{
		//지울 노드의 앞의 노드의 next를 지울노드의 Next로 갱신 
		_iter.m_pNode->pPrev->pNext = _iter.m_pNode->pNext;
		//지울노드의 Next노드의 Prev를 지울노드의 Prev로 갱신 
		_iter.m_pNode->pNext->pPrev = _iter.m_pNode->pPrev;

	}


	// 삭제할 노드의 메모리 해제
	delete _iter.m_pNode;
	--m_iCount;

	// 삭제한 노드의 다음 노드를 가리키는 iterator 반환
	return iterator(this, _iter.m_pNode);
	}

