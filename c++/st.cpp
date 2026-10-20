#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
int f[17][MAX];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[0][i];
	}
	for(int j=1;j<17;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
		}
	}
	int m;
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		int s=31-__builtin_clz(r-l+1);
		cout<<max(f[s][l],f[s][r-(1<<s)+1])<<endl;
	}
}
