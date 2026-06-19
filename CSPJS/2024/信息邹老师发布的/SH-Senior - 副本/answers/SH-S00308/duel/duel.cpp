#include<bits/stdc++.h>
using namespace std;
int n=0;
int s[100009];
int ans=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(s,s+n);
	int l=0,r=1;
	while(1){
		if(s[l]<s[r]){
			l++;
			r++;
		}
		else{
			r++;
		}
		if(r>=n){
			break;
		}
	}
	cout<<n-l;
	return 0;
} 
