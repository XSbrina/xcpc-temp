#include <chrono>
#include<iostream>
#include<random>
#include<map>
#define ull unsigned long long
using namespace std;
const int MAX=2.5e5+5;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ull prehash1[MAX];
ull prehash2[MAX];
ull pre1[MAX],pre2[MAX];
ull f1[MAX],f2[MAX];
int n,q;
int a[MAX];
void preSolve() {
    for (int i=1;i<MAX;i++) {
        f1[i]=rng();
        f2[i]=rng();
    }
    for (int i=1;i<=n/2;i++) {
        prehash1[i]=prehash1[i-1]+f1[i]*2;
        prehash2[i]=prehash2[i-1]+f2[i]*2;
    }
    for (int i=1;i<=n;i++) {
        pre1[i]=pre1[i-1]+f1[a[i]];
        pre2[i]=pre2[i-1]+f2[a[i]];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    preSolve();
    while (q--) {
        int l,r;
        cin>>l>>r;
        int len=r-l+1;
        if (len&1||pre1[r]-pre1[l-1]!=prehash1[len/2]||pre2[r]-pre2[l-1]!=prehash2[len/2]) {
            cout<<"No"<<'\n';
        }
        else cout<<"Yes"<<'\n';
    }
    return 0;
}