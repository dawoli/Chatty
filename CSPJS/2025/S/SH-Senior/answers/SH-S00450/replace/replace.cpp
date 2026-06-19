#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
pair<string,string> s[200002];
pair<int,int>b[200002];
string tt1,tt2,diff1,diff2;
string subst(string s,int l,int r){
	string ans="";
	for(int i=l;i<=r;i++)ans+=s[i];
	return ans;
}
int get_wz(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='b')return i;
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	if(q==1||(n<=1000&&q<=1000)){
		while(q--){
			cin>>tt1>>tt2;
			int len=tt1.size();
			int l=0,r=len-1;
			while(tt1[l]==tt2[l])l++;
			while(tt1[r]==tt2[r])r--;
			diff1=subst(tt1,l,r);
			diff2=subst(tt2,l,r);
			for(int i=1;i<=n;i++){
				string ss1=s[i].first,ss2=s[i].second;
				int lens=ss1.size();
				if(ss1.find(diff1)!=string::npos&&ss2.find(diff2)!=string::npos&&lens<=len&&ss1.find(diff1)==ss2.find(diff2)){
					int wz1=ss1.find(diff1)-1,wz2=wz1+r-l+2;//n个变换的字符串s 
					int ll=l-1,rr=r+1;//q询问的字符串t 
					//cout<<wz1<<" "<<wz2<<" "<<ll<<" "<<rr<<endl;
					string zz1=diff1,zz2="";
					while(ll>=0&&wz1>=0&&tt1[ll]==ss1[wz1]&&tt1[ll]==ss2[ll]){
						ll--;wz1--;
					}
					while(rr<len&&wz2<lens&&tt1[rr]==ss1[wz2]&&tt1[rr]==ss2[rr]){
						rr++;wz2++;
					}
					if(wz1==-1&&wz2==lens)ans++;
				}
			}
			cout<<ans<<endl;
			ans=0;diff1="";diff2="";
		}
	}
	else{//特殊性质B 
		for(int i=1;i<=n;i++){//求出所有字符串的b的位置 
			b[i].first=get_wz(s[i].first);
			b[i].second=get_wz(s[i].second);
		}
		while(q--){
			string tt1,tt2;
			cin>>tt1>>tt2;
			int len=tt1.size();
			int wz1=get_wz(tt1),wz2=get_wz(tt2);
			for(int i=1;i<=n;i++){
				int lens=s[i].first.size();
				if(lens<=len){
					int l=wz1-b[i].first;//更换序列的左端点
					if(l+b[i].second==wz2)ans++; 
				}
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
