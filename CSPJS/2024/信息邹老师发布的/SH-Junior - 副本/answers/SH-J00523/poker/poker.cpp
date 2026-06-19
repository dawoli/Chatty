#include<bits/stdc++.h>
using namespace std;
int n,cnt[53],ans=52;
char s[7],p[140],q[140];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n),p['S']=1,p['D']=2,p['H']=3,p['C']=4;
	for(int w='2';w<='9';w++)q[w]=w-'0';
	q['T']=10,q['J']=11,q['Q']=12,q['K']=13,q['A']=1;
	for(int w=1;w<=n;w++)scanf("%s",s),cnt[(p[s[0]]-1)*13+q[s[1]]]=1;
	for(int w=1;w<=52;w++)ans-=cnt[w];
	printf("%d",ans);
	return 0;
}
