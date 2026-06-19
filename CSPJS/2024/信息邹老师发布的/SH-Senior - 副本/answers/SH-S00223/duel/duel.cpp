#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n, a[100005];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	
	int head = 0;
	int tail = 1;
	while (tail < n){
		while (a[tail] <= a[head] and tail < n) tail ++;
		if (tail >= n) break;
		head ++;
		tail ++;
	}
	
	int ans = tail - head;
	cout << ans;
	
	return 0; 
}
