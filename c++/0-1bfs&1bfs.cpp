#include<bits/stdc++.h>
using namespace std;
const int M=200005;
const int N=100005;
const int INF=0x3f3f3f3f;
struct edge {
    int to,w,next;
}e[M];
int cnt,head[N],dis[N];
//处理边权只有一种的情况
int bfs_1(int s,int t) {
    memset(dis,INF,sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for (int i=head[u];i;i=e[i].next) {
            int v=e[i].to;
            if (dis[v]>dis[u]+1) dis[v]=dis[u]+1,q.push(v);
        }
    }
    return dis[t];
}
//处理边权只有0和1的情况，或者k和k+1
int bfs_01(int s,int t) {
    memset(dis,INF,sizeof(dis));
    deque<int> q;
    q.push_front(s);
    dis[s]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop_front();
        for (int i=head[u];i;i=e[i].next) {
            int v=e[i].to;
            if (dis[v]>dis[u]+e[i].w) {
                dis[v]=dis[u]+e[i].w;
                if (!e[i].w) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    return dis[t];
}