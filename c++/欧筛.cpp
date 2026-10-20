#include<iostream>
#include<vector>
const int MAX=1e6+5; 
using namespace std;
vector<bool> jkl(MAX,false);
int pre[MAX];
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		if(!jkl[i]){
			pre[++pre[0]]=i;
		}
		for(int j=1;j<=pre[0]&&i*pre[j]<=n;j++){
			jkl[pre[j]*i]=true;
			if(i%pre[j]==0) break;
		}
	}
	cout<<pre[0];
}
