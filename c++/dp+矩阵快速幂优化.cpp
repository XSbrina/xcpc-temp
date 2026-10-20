#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
int k;
int a[10][10],ans[10][10],temp[10][10];
int f[10],F[10];
void get1() {
    memset(temp,0,sizeof(temp));
    for (int i=0;i<=9;i++) {
        for (int j=0;j<=9;j++) {
            for (int l=0;l<=9;l++) {
                temp[i][j]=(temp[i][j]+ans[i][l]*a[l][j])%MOD;
            }
        }
    }
    for (int i=0;i<=9;i++) {
        for (int j=0;j<=9;j++) {
            ans[i][j]=temp[i][j];
        }
    }
}
void get2() {
    memset(temp,0,sizeof(temp));
    for (int i=0;i<=9;i++) {
        for (int j=0;j<=9;j++) {
            for (int l=0;l<=9;l++) {
                temp[i][j]=(temp[i][j]+a[i][l]*a[l][j])%MOD;
            }
        }
    }
    for (int i=0;i<=9;i++) {
        for (int j=0;j<=9;j++) {
            a[i][j]=temp[i][j];
        }
    }
}
void quick() {
    int b=k-1;
    while (b) {
        if (b&1) get1();
        get2();
        b>>=1;
    }
}
void init() {
    cin>>k;
    for (int i=1;i<=9;i++) f[i]=1;
    for (int i=0;i<=9;i++) {
        for (int j=0;j<=9;j++) {
            if (abs(i-j)<=2) a[i][j]=1;
        }
    }
    for (int i=0;i<=9;i++) ans[i][i]=1;
}
signed main() {
    init();
    if (k==1) cout<<10;
    else {
        quick();
        for (int i=0;i<=9;i++) {
            for (int j=0;j<=9;j++) {
                F[i]=(F[i]+f[j]*ans[j][i])%MOD;
            }
        }
        int jkl=0;
        for (int i=0;i<=9;i++) jkl=(jkl+F[i])%MOD;
        cout<<jkl;
    }
    return 0;
}