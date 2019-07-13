// SnakeAndLadder
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
			T temp = des;
	 		while(temp!=src){
	 			cout<<temp<<"<--";
	 			temp = parent[temp];
	 		}
	 		cout<<src<<endl;
	 		return dist[des];
	 	}
};

int main(){
	Graph<int > g;
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17]=-13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for(int u=0;u<=36;u++){
		for(int dice = 1; dice<=6;dice++){
			int v = u+dice+board[u+dice];
			g.addEdge(u,v,false);
		}
	}
	g.Print();
	cout<<g.SSSP(0,36)<<endl;
}