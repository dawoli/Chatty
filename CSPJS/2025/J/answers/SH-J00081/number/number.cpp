#include<bits/stdc++.h>
using namespace std;
long long len_; 
string sa_;
vector<long long> ans_;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sa_;
	len_=sa_.size();
	for(int i=0;i<len_;i++){
//		cin>>s;
//		if(s==' ') break;
		if(sa_[i]=='0' || sa_[i]=='1' || sa_[i]=='2' || sa_[i]=='3' || sa_[i]=='4' || sa_[i]=='5' || sa_[i]=='6' || sa_[i]=='7' || sa_[i]=='8' || sa_[i]=='9'){
//			cout<<"sa[i]= "<<sa[i]<<endl;
			ans_.push_back(sa_[i]-48);
//			cout<<"ans[i]= "<<ans[i]<<endl;
		}
//		cout<<sa[i]<<endl;
	}
	sort(ans_.begin(),ans_.end());
//	cout<<"ans[0]= "<<ans[0]<<endl;
	for(int i=ans_.size()-1;i>=0;i--){
		cout<<ans_[i];
	}
	return 0;
}
