#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
vector<int> g[MAX];
int deg[MAX];
int n;
void init(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[v]++;
		deg[u]++;
	}
}
void get_center(){
	queue<int> leaf;
	for(int i=1;i<=n;i++){
		if(deg[i]==1) leaf.push(i);
	}
	int left=n;
	while(left>2){
		int len=leaf.size();
		left-=len;
		for(int i=1;i<=len;i++){
			int temp=leaf.front();
			leaf.pop();
			for(int v:g[temp]){
				if(--deg[v]==1) leaf.push(v);
			}
		}
	}
	while(!leaf.empty()){
		cout<<leaf.front()<<endl;
		leaf.pop();
	}
}
int main(){
	init();
	get_center();
	return 0;
}
