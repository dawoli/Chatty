#include<bits/stdc++.h>
using namespace std;

int n,m,t,b,c,d,e,wz,hang,l;
int a[105];

bool cmp(int a1,int a2){
	return a1>a2;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(b==a[i]){
			wz=i;
			break;
		}
	}
	hang=(wz-1)/n+1;
	if(hang%2==1){
		l=(wz-1)%n+1;
	}else{
		l=n-((wz-1)%n);
	}
	cout<<hang<<" "<<l;
	
	
	
	
	return 0;
}
