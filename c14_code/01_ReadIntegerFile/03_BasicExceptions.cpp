#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <exception>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
	ifstream inputStream(fileName.data());
	if (inputStream.fail()) {
		// 파일 열기에 실패: 익셉션을 던진다.
		throw exception();
	}

	// 파일에 담긴 정숫값을 하나씩 읽어서 벡터에 추가한다.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}
	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try {
		myInts = readIntegerFile(fileName);
	} catch (const exception& /* e */) {
		cerr << "Unable to open file " << fileName << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
