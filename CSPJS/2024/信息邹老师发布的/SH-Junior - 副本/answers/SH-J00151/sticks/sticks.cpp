#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++)
				cout<<'8';
			cout<<endl;
			continue;
		}
		if((n-1)%7==0){
			cout<<10;
			n-=8;
			for(int i=1;i<=n/7;i++)
				cout<<8;
			cout<<endl;
			continue;
		}
		if(n<=50){
			long long minn=n/7;
			if(n%7)
				minn++;
			long long i=pow(10,minn-1);
			for(i;i<=pow(10,minn)-1;i++){
				string s="";
				char c;
				int x;
				long long bo=i;
				while(bo){
					x=bo%10;
					c=x+'0';
					s=s+c;
					bo/=10;
				}
				long long cnt=0;
				for(int j=0;j<s.size();j++)
					cnt+=a[s[j]-'0'];
				if(cnt==n){
					for(int j=s.size()-1;j>=0;j--)
						cout<<s[j];
					cout<<endl;
					break;
				}
			}
			continue;
		}
		cout<<-1;
	}
	return 0;
}
