#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1317;
int n,a[N],tot=1,cnt;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]>a[tot]){
			cnt--;
			tot++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
/*
我永远喜欢珂朵莉
2024-S-T1
这题感觉比较一眼
+100？ 
*/
