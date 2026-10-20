#include<bits/stdc++.h>
using namespace std;
int main(){
	ofstream jkl("rr.dat");
	int n;
	cin>>n;
	jkl<<fixed;
	for(int i=1;i<=n;i++){
		jkl<<setprecision(6)<<sqrt(i)<<" ";
	}
	jkl.close();
	ifstream uio("rr.dat");
	double ans;
	cout<<fixed;
	while(uio>>ans){
		cout<<setprecision(6)<<ans<<" ";
	}
	return 0;
}
