#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l;
struct ren{
	int a,b,c;
	int id,ca;
}re[100010];
int f[5],f1[10];
long long ans;
//int f[50010][50010];
bool cmp(ren o,ren p){
	return o.ca <p.ca;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i = 1;i <= t;i++){
		scanf("%d",&n);
		ans = 0;
		m = n / 2;
		f[1] = f[2] = f[3] = 0;
		for(int j = 1;j <= n;j++){
			scanf("%d%d%d",&re[j].a,&re[j].b,&re[j].c);
			if(re[j].a >= re[j].b){
				if(re[j].a >=re[j].c){
					re[j].id = 1;
					ans = ans + re[j].a;
					f[1]++;
					re[j].ca = re[j].a - max(re[j].b,re[j].c);
				}
				else{
					re[j].id = 3;
					ans = ans + re[j].c;
					f[3]++;
					re[j].ca = re[j].c - max(re[j].b,re[j].a);
				}
			}
			else{
				if(re[j].b >= re[j].c){
					re[j].id = 2;
					ans = ans + re[j].b;
					f[2]++;
					re[j].ca = re[j].b - max(re[j].c,re[j].a);
				}
				else{
					re[j].id = 3;
					ans = ans + re[j].c;
					f[3]++;
					re[j].ca = re[j].c - max(re[j].b,re[j].a);
				}
			}
//			cout << ans <<" " << re[j].id <<" " <<re[j].ca <<endl; 
		}
		if(f[1] > m){
			l = f[1];
			sort(re +1,re +n +1,cmp);
			for(int j = 1;j <= n;j++){
				if(re[j].id == 1){
					ans -= re[j].ca;
					l--;
				}
				if(l == m){
					break;
				}
			}
		}
		else if(f[2] > m){
			l = f[2];
			sort(re +1,re +n +1,cmp);
			for(int j = 1;j <= n;j++){
				if(re[j].id == 2){
					ans -= re[j].ca;
					l--;
				}
				if(l == m){
					break;
				}
			}
		}
		else if(f[3] > m){
			l = f[3];
			sort(re +1,re +n +1,cmp);
			for(int j = 1;j <= n;j++){
				if(re[j].id == 3){
					ans -= re[j].ca;
					l--;
				}
				if(l == m){
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
