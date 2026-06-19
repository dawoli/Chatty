#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	int p=n*m-1,k=0;
	while(1){
		if(a[p]==x){
			k=n*m+1-p;
			break;
		}
		p--;
	}
	if(k%m==0){
		cout<<k/m<<" ";
		if((k/m)%2==0){
			cout<<1;
			return 0;
		}
		else{
			cout<<n;
			return 0;
		}
	}
	else{
		cout<<k/m+1<<" ";
		if((k/m)%2==0){
			cout<<k%m;
			return 0;
		}
		else{
			cout<<n+1-k%m;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
