#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=105;
const int MOD=1e9+7;
int ans[MAXN][MAXN],a[MAXN][MAXN],temp[MAXN][MAXN];
int n,k;
void get1() {
    memset(temp,0,sizeof(temp));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int l=1;l<=n;l++) {
                temp[i][j]=(temp[i][j]+ans[i][l]*a[l][j])%MOD;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            ans[i][j]=temp[i][j];
        }
    }
}
void get2() {
    memset(temp,0,sizeof(temp));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int l=1;l<=n;l++) {
                temp[i][j]=(temp[i][j]+a[i][l]*a[l][j])%MOD;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            a[i][j]=temp[i][j];
        }
    }
}
void quick() {
    while (k) {
        if (k&1) get1();
        get2();
        k>>=1;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;i++) ans[i][i]=1;
    quick();
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}