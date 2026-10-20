#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<vector<vector<int>>> uio;
void init(){
	cin>>n>>m;
	uio.resize(n+1,vector<vector<int>>(n+1,vector<int>(n+1,1e5)));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			uio[i][i][j]=0;
		}
	} 
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(uio[a][b][0]>c){
			uio[a][b][0]=c;
			uio[b][a][0]=c;			
		}
	}
}
void deal(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				uio[j][k][i]=min(uio[j][k][i-1],uio[j][i][i-1]+uio[i][k][i-1]);
			}
		}
	}
}
void output(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<uio[i][j][n]<<" ";
		}
		cout<<endl;
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
