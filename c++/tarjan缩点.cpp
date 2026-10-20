#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> g[N];    //原图
vector<int> sg[N];   //缩点后的DAG
int dfn[N], low[N], tim;
int stk[N], top;
bool in_stk[N];
int scc_id[N];      //每个点属于哪个scc编号
int scc_cnt;        //scc总数量

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    stk[++top] = u;
    in_stk[u] = true;
    for(int v : g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(in_stk[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++scc_cnt;
        int y;
        do{
            y = stk[top--];
            in_stk[y] = false;
            scc_id[y] = scc_cnt;
        }while(y != u);
    }
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    //===== 缩点建DAG =====
    set<pair<int,int>> vis; //去重，防止重边
    for(int u=1;u<=n;u++){
        for(int v:g[u]){
            int a = scc_id[u], b = scc_id[v];
            if(a != b && !vis.count({a,b})){
                sg[a].push_back(b);
                vis.insert({a,b});
            }
        }
    }
    // sg[] 就是缩点后的DAG，一共scc_cnt个点
    /*
     for(int i=scc_cnt;i>=1;i--){}
     这个本身就是一种拓扑序
     */
    return 0;
}
