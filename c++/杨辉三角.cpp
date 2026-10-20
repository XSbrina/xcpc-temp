#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int>> f(n+1,vector<int>(n+1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(!j) f[i][j]=1;
			else f[i][j]=f[i-1][j-1]+f[i-1][j];
		}
	} 
	cout<<f[0][0]<<" "<<f[4][3]<<" "<<f[9][1];
}
