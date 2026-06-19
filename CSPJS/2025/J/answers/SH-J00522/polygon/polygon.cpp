#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=0,sum=1;
int n,t,tot=0;
int a[5005],cnt[5005],edge[5005],an[5005],used[5005];
//int pic[5005];
void f(int e,int c,int ma,int num){//e,benlunzaizhao,c,ma,xianzaiyiyou,num,shangciyonglenatiaobian
	if(e>3 && c>ma*2){
		sum=1;
		for(int i=1;i<e;i++){
			sum*=an[i];
			//cout<<pic[i]<<" ";
		}
		//cout<<endl;
		for(int i=1;i<e;i++){
			sum/=used[i];
			//cout<<used[i]<<" ";
		}
		//cout<<endl;
		sum%=998244353;
		ans+=sum;
		ans%=998244353;
	}
	if(e>n)return;
	for(int i=num;i<tot;i++){
		if(cnt[edge[i]]>0){
			an[e]=cnt[edge[i]];
			cnt[edge[i]]--;
			used[e]=(a[edge[i]]-cnt[edge[i]]);
			//pic[e]=edge[i];
			f(e+1,c+edge[i],max(ma,edge[i]),i);
			//pic[e]=0;
			used[e]=1;
			cnt[edge[i]]++;
			an[e]=1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		a[t]++;
		cnt[t]++;
	}
	for(int i=1;i<=5000;i++){
		used[i]=1;
		an[i]=1;
		if(a[i]!=0){
			edge[tot]=i;
			tot++;
		}
	}
	if(a[1]==n){
		int s=1;
		for(int i=3;i<=n;i++){
			s=1;
			for(int j=n;j>n-i;j--){
				s*=j;
				s/=(n-j+1);
			}
			s%=998244353;
			ans+=s;
			ans%=998244353;
		}
		printf("%llu\n",ans);
		return 0;
	}
	f(1,0,0,0);
	printf("%llu\n",ans);
	return 0;
}
/*
5
1 2 3 4 5
*/
