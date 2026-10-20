#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+5;
vector<int> g[MAX],rg[MAX];
vector<int> vis(MAX,0);
vector<vector<int> > ans;
stack<int> op;
int n,m;
void dfs(int u){
	for(int x:g[u]){
		if(!vis[x]){
			vis[x]=1;
			dfs(x);
		}
	}
	op.push(u);
}
void dfs_temp(int x,vector<int>&temp){
	for(int y:rg[x]){
		if(!vis[y]){
			vis[y]=1;	
			dfs_temp(y,temp);
		}
	}
	temp.push_back(x);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i);
		}
	}
	vis.assign(n+1,0);
	while(!op.empty()){
		vector<int> temp;
		int x=op.top();
		cout<<x<<" ";
		op.pop();
		if(vis[x]) continue;
		vis[x]=1;
		dfs_temp(x,temp);
		ans.push_back(temp);
	}
	cout<<endl;
	for(vector<int> x:ans){
		for(auto y:x) cout<<y<<" ";
		cout<<endl;
	}
	return 0;
}
