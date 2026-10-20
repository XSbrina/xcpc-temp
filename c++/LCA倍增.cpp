#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+5;
int n,m,s;
struct edge{
	int to,next;
}e[2*MAX];
int cnt;
int head[MAX],father[MAX][32],dep[MAX];
void add(int u,int v){
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int root,int fat){
	father[root][0]=fat;
	dep[root]=dep[fat]+1;
	for(int i=1;i<=31;i++){
		father[root][i]=father[father[root][i-1]][i-1];
	}
	for(int i=head[root];i;i=e[i].next){
		if(e[i].to==fat) continue;
		dfs(e[i].to,root);
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int temp=dep[y]-dep[x];
	for(int i=0;temp;i++,temp>>=1){
		if(temp&1) y=father[y][i];
	}
	if(x==y) return y;
	for(int i=31;i>=0&&y!=x;i--){
		if(father[x][i]!=father[y][i]){
			x=father[x][i];
			y=father[y][i];
		}
	}
	return father[y][0];
}
void init(){
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(s,0);
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	return 0;
}
