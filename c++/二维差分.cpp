#include<iostream>
#include<vector>
using namespace std;
struct jkl{
	int x1,y1,x2,y2;
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> map(n+2,vector<int>(n+2,0));
	for(int i=1;i<=m;i++){
		jkl iop;
		cin>>iop.x1>>iop.y1>>iop.x2>>iop.y2;
		map[iop.x1][iop.y1]++;
		map[iop.x1][iop.y2+1]--;
		map[iop.x2+1][iop.y1]--;
		map[iop.x2+1][iop.y2+1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]+=map[i-1][j]+map[i][j-1]-map[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
