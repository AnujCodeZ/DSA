// AdjList_Integer
#include <iostream>
#include <list>
using namespace std;

class Graph
{
	list<int>* adjList;
	int V;
public:
	Graph(int v){
		adjList = new list<int>[v];
		V = v;
	}

	void addEdge(int u,int v,bool bidir = true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void Print(){
		for (int i = 0; i < V; ++i)
		{
			cout<<i<<"->";
			for(auto x:adjList[i]){
				cout<<x<<",";
			}
			cout<<endl;
		}
	}
	
};

int main()
{
	Graph g(5);
	g.addEdge(5,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.Print();

	return 0;
}