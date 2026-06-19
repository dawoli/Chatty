#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[102]={0},t[102]={0};
	int s[12][12]={0};
	int n,m;
	cin>>m>>n;
	int c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	int cnt=1,T=0;
	for(int i=1;i<=c;i++){
		int mx=-1,C;
		for(int j=1;j<=c;j++){
			if(a[j]>mx){
				C=j;
				mx=a[j];
			}
			
		}
		if(C==1){
			T=cnt;
		}
		t[cnt]=a[C];
		cnt++;
		a[C]=-1;
		C=0;
	}
	if(n%2==0){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=m;i++){
				s[j][i]=t[i%(m+1)+m*(j-1)];
				if((i%(m+1)+m*(j-1))==T){
					cout<<j<<' '<<i;
					break;
				}
			}
			j++;
			for(int i=m;i>=1;i--){
				s[j][i]=t[m+1-i%(m+1)+m*(j-1)];
				if((m+1-i%(m+1)+m*(j-1))==T){
					cout<<j<<' '<<i;
					break;
				}
			}
		}
	}
	else{
		for(int j=1;j<=n-1;j++){
			for(int i=1;i<=m;i++){
				s[j][i]=t[i%(m+1)+m*(j-1)];
				if((i%(m+1)+m*(j-1))==T){
					cout<<j<<' '<<i;
					break;
				}
			}
			j++;
			for(int i=m;i>=1;i--){
				s[j][i]=t[m+1-i%(m+1)+m*(j-1)];
				if((m+1-i%(m+1)+m*(j-1))==T){
					cout<<j<<' '<<i;
					break;
				}
			}
		}
		for(int i=1;i<=m;i++){
			s[n][i]=t[i%(m+1)+m*(n-1)];
			if((i%(m+1)+m*(n-1))==T){
				cout<<n<<' '<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
