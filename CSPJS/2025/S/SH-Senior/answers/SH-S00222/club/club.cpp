#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		int k[10];
		k[0]=a+e;
		k[1]=a+f;
		k[2]=b+d;
		k[3]=b+f;
		k[4]=c+d;
		k[5]=c+e;
		int m=-1;
		for(int i=0;i<5;i++){
			if(k[i]>m){
				m=k[i];
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
