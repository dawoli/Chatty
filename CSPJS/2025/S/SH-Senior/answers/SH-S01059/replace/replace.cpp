#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define N 3005
#define M 676
//#define mod 998244353
int n,q;
int to[N][M];
int tot;
int cnt[N*M];
char s1[N],s2[N];
int a[N];
int hsh(int x,int y){
	return (x-'a')*26+(y-'a');
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		int p=0;
		for(int j=1;j<=len;j++){
			int nxt=hsh(s1[j],s2[j]);
			if(!to[p][nxt]) to[p][nxt]=++tot;
			p=to[p][nxt];
		}cnt[p]++;
	}
	while(q--){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1),l,r;
		if(len!=strlen(s2+1)) {
			printf("0\n");
			continue;
		}
		s1[len+1]=s2[len+1];
		for(int i=1;i<=len;i++)
			a[i]=hsh(s1[i],s2[i]);
		for(int i=1;i<=len;i++)
			if(s1[i-1]==s2[i-1]&&s1[i]!=s2[i]){
				l=i;break;
			}
		for(int i=len;i>=1;i--)
			if(s1[i+1]==s2[i+1]&&s1[i]!=s2[i]){
				r=i;break;
			}
	//b	cout<<l<<" "<<r<<endl;
		int ans=0;
		for(int i=1;i<=l;i++){
			int p=0;
			for(int j=i;j<=len;j++){
				if(!to[p][a[j]]){
					break;
				} 
				p=to[p][a[j]];
				if(j>=r) ans+=cnt[p];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
