#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,q,hashval,hashtab[10000019],cnt,flag,cnt2,ans;
string s1,s2,s3,s4;
string t1,t2;
string replac[200005][2];
//fuck wo yao shi ji de KMP zen me xie wo zhi shao duo na 10 fen
//wo bu xi huan ni KMP
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		hashval=0;
		cin>>s1>>s2;
		s3=s1+s2;
		while(s3.empty()==false){
			hashval*=26;
			hashval+=s3[s3.length()-1]-'a'+1;
			hashval%=10000019;
			s3.erase(s3.length()-1);
		}
		if(hashtab[hashval]==0){
			hashtab[hashval]=1;
			replac[cnt][0]=s1;
			replac[cnt][1]=s2;
			cnt++;
		}
	}
	for(int i=0;i<q;i++){
		ans=0;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0;
			continue;
		}
		for(int j=0;j<cnt;j++){
			flag=-1;
			for(int k=0;k<t1.length()-replac[j][0].length()+2;k++){
				cnt2=0;
				while(t1[k+cnt2]==replac[j][0][cnt2]&&cnt2<replac[j][0].length()){
					cnt2++;
				}
				if(cnt2>=replac[j][0].length()){
					flag=k;
				}
			}
			if(flag!=-1){
				if(t1.replace(flag,flag+replac[j][0].length(),replac[j][1]).compare(t2)==0){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
