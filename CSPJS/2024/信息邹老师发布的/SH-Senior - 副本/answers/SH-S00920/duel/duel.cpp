#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;
long long a[maxn],cnt,n;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+1+n);
	
	long long p=1;
	cnt=n;
	for(int i=1;i<=n;i++){
		while(a[i]==a[p]) p++;
		if(a[p]>a[i]){
			cnt--;
			p++;
		}
		if(p>n) break;
	}
	cout<<cnt<<endl;
} 
