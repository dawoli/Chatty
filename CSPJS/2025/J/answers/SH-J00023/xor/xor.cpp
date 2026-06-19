#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
int e[15];
int a[MAXN];
bool flag = true;
int cnt1 = 0,last,oi,cnt = 0;
struct node{
	int l,r;
}ans[MAXN];
bool cmp(node x,node y){
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
int twoo(int x){
	memset(e,-1,sizeof(e));
	int i = 1,sum = 0;
	while(x > 0){
		if(x % 2 == 0) e[i] = 0;
		else e[i] = 1;
		x /= 2;
		i++;
	}
	for(int j = 1;j <= i-1;j++){
		if(e[j] >= 0) sum += e[j] * pow(10,j-1);
	}
	return sum;
}
int tenn(int x){
	int summm = 0,i = 0;
	while(x > 0){
		summm += (x % 10) * pow(2,i);
		x /= 10;
		i++;
	}
	return summm;
}
int xxor(int x,int y){
	string s1,s2;
	int summ = 0;
	while(x > 0){
		if(x % 10 == 1) s1 += '1';
		else s1 += '0';
		x /= 10;
	}
	while(y > 0){
		if(y % 10 == 1) s2 += '1';
		else s2 += '0';		
		y /= 10;
	}
	int lens = max(s1.size(),s2.size());
	for(int i = 0;i < lens;i++){
		if(s1[i] != s2[i]) summ += 1*pow(10,i);
	}
	return summ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;

	for(int i = 1;i <= n;i++){
		int num;
		cin >> num;
		a[i] = twoo(num);
		if(num == 1){
			cnt1++;
			flag = true;
		}
		else flag = false; 
	}
	if(k == 0 && flag == true){
		cout << n / 2;
		return 0;
	}
	if(k == 1){
		cout << cnt1;
		return 0;
	}	
	for(int r = 1;r <= n;r++){
		for(int l = 1;l <= r;l++){
			oi = 0;
			if(l == r){
				if(l == k){
					cnt++;
					ans[cnt].l = l;
					ans[cnt].r = l;
				}
				continue;
			}
			oi = a[l]; 
			for(int i = l;i <= r;i++) oi = xxor(oi,a[i]);
			if(tenn(oi) == k){
				cnt++;
				ans[cnt].l = l;
				ans[cnt].r = r;
			}
		}
	}
	sort(ans+1,ans+cnt+1,cmp);
	
	return 0;
}
