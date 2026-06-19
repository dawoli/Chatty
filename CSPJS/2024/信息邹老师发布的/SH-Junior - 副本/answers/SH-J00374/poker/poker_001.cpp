#include<bits/stdc++.h>
using namespace std;
int b[256][256],n,ans=0;
char a[10]={"DCHS"},m[20]={"A23456789TJQK"},ta,tb;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ta>>tb;
		b[int(ta)][int(tb)]++;
	}for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(b[int(a[i])][int(m[j])]<1)ans++;
		}
	}cout<<ans;
	return 0;
}
