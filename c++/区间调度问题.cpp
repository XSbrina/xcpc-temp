#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=2e5+5;
pair<int,int> f[MAX];
int n,k;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		f[i]={l,r};
	}
	sort(f+1,f+n+1,cmp);
	int cnt=0,cur_r=INT_MIN,x=INT_MAX;
	for(int i=1;i<=n;i++){
		if(f[i].first>cur_r){
			cnt++;
			x=min(x,f[i].first-cur_r);
			cur_r=f[i].second;
		}
	}
	if(cnt<k){
		cout<<-1;
		return 0;
	}
	int ans;
	int l=x,r=1e9+5;
	while(l<=r){
		int m=l+((r-l)>>1);
		int cur=INT_MIN;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(f[i].first>=cur){
				cnt++;
				cur=f[i].second+m;
			}
		}
		if(cnt>=k){
			ans=m;
			l=m+1;
		}
		else r=m-1;
	}
	cout<<ans;
	return 0;
}
