#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long mp[110];
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>mp[i];
	}
	k=mp[1];
	sort(mp+1,mp+n*m+1,cmp);
	for(int i=1; i<=n*m; i++){
		if(mp[i]==k){
			k=i;
			break;
		}
	}
	if(k%n==0){
		if((k/n)%2==0) cout<<k/n<<" "<<1;
		else cout<<k/n<<" "<<n;
	}else{
		if((k/n)%2==0) cout<<k/n+1<<" "<<k%n;
		else cout<<k/n+1<<" "<<n-k%n+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
