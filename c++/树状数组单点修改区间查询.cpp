#include<iostream>
#define lowbit(x) (x&(-x))
using namespace std;
const int MAXN=5e5+5;
int n;
int a[MAXN],c[MAXN];
//单点更新
void update(int pos,int x) {
    for (int i=pos;i<=n;i+=lowbit(i)) c[i]+=x;
}
//区间查询,返回1-pos的和
int query(int pos) {
    int ans=0;
    for (int i=pos;i;i-=lowbit(i)) ans+=c[i];
    return ans;
}
int main() {
    int m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i],update(i,a[i]);
    while (m--) {
        int id;
        cin>>id;
        if (id==1) {
            int pos,x;
            cin>>pos>>x;
            update(pos,x);
        }
        else {
            int l,r;
            cin>>l>>r;
            cout<<query(r)-query(l-1)<<'\n';
        }
    }
    return 0;
}