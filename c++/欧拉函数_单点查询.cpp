//1 ~ i 中与 i 互质的整数个数，时间复杂度o(sqrt(n))
int jkl(int i){
	int ans=i;
	for(int j=2;j*j<=i;j++){
		if(i%j==0){
			while(i%j==0){
				i/=j;
			}
			ans-=ans/j;
		}
	}
	if(i>1){
		ans-=ans/i;
	}
	return ans;
}
