#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct SegTree {
    int sum[N << 2], lazy[N << 2];
    int a[N];
    void pushup(int u) {
        sum[u] = sum[u << 1] + sum[u << 1 | 1];
    }
    void apply(int u, int l, int r, int k) {
        sum[u] += (r - l + 1) * k;
        lazy[u] += k;
    }
    void pushdown(int u, int l, int r) {
        if (!lazy[u]) return;
        int mid = (l + r) >> 1;
        apply(u << 1, l, mid, lazy[u]);
        apply(u << 1 | 1, mid + 1, r, lazy[u]);
        lazy[u] = 0;
    }
    void build(int u, int l, int r) {
        lazy[u] = 0;
        if (l == r) {
            sum[u] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    // [L,R] 全部加 k
    void modify(int u, int l, int r, int L, int R, int k) {
        if (L <= l && r <= R) {
            apply(u, l, r, k);
            return;
        }
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid) modify(u << 1, l, mid, L, R, k);
        if (R > mid) modify(u << 1 | 1, mid + 1, r, L, R, k);
        pushup(u);
    }
    // 查询 [L,R] 区间和
    int query(int u, int l, int r, int L, int R) {
        if (L <= l && r <= R) return sum[u];
        pushdown(u, l, r);
        int mid = (l + r) >> 1;
        int ans = 0;
        if (L <= mid) ans += query(u << 1, l, mid, L, R);
        if (R > mid) ans += query(u << 1 | 1, mid + 1, r, L, R);
        return ans;
    }
    // 对外接口
    void build(int n) {
        build(1, 1, n);
    }
    void modify(int n, int l, int r, int k) {
        modify(1, 1, n, l, r, k);
    }
    int query(int n, int l, int r) {
        return query(1, 1, n, l, r);
    }
} seg;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> seg.a[i];
    seg.build(n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            seg.modify(n, l, r, k);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(n, l, r) << '\n';
        }
    }
}