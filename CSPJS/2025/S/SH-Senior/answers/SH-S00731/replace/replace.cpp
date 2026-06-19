#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
struct node{
	string s1,s2;
}s[maxn],t[maxn];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].s1>>t[i].s2;
	}
	for(int j=1;j<=q;j++){
		if(t[j].s1.size()!=t[j].s2.size())printf("0\n"); 
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				if(t[j].s1.find(s[i].s1)<=5e6+10){
					int st=t[j].s1.find(s[i].s1),len=s[i].s1.size();
					for(int k=st;k<=st+len-1;k++)t[j].s1[k]=s[i].s2[k-st];
					if(t[j].s1==t[j].s2)ans++;
					for(int k=st;k<=st+len-1;k++)t[j].s1[k]=s[i].s1[k-st];
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
