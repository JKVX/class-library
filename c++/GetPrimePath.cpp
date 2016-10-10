//<summary>
//文件名:GetPrimePath.js
//作者：JKVX
//创建日期：2016-10-09
//描述:输入有向图，输出主路径。输入文件名：get_prime_path.txt
//修改日期：2016-10-09
//Email:357800013@qq.com
//</summary>
#include <iostream>
#include <fstream>
#include <queue>
#include<vector>
using namespace std;

//利用邻接表表示法来表示有向图
//边表 
struct ArcNode
{
	int adjvex;//邻接点域 
	ArcNode *nextarc;//指针域 
};
/*顶点表*/
struct VNode
{
	int data;
	ArcNode *first_arc;//边表头指针 
};

/*value*/
typedef char VertexType;
const int max_vertex_num = 20;
VNode adj_list[max_vertex_num];
char vertex[max_vertex_num];
int vertex_num, edge_num;
vector<string> simple_path;
vector<string> prime_path;

/*function*/
int LocateVex(const char&);
void CreateGraph();
void BFS(const VertexType&, const VertexType&);
void GetSimplePath();
void DestroyGraph();
void GetPrimePath();
void PrintResult();
int main()
{
	CreateGraph();//生成图
	GetSimplePath();//找出图中简单路径
	GetPrimePath();//找出简单路径中主路径
	DestroyGraph();//释放图
	PrintResult();//打印结果
	return 0;
}

/**
*找出节点在节点表中的位置
*@param vertex
*return 节点位置i
*/
int LocateVex(const char& ver)
{
	for (int i = 1; i <= vertex_num; i++)
	{
		if (vertex[i] == ver)
		{
			return i;
		}
	}
	return 0;
}

/**
*生成图
*/
void CreateGraph()
{
	ifstream fin("get_prime_path.txt");
	fin >> vertex_num >> edge_num;//输入节点数、边数 
	VertexType start_vertex, end_vertex;
	ArcNode *p;

	/*输入节点信息，并初始化节点*/
	for (int i = 1; i <= vertex_num; i++)
	{
		fin >> vertex[i];
		adj_list[i].data = 0;
		adj_list[i].first_arc = 0;
	}

	/*输入边信息，并更新节点信息*/
	for (int i = 1; i <= edge_num; i++)
	{
		fin >> start_vertex >> end_vertex;
		p = new ArcNode;
		p->adjvex = LocateVex(end_vertex);
		p->nextarc = adj_list[LocateVex(start_vertex)].first_arc;
		adj_list[LocateVex(start_vertex)].first_arc = p;
		adj_list[LocateVex(end_vertex)].data++;
	}
}

/**
*找出两点之间的简单路径
*@param VertexType& start;VertexType& end
*/
void BFS(const VertexType& start, const VertexType& end)
{
	queue<int> q;
	ArcNode *p;
	int start_pos, end_pos;
	start_pos = LocateVex(start);
	end_pos = LocateVex(end);
	bool *visited = new bool[vertex_num + 1];
	int *parent = new int[vertex_num + 1];

	for (int i = 1; i <= vertex_num; i++)
	{
		visited[i] = false;
		parent[i] = 0;
	}
	q.push(start_pos);
	visited[start_pos] = true;
	while (!q.empty())
	{
		int j = q.front();
		q.pop();
		p = adj_list[j].first_arc;
		while (p != 0)
		{
			if (p->adjvex == end_pos)
			{
				parent[p->adjvex] = j;
				//cout << "A path has been found:";
				int i = end_pos;
				string path = "";
				do
				{
					path = vertex[i] + path;
					i = parent[i];
				} while (i != start_pos);
				path = vertex[start_pos] + path;
				simple_path.push_back(path);
				//cout << path<<endl;
			}
			else if (visited[p->adjvex] == false)
			{
				visited[p->adjvex] = true;
				parent[p->adjvex] = j;
				q.push(p->adjvex);
			}
			p = p->nextarc;
		}
	}
	delete[] visited;
	delete[] parent;
}

/**
*邻接表图种找出所有简单路径
*return simple_path
*/
void GetSimplePath()
{
	for (int i = 0; i<vertex_num; i++) {
		for (int j = 0; j<vertex_num; j++) {
			if (i != j) {
				BFS(vertex[i], vertex[j]);
			}
		}
	}
}

void DestroyGraph()
{
	ArcNode *p, *q;
	int i;
	for (i = 1; i <= vertex_num; i++)
	{
		p = adj_list[i].first_arc;
		while (p != 0)
		{
			q = p;
			p = p->nextarc;
			delete q;
		}
	}
}

/**
*简单路径中找出所有主路径
*@param vector<string> simple_path
*return vector<string> prime_path
*/
void GetPrimePath() {
	for (vector<string>::iterator i = simple_path.begin(); i != simple_path.end(); i++) {
		bool if_prime_path = true;
		for (vector<string>::iterator j = simple_path.begin(); j != simple_path.end(); j++) {
			if ((*i) != (*j)) {
				if ((*j).find(*i) != -1) {
					if_prime_path = false;
					break;
				}

			}
		}
		if (if_prime_path == true) {
			prime_path.push_back(*i);
		}
	}
}

void PrintResult() {
	vector<string>::iterator iter;
	ofstream out("get_prime_path_result.txt");
	int count = 0;
	out << "Prime Path:"<<endl;
	for (iter = prime_path.begin(); iter != prime_path.end(); iter++) {
		out << *iter << endl;
		count++;
	}
	out << count <<" Prime Path"<< endl;
}
