#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int f[5005][5005];
int n,m;
int parent[5005],dis[5005],vis[5005];
int ans;
void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=INF;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=min(w,f[u][v]);
		f[v][u]=min(w,f[v][u]);
	}
}
bool deal(){
	for(int i=1;i<=n;i++) parent[i]=1,dis[i]=INF,vis[i]=0;
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(f[1][i]!=INF) dis[i]=f[1][i];
	}
	for(int i=2;i<=n;i++){
		int Min=INF;
		int v=-1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<Min){
				Min=dis[j];
				v=j;
			}
		}
		ans+=Min;
		if(v==-1){
			cout<<"orz";
			return false;
		}
		vis[v]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&f[v][j]<dis[j]){
				dis[j]=f[v][j];
				parent[j]=v;
			}
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	if(deal()){
		cout<<ans;
	}
	return 0;
}
