// Generic_AdjList
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <climits>

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

 	int SSSP(T src, T des){
 		map<T,int> dist;
 		map<T, T> parent;
 		for(auto node:adjList){
 			dist[node.first] = INT_MAX;
 		}
 		queue<T> q;
 		dist[src] = 0;
 		q.push(src);
 		while(!q.empty()){
 			T node = q.front();
 			q.pop();
 			int parent_dist = dist[node];
 			for(auto children:adjList[node]){
 				if(dist[children] == INT_MAX){
 					dist[children] = parent_dist + 1;
 					parent[children] = node;
 					q.push(children);
 				}
 			}
 		}
 		// for(auto x:dist){
 		// 	cout<<"Distance from "<<x.first<<" to "<<src<<" is "<<x.second<<endl;
 		// }
 		T temp = des;
 		while(temp!=src){
 			cout<<temp<<"<--";
 			temp = parent[temp];
 		}
 		cout<<src<<endl;
 		return dist[des];
 	}

 	void DFSHelper(T src, map<T,bool> &visited){
 		cout<<src<<" ";
 		visited[src] = true;
 		for(auto children:adjList[src]){
 			if(!visited[src]){
 				DFSHelper(children,visited);
 			}
 		}

 	}
 	void DFS(T src){
 		map<int,bool> visited;
 		int component = 1;
 		DFSHelper(src,visited);
 		for(auto node:adjList){
 			if(!visited[node.first]){
 				component++;
 				DFSHelper(node.first,visited);
 			}
 		}
 		cout<<endl;
 		cout<<"No. of components : "<<component<<endl;
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
	g.addEdge(10,15);
	g.addEdge(20,10);

	g.BFS(0);
	cout<<g.SSSP(0,5)<<endl;
	g.DFS(0);
	g.Print();

	return 0;
}