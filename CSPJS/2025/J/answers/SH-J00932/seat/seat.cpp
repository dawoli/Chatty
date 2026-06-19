#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool v[110][110];
ll n,m,a[10010],x,i=1,j=0,idx=0;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(1){
		if(a[idx]==x&&idx>0){
			printf("%lld %lld",i,j);
			break;
		}
		if(!v[i][j+1]&&j+1<=n){
			j++;
			v[i][j]=1;
			idx++;
		}
		else if(!v[i][j-1]&&j-1>=1){
			j--;
			v[i][j]=1;
			idx++;
		}
		else if(j+1==n+1){
			i++;
			v[i][j]=1;
			idx++;
		}
		else if(j-1==0){
			i++;
			v[i][j]=1;
			idx++;
		}
	}
	return 0;
}
