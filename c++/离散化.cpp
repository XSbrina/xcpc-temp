#include<iostream>
#include<vector>
#include <algorithm>
#define int long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int MAXN=1e5+5;
int n,k,tot,res;
int a[MAXN],pre[MAXN],c[MAXN<<1];
vector<int> temp;
int getRank(int x) {
    int rk=lower_bound(temp.begin(),temp.end(),x)-temp.begin();
    return rk+1;
}
void update(int pos,int x) {
    for (int i=pos;i<=tot;i+=lowbit(i)) c[i]+=x;
}
int query(int pos) {
    int ans=0;
    for (int i=pos;i;i-=lowbit(i)) ans+=c[i];
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        temp.push_back(pre[i]);
        temp.push_back(pre[i]-k);
    }
    temp.push_back(0);
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    tot=temp.size();
    update(getRank(pre[0]),1);
    for (int r=1;r<=n;r++) {
        int target=pre[r]-k;
        int rk=getRank(target);
        res+=query(rk);
        update(getRank(pre[r]),1);
    }
    cout<<res<<'\n';
    return 0;
}