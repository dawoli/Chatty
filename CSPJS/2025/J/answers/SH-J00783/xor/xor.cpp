#include<bits/stdc++.h>
using namespace std;
struct qj{
	int st;
	int ed;
};
bool cmp(qj x,qj y){
	if(x.ed==y.ed){
		return x.st<y.st;
	}return x.ed<y.ed;
}
vector<qj> arr;
int num[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}for(int i=0;i<n;i++){
		int a=0;
		for(int j=i;j<n;j++){
			a^=num[j];
			if(a==k){
				arr.resize(arr.size()+1);
				arr[cnt].st=i+1;
				arr[cnt].ed=j+1;
				cnt++;
			}
		}
	}sort(arr.begin(),arr.end(),cmp);
	cnt=0;
	int le=0;
	for(int i=0;i<arr.size()+1;i++){
		if(arr[i].st!=0 && arr[i].ed!=0){
			if(arr[i].st>le){
				cnt++;
				le=arr[i].ed;
			}
		}
	}cout<<cnt;
	return 0;
}
