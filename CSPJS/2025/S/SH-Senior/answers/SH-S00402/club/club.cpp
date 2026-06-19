#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
int n;
ll maxcnt;
int a[200000],b[200000],c[200000];
void d(int t,ll cnt,int cnta,int cntb,int cntc){
	if(t==n+1){
		maxcnt=max(cnt,maxcnt);
		return;
	}
	if(cnta<n/2) d(t+1,cnt+a[t],cnta+1,cntb,cntc);
	if(cntb<n/2) d(t+1,cnt+b[t],cnta,cntb+1,cntc);
	if(cntc<n/2) d(t+1,cnt+c[t],cnta,cntb,cntc+1);
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		cin>>n;
		if(n<=10){
			maxcnt=0;
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i],&b[i],&c[i]);
			}
			d(1,0,0,0,0);
			printf("%ld\n",maxcnt);
			continue;
		}
		else{
			int cntb=0,cntc=0;
			ll cnt=0;
			priority_queue<pii> q;
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i],&b[i],&c[i]);
				q.push({max(b[i]-a[i],c[i]-a[i]),i});
				cnt+=a[i];
			}
			for(int i=1;i<=n/2;i++){
				pii t=q.top();
				q.pop();
				int idx=t.second;
				if(b[idx]>c[idx]&&cntb<n/2){
					cntb++;
					cnt+=b[idx]-a[idx];
				}
				else if(c[idx]-a[idx]>0&&cntc<n/2){
					cntc++;
					cnt+=c[idx]-a[idx];
				}
			}
			pii t=q.top();
			while(!q.empty()&&t.first>0){
				q.pop();
				int idx=t.second;
				if(b[idx]>c[idx]&&cntb<n/2){
					cntb++;
					cnt+=b[idx]-a[idx];
				}
				else if(c[idx]-a[idx]>0&&cntc<n/2){
					cntc++;
					cnt+=c[idx]-a[idx];
				}
				t=q.top();
			}
			printf("%ld\n",cnt);
			continue;
		}
	}
	return 0;
}
/*
1
30
6090 4971 4101
14495 19657 10011
6294 14948 17496
3266 18897 6963
3129 14412 12639
5331 7102 7590
12533 15635 16270
2339 16892 11211
6980 3113 19980
16859 13322 9404
16742 1573 8946
1285 5253 2697
18072 16412 5595
15870 17311 7711
19194 4644 11192
1306 6558 10317
11128 16814 5947
1603 6202 15251
4014 5797 2498
1557 4235 12431
1561 16149 16433
9399 1760 809
13383 18379 10169
7679 4131 17310
2900 8148 13627
14783 19510 17642
19717 4666 6335
9868 5451 19561
11196 1774 11436
10753 10148 6994
*/
