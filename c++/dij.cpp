#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> jkl;
vector<int> fin;
vector<int> dis;
void init(){
	cin>>n;
	jkl.resize(n,vector<int>(n));
	fin.resize(n,0);
	fin[0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>jkl[i][j];
	}
	for(int i=0;i<n;i++) dis.push_back(jkl[0][i]);
}
void deal(){
	int t=n-1;
	while(t--){
		int Min=INT_MAX,k;
		for(int i=1;i<n;i++){
			if(!fin[i]&&dis[i]<Min) Min=dis[i],k=i;
		}
		fin[k]=1;
		for(int i=0;i<n;i++){
			if(!fin[i]){
				dis[i]=min(dis[i],jkl[i][k]+Min);
			}
		}
	}
}
void output(){
	for(int i=0;i<n;i++){
		cout<<dis[i]<<" ";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	deal();
	output();
	return 0;
	
}
