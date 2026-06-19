#include<bits/stdc++.h>
using namespace std;
int n,m,T,answerr=1;
int a[100005],c[100005],a2[100005];
int shuju[10005][5];
char chouqian[1005][1005];
int jie(int qiu){
	for(int i=1;i<=10000;i++){
		int s=pow(2,i);
		if(s>=qiu)return i;
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	int k=jie(n);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=pow(2,k-i);j++)cin>>chouqian[i][j];
	}
	cin>>T;
	for(int i=1;i<=T;i++){
	cin>>shuju[i][0]>>shuju[i][1]>>shuju[i][2]>>shuju[i][3];
	int t=i%4;
	a2[i]=a[i]^shuju[i][t];
	}
	for(int j=1;j<=T;j++){
	for(int i=1;i<=k;i++){
		answerr^=i*i;
	}
	cout<<answerr<<endl;
	answerr=1;
	}
	return 0;
}
