#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int r[N];
int r1[N]={0};
bool r2[N]={0};//©иртсц 
int cnt=0;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	sort(r+1,r+1+n);
	int cnt=0;
	for(int i=1,j=i-1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(r[i]<r[j]&&r2[j]==0){
				r2[j]=1;//r1[i]=1;
				cnt++;
				break;
			}
		}
	}
	printf("%d",n-cnt);
	return 0;
}

