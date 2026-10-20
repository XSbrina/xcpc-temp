#include<bits/stdc++.h>
using namespace std;
struct node {
    int cnt;
    int ans[10];
    node() {
        memset(ans,0,sizeof(ans));
        cnt=-1;
    }
};
int n;
node dp[11][2];
node dfs(int len,int nz,int free,int offset) {
    node temp;
    temp.cnt=0;
    if (!len) {
        temp.cnt=1;
        return temp;
    }
    if (free&&dp[len][nz].cnt!=-1) return dp[len][nz];
    int cur=n/offset%10;
    int ed=free?9:cur;
    node jkl;
    for (int i=0;i<=ed;i++) {
        int new_nz=nz||i;
        int nwe_free=free||i<cur;
        jkl=dfs(len-1,new_nz,nwe_free,offset/10);
        temp.cnt+=jkl.cnt;
        if (new_nz) temp.ans[i]+=jkl.cnt;
        for (int j=0;j<=9;j++) temp.ans[j]+=jkl.ans[j];
    }
    if (free) dp[len][nz]=temp;
    return temp;
}
int main() {
    cin>>n;
    int temp=n,len=0,offset=1;
    while (temp) {
        temp/=10;
        len++;
        offset*=10;
    }
    node jkl=dfs(len,0,0,offset/10);
    for (int i=0;i<=9;i++) cout<<jkl.ans[i]<<'\n';
    return 0;
}