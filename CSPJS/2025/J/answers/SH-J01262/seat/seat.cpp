#include<bits/stdc++.h>
using namespace std;
int a[110];

bool cmp(int num1,int num2){
	return num1>num2;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q,q_pos,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) q=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			q_pos=i;
			break;
		}
	}
	if(q_pos%n==0){
		if((q_pos/n)%2==0) c=q_pos/n,r=1;
		else c=q_pos/n,r=n;
	}else{
		if((int)ceil(q_pos*1.0/n)%2==0) c=ceil(q_pos*1.0/n),r=n+1-(q_pos%n);
		else c=ceil(q_pos*1.0/n),r=q_pos%n;
	}
	cout<<c<<' '<<r;
	return 0;
}

