#include <mutex>

using namespace std;

mutex mut1;
mutex mut2;

void process()
{
	//scoped_lock locks(mut1, mut2);
	scoped_lock<mutex, mutex> locks(mut1, mut2);

	// ���� ���� ���
} // ������ ����� ���� �ڵ����� �����ȴ�.

int main()
{
	process();
	
	return 0;
}