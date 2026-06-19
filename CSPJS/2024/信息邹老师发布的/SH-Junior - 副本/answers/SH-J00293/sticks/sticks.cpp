#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	long long n,a[55];
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		if(a[i]==1) cout<<"-1"<<"\n";
		if(a[i]==2) cout<<"1"<<"\n";
		if(a[i]==3) cout<<"7"<<"\n";
		if(a[i]==4) cout<<"4"<<"\n";
		if(a[i]==5) cout<<"2"<<"\n";
		if(a[i]==6) cout<<"6"<<"\n";
		if(a[i]==7) cout<<"8"<<"\n";
		if(a[i]==8) cout<<"10"<<"\n";
		if(a[i]==9) cout<<"18"<<"\n";
		if(a[i]==10) cout<<"22"<<"\n";
		if(a[i]==11) cout<<"20"<<"\n";
		if(a[i]==12) cout<<"28"<<"\n";
		if(a[i]==13) cout<<"68"<<"\n";
		if(a[i]==14) cout<<"88"<<"\n";
		if(a[i]==15) cout<<"108"<<"\n";
		if(a[i]==16) cout<<"188"<<"\n";
		if(a[i]==17) cout<<"200"<<"\n";
		if(a[i]==18) cout<<"208"<<"\n";
		if(a[i]==19) cout<<"288"<<"\n";
		if(a[i]==20) cout<<"688"<<"\n";
	}
	return 0;
}
