#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>num[200008];
int n,q,l,a1,a2,ans,l1,l2;
char s1[5000008],s2[5000008];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%s%s",s1,s2);
		l=strlen(s1);
		for(int j=0;j<l;j++) if(s1[j]=='b'){
			a1=j;
			break; 
		}
		for(int j=0;j<l;j++) if(s2[j]=='b'){
			a2=j;
			break; 
		}
		num[l].push_back({a1,a2});
	}
	while(q--){
		scanf("%s%s",s1,s2);
		l1=strlen(s1),l2=strlen(s2);
		if(l1!=l2){
			printf("0\n");
			continue;
		}
		l=l1;
		for(int j=0;j<l;j++) if(s1[j]=='b'){
			a1=j;
			break; 
		}
		for(int j=0;j<l;j++) if(s2[j]=='b'){
			a2=j;
			break; 
		}
		for(int j=2;j<=l;j++) for(int k=0;k<num[j].size();k++)
			if(num[j][k].first<=a1&&a1-num[j][k].first<=l-j&&num[j][k].first-num[j][k].second==a1-a2)
				ans++;
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
