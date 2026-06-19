#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=110;
int n,m;
int r,a[N];
int x=1,y=1;
void f(int &i,int &j){
	if(j>m)return ;
	if(j&1){
		if(i==n)j++;
		else i++;
	}else{
		if(i==1)j++;
		else i--;
	}
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}r=a[1]; 
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	for(int i=1;a[i]!=r;i++){
		f(x,y);
	}cout<<y<<" "<<x<<"\n";//先输出列，再输出行 
	return 0;
}/*
3 3
94 95 96 97 98 99 100 93 92
*/
