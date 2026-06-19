#include<bits/stdc++.h>
using namespace std;
int T,n,f[200005],c[200005];
struct{
	int head,last;
}a[100005];
int main(){
	cin>>T>>n;
	int l = 0;
	for(int i = 1;i<=n;++i){
		cin>>f[i];
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<i;++j)
			if(f[i]==f[j]){
				++l;
				a[l].head = j;
				a[l].last = i;
			}
	}
	for(int i = 1;i<=l;++i){
		int ans = 0;
		for(int j = a[head]+1;j<)
	}
}
