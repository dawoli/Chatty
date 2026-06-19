#include <bits/stdc++.h>

using namespace std;

int n,x;
int a[100001]={0};
int canAttack[100001]={0};
int m=0;
int ans;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	ans=n;
	for(register int i=1;i<=n;i++){
		scanf("%d",&x);
		m=max(m,x);
		a[x]++;
		canAttack[x]++;
	}
	
	x=0;
	while(a[x] == 0){
		x++;
	}
	
	for(register int findN=x+1;findN<=m;){
		while(canAttack[findN] == 0 || findN<=x){
			findN++;
		}
		if(findN>m){
			break;
		}
		if(canAttack[findN]>=a[x]){
			//cout<<x<<" "<<a[x]<<" "<<findN<<" "<<canAttack[findN]<<endl;
			canAttack[findN]-=a[x];
			ans-=a[x];
			a[x]=0;
			while(a[x] == 0){
				x++;
			}
		} else{
			//cout<<x<<" "<<a[x]<<" "<<findN<<" "<<canAttack[findN]<<endl;
			ans-=canAttack[findN];
			a[x]-=canAttack[findN];
			canAttack[findN]=0;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
