#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
struct node{
	int e1,e2,e3;
}a[MAXN];
bool cmp(node x,node y){
	return x.e1 > y.e1;
}
int n,t,sum,maxn,maxn1;
bool flag2,flag3;
void dfs(int d1,int d2,int sum,int i){
	if(i == n+1 || d1 > n/2 || d2 > n/2){
		maxn = max(maxn,sum);
		return ;
	}
	dfs(d1+1,d2,sum+a[i].e1,i+1);
	dfs(d1,d2+1,sum+a[i].e2,i+1);
}
void dfs11(int d11,int d21,int d31,int sum1,int i1){
	if(i1 == n+1 || d11 > n/2 || d21 > n/2 || d31 > n/2){
		maxn1 = max(maxn1,sum1);
		return ;
	}
	dfs11(d11+1,d21,d31,sum1+a[i1].e1,i1+1);
	dfs11(d11,d21+1,d31,sum1+a[i1].e2,i1+1);
	dfs11(d11,d21,d31+1,sum1+a[i1].e3,i1+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		maxn = 0,sum = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].e1 >> a[i].e2 >> a[i].e3;
			if(a[i].e2 != 0) flag2 = false;
			if(a[i].e3 != 0) flag3 = false;
		}
		if(n == 2){
			cout << max(max(max(max(max(a[1].e1+a[2].e2,a[1].e1+a[2].e3),a[1].e2+a[2].e1),a[1].e2+a[2].e3),a[1].e3+a[2].e1),a[1].e3+a[2].e2);
			return 0;
		}
//		if(n == 4){
//			long long w11 = a[1].e1;
//			long long w22 = a[1].e2;
//			long long w33 = a[1].e3;
//			long long x11 = a[2].e1;
//			long long x22 = a[2].e2;
//			long long x33 = a[2].e3;
//			long long y11 = a[3].e1;
//			long long y22 = a[3].e2;
//			long long y33 = a[3].e3;
//			long long z11 = a[4].e1;
//			long long z22 = a[4].e2;
//			long long z33 = a[4].e3;
//			cout << max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(w11+x11+y22+z22,w11+x11+y22+z33),w11+x11+y33+z22),w11+x11+y33+z33),w11+x22+y11+z22),w11+x22+y11+z33),w11+x22+y22+z11),w11+x22+y22+z33),w11+x22+y33+z11),w11+x22+y33+z22),w11+x22+y33+z33),w11+x33+y11+z22),w11+x33+y11+z33),w11+x33+y22+z11),w11+x33+y22+z22),w11+x33+y22+z33),w11+x33+y33+z11),w11+x33+y33+z22),w22+x11+y11+z22),w22+x11+y11+z33),w22+x11+y22+z11),w22+x11+y22+z33),w22+x11+y33+z11),w22,x11,y33,z22),w22+x11+y33+z33),w22+x22+y11+z11),w22+x22+y11+z33),w22+x22+y33+z11),w22+x22+y33+z33),w22+x33+y11+z11),w22+x33+y11+z22),w22+x33+y11+z33),w22+x33+y22+z11),w22+x33+y22+z33),w22+x33+y33+11),w22+x33+y33+z22),w33+x11+y11+z22)w33+x11+y11+z33)w33+x11+y22+z11),w33+x11+y22+z22),w33+x11+y22+z33),w33+x11+y33+z11),w33+x11+y33+z22),w33+x22+y11+z11),w33+x22+y11+z22),w33+x22+y11+z33),w33+x22+y22+z11),w33+x22+y22+z33),w33+x22+y33+z11),w33+x22+y33+z22),w33+x33+y11+z11),w33+x33+y11+z22),w33+x33+y22+z11),w33+x33+y22+z22);
//			return 0;
//		}
		else if(flag2 == true || flag3 == true){
			sort(a+1,a+n+1,cmp);
			for(int i = 1;i <= n/2;i++) sum += a[i].e1; 
			cout << sum;	
			return 0;	
		}
		else if(flag3 == true){
			dfs(0,0,0,1);
			cout << maxn;
			return 0;
		}
		else{
			dfs11(0,0,0,0,1);
			cout << maxn1;
		}
	} 
	return 0;
}
