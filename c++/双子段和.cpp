#include<iostream>
#include<math.h>
#define ll long long
using namespace std;
ll l[1000005],r[1000005],num[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	l[1]=num[1],r[n]=num[n];
	for(int i=2;i<=n;i++) l[i]=max(l[i-1]+num[i],num[i]);
	for(int i=n-1;i>=1;i--) r[i]=max(r[i+1]+num[i],num[i]);
	for(int i=2;i<=n;i++) l[i]=max(l[i-1],l[i]);
	for(int i=n-1;i>=1;i--) r[i]=max(r[i+1],r[i]);
	ll ans=0xf000000000000000; 
	for(int i=2;i<=n-1;i++) ans=max(ans,l[i-1]+r[i+1]);
	cout<<ans;
	return 0;
}
