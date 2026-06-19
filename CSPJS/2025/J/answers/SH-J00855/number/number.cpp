#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int num[10]={0}, n = 0;
	char s[1000010];
	char a = getchar();
	while (a != '\n'){
		s[n] = a;
		n++;
		a = getchar();
	}
	for (int i =0;i<n;++i){
		if (s[i]>='0' && s[i] <= '9'){
			int b = s[i] - '0';
			num[b]++;
		}
	}
	for (int i=9;i>=0;--i){
		for (int cnt = 0;cnt < num[i];++cnt){
			cout<<i;
		}
	}
	return 0;
}
 
