// 求一些大小关系限制了的条件下的组合个数
#include<iostream>
#define int long long
using namespace std;
const int MOD=998244353;
int n;
int p[25],dp[1<<22],pre[25];
signed main() {
    int flag=0;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i];
        if (i>=2&&p[i]<p[i-1]) flag=1;
    }
    if (!flag) {
        int ans=1;
        for (int i=1;i<=n;i++) {
            ans=(ans*i)%MOD;
        }
        cout<<ans<<endl;
        return 0;
    }
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (p[i]>p[j]) {
                pre[p[j]-1]|=(1<<(p[i]-1));
            }
        }
    }
    dp[0]=1;
    for (int mask=0;mask<(1<<22);mask++) {
        if (!dp[mask]) continue;
        for (int i=0;i<n;i++) {
            if (mask&(1<<i)) continue;
            if ((pre[i]&mask)==pre[i]) {
                int next=mask|(1<<i);
                dp[next]=(dp[next]+dp[mask])%MOD;
            }
        }
    }
    cout<<(2*dp[(1<<n)-1])%MOD<<endl;
    return 0;
}
