#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		vector<short> v;
		while(n>=7){
			v.push_back(8);
			n-=7;
		}
		if(n==1){
			v.back()=6;
			v.push_back(1);
		}
		if(n==2)
			v.push_back(1);
		if(n==3){
			if(v.size()==0)
				v.push_back(7);
			else if(v.size()==1){
				v.back()=2;
				v.push_back(2);
			}
			else{
				v.back()=0;
				v[v.size()-2]=0; 
				v.push_back(2);
			}
		}
		if(n==4){
			if(v.size()==0)
				v.push_back(4); 
			else{
				v.back()=0;
				v.push_back(2);
			}
		}
		if(n==5)
			v.push_back(2);
		if(n==6)
			v.push_back(6);
		for(int i=v.size()-1;i>=0;i--)
			cout<<v[i];
		cout<<endl;
	}
	return 0;
}

