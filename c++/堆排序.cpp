#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int n;
vector<int> f;
void init();
void adjust(int start,int end);
void sort_heap();
int  main(){
	init();
	sort_heap();
	for(auto x:f) cout<<x<<" ";
	return 0;
}
void init(){
	cin>>n;
	f.resize(n);
	for(int i=0;i<n;i++) cin>>f[i];
}
void adjust(int start,int end){
	for(int i=2*start+1;i<=end;i=2*i+1){
		if(i<end&&f[i]<f[i+1]) i++;//找出两个子节点较大的一个 
		if(f[i]>f[start]){
			swap(f[i],f[start]);
			start=i;//找到后要更新start 
		}
		else break;//不满足说明下面已经是大根堆了 
	}
}
void sort_heap(){
	//构造大根堆
	for(int i=n/2-1;i>=0;i--){
		//从n/2-1即最后一个非叶子节点开始往前 
		adjust(i,n-1);
	}
	//交换已经确定的顶 
	for(int i=0;i<n;i++){
		swap(f[0],f[n-i-1]);//交换开头和不断前进的末尾 
		adjust(0,n-i-2);
	}
}
/*
10
23 32 1 2 3 44 23 2 0 1
*/
