#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char s1[N],s2[N],t1[N],t2[N];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
		cin>>t1[i]>>t2[i];
	
	return 0;
} 
