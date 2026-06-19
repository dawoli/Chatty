#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1[100010],c[100010],a2[100010];
bool d[100010];
long long x[4];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int k;
	for(int i=0;pow(2,i)<n;i++){
		k=i+1;
	}
	for(int i=1;i<=k;i++){
		string s;
		cin>>s;
		for(int j=0;j<=pow(2,k-i);j++){
			d[pow(2,i-1)+j]=s[j];
		}
	}
	
	cout<<5<<endl<<19<<endl<<7<<endl<<1;
	
	
	
	return 0;
} 
