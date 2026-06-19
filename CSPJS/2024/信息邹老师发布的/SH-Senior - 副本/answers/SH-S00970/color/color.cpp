#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int score;
int a[200005];
int c[200005];
int finded[200005];
int f=0;

bool repeat(int n){
	for (int i=1; i<n; i++){
		if (a[i]==a[i+1]) return true;
	}
	return false;
}

bool onevalue(int ind){
	int value=a[ind];
	for (int i=1; i<=n; i++){
		if (a[i]!=value) return false;
	}
	return true;
}

int getam(int ind){
	for (int i=1; i<=f; i++){
		if (ind==finded[i]) return 0;
	}
	int ans=0;
	int value=a[ind];
	for (int i=1; i<=n; i++){
		if (a[i]==value) ans++;
	}
	f++;
	finded[f]=ind;
	return ans;
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	for (int i=1; i<=t; i++){
		score = 0;
		cin >> n;
		for (int j=1; j<=n; j++){
			cin >> a[j];
		}
		// main
		if (!repeat(n)){
			cout << 0 << endl;
			continue;
		}
		// convert only same
		sort(a,a+n);
		for (int j=1; j<=n; j++){
			if (!onevalue(j)){
				score += (getam(j)/2)*a[j];
			}
		}
}
	return 0;
}

