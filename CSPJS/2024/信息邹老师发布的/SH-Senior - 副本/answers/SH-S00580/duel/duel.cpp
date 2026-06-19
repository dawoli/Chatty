#include<bits/stdc++.h>
const int maxn=1e5+10;
using namespace std;
int n,a[maxn],s,tot=1,num[maxn];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int hh=1;
	num[1]++;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			num[hh]++;
		}
		else{
			num[++hh]++;
		}
	}
	s+=num[1];
	for(int i=2;i<=hh;i++){
		if(num[i]>=s){
			s=0;
		}
		else{
			s-=num[i];
		}
		s+=num[i];
	}
	cout<<s;
	return 0;
}




















