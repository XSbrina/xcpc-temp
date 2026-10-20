#include<iostream>
using namespace std;
int a[500005],c[500005];
long long ans=0;
void resort(int l,int r){ 
	if(l==r) return;
	int mid=(l+r)/2;
	int i=l,j=mid+1,k=l;
	resort(l,mid);
	resort(mid+1,r);
	while(i<=mid&&j<=r){
		if(a[i]<a[j]){
			c[k++]=a[i++];
		}
		else{
			c[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid) c[k++]=a[i++];
	while(j<=r) c[k++]=a[j++];
	for(int x=l;x<=r;x++){
		a[x]=c[x];
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	resort(1,n);
	cout<<ans;
	return 0;
}
