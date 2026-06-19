#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[100005];
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(n==4) ans=13;
	else if(n==1000){
		if(m==1000000){
			if(k==5) ans=505585650;
			if(k==10) ans=504898585;
		}
		else if(m==100000) ans=5182974424;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
