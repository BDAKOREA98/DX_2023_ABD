#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include <deque>


// stack frame 함수들이 쌓이는 것 => 팬케이크
// First Input Last Out

using namespace std;


// 자료구조 자료가 어떠한 구조로 이루어져 있는가??
// ex) 컨테이너 : 벡터, 이진탐색트리 : 맵 , 해쉬테이블 : 언오디드 맵
// 알고리즘과 자료구조가 같이 언급되는 이유
// 자료구조는 정렬이 가능하다.
// 해당 자료구조를 정렬하기에 최적의 방법 => 알고리즘
template <typename T, typename  Container = vector<T>>
class Stack
{
public:
	void push(const T& value)
	{
		container.push_back(value);
	}
	void pop()
	{
		container.pop_back();

	}

	const T& top()
	{

		return container.back();
	}
	bool empty()
	{
		return container.empty();
	}



private:

	Container container;



};


int main()
{



	Stack<int, deque<int>> s;
	s.push(1);
	s.push(2);
	s.push(6);
	s.push(3);
	s.push(10);

	// s.emplace() 오른값 참조로 받기에 생성자  호출을 하지 않음 
	while (true)
	{
		if (s.empty())
		{
			break;
		}
		cout << s.top() << endl;
		s.pop();

	}

	return 0;
}