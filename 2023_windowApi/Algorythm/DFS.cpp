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
vector<bool> visited;

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

void DFS(int here)
{
	visited[here] = true;
	cout << here << " 을 방문" << endl;

	for (int there = 0; there < adjacent.size(); there++)
	{
		if (here == there)
		{
			continue;
		}
		if (adjacent[here][there] == false)
		{
			continue;
		}
		
		if (visited[there] == true)
		{
			continue;
		}


		DFS(there);
	}

}



int main()
{




	CreateGraph(); // 인접 행렬

	visited = vector<bool>(adjacent.size(), false);

	DFS(0);



	return 0;

}