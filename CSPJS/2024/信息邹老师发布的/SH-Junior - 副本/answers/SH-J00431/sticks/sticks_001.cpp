#include<bits/stdc++.h>
using namespace std;

int n,t,s,f;
int A[10000010],q[10]={6,2,5,5,4,5,6,3,7,6};

void dfs(int x,int a){
	if(a>n){
		return;
	}
	if(f==1){
		return;
	}
	if(x==s+1 && a==n){
		for(int j=1;j<=s;j++){
			cout<<A[j];
		}
		cout<<endl;
		f=1;
		return;
	}
	for(int i=0;i<=9;i++){
		if(x==1 && i==0){
			continue;
		}
		A[x]=i;
		a+=q[i];
		dfs(x+1,a);
		a-=q[i];
	}
	return;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<2){
			cout<<-1<<"\n";
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<"\n";
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-1)/7;i++){
				cout<<8;
			}
			cout<<"\n";
		}
		else{
			s=(n-n%7)/7+1;
			f=0;
			dfs(1,0);
			if(f==0){
				cout<<-1<<"\n";
			}
		}
	}
	return 0;
}
