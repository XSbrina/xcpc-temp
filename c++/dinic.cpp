struct MF {
    struct edge {
        int v, nxt, cap, flow;
    } e[M<<1];
    int head[N], cnt = 0;
    int n, S, T;
    ll maxflow = 0;
    int dep[N], cur[N];
    void init() {
        memset(head, -1, sizeof head);
        cnt = 0;
        maxflow = 0;
    }
    void addedge(int u, int v, int w) {
        e[cnt] = {v, head[u], w, 0};
        head[u] = cnt++;
        e[cnt] = {u, head[v], 0, 0};
        head[v] = cnt++;
    }
    bool bfs() {
        queue<int> q;
        memset(dep, 0, sizeof(int) * (n + 1));
        dep[S] = 1;
        q.push(S);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = head[u]; ~i; i = e[i].nxt) {
                int v = e[i].v;
                if ((!dep[v]) && (e[i].cap > e[i].flow)) {
                    dep[v] = dep[u] + 1;
                    q.push(v);e.cpp
                }
            }
        }
        return dep[T];
    }
    int dfs(int u, int flow) {
        if ((u == T) || (!flow)) return flow;
        int ret = 0;
        for (int& i = cur[u]; ~i; i = e[i].nxt) {
            int v = e[i].v, d;
            if ((dep[v] == dep[u] + 1) &&(d = dfs(v, min(flow - ret, e[i].cap - e[i].flow)))) {
                ret += d;
                e[i].flow += d;
                e[i ^ 1].flow -= d;
                if (ret == flow) return ret;
            }
        }
        return ret;
    }
    void dinic() {
        while (bfs()) {
            memcpy(cur, head, sizeof(int) * (n + 1));
            maxflow += dfs(S, INF);
        }
    }
    //找最小割集合的
    bool vis[N];
    void dfs_cut(int u) {
        vis[u]=true;
        for (int i=head[u];~i;i=e[i].nxt) {
            auto &ed=e[i];
            if (!vis[ed.v]&&ed.cap>ed.flow) {
                dfs_cut(ed.v);
            }
        }
    }
} mf;