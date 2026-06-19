#include<bits/stdc++.h>
using namespace std;
int n;
long long r[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int z=1,y=2; 
	while(y<=n){
		if(r[y]>r[z]){
			y++;
			z++;
		}
		else y++;
	}
	cout<<y-z;
	return 0;
}
