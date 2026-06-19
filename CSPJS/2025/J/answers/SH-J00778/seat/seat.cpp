#include<bits/stdc++.h>
using namespace std;

int n,m,a[505],r,t,ansc,ansr;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			r=i;
			break;
		}
	}
	int f=r/(2*m);
	if(r%(m*2)>m) ansc=f*2+2,ansr=m-(r%(2*m)-m)+1;
	else ansc=f*2+1,ansr=r%(2*m);
	cout<<ansc<<' '<<ansr<<endl; 
	return 0;
}
