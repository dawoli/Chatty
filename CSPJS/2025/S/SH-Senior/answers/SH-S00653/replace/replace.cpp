#include<bits/stdc++.h>
using namespace std;
int n,q,k=1;
string t1,t2,s1[n+1],s2[n+1];
int main(){
	cin>>n>>q>>t1>>t2;
	for(int i=2;i<=n+q;i++){
		cin>>s1[k]>>s2[k];
		if(s1[k]==t1&&s2[k]==t2)k--;
		k++;
	}
	return 0;
}
