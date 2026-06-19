#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(v[0]+v[1]>v[2])cout<<1;
		return 0;
	}
	
	
	long long cnt=0;
	for(int i=2;i<v.size();i++){
		int k=3;
		while(k<=i+1){	
			for(int l=0;l+k-1<=i;l++){
				int sum=0;
				for(int j=l;j<l+k-1;j++)sum+=v[j];
				if(sum>v[i])cnt++;
			}
			k++;
		}	
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}
