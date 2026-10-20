#include<bits/stdc++.h>
using namespace std;
//原图中两点间所有简单路径的最大边权最小值，等于最小生成树上两点之间边权最大值，等于重构树上两点 LCA 的点权
//原图中两点间所有简单路径的最小边权最大值，等于最大生成树上两点之间边权最小值，等于重构树上两点 LCA 的点权
const int MAXM=5e4+5;
const int MAXN=1e4+5;

struct edge{
	int to,w,next;
}e[MAXM<<1];

struct node{
	int u,v,w;
	bool operator<(const node&temp)const{
		return temp.w>w;
	}
};

int n,m;
int cnt;
int head[MAXN<<1];
map<pair<int,int>,int> f;
priority_queue<node> Node;
vector<int> father(MAXN<<1,-1);
int tot;
unordered_map<int,int> key;

void add(int u,int v){
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

int find(int x){
	if(father[x]>0) return father[x]=find(father[x]);
	return x;
}
//kruskal
void kruskal(){
	while(!Node.empty()){
		auto temp=Node.top();
		Node.pop();
		temp.u=find(temp.u);
		temp.v=find(temp.v);
		if(temp.u!=temp.v){
			add(temp.u,tot);
			add(temp.v,tot);
			add(tot,temp.u);
			add(tot,temp.v);
			father[temp.u]=tot;
			father[temp.v]=tot;
			key[tot]=temp.w;
			tot++;
		}
	}
}
//lca
int fa[MAXN<<1][32],dep[MAXN<<1],vis[MAXN<<1];
void dfs(int root,int fat){
	vis[root]=1;
	fa[root][0]=fat;
	dep[root]=dep[fat]+1;
	for(int i=1;i<=31;i++) fa[root][i]=fa[fa[root][i-1]][i-1];
	for(int i=head[root];i;i=e[i].next){
		if(e[i].to==fat) continue;
		dfs(e[i].to,root);
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int temp=dep[y]-dep[x];
	for(int i=0;temp;i++,temp>>=1){
		if(temp&1) y=fa[y][i];
	}
	if(x==y) return y;
	for(int i=31;i>=0&&y!=x;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[y][0];
}

void init(){
	cin>>n>>m;
	tot=n+1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[{u,v}]=max(f[{u,v}],w);
	}
	for(auto temp:f){
		Node.push({temp.first.first,temp.first.second,temp.second});
	}
	kruskal();
	for(int i=1;i<tot;i++){
		if(father[i]==-1) dfs(i,0);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(find(a)!=find(b)){
			cout<<-1<<'\n';
			continue;
		}
		else{
			cout<<key[lca(a,b)]<<'\n';
		}
	}
	return 0;
}
