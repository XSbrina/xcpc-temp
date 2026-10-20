#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,tend=0;
    cin>>n>>k;
    deque<int> f;
    int i,j;
    i=j=0;
    while(k--){
        int l,r;
        cin>>l>>r;
        if(!i&&!j){
            i=l,j=r;
            for(int z=1;z<i;z++) cout<<z<<" ";
            for(int z=i;z<=j;z++) f.push_back(z);
            tend=1;
        }
        else{
            if(l>j){
                if(tend) while(!f.empty()) cout<<f.back()<<" ",f.pop_back();
                else while(!f.empty()) cout<<f.front()<<" ",f.pop_front();
                for(int z=j+1;z<l;z++) cout<<z<<" ";
                for(int z=l;z<=r;z++) f.push_back(z);
                tend=1;
            }
            else{
                int cnt=l-i;
                if(tend) while(cnt--) cout<<f.back()<<" ",f.pop_back();
                else while(cnt--) cout<<f.front()<<" ",f.pop_front();
                for(int z=j+1;z<=r;z++){
                    if(tend) f.push_front(z);
                    else f.push_back(z);
                }
                tend=1-tend;
            }
            i=l,j=r;
        }
    }
    if(tend) while(!f.empty()) cout<<f.back()<<" ",f.pop_back();
    else while(!f.empty()) cout<<f.front()<<" ",f.pop_front();
    for(int z=j+1;z<=n;z++) cout<<z<<" ";
    return 0;
}