#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> a={4,3,1,2,3};
	nth_element(a.begin(),a.begin()+2,a.end());
	for(auto x:a) cout<<x<<" ";
}
