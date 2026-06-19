#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int n,m,pt[509];
char c[509];
long long pai(int n, int get){
	long long tot = 1;
	while(get >= 1){
		tot *= n % mod;
		n--;
		get--;
	}
	return tot % mod;
}
bool is_check(int *a, char *c, int *pt){
	int get = 0;
	int not_get = 0;
	for(int i=0; i<n; i++){
		if(c[i] == '0'){
			not_get++;
		}else if(not_get >= pt[i]){
			not_get++;
		}else{
			get++;
		}
	}
	if(get >= m){
		return true;
	}else{
		return false;
	}
}
long long get_pai(int idx,int *a, char *c, int *pt, long long tot){
	if(idx >= n){
		if(is_check(a,c,pt)){
			tot++;
		}
		return tot;
	}
	for(int i=idx; i<n; i++){
		swap(a[idx],a[i]);
		swap(pt[idx],pt[i]);
		tot = get_pai(idx+1,a,c,pt,tot);
		swap(a[idx],a[i]);
		swap(pt[idx],pt[i]);
	}
	return tot;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	bool s1 = true;
	for(int i=0; i<n; i++){
		cin >> c[i];
		if(c[i] != '1'){
			s1 = false;
		}
	}
	for(int i=0; i<n; i++){
		cin >> pt[i];
	}
	if(s1){
		cout << pai(n,n) % mod << endl;
	}
	if(n <= 10){
		int a[10];
		for(int i=0; i<n; i++){
			a[i] = i;
		}
		cout << get_pai(0,a,c,pt,0) % mod << endl;
	}
	return 0;
}
