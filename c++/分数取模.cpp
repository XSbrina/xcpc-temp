#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int jkl(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}
signed main(){
	cout<<jkl(2,MOD-2);
}
//求a/b(modMOD)的结果就是(a*b^(MOD-2))%MOD