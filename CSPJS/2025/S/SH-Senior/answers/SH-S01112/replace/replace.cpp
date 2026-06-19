#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pb emplace_back
const int P=998244353;
int n,q;
char s[5000005],t[5000005];
namespace Sub1{
	ull ks[5000005];
	int l[200005],r[200005],len[200005];
	vector<ull> has[200005],hat[200005];
	ull hss[5000005],hst[5000005];
	inline ull calc(int id,int p,int q,int op){
		if(op==0){
			if(id==-1)return hss[q]-hss[p-1]*ks[q-p+1];
			else return has[id][q]-has[id][p-1]*ks[q-p+1]; 
		}else{
			if(id==-1)return hst[q]-hst[p-1]*ks[q-p+1];
			else return hat[id][q]-hat[id][p-1]*ks[q-p+1];
		}
	}
	void work(){
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			scanf("%s",t+1);
			len[i]=strlen(s+1);
			int ll=1,rr=len[i];
			while(ll<=len[i] && s[ll]==t[ll])ll++;
			while(rr>=1 && s[rr]==t[rr])rr--;
			l[i]=ll;r[i]=rr;
			ull sum=0;
			has[i].pb(sum);
			for(int j=1;j<=len[i];j++){
				sum=sum*P+s[j]-'a'+1;
				has[i].pb(sum);
			}
			sum=0;
			hat[i].pb(sum);
			for(int j=1;j<=len[i];j++){
				sum=sum*P+t[j]-'a'+1;
				hat[i].pb(sum);
			}
		}
		ks[0]=1;for(int i=1;i<=(int)5e6;i++)ks[i]=ks[i-1]*P;
		for(int i=1;i<=q;i++){
			scanf("%s%s",s+1,t+1);
			if(strlen(s+1)!=strlen(t+1)){
				printf("0\n");
				continue;
			}
			int lent=strlen(s+1);
			for(int j=1;j<=lent;j++){
				hss[j]=hss[j-1]*P+s[j]-'a'+1;
				hst[j]=hst[j-1]*P+t[j]-'a'+1;
			}
			int ll=1,rr=lent;
			while(s[ll]==t[ll])ll++; 
			while(s[rr]==t[rr])rr--;
			int sum=0;
			for(int j=1;j<=n;j++){
				if(l[j]<=len[j] && rr-ll==r[j]-l[j] &&
				   calc(-1,ll,rr,0)==calc(j,l[j],r[j],0) &&
				   calc(-1,ll,rr,1)==calc(j,l[j],r[j],1) && 
				   ll>=l[j] && lent-rr>=len[j]-r[j] && 
				   calc(-1,ll-l[j]+1,ll-1,0)==calc(j,1,l[j]-1,0) &&
				   calc(-1,rr+1,len[j]-r[j]+rr,0)==calc(j,r[j]+1,len[j],0))
				sum++;
			}
			printf("%d\n",sum);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n<=10000 && q<=10000)Sub1::work();
	else if(q==1)Sub1::work();
	return 0;
}
