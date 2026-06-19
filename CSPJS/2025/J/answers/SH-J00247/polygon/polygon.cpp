#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int n,sum=0;
vector<int> s;
int pailie[1000];
void sort_(){
	for(int i=0;i<s.size();i++){
		for(int j=i;j>0;j--){
			if(s[j]>s[j-1])swap(s[j-1],s[j]);
		}
	}
}
void pai(int b, int depth, int number){
	if(number>=n)return;
	pailie[depth-1]=s[number];
	if(depth==b){
		int max1=0,sum1=0;
		for(int i=0;i<b;i++){
			max1=max(max1,pailie[i]);
			sum1=sum1+pailie[i];
		}
		if(sum1>max1*2)sum++;
		return;
	}
	for(int i=number+1;i<n;i++){
		pai(b,depth+1,i);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int j;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>j;
		s.push_back(j);
	}
	sort_();
	for(int i=3;i<=n;i++){
		for(int j=0;j<n;j++){
			pai(i,1,j);
		}
	}
	cout<<sum;
	return 0;
}
