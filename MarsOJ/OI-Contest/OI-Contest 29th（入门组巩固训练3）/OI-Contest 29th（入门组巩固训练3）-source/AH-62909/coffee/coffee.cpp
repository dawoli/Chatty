#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	int t,m,sx,ti,x,b[6];
	cin>>t;
	for(int i=0;i<t;i++) {
		m=0;
		sx=0;
		for(int j=0;j<5;j++) {
			for(int k=0;k<8;k++) {
				cin>>a;
				if(a[0]=='m'&&a[1]=='a'&&a[2]=='t'&&a[3]=='h'){
					b[j]++;
					m++;
				}
			}
		}
		cin>>ti>>x;
		int kk=6-x;
		int ll=ti-kk+2;
		int mod=(ti-ll)%7;
		int chu=(ti-ll)/7;
		if(kk>0)
			for(int j=0;j<mod;j++){
				sx+=b[j];
			}
	
		sx+=(chu*m);
		if(mod<5){
			for(int j=0;j<mod;j++){
				sx+=b[j];
			}
		}
		else{
			sx+=m;
		}
		cout<<sx<<endl;
	}

}
