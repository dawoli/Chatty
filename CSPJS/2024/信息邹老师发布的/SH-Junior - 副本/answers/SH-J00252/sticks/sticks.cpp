#include<bits/stdc++.h>
using namespace std;
int t,n,l,k;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		l=n/7;
		k=n%7;
		if(k==1){
			if(l){
				l--;
				cout<<10;
			}else{
				cout<<"-1\n";
				continue;
			}
		}
		else if(k==2) cout<<1;
		else if(k==3)
			if(l){
				l--;
				if(l){
					l--;
					cout<<200;
				}else{
					cout<<"22\n";
					continue;
				}
			}else{
				cout<<"7\n";
				continue;
			}
		else if(k==4)
			if(l){
				l--;
				cout<<20;
			}else{
				cout<<"4\n";
				continue;
			}
		else if(k==5) cout<<2;
		else if(k==6) cout<<6;
		for(int i=l;i>0;i--) cout<<8;
		cout<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
