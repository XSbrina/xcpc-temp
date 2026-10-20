#include<iostream>
#define lowbit(x) (x&(-x))
using namespace std;
const int MAXN=5e5+5;
int n;
int c[MAXN];
void update(int pos,int x) {
    for (int i=pos;i<=n;i+=lowbit(i)) c[i]+=x;
}
int query(int pos) {
    int ans=0;
    for (int i=pos;i;i-=lowbit(i)) ans+=c[i];
    return ans;
}
int main() {
    int m;
    cin>>n>>m;
    int last=0;
    for (int i=1;i<=n;i++) {
        int a;
        cin>>a;
        update(i,a-last);
        last=a;
    }
    while (m--) {
        int id;
        cin>>id;
        if (id==1) {
            int l,r,x;
            cin>>l>>r>>x;
            update(l,x);
            update(r+1,-x);
        }
        else {
            int pos;
            cin>>pos;
            cout<<query(pos)<<'\n';
        }
    }
    return 0;
}