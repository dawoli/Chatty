#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,x,rs;
	vector<int> v;
	cin>>c>>r;
	for(int i=0;i<c*r;i++){
		cin>>x;
		v.push_back(x);
	}
	rs=v[0];
	sort(v.begin(),v.end(),cmp);
	int locat=0;
	for(int i=0;i<c*r;i++){
		if(v[locat]==rs){
			break;
		}
		locat++;
	}
	locat++;
	if(locat%c==0){
		cout<<locat/c<<" "<<r<<endl;
		return 0;
	}
	else
	{
		int mod=locat%c;
		cout<<(locat-mod)/c+1;
		if(((locat-mod)/c+1)%2==0){
			cout<<" "<<c-mod+1;
		}
		else
		{
			cout<<" "<<mod;
		}
	}
}
