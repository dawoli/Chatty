#include <bits/stdc++.h>
using namespace std;
int t,s[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	for (int i=1;i<=t;i++){
		int n,num=0,cnt=0;
		bool flag=false;
		cin>>n;
		while (true){
			if (cnt>1e6){num=-1;break;}
			num++;
			int temp=num,sum=0;
			while (temp){
				sum+=s[temp%10];
				temp/=10;
			}
			if (sum==n) break;
			cnt++;
		}
		cout<<num<<endl;
	}
	return 0;
}
