#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int t,n,k,q,rj,cj;
char c;
bool flag;
string S[100001],s;
int l[100001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++){
				cin>>c;
				S[i]+=c;
			}
			cout<<S[i];
		}
		for(int j=1;j<=q;j++){
			flag=false;
			scanf("%d%d",&rj,&cj);
			for(int i=1;i<=n;i++){
				if(S[i].find('1')!=-1 && S[i].find(char(cj+'0'),S[i].find('1')+1)!=-1 && S[i].find(char(cj+'0'),S[i].find('1')+1)-S[i].find('1')+1<=k)flag=true;
			}
			if(flag)printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
