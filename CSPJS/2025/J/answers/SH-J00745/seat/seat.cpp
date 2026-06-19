#include<bits/stdc++.h>
using namespace std;
const int N=1006;
int n,m,my,pos;
int goal[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>goal[i];
	}
	my=goal[1];
	sort(goal+1,goal+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(goal[i]==my){
			pos=n*m-i+1;
			break;
		}
	}
	int a=pos/n;
	if(pos-a*n<=0)
		cout<<a<<" ";
	else{
		a++;
		cout<<a<<" ";
	}
	if(pos%n==0)
		if(a%2>0)
			cout<<n;
		else	
			cout<<0;
	else 
		if(a%2>0)
			cout<<pos%n;
		else	
			cout<<n-pos%n+1;
	return 0;
} 
