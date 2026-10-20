#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
struct SegmentTree {
    struct Node {
        int sum;
        int add;    // 加法懒标记
        int mul;    // 乘法懒标记
    } tr[N << 2];
    int a[N];
    int mod;
    void pushup(int u) {
        tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
    }
    void build(int u, int l, int r) {
        // 乘法标记初始必须是1
        tr[u].add = 0;
        tr[u].mul = 1;
        if (l == r) {
            tr[u].sum = a[l] % mod;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    // 当前区间整体乘 k
    void apply_mul(int u, int l, int r, int k) {
        tr[u].sum = tr[u].sum * k % mod;
        // 原来的加法标记也要乘k
        tr[u].add = tr[u].add * k % mod;
        // 更新乘法标记
        tr[u].mul = tr[u].mul * k % mod;
    }
    // 当前区间整体加 k
    void apply_add(int u, int l, int r, int k) {
        tr[u].sum = (tr[u].sum + (r - l + 1) * k) % mod;
        tr[u].add = (tr[u].add + k) % mod;
    }
    void pushdown(int u, int l, int r) {
        int mid = (l + r) >> 1;
        // 先乘
        if (tr[u].mul != 1) {
            apply_mul(u << 1, l, mid, tr[u].mul);
            apply_mul(u << 1 | 1, mid + 1, r, tr[u].mul);
            tr[u].mul = 1;
        }
        // 再加
        if (tr[u].add != 0) {
            apply_add(u << 1, l, mid, tr[u].add);
            apply_add(u << 1 | 1, mid + 1, r, tr[u].add);
            tr[u].add = 0;
        }
    }
    // 区间乘 k
    void modify_mul(int u, int l, int r,int L, int R, int k) {
        if (L <= l && r <= R) {
            apply_mul(u, l, r, k);
            return;
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid) modify_mul(u << 1, l, mid, L, R, k);
        if (R > mid) modify_mul(u << 1 | 1, mid + 1, r, L, R, k);
        pushup(u);
    }
    // 区间加 k
    void modify_add(int u, int l, int r,int L, int R, int k) {
        if (L <= l && r <= R) {
            apply_add(u, l, r, k);
            return;
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid) modify_add(u << 1, l, mid, L, R, k);
        if (R > mid) modify_add(u << 1 | 1, mid + 1, r, L, R, k);
        pushup(u);
    }
    // 区间求和
    int query(int u, int l, int r,int L, int R) {
        if (L <= l && r <= R) return tr[u].sum;
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        int ans = 0;
        if (L <= mid) ans = (ans + query(u << 1, l, mid, L, R)) % mod;
        if (R > mid) ans = (ans + query(u << 1 | 1, mid + 1, r, L, R)) % mod;
        return ans;
    }
} seg;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, mod;
    cin >> n >> q >> mod;
    seg.mod = mod;
    for (int i = 1; i <= n; i++) cin >> seg.a[i];
    seg.build(1, 1, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            // [l,r] 乘 k
            int k;
            cin >> k;
            seg.modify_mul(1, 1, n,l, r, k % mod);
        }
        else if (op == 2) {
            // [l,r] 加 k
            int k;
            cin >> k;
            seg.modify_add(1, 1, n,l, r, k % mod);
        }
        else {
            // 查询 [l,r] 的和
            cout << seg.query(1, 1, n,l, r) % mod << '\n';
        }
    }
    return 0;
}