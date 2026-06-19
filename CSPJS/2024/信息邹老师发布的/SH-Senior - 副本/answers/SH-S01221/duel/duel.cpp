#include<bits/stdc++.h>
using namespace std;
long long int n,r[205000],ans,l=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>r[i];}
    sort(r+1,r+n+1);
	for(int i=2;i<=n;i++){
	if(r[i]>r[l]){
	l++;
	ans++;	
	}
}
cout<<n-ans;
    return 0;	
}
