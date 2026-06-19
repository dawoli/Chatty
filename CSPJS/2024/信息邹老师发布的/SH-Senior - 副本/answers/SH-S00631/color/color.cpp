#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100001]={0};
long long s=0;l[100001],r[100001];
bool b;
int op(int d,int s,int l,int r){
	if(a[d]==a[rm]){
		s++;l=d;
		op(d+1,s,l,r);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			b=false;
		}
	}
	return 0;
} 
