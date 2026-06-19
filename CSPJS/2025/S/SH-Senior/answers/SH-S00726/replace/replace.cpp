#include<iostream>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
#include<cmath>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
char s1[200010],s2[1000010];
int ans=0;
struct sz{
	long long yuan;
	long long now;
};
bool cmp(sz a,sz b){
	return a.yuan<b.yuan;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	sz s3[n];
	for(int i=0;i<n;i++){
		int s=0,e;
		cin>>s1>>s2;
		int chang=strlen(s1);
		e=chang-1;
		for(int j=0;j<chang;j++){
			if(s1[j]==s2[j])s++;
			else	break;
		}for(int j=chang-1;j>=0;j--){
			if(s1[j]==s2[j])e--;
			else	break;
		}
		//cout<<s<<" "<<e<<" "<<chang<<endl;
		long long mod=29113331,base=1;
		s3[i].yuan=s3[i].now=0;
		for(int j=s;j<=e;j++){
			s3[i].yuan=(s3[i].yuan+s1[j]*base)%mod;
			s3[i].now=(s3[i].now+s2[j]*base)%mod;
			//cout<<s3[i].yuan<<endl;
			base=base*131%mod;
		}
	}sort(s3,s3+n,cmp);
	for(int i=0;i<q;i++){
		int s=0,e;
		cin>>s1>>s2;
		if(strlen(s1)!=strlen(s2)){
			cout<<0;
			cout<<endl;
			continue;
		}
		int chang=strlen(s1);
		e=chang-1;
		for(int j=0;j<chang;j++){
			if(s1[j]==s2[j])s++;
			else	break;
		}for(int j=chang-1;j>=0;j--){
			if(s1[j]==s2[j])e--;
			else	break;
		}
		//cout<<s<<" "<<e<<" "<<chang<<endl;
		long long mod=29113331,base=1;
		long long s4=0,s5=0;
		for(int j=s;j<=e;j++){
			s4=(s4+s1[j]*base)%mod;
			//cout<<s4<<endl;
			s5=(s5+s2[j]*base)%mod;
			base=base*131%mod;
		}
		long long st=0,en=n-1,tar=-1;
		while(st<=en){
			long long mid=(st+en)/2;
			if(s4==s3[mid].yuan){
				tar=mid;
				break;
			}else if(s4>=s3[mid].yuan){
				st=mid+1;
			}else{
				en=mid-1;
			}
		}if(tar==-1)cout<<0<<endl;
		else{
			for(int j=tar;j>=0;j--){
				if(s4==s3[j].yuan&&s5==s3[j].now)ans++;
				else if(s4!=s3[j].yuan)break;
			}for(int j=tar+1;j<n;j++){
				if(s4==s3[j].yuan&&s5==s3[j].now)ans++;
				else if(s4!=s3[j].yuan)break;
			}cout<<ans<<endl;
		}
		ans=0;
	}
	return 0;
}
