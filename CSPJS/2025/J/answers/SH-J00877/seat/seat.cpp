#include<bits/stdc++.h>
using namespace std;
int N,M,x,y,s[10005],bas,k;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N*M;i++)cin>>s[i];
	bas=s[1];
	sort(s+1,s+1+N*M,cmp);
	for(int i=1;i<=M;i++){
		if(i%2==1)for(int j=1;j<=N;j++){
			++k;
			if(s[k]==bas){cout<<i<<" "<<j<<endl;return 0;}
		}
		else for(int j=N;j>=1;j--){
			++k;
			if(s[k]==bas){cout<<i<<" "<<j<<endl;return 0;}
		}
	}return 0;
}
