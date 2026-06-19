#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1370000007,n,q,st[137010],ed[137010],len[137010],hsh1[137010],hsh2[137010],p137[2000010]={1,137},sum1[2000010],sum2[2000010];
char s1[2000010],s2[2000010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=2;i<=2000000;i++)
		p137[i]=p137[i-1]*137%mod;
//	if(q==1||n<=13700){
		for(int i=0;i<n;i++){
			scanf("%s%s",s1,s2);
			len[i]=strlen(s1);
			for(int j=0;j<len[i];j++)
				if(s1[j]!=s2[j]){
					st[i]=j-1;
					break;
				}
			for(int j=len[i]-1;j>=0;j--)
				if(s1[j]!=s2[j]){
					ed[i]=j+1;
					break;
				}
			for(int j=0;j<len[i];j++){
				hsh1[i]=(hsh1[i]*137+s1[j]-'a'+1)%mod;
				hsh2[i]=(hsh2[i]*137+s2[j]-'a'+1)%mod;
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%s%s",s1,s2);
			int s,e;
			int l=strlen(s1);
			for(int j=0;j<l;j++)
				if(s1[j]!=s2[j]){
					s=j-1;
					break;
				}
			for(int j=l-1;j>=0;j--)
				if(s1[j]!=s2[j]){
					e=j+1;
					break;
				}
			sum1[0]=s1[0]-'a'+1;
			sum2[0]=s2[0]-'a'+1;
			for(int j=1;j<l;j++){
				sum1[j]=(sum1[j-1]*137+s1[j]-'a'+1)%mod;
				sum2[j]=(sum2[j-1]*137+s2[j]-'a'+1)%mod;
			}
			int ans=0;
			for(int j=0;j<n;j++){
//				cout<<endl;
				if(e-s!=ed[j]-st[j])
					continue;
//				if(i==101)
//				cout<<j;
				if(st[j]>s)
					continue;
//				if(i==101)
//				cout<<j;
				if(len[j]-ed[j]>l-e)
					continue;
//				if(i==101)
//				cout<<j<<" "<<hsh1[j]<<" "<<hsh2[j]<<" ";
				int h1=(sum1[e+len[j]-ed[j]-1]-(st[j]==s?0:sum1[s-st[j]-1])*p137[e-s-1]%mod+mod)%mod;
				int h2=(sum2[e+len[j]-ed[j]-1]-(st[j]==s?0:sum2[s-st[j]-1])*p137[e-s-1]%mod+mod)%mod;
//				if(i==101)
//				cout<<h1<<" "<<h2<<endl;
				if(h1==hsh1[j]&&h2==hsh2[j])
					ans++;
			}
			printf("%lld\n",ans);
		}
//	}
}
