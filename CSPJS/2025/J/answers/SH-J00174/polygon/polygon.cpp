#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD = 998244353;
const int N = 5010;
int n;
int a[N],aa[N];
bool cmp(int x,int y){
	return x < y;
}
/*
int f(int x,int sum){
	int cnt = 0;
	int acc = x - 2;
	for (int i = 1;i <= x;i++){
		if (aa[x]-a[i] > )
	}
}
* */
 
int main(){
	
    freopen64("polygon.in","w",stdin);
    freopen64("polygon.in","r",stdin);
    freopen64("polygon.out","w",stdout);
    
    cin >> n;
    memset(aa,0,sizeof(aa));
    for (int i= 1;i <= n;i++){
		cin >> a[i];
		aa[i] = a[i]+aa[i-1];
	}
	//n = 3 -> triangle -> 12'
	if (n < 3){
		cout << 0 << "\n";
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if (n == 3){
		if (a[2]-a[1] < a[3] && a[2]+a[1] > a[3]) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	/*
	if (n <= 20) // 1~10
	{
		long long ans = 0;
		for (int i = 1;i <= n;i++){
			if (aa[i-1] <= a[i]) continue;
			// > a[i]
			//1-i choose aXnum -> sum < m
			ans += f(i,)
		}
	}
	* */
	
	return 0;
}
