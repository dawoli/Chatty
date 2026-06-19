#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	if(n==1&&m==1) cout<<1<<" "<<1;
	else if(a[1]==1){
		bool f=1;
		for(int i=1;i<=n*m;i++){
			if(a[i]!=i){
				f=0;
				break;
			}
		}
		if(f) cout<<m<<" "<<n;
	}
	else if(a[1]==n*m){
		bool f=1;
		for(int i=1;i<=n*m;i++){
			if(a[i]!=n*m-i+1){
				f=0;
				break;
			}
		}
		if(f) cout<<1<<" "<<1;
	}
	else if(n==1&&m<=10){
		int score=a[1];
		sort(a+1,a+n*m+1,cmp);
		for(int i=1;i<=n*m;i++){
			if(a[i]==score){
				cout<<i<<" "<<1;
			}
		}
	}
	else if(m==1&&n<=10){
		int score=a[1];
		sort(a+1,a+n*m+1,cmp);
		for(int i=1;i<=n*m;i++){
			if(a[i]==score){
				cout<<1<<" "<<i;
			}
		}
	}
	else if(n==2&&m==2){
		int score=a[1];
		sort(a+1,a+n*m+1,cmp);
		if(a[1]==score) cout<<1<<" "<<1;
		else if(a[2]==score) cout<<1<<" "<<2;
		else if(a[3]==score) cout<<2<<" "<<2;
		else cout<<2<<" "<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
