#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void AddEdge(vector<int> arr[],int u,int v){

	arr[u].push_back(v);
	arr[v].push_back(u);
}

void printGraph(vector<int>arr[],int V){

	for(int v=0;v<V;v++){
		cout<<"\nadjacency list of vertex "<<v<<"\n head";
		for(auto x : arr[v])
			cout<<"=>"<<x;

		cout<<"\n";		
		
	}
}

int main(){
	int V=5;
	vector<int>arr[V];
	
	AddEdge(arr,0,1);
	AddEdge(arr,0,4);
	AddEdge(arr,1,2);
	AddEdge(arr,1,3);
	AddEdge(arr,1,4);
	AddEdge(arr,2,3);
	AddEdge(arr,3,4);

	printGraph(arr,V);
	return 0;
}