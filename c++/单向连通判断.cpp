#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+5;
vector<int> g[MAX],rg[MAX];
vector<int> vis(MAX,0);
vector<vector<int> > ans;
stack<int> op;
vector<int> color(MAX);
int scc=0;
int n,m;
//Kosaraju两次dfs
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
	color[x]=scc;
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
	//Kosaraju 
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
		op.pop();
		if(vis[x]) continue;
		scc++;
		vis[x]=1;
		dfs_temp(x,temp);
		ans.push_back(temp);
	}
	//缩点构成有向无环图
	set<int> f[scc+1];
	vector<int> deg(scc+1,0);
	for(int i=1;i<=n;i++){
		for(int x:g[i]){
			int ci=color[i];
			int cx=color[x];
			if(ci!=cx&&!f[ci].count(cx)){
				f[ci].insert(cx);
				deg[cx]++;
			}
		}
	}
	//拓扑排序
	vector<int> id;
	queue<int> deal;
	for(int i=1;i<=scc;i++){
		if(deg[i]==0) deal.push(i);
	}
	while(!deal.empty()){
		if (deal.size()>1) {
			cout<<"No";
			return 0;
		}
		int x=deal.front();
		deal.pop();
		id.push_back(x);
		for(int v:f[x]){
			deg[v]--;
			if(deg[v]==0) deal.push(v);
		}
	}
	//判断拓扑序列相邻两点是否连通
	int sz=id.size();
	for(int i=1;i<sz;i++){
		if(!f[id[i-1]].count(id[i])){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
