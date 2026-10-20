#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+5;
int n;
int fa[MAX];
int find(int x){
	if(fa[x]>0){
		return fa[x]=find(fa[x]);
	}
	return x;
} 
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	if(fa[x]<fa[y]){
		fa[x]+=fa[y];
		fa[y]=x;
	}
	else{
		fa[y]+=fa[x];
		fa[x]=y;
	}
	return ;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=-1;
}
