#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n*m];cin>>a[0];int cnt=1;
	for(int i=1;i<n*m;i++){
		cin>>a[i]; if(a[i]>a[0]) cnt++;
	} 
	int li=(cnt-1)/n+1;
	int le=cnt-n*(li-1);
	int le2;
	if(li%2==1){
		le2=le;
	}else{
		le2=m-le+1;
	}
	cout<<li<<" "<<le2<<endl;
	return 0;
}
