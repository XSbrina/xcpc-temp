#include<iostream>
#include<map>
using namespace std;
const int MAX=2e5+5;
struct node {
    int to,next;
}e[MAX<<1];
int n,m,cnt,ans;
int head[MAX],color[MAX];
int cnt0,cnt1;
bool flag;
void add(int u,int v) {
    cnt++;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int u,int c) {
    color[u]=c;
    if (c) cnt1++;
    else cnt0++;
    for (int i=head[u];i;i=e[i].next) {
        int v=e[i].to;
        if (color[v]!=-1) flag=(color[v]==(c^1))&&flag;
        else dfs(v,c^1);
    }
}
void Solve() {
    cin>>n>>m;
    cnt=0;
    ans=n;
    for (int i=1;i<=n;i++) head[i]=0,color[i]=-1;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for (int i=1;i<=n;i++) {
        if (color[i]!=-1) continue;
        cnt0=cnt1=0;
        flag=true;
        dfs(i,0);
        if (!flag) ans-=cnt0+cnt1;
        else ans-=min(cnt0,cnt1);
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) Solve();
    return 0;
}