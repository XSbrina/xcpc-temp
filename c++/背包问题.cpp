#include <algorithm>
void 01背包(){
    for (int i=1;i<=n;i++) {
        for (int j=w;j>=w[i];j--) {
            f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }

    //装满
    fill(dp,dp+w+1,-INF);
    dp[0]=0;
    for (int i=1;i<=n;i++) {
        for (int j=w;j>=w[i];j--) {
            f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }
    dp[W]<0表示没有填满的方案

    //最大价值方案数
    vector<int> cnt(w+1);
    cnt[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=w;j>=w[i];j--){
            if(dp[j]<dp[j-w[i]]+v[i]) dp[j]=dp[j-w[i]]+v[i],cnt[j]=cnt[j-w[i]];
            else if(dp[j]==dp[j-w[i]]+v[i]) cnt[j]+=cnt[j-w[i]];
            cnt[j]%=MOD;
        }
    }
    //输出方案
    bool taken[n][w];
    for (int i=1;i<=n;i++) {
        for (int j=w;j>=w[i];j--) {
            if (dp[j-w[i]]+v[i]>=dp[j]) {
                dp[j]=dp[j-w[i]]+v[i];
                taken[i][j]=true;
            }
            else taken[i][j]=false;
        }
    }
    vector<int> ans;
    int i=n,j=w;
    while (i>=1) {
        if (taken[i][j]) {
            ans.push_back(i);
            j-=w[i];
        }
        i--;
    }
}
void 完全背包() {
    for (int i=1;i<=n;i++) {
        for (int j=w[i];j<=w;j++) {
            f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }
}
void 分组背包() {
    int t,cnt[t+1];//t组，第i组cnt[i]个
    int id[t+1][cnt[i]];
    for (int zu=1;zu<=t;zu++) {
        for (int j=w;j>=0;j--) {
            for (int i=1;i<=cnt[zu];i++) {
                if (j>=w[id[zu][i]]) f[j]=max(f[j],f[j-w[id[zu][i]]]+v[id[zu][i]]);
            }
        }
    }
}