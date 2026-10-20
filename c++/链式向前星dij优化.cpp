#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,w,next;
};
struct node{
	int pos,w;
	bool operator<(const node&x)const{
		return w>x.w;
	}
};

int n,m,s;
int cnt;
vector<edge> e;
vector<int> dis;
vector<int> fin;
vector<int> head;
priority_queue<node> q;

void add(int u,int v,int w){
	cnt++;
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void init(){
	cin>>n>>m>>s;
	e.resize(m+1);
	dis.resize(n+1,INT_MAX);
	fin.resize(n+1);
	head.resize(n+1);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
}

void dij(){
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		auto temp=q.top();
		q.pop();
		int jkl=temp.pos;
		if(fin[jkl]) continue;
		fin[jkl]=1;
		for(int i=head[jkl];i;i=e[i].next){
			int iop=e[i].to;
			if(dis[iop]>dis[jkl]+e[i].w){
				dis[iop]=dis[jkl]+e[i].w;
				if(!fin[iop]){
					q.push({iop,dis[iop]});
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	dij();
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}
