// Generic_AdjList
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

template<typename T>
class Graph
{
	map<T, list<T> > adjList;
public:

	void addEdge(T u,T v,bool bidir = true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void Print(){
		for(auto n:adjList){
			cout<<n.first<<"->";
			for(auto x:n.second){
				cout<<x<<",";
			}
			cout<<endl;
		}
	}
	

	void BFS(T src){
		queue<T>  q;
		unordered_map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto n:adjList[node]){
				if(!visited[n]){
					q.push(n);
					visited[n] = true;
				}
			}
		}
		cout<<endl;
 	}
};

int main()
{
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.BFS(0);
	g.Print();


	return 0;
}