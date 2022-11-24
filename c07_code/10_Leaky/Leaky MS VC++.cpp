#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif  // _DEBUG

class Simple 
{
public:
	Simple() { mIntPtr = new int(); }
	~Simple() { delete mIntPtr; }

	void setValue(int value) { *mIntPtr = value; }

private:
	int* mIntPtr;
};

void doSomething(Simple*& outSimplePtr)
{
	outSimplePtr = new Simple(); // ����! ���� ��ü�� �������� �ʾҴ�.
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Simple* simplePtr = new Simple(); // Simple ��ü �ϳ��� �Ҵ��Ѵ�.

	doSomething(simplePtr);

	delete simplePtr; // �� ��° ��ü�� �����Ѵ�.

	return 0;
}
