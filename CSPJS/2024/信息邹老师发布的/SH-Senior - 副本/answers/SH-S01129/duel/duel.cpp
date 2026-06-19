#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
int b[100005];
int maxn,temp;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		if(maxn<=r[i]){
			maxn=r[i];
		}
		b[r[i]]++; 
	}
	for(int i=1;i<=maxn;i++){
		if(b[i]){
			if(temp>=b[i]) continue;
			else temp=b[i];
		}
	}
	cout<<temp;
	return 0;
} 
