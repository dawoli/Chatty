#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1[200005],a2[200005],b1[200005],b2[200005],num[200005];
const int mod1=1000000007,mod2=1000000009;
int tmp,tmp1;
string s1,s2;
int hshs1[200005],hshs2[200005],hss1[200005],hss2[200005];
void hsh(string s){
	tmp=0,tmp1=0;
	for(int i=0;i<s.length();i++){
		tmp=(tmp%mod1*233%mod1+s[i]-'0')%mod1;
		tmp1=(tmp1%mod2*1009%mod2+s[i]-'0')%mod2;
	}
}
void hsh2(){
	hshs1[1]=s1[0]-'0';
	hss1[1]=s1[0]-'0';
	for(int i=2;i<=s1.length();i++){
		hshs1[i]=(hshs1[i-1]%mod1*233%mod1+s1[i-1]-'0')%mod1;
		hss1[i]=(hss1[i-1]%mod2*1009%mod2+s1[i-1]-'0')%mod2;
	}
	hshs2[1]=s2[0]-'0';
	hss2[1]=s2[0]-'0';
	for(int i=2;i<=s2.length();i++){
		hshs2[i]=(hshs2[i-1]%mod1*233%mod1+s2[i-1]-'0')%mod1;
		hss2[i]=(hss2[i-1]%mod2*1009%mod2+s2[i-1]-'0')%mod2;
	}
}
int fz1[200005],fz2[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	fz1[0]=1;
	fz2[0]=1;
	for(int i=1;i<=n;i++){
		fz1[i]=(fz1[i-1]%mod1*233%mod1);
		fz2[i]=(fz2[i-1]%mod2*1009%mod2);
	}
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		hsh(s1);
		a1[i]=tmp,a2[i]=tmp1;
		num[i]=s1.length();
		hsh(s2);
		b1[i]=tmp,b2[i]=tmp1;
	}
	while(q--){
		cin>>s1>>s2;
		hsh2();
		int ans=0;
		if(s1.length()!=s2.length()){
			cout<<"0"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j+num[i]-1<=s1.length();j++){
				if((hshs1[j+num[i]-1]%mod1-hshs1[j-1]%mod1*fz1[num[i]]%mod1)%mod1==a1[i]){
					if((hss1[j+num[i]-1]%mod2-hss1[j-1]%mod2*fz2[num[i]]%mod2)%mod2==a2[i]){
					    int t1=s1.length()-(j+num[i]-1);
					    if((hshs1[s1.length()]-fz1[t1]*a1[i]%mod1+fz1[t1]*b1[i]%mod1)%mod1==hshs2[s1.length()]){
					    	if((hss1[s1.length()]-fz2[t1]*a2[i]%mod1+fz2[t1]*b2[i]%mod1)%mod2==hss2[s1.length()]){
					    	    ans++;
						    }
						}
				    }
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
