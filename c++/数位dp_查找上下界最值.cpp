#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=50;
int dp[MAX][100][50][2];
int Search(int len,int l,int r,int sum,bool free_l,bool free_r,int cnt,int offset,int nz) {
    int ans=-0x3f3f3f3f;
    if (!len) {
        if (!nz) return 1;
        ans=max(ans,sum+cnt);
        return ans;
    }
    if (free_l&&free_r&&dp[len][sum][cnt][nz]!=-1) return dp[len][sum][cnt][nz];
    int cur_l=l/offset;
    cur_l%=3;
    int cur_r=r/offset;
    cur_r%=3;
    int st=free_l?0:cur_l;
    int ed=free_r?2:cur_r;
    if (!nz) {
        if(0 >= st && 0 <= ed)
        {
            bool nfr = free_r || (0 < cur_r);
            ans=max(ans,Search(len-1,l,r,sum,free_l,nfr,cnt,offset/3,0));
        }
        for (int i=st;i<=ed;i++) {
            if (i==0) continue;
            bool jkl=i>cur_l||free_l;
            bool uio=i<cur_r||free_r;
            ans=max(ans,Search(len-1,l,r,sum+i,jkl,uio,cnt+1,offset/3,1));
        }
    }
    else {
        for (int i=st;i<=ed;i++) {
            bool jkl=i>cur_l||free_l;
            bool uio=i<cur_r||free_r;
            ans=max(ans,Search(len-1,l,r,sum+i,jkl,uio,cnt+1,offset/3,1));
        }
    }
    if (free_l&&free_r) dp[len][sum][cnt][nz]=ans;
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--) {
        int l,r;
        cin>>l>>r;

        int temp,len,offset;
        temp=r,len=0,offset=1;
        while (temp) {
            len++;
            temp/=3;
            offset*=3;
        }
        cout<<Search(len,l,r,0,false,false,0,offset/3,0)<<'\n';
    }
    return 0;
}