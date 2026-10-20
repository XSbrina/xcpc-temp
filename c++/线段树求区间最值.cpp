#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a,f,b;
void init();
void build(int l,int r,int p);
void update(int l,int r,int p,int s,int t,int c);
void push_down(int l,int r,int p);
int query(int l,int r,int p,int s,int t);
void sync_a(int l,int r,int p); 
int main(){
	init();
	build(1,n,1);
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<query(1,n,1,l,r);
		cout<<endl;
	}
} 
void init(){
	cin>>n;
	a.resize(n+1);
	f.resize(n<<2);
	b.resize(n<<2);
	for(int i=1;i<=n;i++) cin>>a[i];
}
void build(int l,int r,int p){
	if(l==r){
		f[p]=a[l];
		return ;
	}
	int m=l+((r-l)>>1);
	build(l,m,p<<1);
	build(m+1,r,p<<1|1);
	f[p]=max(f[p<<1],f[p<<1|1]);
}
void update(int l,int r,int p,int s,int t,int c){
	if(s<=l&&r<=t){	
		b[p]+=c;
		f[p]+=b[p];
		return ;
	}
	if(b[p]) push_down(l,r,p);
	int m=l+((r-l)>>1);
	if(m>=s) update(l,m,p<<1,s,t,c);
	if(m<t) update(m+1,r,p<<1|1,s,t,c);
	f[p]=max(f[p<<1],f[p<<1|1]);
}
void push_down(int l,int r,int p){
	if(l==r) return ;
	if(b[p]){
		b[p<<1]+=b[p];
		b[p<<1|1]+=b[p];
		f[p<<1]+=b[p];
		f[p<<1|1]+=b[p];
		b[p]=0;
	}
}
int query(int l,int r,int p,int s,int t){
	if(s<=l&&r<=t) return f[p];
	if(b[p]) push_down(l,r,p);
	int m=l+((r-l)>>1);
	int res=-0x3f3f3f3f;
	if(m>=s) res=max(res,query(l,m,p<<1,s,t));
	if(m<t) res=max(res,query(m+1,r,p<<1|1,s,t));
	return res;
}
void sync_a(int l,int r,int p){
	if(b[p]) push_down(l,r,p);
	if(l==r){
		a[l]=f[p];
		return ;
	}
	int m=l+((r-l)>>1);
	sync_a(l,m,p<<1);
	sync_a(m+1,r,p<<1|1);
}
