#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int t,n,ans;
int num[3];
int sel[maxn];
int a[3][maxn];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t --){
		ans = 0;
		num[0] = num[1] = num[2] = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++){
			scanf("%d %d %d",&a[0][i],&a[1][i],&a[2][i]);
		}
		for(int i = 1;i <= n;i ++){
			int mx = max(a[0][i],max(a[1][i],a[2][i]));
			if(mx == a[0][i]){
				sel[i] = 0;	num[0] ++;
				ans += a[0][i];
			}else if(mx == a[1][i]){
				sel[i] = 1;	num[1] ++;
				ans += a[1][i];
			}else{
				sel[i] = 2; num[2] ++;
				ans += a[2][i];
			}
		}
		if(num[0] > n / 2 || num[1] > n / 2 || num[2] > n / 2){
			int v = 0;
			if(num[1] > n / 2)	v = 1;
			else if(num[2] > n / 2)	v = 2;
			if(v > 0){
				swap(num[0],num[v]);
				swap(a[0],a[v]);
				for(int i = 1;i <= n;i ++){
					if(sel[i] == 0)	sel[i] = v;
					else if(sel[i] == v)	sel[i] = 0;
				}
			}
			priority_queue<int> pq; 
			for(int i = 1;i <= n;i ++){
				if(sel[i] == 0)	pq.push(max(a[1][i],a[2][i]) - a[0][i]);
			}
			for(int i = 1;i <= num[0] - n / 2;i ++){
				ans += pq.top();
				pq.pop();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
