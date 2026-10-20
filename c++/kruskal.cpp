#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,w;
	bool operator<(const Node&a)const{
		return w>a.w;
	}
};
int n,m;
int ans;
int vex[5005];
priority_queue<Node> f;
bool find(int u,int v){
	while(vex[u]>=0) u=vex[u];
	while(vex[v]>=0) v=vex[v];
	if(u==v) return true;
	else return false;
}
void Union(int u,int v){
	while(vex[u]>=0) u=vex[u];
	while(vex[v]>=0) v=vex[v];
	if(u==v) return ;
	if(vex[u]<vex[v]) vex[u]+=vex[v],vex[v]=u;
	else vex[v]+=vex[u],vex[u]=v;
	return ;
}
void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) vex[i]=-1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f.push({u,v,w});
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int cnt=0;
	while(cnt!=n-1&&!f.empty()){
		Node temp=f.top();
		f.pop();
		int u=temp.u,v=temp.v;
		if(!find(u,v)){
			ans+=temp.w;
			Union(u,v);
			cnt++;
		}
	}
	if(cnt!=n-1) cout<<"orz";
	else cout<<ans;
	return 0;
}
