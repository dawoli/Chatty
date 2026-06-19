#include<bits/stdc++.h>
using namespace std;
//define int long long
typedef long long ll;
typedef unsigned long long ull;
#define fr(asd,fgh,i) for(int i=asd,i##end=fgh;i<=i##end;++i)
#define rf(asd,fgh,i) for(int i=asd,i##end=fgh;i>=i##end;--i)
#define maxn 6000007
#define maxm 1000007
int n,q;
ull hsh1[maxn],hsh2[maxn],hsh3[maxn],hsh4[maxn],jc1[maxn],jc2[maxn];  
/*bool ck(p x,p y){
	return (x.h1==y.h1)&&(x.h2==y.h2);
}*/
map<pair<pair<ull,ull>,pair<ull,ull> >,bool>mp; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>q;
	jc1[0]=jc2[0]=1;
	fr(1,n,i) jc1[i]=jc1[i-1]*29;
	fr(1,n,i) jc2[i]=jc2[i-1]*37;
	fr(1,n,i){
		string s1,s2;cin>>s1>>s2;
		ull hsh1_=0,hsh2_=0,hsh3_=0,hsh4_=0;
		fr(1,s1.size(),j){
			hsh1_=hsh1_*29+(s1[j-1]-'a'+1);
			hsh2_=hsh2_*37+(s1[j-1]-'a'+1);
		}//得到了可以修改的s1的哈希值 
		fr(1,s2.size(),j){
			hsh3_=hsh3_*29+(s2[j-1]-'a'+1);
			hsh4_=hsh4_*37+(s2[j-1]-'a'+1);
		}//得到了可以修改的s1的哈希值 
		//cout<<i<<" "<<hsh1_<<" "<<hsh2_<<" "<<hsh3_<<" "<<hsh4_<<endl;
		mp[{{hsh1_,hsh2_},{hsh3_,hsh4_}}]=1;
	}
	while(q--){
		//每一次询问，对于t1=>t2,有子段，枚举子段，使子段1和s1相同，子段2和s2相同即可算为一种替换 
		string t1,t2;cin>>t1>>t2;
		int nn=t1.size(),mm=t2.size();
		if(nn!=mm||t1==t2){
			printf("0\n");continue;
		}int l=-1,r=-1;bool fl=0;
		t1=" "+t1,t2=" "+t2;
		fr(1,nn,i){
			if(l==-1&&t1[i]!=t2[i]) l=i;
			if(l>=0&&r==-1&&t1[i]==t2[i]) r=i;
			if(r>=0&&t1[i]!=t2[i]){
				r=-999;break;
			} 
		}if(r==-999){
			printf("0\n");continue;
		}
		if(r==-1) r=nn+1;
		r--;
		fr(1,nn,i){
			hsh1[i]=hsh1[i-1]*29+(t1[i]-'a'+1);
			hsh2[i]=hsh2[i-1]*37+(t1[i]-'a'+1);
		}fr(1,nn,i){
			hsh3[i]=hsh3[i-1]*29+(t2[i]-'a'+1);
			hsh4[i]=hsh4[i-1]*37+(t2[i]-'a'+1);
		}ll ans=0;string v;
		fr(1,l,i){
			fr(r,nn,j){
				ull asdf1=hsh1[j]-hsh1[i-1]*jc1[j-i+1];
				ull asdf2=hsh2[j]-hsh2[i-1]*jc2[j-i+1];
				ull asdf3=hsh3[j]-hsh3[i-1]*jc1[j-i+1];
				ull asdf4=hsh4[j]-hsh4[i-1]*jc2[j-i+1];
				if(mp.count({{asdf1,asdf2},{asdf3,asdf4}})){
					ans++;//cout<<i<<"[]"<<j<<"::"<<asdf1<<" "<<asdf2<<" "<<asdf3<<" "<<asdf4<<" "<<endl;
				}
			}
		} 
		printf("%lld\n",ans);
	}//cout<<"KKK"<<" "<<clclc<<endl;
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

*/
