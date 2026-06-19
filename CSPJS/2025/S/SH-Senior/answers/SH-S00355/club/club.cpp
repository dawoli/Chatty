#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,cnt[4],ha[100009],ans;
struct peo{
	int a,b,c,d,m,p;	//d=最大-第二大 
}h[100009];
void work(int x){
	int temp[4];
	temp[1]=h[x].a;
	temp[2]=h[x].b;
	temp[3]=h[x].c;
	sort(temp+1,temp+4);
	h[x].d=temp[3]-temp[2];
	h[x].m=temp[3];
	if (h[x].m==h[x].a){
		cnt[1]++;
		h[x].p=1;
	}
	else if (h[x].m==h[x].b){
		cnt[2]++;
		h[x].p=2;
	}
	else if (h[x].m==h[x].c){
		cnt[3]++;
		h[x].p=3;
	}
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&h[i].a,&h[i].b,&h[i].c);
			work(i);
			ans+=h[i].m;
		}
		int max_cnt=max(cnt[1],max(cnt[2],cnt[3]));
		int max_num=0;
		if (max_cnt==cnt[1]) max_num=1;
		else if (max_cnt==cnt[2]) max_num=2;
		else if (max_cnt==cnt[3]) max_num=3;
		int k=max_cnt-n/2;
		if (k>0){
			int top=0;
			for(int i=1;i<=n;i++){
				if (h[i].p==max_num){
					top++;
					ha[top]=h[i].d;
//					cout<<top<<' '<<ha[top]<<endl;
				}
			}
			sort(ha+1,ha+top+1);
			for(int i=1;i<=k;i++) ans-=ha[i];
		}
		cout<<ans<<endl;
		for(int i=1;i<=100005;i++) ha[i]=0;
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++) h[i].a=h[i].b=h[i].c=h[i].d=h[i].m=h[i].p=0;
	}
	return 0;
} 
