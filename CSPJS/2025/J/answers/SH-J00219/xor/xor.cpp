#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=1e5;
string nums[maxn];
bool check(int l,int r){
	string re="";
	for(int i=l-1;i<=r-1;i++){
		for(int j=0;j<=nums[i].size();j++){
			if(nums[i][j]==re[j]){
				re[j]=0;
			}else{
				re[j]=1;
			}
		}
	}
	int numr=0;
	for(int i=0;i<re.size();i++){
		int r=1;
		for(int j=0;j<=i;j++){
			r*=2;
		}
		numr+=(re[i]-'0')*r;
	}
	cout<<numr;
	return numr==k;
}
int main(){
	freopen("xor.in","r");
	freopen("xor.out","w");
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		string numa="";
		while(a){
			numa+=(a%2+'0');
			a=a/2;
		}
		if(numa=="")numa+='0';
		nums[i]=numa;
	}
	for(int i=1;i<=n;i++){
		cout<<nums[i]<<' ';
	}
	check(1,3);
	return 0;
}
