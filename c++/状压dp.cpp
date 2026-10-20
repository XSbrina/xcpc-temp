int dp[1<<22];
memset(dp,0,sizeof dp);
dp[0]=1;

for(int mask=0;mask < (1<<n);mask++){
    if(dp[mask]==0) continue; // 无法到达，跳过
    
    for(int u=0;u<n;u++){
        if(mask & (1<<u)) continue; // u已经选过
        
        if(满足选u的条件){
            dp[mask | (1<<u)] += dp[mask];
            dp[...] %= MOD;
        }
    }
}