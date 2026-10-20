#include<algorithm>
#include<iostream>
using namespace std;
int a[100005]; 
void change(int l,int r){
	int i=l,j=r;
	int judge=(a[i]+a[j])/2;
	while(i<=j){
		while(a[i]<judge) i++;
		while(a[j]>judge) j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	if(l<j) change(l,j);
	if(r>i) change(i,r);
} 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	change(1,n);
	for(int i=1;i<n;i++){
		printf("%d ",a[i]);
	}
	cout<<a[n];
	return 0;
}
