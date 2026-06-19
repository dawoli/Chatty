#include <bits\stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,al;//n是行,m是列 
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int c,r;//r是行,c是列 
int check(int num){
	c++;
	while(num-m>0){
		num-=m;
		c++;
	}
	if(c%2==0){
		r=n-num+1;
	}else{
		r=num;
	}
	cout<<c<<" "<<r;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	al=m*n;
	for(int i=1;i<=al;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+al,cmp);
	for(int i=1;i<=al;i++){
		if(a[i]==R){
			check(i);
			break;
		}
	}
	return 0;
} 
