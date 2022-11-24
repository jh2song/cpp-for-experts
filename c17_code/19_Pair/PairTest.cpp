#include <utility>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	// �μ��� �� ���� �����ڿ� ����Ʈ ������
	pair<string, int> myPair("hello", 5);
	pair<string, int> myOtherPair;

	// first�� second�� ���� ������ �� �ִ�.
	myOtherPair.first = "hello";
	myOtherPair.second = 6;

	// ���� ������
	pair<string, int> myThirdPair(myOtherPair);

	// operator<
	if (myPair < myOtherPair) {
		cout << "myPair is less than myOtherPair" << endl;
	} else {
		cout << "myPair is greater than or equal to myOtherPair" << endl;
	}

	// operator==
	if (myOtherPair == myThirdPair) {
		cout << "myOtherPair is equal to myThirdPair" << endl;
	} else {
		cout << "myOtherPair is not equal to myThirdPair" << endl;
	}

	pair<int, double> aPair = make_pair(5, 10.10);
	auto aSecondPair = make_pair(5, 10.10);
	auto aThirdPair = pair(5, 10.10);
	
	// C++17���� �߰��� ������ ���ε��� �̿��ϸ�
	// pair�� ���� ���Ҹ� ���� �ٸ� ������ �и��� �� �ִ�.
	auto[theString, theInt] = myPair;
	cout << "theString: " << theString << endl;
	cout << "theInt: " << theInt << endl;

	return 0;
}