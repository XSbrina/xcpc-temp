#include<bits/stdc++.h>
using namespace std;

//前缀函数计算
//aabaaab 的前缀函数为 [0,1,0,1,2,2,3]
vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}
//text:aabaaab  pattern:ab
//0-base return 1 5
vector<int> find_occurrences(string text, string pattern) {
	string cur = pattern + '#' + text;
	int sz1 = text.size(), sz2 = pattern.size();
	vector<int> v;
	vector<int> lps = prefix_function(cur);
	for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
		if (lps[i] == sz2) v.push_back(i - 2 * sz2);
	}
	return v;
}