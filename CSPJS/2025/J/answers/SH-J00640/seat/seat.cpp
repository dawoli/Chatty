#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],x,Num,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i;j>=1;j--){
			if(a[j]<=a[j+1]) swap(a[j],a[j+1]);
		}
	}
	
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			Num=i;
			break;
		}
	}
	if(Num%n==0) ans1=Num/n;
	else ans1=Num/n+1;
	
	if(ans1%2==1){
		ans2=Num-(ans1-1)*n;
	}
	else{
		ans2=n-(Num-(ans1-1)*n)+1;
	}
	cout<<ans1<<' '<<ans2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

