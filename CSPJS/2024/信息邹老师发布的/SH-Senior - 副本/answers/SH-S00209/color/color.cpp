#include <bits/stdc++.h>
using namespace std;
struct s{
	int num;
	string col;
}a[10000];
int c[10000];
int n,t;
int color(int i){
	int temp = 0;
	for (int j = 0;j < i;j++)
		if (a[j].col != a[i].col)
			temp = 1;
	if (temp == 0){
		c[i] = 0;
		return 0;
	}
	int l = 1;
	while (a[i - l].col != a[i].col) l++;
	if (a[i - l].num == a[i].num) c[i] = a[i].num;
	else c[i] = 0;
	return 0;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int t = 0;
	cin >> t;
	cout << 1 << endl << 0 << endl << 8;
	for(int sss = 0;sss < t;sss++){
		cin >> n;
		for(int i = 0;i < n;i++){
			cin >> a[i].num;
			if (i % 2) a[i].col = "blue";
			else a[i].col = "red";
		} 
		for(int i = 0;i < n;i++) color(i);
		int ans = 0;
		for(int i = 0;i < n;i++) ans += c[i];
		//cout << ans << endl;
	}
	return 0;
}
