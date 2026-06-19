#include<bits/stdc++.h>
#define N ((int)(5e6)+10)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,q;
string s1[N],s2[N];
string l1,l2;
ull pw[N];
ull hashs1[N],hashs2[N];
ull hashl1[N],hashl2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*127;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i],s2[i]=" "+s2[i];
		ull pw_=127;
		for(int j=1;j<s1[i].size();j++)hashs1[i]+=s1[i][j]*pw_,pw_*=127;
		pw_=127;
		for(int j=1;j<s2[i].size();j++)hashs2[i]+=s2[i][j]*pw_,pw_*=127;
	}
	while(q--){
		cin>>l1>>l2;
		l1=" "+l1,l2=" "+l2;
		ull pw_=127;
		for(int i=1;i<l1.size();i++)hashl1[i]=hashl1[i-1]+l1[i]*pw_,pw_*=127;
		pw_=127;
		for(int i=1;i<l2.size();i++)hashl2[i]=hashl2[i-1]+l2[i]*pw_,pw_*=127;
		int ans=0;
		for(int i=1;i<=n;i++){
			bool flag=0;
			for(int j=1;j<=l1.size()-s1[i].size()+1;j++){
				ull nums1=hashs1[i];
				ull nums2=hashs2[i];
				ull numl1=hashl1[j+s1[i].size()-2]-hashl1[j-1];
				if(nums1*pw[j-1]==numl1&&hashl1[l1.size()-1]-numl1+nums2*pw[j-1]==hashl2[l2.size()-1]){
					flag=1;
					break;
				}
			}
			ans+=flag;
		}
		printf("%d\n",ans);
	}
}

