#include<bits/stdc++.h>
using namespace std;
const int N=19,NN=109;
int a[NN],x[NN],y[NN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++)cin>>a[i];
	int score=a[1];
	sort(a+1,a+1+nm);
	int id=lower_bound(a+1,a+1+nm,score)-a;
	id=nm-id+1;
//	cout<<id<<"\n";
	x[1]=y[1]=1;
	for(int i=1;i<nm;i++){
		if(x[i]!=n&&y[i]%2==1)x[i+1]=x[i]+1,y[i+1]=y[i];
		else if(x[i]!=1&&y[i]%2==0)x[i+1]=x[i]-1,y[i+1]=y[i];
		else x[i+1]=x[i],y[i+1]=y[i]+1;
	}
//	for(int i=1;i<=nm;i++)cout<<x[i]<<" "<<y[i]<<"\n";
	cout<<y[id]<<" "<<x[id];
	return 0;
}
/*
人生得意须尽欢，莫使金樽空对月
天生我材必有用，千金散尽还复来
烹羊宰牛且为乐，会须一饮三百杯
岑夫子，丹丘生，将进酒，杯莫停 
*/
