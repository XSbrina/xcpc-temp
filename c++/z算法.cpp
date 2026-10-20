#include<bits/stdc++.h>
using namespace std;
//𝑧(𝚊𝚊𝚊𝚋𝚊𝚊𝚋) =[0,2,1,0,2,1,0]
//𝑧(𝚊𝚋𝚊𝚌𝚊𝚋𝚊) =[0,0,1,0,3,0,1]
//i=1表示s.substr(i)和s的最长前缀，令z[0]=0
vector<int> z_function(string s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}