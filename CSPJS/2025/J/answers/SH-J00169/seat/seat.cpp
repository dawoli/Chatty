#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int s[N],a[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>s[i];
	}
	int msc=s[1];
	sort(s+1,s+1+num);
	int i=1;
	int j=1;
	for(int k=num;k>=1;k--){
		a[i][j]=s[k];
		if(i+1>n && j%2==1){
			i=i;
			j+=1;
		}else if(i-1<1 && j%2==0){
			i=i;
			j+=1;
		}else if(j%2==0){
			i-=1;
			j=j;
		}else{
			i+=1;
			j=j;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==msc){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
