#include<bits/stdc++.h>
using namespace std;
int s[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>s[i];
	}
	int r=s[1];
	int k;
	sort(s+1,s+t+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==s[i]){
			k=i;
			break; 
		}
	}
	int y=1,z=1;
	for(int i=1;i<k;i++){
		if(i%n==0)
			y++;
		else
			z+=pow(-1,y+1);
	}
	cout<<y<<" "<<z;
	return 0;
} 
