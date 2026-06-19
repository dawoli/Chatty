#include<bits/stdc++.h>
using namespace std;
int n,m,len,a[105],num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=0;i<len;i++){
		cin>>a[i];
	}
	int grade=a[0]-0;
	sort(a,a+len);
	for(int i=len-1;i>=0;i--){
		if(a[i]==grade){
			num=len-i;
			break;
		}
	}
	int x;
	if(num-num/m*m>0){
		cout<<num/m+1<<" ";
		x=num/m+1;
	}
	else{
		cout<<num/m<<" ";
		x=num/m;
	}
	if(x%2==1){
		cout<<num-(x-1)*m;
	}
	else{
		cout<<n-(num-((x-1)*m))+1;
	}
	return 0;
}
