#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;//数组长度
const int M = N * 25;//*log(N)
struct PresidentTree {
    struct Node {
        int ls, rs;
        int sum;
    } tr[M];
    int root[N], tot;
    // 在旧版本 pre 的基础上，把位置 x 的计数 +1
    void insert(int &u, int pre, int l, int r, int x) {
        u = ++tot;
        tr[u] = tr[pre];
        tr[u].sum++;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (x <= mid) insert(tr[u].ls, tr[pre].ls, l, mid, x);
        else insert(tr[u].rs, tr[pre].rs, mid + 1, r, x);
    }
    // 查询 [L,R] 中第 k 小
    int kth(int u, int v, int l, int r, int k) {
        if (l == r)
            return l;
        int mid = (l + r) >> 1;
        int cnt = tr[tr[u].ls].sum - tr[tr[v].ls].sum;
        if (k <= cnt) return kth(tr[u].ls, tr[v].ls, l, mid, k);
        else return kth(tr[u].rs, tr[v].rs, mid + 1, r, k - cnt);
    }
    // 查询 [L,R] 中，小于离散化位置 x 的数有多少个
    int Rank(int u, int v, int l, int r, int x) {
        // 如果整个区间都 < x，直接返回整个区间的元素个数
        if (r < x) return tr[u].sum - tr[v].sum;
        // 如果整个区间都 >= x
        if (l >= x) return 0;
        int mid = (l + r) >> 1;
        return Rank(tr[u].ls, tr[v].ls, l, mid, x)+ Rank(tr[u].rs,tr[v].rs,mid + 1, r, x);
    }
} seg;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    // 离散化
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size();
    // 建立每个前缀的版本
    for (int i = 1; i <= n; i++) {
        int x = lower_bound(b.begin(), b.end(), a[i])- b.begin() + 1;
        seg.insert(seg.root[i],seg.root[i - 1],1, m, x);
    }
    while (q--) {
        int op;
        cin >> op;
        // 查询 [l,r] 第 k 小
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            int pos = seg.kth(seg.root[r],seg.root[l - 1],1, m, k);
            cout << b[pos - 1] << '\n';
        }
        // 查询 x 在 [l,r] 中的 rank
        // rank = 小于 x 的数的数量 + 1
        else {
            int l, r, x;
            cin >> l >> r >> x;
            // 第一个 >= x 的数
            // pos 范围可以到 m+1
            int pos = lower_bound(b.begin(),b.end(),x) - b.begin() + 1;
            int ans = seg.Rank(seg.root[r],seg.root[l - 1],1, m, pos);
            cout << ans + 1 << '\n';
        }
    }
    return 0;
}