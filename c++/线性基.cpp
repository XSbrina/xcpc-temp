//求数组a的所有子集异或最大值
//判断a的子集异或是否能得到x
#include<bits/stdc++.h>
#define MAX 60
#define int long long
using namespace std;
int Bit[MAX+1];
void insert(int x) {
    for (int i=MAX;i>=0;i--) {
        if (x&(1LL<<i)) {
            if (!Bit[i]) {
                Bit[i]=x;
                break;
            }
            else x^=Bit[i];
        }
    }
}
int get_max() {
    int ans=0;
    for (int i=MAX;i>=0;i--) {
        if ((ans^Bit[i])>ans) ans^=Bit[i];
    }
    return ans;
}
//不能判断0可否由非空子集异或出
bool exist(int x) {
    for (int i=MAX;i>=0;i--) {
        if (x&(1LL<<i)) x^=Bit[i];
    }
    return x==0;
}
//判断0可否由非空子集异或出
int count_sz() {
    int cnt=0;
    for (int i=MAX;i>=0;i--) {
        if (Bit[i]) cnt++;
    }
    return cnt;
}
signed main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int a;
        cin>>a;
        insert(a);
    }
    if (n>count_sz()) {
        cout<<"0可以被非空子集异或出";
    }
    cout<<get_max();
    return 0;
}