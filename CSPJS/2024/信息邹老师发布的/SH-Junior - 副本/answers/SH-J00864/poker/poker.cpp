#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
struct node{
	int a=0;
	string b;
}p[60];
int main(){
	//freopen("poker.in","r",stdin);
	//freopen("poker.out","w",stdout);
	cin>>n;
	
	cin>>p[1].b;
	p[1].a++;
	for(int i=2;i<=n;i++){
		string x;
		cin>>x;
		for(int j=1;j<i;j++){
			if(x!=p[j].b){
				p[i].a++;
				p[i].b=x;
			}
		}
	}
	for(int i=1;i<=52;i++){
		if(p[i].a==0) ans++;
	}
	cout<<ans;
	return 0;
}
