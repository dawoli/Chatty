#include<bits/stdc++.h>
using namespace std;
int s[100010],n,lst;
signed main(){
	freopen("duel.in","r",stdin); 
	freopen("duel.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n);
	for(int i=0;i<n;i++)
		if(s[i]>s[lst])
			lst++;
	cout<<n-lst;
} 
