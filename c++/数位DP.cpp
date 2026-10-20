#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX=15;
ll a,b;
ll dp[MAX],mi[MAX],ansl[10],ansr[10];
void Solve(ll n,ll ans[]) {
    vector<ll> a(MAX);
    int j=0;
    ll jkl=n;
    while (n) {
        a[++j]=n%10;
        n/=10;
    }
    for (int i=j;i>=1;i--) {
        for (int k=0;k<=9;k++) ans[k]+=dp[i-1]*a[i];
        for (int k=0;k<a[i];k++) ans[k]+=mi[i-1];
        jkl-=a[i]*mi[i-1];
        ans[a[i]]+=jkl+1;
        ans[0]-=mi[i-1];
    }
}
int main() {
    cin>>a>>b;
    mi[0]=1;
    for (int i=1;i<MAX;i++) dp[i]=dp[i-1]*10+mi[i-1],mi[i]=mi[i-1]*10;
    Solve(a-1,ansl);
    Solve(b,ansr);
    for (int i=0;i<=9;i++) cout<<ansr[i]-ansl[i]<<" ";
    return 0;
}