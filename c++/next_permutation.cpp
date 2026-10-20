#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt=1;
	for(int i=1;i<=n;i++) cnt*=i;
	while(cnt--){
		cout<<s<<endl;
		next_permutation(s.begin(),s.end());
	}
	return 0;
}
