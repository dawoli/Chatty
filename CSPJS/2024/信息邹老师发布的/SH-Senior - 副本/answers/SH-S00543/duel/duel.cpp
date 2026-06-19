#include <bits/stdc++.h>
using namespace std;

int n, cnt, ans;
int r[100005];
struct node{
	int num, size;
} a[100005];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout); 
	
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d", &r[i]);
	}
	
	sort(r, r + n);
	
	a[cnt].num = r[0];
	a[cnt].size = 1;
	
	for(int i = 1; i < n; i++){
		if(r[i] == r[i - 1]){
			a[cnt].size++;
		}
		else{
			cnt++;
			a[cnt].num = r[i];
			a[cnt].size = 1;
		}
	}
	
	ans = n;
	
	for(int i = 1; i <= cnt; i++){
		int mins = min(a[i].size, a[i - 1].size);
		ans -= mins;
		a[i - 1].size -= mins;
		a[i].size += a[i - 1].size;
		a[i - 1].size = 0;
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
