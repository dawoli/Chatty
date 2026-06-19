#include<bits/stdc++.h>
using namespace std;
struct sage{
	int r;
	bool jg=false,sm=false;
}a[100005];
bool cmp(sage a,sage b){
	if(a.r==b.r) return a.sm>b.sm;
	return a.r<b.r;
}
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].r);
	sort(a+1,a+n+1,cmp);
	while(true){
		int t=1;
		int cnt=0;
		bool flag=0;
		for(int i=2;i<=n;i++){
			if(a[i].r>a[t].r&&!a[t].sm){
				if(a[i].jg==1||a[i].sm==1){
					if(!flag) flag=1,t=i-1;
				}
				else{
					a[t].sm=1,a[i].jg=1;
					a[t].r=a[i].r;
					cnt++;
					break;
				}
			}
			if(!flag) t=i;
		}
		flag=0;
		for(int i=1;i<=n;i++){
			if(a[i].sm==0&&a[i].jg==0){
				flag=true;
				break;
			}
		}
		if(!flag||!cnt) break;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!a[i].sm) cnt++;
	}
	cout<<cnt;
	return 0;
}
