#include<stdio.h>
int main(){
	unsigned long long a,b,c,ans=1;
	scanf("%llu%llu%llu",&a,&b,&c);
	
	while(b>0){
		if(b%2==1) ans=(ans*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	printf("%llu",ans);
	return 0;
}
