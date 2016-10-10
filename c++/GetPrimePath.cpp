//<summary>
//�ļ���:GetPrimePath.js
//���ߣ�JKVX
//�������ڣ�2016-10-09
//����:��������ͼ�������·���������ļ�����get_prime_path.txt
//�޸����ڣ�2016-10-09
//Email:357800013@qq.com
//</summary>
#include <iostream>
#include <fstream>
#include <queue>
#include<vector>
using namespace std;

//�����ڽӱ��ʾ������ʾ����ͼ
//�߱� 
struct ArcNode
{
	int adjvex;//�ڽӵ��� 
	ArcNode *nextarc;//ָ���� 
};
/*�����*/
struct VNode
{
	int data;
	ArcNode *first_arc;//�߱�ͷָ�� 
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
	CreateGraph();//����ͼ
	GetSimplePath();//�ҳ�ͼ�м�·��
	GetPrimePath();//�ҳ���·������·��
	DestroyGraph();//�ͷ�ͼ
	PrintResult();//��ӡ���
	return 0;
}

/**
*�ҳ��ڵ��ڽڵ���е�λ��
*@param vertex
*return �ڵ�λ��i
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
*����ͼ
*/
void CreateGraph()
{
	ifstream fin("get_prime_path.txt");
	fin >> vertex_num >> edge_num;//����ڵ��������� 
	VertexType start_vertex, end_vertex;
	ArcNode *p;

	/*����ڵ���Ϣ������ʼ���ڵ�*/
	for (int i = 1; i <= vertex_num; i++)
	{
		fin >> vertex[i];
		adj_list[i].data = 0;
		adj_list[i].first_arc = 0;
	}

	/*�������Ϣ�������½ڵ���Ϣ*/
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
*�ҳ�����֮��ļ�·��
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
*�ڽӱ�ͼ���ҳ����м�·��
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
*��·�����ҳ�������·��
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
