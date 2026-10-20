#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
const int M = N * 40;  // 动态开点空间
struct SegmentTree {
    struct Node {
        int ls, rs;    // 左右儿子编号
        int sum;       // 这个值域中有多少个数
    } tr[M];
    int root, tot;
    // 在位置 x 加 k
    void modify(int &u, int l, int r, int x, int k) {
        if (!u) u = ++tot;
        tr[u].sum += k;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (x <= mid) modify(tr[u].ls, l, mid, x, k);
        else modify(tr[u].rs, mid + 1, r, x, k);
    }
    // 查询值域 [L,R] 中有多少个数
    int query(int u, int l, int r, int L, int R) {
        if (!u) return 0;
        if (L <= l && r <= R) return tr[u].sum;
        int mid = (l + r) >> 1;
        int ans = 0;
        if (L <= mid) ans += query(tr[u].ls, l, mid, L, R);
        if (R > mid) ans += query(tr[u].rs, mid + 1, r, L, R);
        return ans;
    }
    // 求第 k 小
    int kth(int u, int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) >> 1;
        int cnt = tr[tr[u].ls].sum;
        if (k <= cnt) return kth(tr[u].ls, l, mid, k);
        else return kth(tr[u].rs, mid + 1, r, k - cnt);
    }
    // 插入 x
    void insert(int x) {
        modify(root, 1, 1e9, x, 1);
    }
    // 删除 x
    void erase(int x) {
        modify(root, 1, 1e9, x, -1);
    }
    // 查询 <= x 的数有多少个
    int get_rank(int x) {
        return query(root, 1, 1e9, 1, x);
    }
    // 查询第 k 小
    int kth(int k) {
        return kth(root, 1, 1e9, k);
    }
} seg;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            seg.insert(x);
        }
        else if (op == 2) {
            seg.erase(x);
        }
        else if (op == 3) {
            // <= x 的数的个数
            cout << seg.get_rank(x) << '\n';
        }
        else {
            // 第 x 小
            cout << seg.kth(x) << '\n';
        }
    }
}