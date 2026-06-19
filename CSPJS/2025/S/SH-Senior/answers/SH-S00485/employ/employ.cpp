#include<iostream>
#include<vector>
using namespace std;
int cnt=0;
int n1,m;
void rdmc(vector<int> src,vector<int> n,int idx,string arg){
	if(idx==n1){
		int fl=0;
		for(int i=0;i<n1;i++){
			fl+=(arg[i]=='0'||n[i]<=fl);
		}
		if(n1-fl>=m){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	int t;
	for(int i=0;i<src.size();i++){
		t=src[i];
		n.push_back(t);
		src.erase(src.begin()+i);
		rdmc(src,n,idx+1,arg);
		n.pop_back();
		src.insert(src.begin()+i,t);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n1>>m;
	string dfc;
	cin>>dfc;
	if(dfc==string('1',n1)){
		int r=1;
		while(true){
			r*=n1;
			r%=998244353;
			n1--;
			if(n1==1)break;
		}
		cout<<r;
		return 0;
	}
	vector<int> pat(n1);
	for(int i=0;i<n1;i++)cin>>pat[i];
	rdmc(pat,vector<int>(),0,dfc);
	cout<<cnt;
	return 0;
}

