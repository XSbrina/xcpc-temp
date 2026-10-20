#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAX=1e5+5;
int n;
stack<pair<double,double> > s,t;
bool cmp(pair<double,double> a,pair<double,double> b){
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
int Fork(double a,double b,double c,double d){
	double temp=a*d-b*c;
	if(temp>0) return 1;
	if(temp<0) return -1;
	return 0;
}
double getDis(double a,double b,double c,double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
	cout<<fixed<<setprecision(2);
	cin>>n;
	vector<pair<double,double> > f(n+1);
	for(int i=1;i<=n;i++){
		double a,b;
		cin>>a>>b;
		f[i]={a,b};
	}
	sort(f.begin()+1,f.end(),cmp);
	f.erase(unique(f.begin()+1,f.end()),f.end());
	n=f.size()-1;
	//下凸壳
	for(int i=1;i<=n;i++){
		double x=f[i].first;
		double y=f[i].second;
		while(s.size()>1){
			pair<double,double> f1=s.top();
			s.pop();
			pair<double,double> f2=s.top();
			double x1=f1.first-f2.first;
			double y1=f1.second-f2.second;
			double x2=x-f1.first;
			double y2=y-f1.second;
			int temp=Fork(x1,y1,x2,y2);
			if(temp>0){
				s.push(f1);
				break;
			}
		}
		s.push(f[i]);
	}
	//上凸壳
	for(int i=1;i<=n;i++){
		double x=f[i].first;
		double y=f[i].second;
		while(t.size()>1){
			pair<double,double> f1=t.top();
			t.pop();
			pair<double,double> f2=t.top();
			double x1=f1.first-f2.first;
			double y1=f1.second-f2.second;
			double x2=x-f1.first;
			double y2=y-f1.second;
			int temp=Fork(x1,y1,x2,y2);
			if(temp<0){
				t.push(f1);
				break;
			}
		}
		t.push(f[i]);
	}
	double ans=0;
	double curx,cury;
	curx=s.top().first;
	cury=s.top().second;
	s.pop();
	while(!s.empty()){
		double p=s.top().first;
		double q=s.top().second;
		s.pop();
		ans+=getDis(curx,cury,p,q);
		curx=p;
		cury=q;
	}
	curx=t.top().first;
	cury=t.top().second;
	t.pop();
	while(!t.empty()){
		double p=t.top().first;
		double q=t.top().second;
		t.pop();
		ans+=getDis(curx,cury,p,q);
		curx=p;
		cury=q;
	}
	cout<<ans;
	return 0;
}