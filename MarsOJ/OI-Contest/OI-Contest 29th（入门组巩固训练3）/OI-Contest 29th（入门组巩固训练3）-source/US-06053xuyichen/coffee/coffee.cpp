#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++){
		for(int i=0;i<5;i++){
			int m=0;
			for(int j=0;j<=7;j++){
				string s;
				cin>>s;
				if(s=="math")
					m++;
			}
			mp[i]=m;
		}
		mp[5]=0;
		mp[6]=0;
		int day,now;
		long long sum=0;
		cin>>day>>now;
		sum+=(day/7)*(mp[0]+mp[1]+mp[2]+mp[3]+mp[4]);
		for(int i=0;i<day%7;i++){
			sum+=mp[(now-1)%7];
		}
		cout<<sum<<"\n";
	}
	
} 
