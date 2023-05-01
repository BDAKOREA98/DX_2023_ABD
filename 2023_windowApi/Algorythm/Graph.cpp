#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

vector <vector<bool>> adjacent;

// �������
// �̸� �Ҵ��� ���⿡ �޸𸮸� ���� ��� ������ Ž���� ������.
void CreateGraph() {
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][4] = true;

	adjacent[1][1] = true;
	adjacent[1][0] = true;
	adjacent[1][6] = true;

	adjacent[2][2] = true;
	adjacent[2][0] = true;
	adjacent[2][5] = true;
	adjacent[2][3] = true;

	adjacent[3][3] = true;
	adjacent[3][0] = true;
	
	adjacent[4][0] = true;
	adjacent[4][4] = true;
	
	adjacent[5][5] = true;
	adjacent[5][2] = true;

	adjacent[6][6] = true;
	adjacent[6][1] = true;
}


vector<vector<int>> _adjacent_list;


void CreateGraph_ByList()
{

	 // ���� ����Ʈ
	_adjacent_list.resize(7);


	_adjacent_list[0].push_back(0);
	_adjacent_list[0].push_back(1);
	_adjacent_list[0].push_back(2);
	_adjacent_list[0].push_back(4);

	_adjacent_list[1].push_back(1);
	_adjacent_list[1].push_back(0);
	_adjacent_list[1].push_back(6);

	_adjacent_list[2].push_back(2);
	_adjacent_list[2].push_back(0);
	_adjacent_list[2].push_back(5);
	_adjacent_list[2].push_back(3);

	_adjacent_list[3].push_back(3);
	_adjacent_list[3].push_back(2);

	_adjacent_list[4].push_back(0);
	_adjacent_list[4].push_back(4);

	_adjacent_list[5].push_back(2);
	_adjacent_list[5].push_back(5);

	_adjacent_list[6].push_back(1);
	_adjacent_list[6].push_back(6);



}

// ��������Ʈ
// ���� : ����Ȱ� �ʹ� �������� n ��ŭ Ž���� �ؾ��Ѵ�. 
// 


int main()
{
	CreateGraph_ByList();

	// 0�� 1�� �������ִ°�?

	auto iter = std::find(_adjacent_list[0].begin(), _adjacent_list[0].end(), 1);
	if (iter !=_adjacent_list[0].end())
	{
		cout << *iter << "�� 0�� �������ֽ��ϴ�." << endl;
	}


	CreateGraph(); // ���� ���

	// 5�� 2�� ������ �ִ°�?

	if (adjacent[5][2])
	{
		cout << "5�� 2�� �������ֽ��ϴ�." << endl;
	}


	return 0;

}