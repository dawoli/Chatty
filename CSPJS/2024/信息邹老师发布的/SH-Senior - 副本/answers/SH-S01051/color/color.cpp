#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull T, n, a[200005], mx;
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		mx = 0;
		for(ull j = 0;j < 1<<(n-1);j++){
			ull lr = 0, lb = 0, ans = 0;
			for(int k = 1;k <= n;k++){
				bool tmp = (j>>(k-1)) & 1;
				if(tmp){
					if(a[lr] == a[k]) ans += a[k];
					lr = k;
				}else{
					if(a[lb] == a[k]) ans += a[k];
					lb = k;
				}
			}
			mx = max(mx, ans);
		}
		cout<<mx<<endl;
	}
	return 0;
}
