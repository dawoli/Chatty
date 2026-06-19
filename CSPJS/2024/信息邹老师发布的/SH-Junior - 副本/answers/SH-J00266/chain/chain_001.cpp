#include<bits/stdc++.h>
using namespace std;
int T,n,k,q;
int l[114514],r[114514];
int c[114514];
string s[114514];
int ss_1,usd_1[114514];
bool flag;
int tong_1[114514];
bool jielong(int cnt,char en,int pre_usd1){
	if(cnt==0){
		if(en!='1'){
			return 0;
		}
		flag=1;
		return 1;
	}
	for(int i=0;i<n;i++){
		if(usd_1[i]==1) continue;
		for(int j=1;j<s[i].size();j++){
			if(s[i][j]!=en) continue;
			usd_1[pre_usd1]=0;
			usd_1[i]=1;
			for(int kk_1=j-1;kk_1>=j-k+1&&kk_1>=0;kk_1--){
				jielong(cnt-1,s[i][kk_1],i);
			}
		}
	}
	if(flag) return 1;
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int p=1;p<=T;p++){
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>l[i];
			for(int j=0;j<l[i];j++){
				cin>>ss_1;
				s[i]+=(ss_1+'0');
				if(ss_1<114514){
					tong_1[ss_1]++;
				}
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			if(c[i]<114514&&tong_1[c[i]]==0){
				cout<<0<<endl;
				continue;
			}
			flag=0;
			cout<<jielong(r[i],c[i]+'0',0)<<endl;
			memset(usd_1,0,sizeof(usd_1));
		}
		for(int i=0;i<n;i++){
			s[i]="";
		}
		memset(tong_1,0,sizeof(tong_1));
	}
	return 0;
}
