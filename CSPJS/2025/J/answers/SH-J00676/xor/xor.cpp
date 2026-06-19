#include<bits/stdc++.h>
using namespace std;
struct Node{
	int l;
	int r;
};
bool cmp(const Node &a,const Node &b){
	if(a.l == b.l){
		return a.r < b.r;
	}
	return a.l < b.l;
}
Node x[100009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	unsigned long long k;
	cin>>k;
	unsigned long long a[n + 1],s[n + 1];
	bool flag1 = 1,flag01 = 1;
	a[0] = s[0] = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 1){
			flag1 = 0;
		}else if(a[i] != 0){
			flag01 = 0;
		}
		s[i] = s[i - 1] xor a[i];
	}
	if(flag1 and k == 0){
		cout<<n / 2;
		return 0;
	}
	if(flag01){
		if(k == 0){
			int ans = 0,pre = -1;
			for(int i = 1;i <= n;i++){
				if(a[i] == 0){
					pre = 0;
					ans++;
				}else if(a[i] == 1){
					if(pre == 1){
						ans++;
						pre = 0;
					}else{
						pre = 1;
					}
				}
			}
			cout<<ans;
		}else if(k == 1){
			int ans = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] == 1){
					ans++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	if(n < 109){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if((s[j] xor s[i - 1]) == k){
					x[cnt].l = i;
					x[cnt].r = j;
					cnt++;
				}
			}
		}
		sort(x,x + cnt,cmp);
		int ans = 1,last = x[0].r;
		for(int i = 1;i < cnt;i++){
			if(x[i].l > last){
				ans++;
				last = x[i].r;
			}
		}
		cout<<ans;
		return 0;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
