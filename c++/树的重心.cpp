#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5;
vector<int> g[MAX];
int n;
int sz[MAX];
vector<int> ans;
int cur=0x3f3f3f3f;
void init(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
void get_centroid(int root,int father){
	int temp=0;
	sz[root]=1;
	for(int v:g[root]){
		if(v==father) continue;
		get_centroid(v,root);
		sz[root]+=sz[v];
		temp=max(temp,sz[v]);
	}
	temp=max(temp,n-sz[root]);
	if(temp<cur){
		cur=temp;
		ans.clear();
		ans.push_back(root);
	}
	else if(temp==cur) ans.push_back(root); 
}
void output(){
	for(int x:ans){
		cout<<x<<" ";
	}
}
int main(){
	init();
	get_centroid(1,0);
	output();
	return 0;
}
