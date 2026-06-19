#include <bits/stdc++.h>
using namespace std;

map<int, int> p;
int n, temp, ans=0;

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (p.find(temp) == p.end()) {
			p[temp] = 1;
		} else {
			p[temp]++;
		}
	}
	
	for (map<int,int>::iterator i = p.begin(); i != p.end(); i++) {
		if (ans < (i->second)) ans = i->second;
	}
	printf("%d\n", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
