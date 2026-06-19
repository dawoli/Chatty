#include<bits/stdc++.h>
using namespace std;
void fr(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
}
struct num{
	int n=0,id;
};
int a[10]={6,2,5,5,4,5,6,3,7,6};//每个数字所需的小木棍数量 
vector<int> b[100005];
void init(){
	for(int i=0;i<100005;i++){
		int t=i,ans=0;
		while(t!=0){
			ans+=a[t%10];
			t/=10;
		}
		b[ans].push_back(i);
	}
}
bool cmp(int a,int b){
	return a<b;
}
int main(){
	fr();
	int t;
	cin>>t;
	init();
	for(int i=0;i<100005;i++){
		sort(b[i].begin(),b[i].end());
	}
	while(t--){
		int n;
		cin>>n;
		if(b[n].size()==0)cout<<-1<<endl;
		else cout<<b[n][0]<<endl;
	}
	return 0;
}
