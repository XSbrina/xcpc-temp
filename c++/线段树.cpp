#include<iostream>
#include<vector>
#define m(l,r) l+((r-l)>>1)
using namespace std;
int n,t1,t2;
vector<int> a,f,mk;
void init();
void build(int l,int r,int p);
void update(int l,int r,int s,int t,int p,int c);
int query(int l,int r,int s,int t,int p);
void sync_a(int l,int r,int p);
void output();
int main(){
	init();
	build(1,n,1);
	cin>>t1;
	while(t1--){
		int tl,tr,c;
		cin>>tl>>tr>>c;
		update(1,n,tl,tr,1,c);
		sync_a(1,n,1);
		output();
	}
	cin>>t2;
	while(t2--){
		int tl,tr;
		cin>>tl>>tr;
		cout<<query(1,n,tl,tr,1)<<endl;
	}
	return 0;
}
void init(){
	cin>>n;
	a.resize(4*n+1);
	f.resize(4*n+1);
	mk.resize(4*n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
}
void build(int l,int r,int p){
	if(l==r){
		f[p]=a[l];
		return ;
	}
	int m=m(l,r);
	build(l,m,2*p);
	build(m+1,r,2*p+1);
	f[p]=f[2*p]+f[2*p+1];
}
void push_down(int l,int r,int p){
	if(l==r) return ;
	int m=m(l,r);
	f[2*p]+=mk[p]*(m-l+1);
	f[2*p+1]+=mk[p]*(r-m);
	mk[2*p]+=mk[p];
	mk[2*p+1]+=mk[p];
	mk[p]=0;
}
void update(int l,int r,int s,int t,int p,int c){
	if(s<=l&&r<=t){
		f[p]+=c*(r-l+1);
		mk[p]+=c;
		return ;
	}
	if(mk[p]) push_down(l,r,p);
	int m=m(l,r);
	if(m>=s) update(l,m,s,t,2*p,c);
	if(m<t) update(m+1,r,s,t,2*p+1,c);
	f[p]=f[2*p]+f[2*p+1];
}
int query(int l,int r,int s,int t,int p){
	if(s<=l&&r<=t) return f[p];
	if(mk[p]) push_down(l,r,p);
	int m=m(l,r),sum=0;
	if(m>=s) sum+=query(l,m,s,t,2*p);
	if(m<t) sum+=query(m+1,r,s,t,2*p+1);
	return sum;
}
void sync_a(int l,int r,int p){
	if(mk[p]) push_down(l,r,p);
	if(l==r){
		a[l]=f[p];
		return ;
	}
	int m=m(l,r);
	sync_a(l,m,2*p);
	sync_a(m+1,r,2*p+1);
}
void output(){
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
/*
7
1 2 3 4 5 6 7
3 
1 1 2
2 5 2
3 4 1
8 
1 1 
2 2 
3 3
4 4
5 5
6 6
7 7
1 7 
*/
