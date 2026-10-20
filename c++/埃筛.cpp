#include<iostream>
#include<vector>
#define int long long
using namespace std;
vector<int> prime;
const int JKL=10e4;
void search(){
	vector<bool> pri(JKL,true);
	pri[0]=false;
	pri[1]=false;
	for(int i=2;i*i<=JKL;i++){
		if(pri[i]){
			for(int j=i*i;j<=JKL;j+=i){
				pri[j]=false;
			}
		}
	} 
	for(int i=2;i<=JKL;i++){
		if(pri[i]==true){
			prime.push_back(i);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	search();
	for(int x:prime){
		cout<<x<<" ";
	}
}
