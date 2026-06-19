#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//bool cho[5009];
//int n,ans,tmp,maxx,a[5009],sum[5009];
//void choose(int num,int x){
//	if(tmp > maxx * 2 && num >= 3)ans++;
//	if(x >= n)return;
//	cho[x] = 0;
//	choose(num,x + 1);
//	cho[x] = 1;maxx = maxa(x);tmp += a[x];
//	choose(num + 1,x + 1);
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	cin>>n;
//	for(int i = 0;i < n;i++)
//		cin>>a[i];
//	sort(a,a + n);
////	for(int i = 0;i < n;i++)
////		sum[i] = sum[i - 1] + a[i];
//	choose(0,0);
//	cout<<ans;
	int n;
	cin>>n;
	if(n == 1 || n == 2){
		cout<<0;
	}else if(n == 3){
		int ans,tmp,maxx;
		for(int i = 0;i < n;i++)
			cin>>tmp,maxx = max(tmp,maxx),ans += tmp;
		if(ans > tmp * 2)
			cout<<1;
		else
			cout<<0;
	} 
	return 0;
}
