#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
int n,ans,dis[MAX];
vector<int> f[MAX]; 
void dfs(int root,int fa){
	for(int x:f[root]){
		if(x==fa) continue;
		dis[x]=dis[root]+1;
		if(dis[x]>dis[ans]) ans=x;
		dfs(x,root);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		f[v].push_back(u);
		f[u].push_back(v);
	}
	dfs(1,0);
	dis[ans]=0;
	dfs(ans,0);
	cout<<dis[ans];
	return 0;
}
