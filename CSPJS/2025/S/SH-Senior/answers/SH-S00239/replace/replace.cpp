#include<iostream>
std::string s[100001],t[100001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	std::cin>>n>>q;
	for(int i=0;i<n;i++)std::cin>>s[i]>>t[i];
	while(q--){
		std::string nows,nowt;
		std::cin>>nows>>nowt;
		if(nows.size()!=nowt.size()){
			std::cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(nows.size()<s[i].size())continue;
			for(int j=0;j<=nows.size()-s[i].size();j++){
				bool f=true;
				std::string xx=nowt;
				for(int k=0;k<s[i].size();k++)
					if(nows[j+k]!=s[i][k]){
						f=false;break;
					}
					else{
						if(xx[j+k]!=t[i][k]){
							f=false;break;
						}
						else xx[j+k]=s[i][k];
					}
				if(xx!=nows)continue;
//				if(f)std::cout<<i<<" "<<j<<"\n";
				ans+=f;
			}
		}
		std::cout<<ans<<"\n";
	}
}
//30'(虽然是暴力但是10^3应该还是能过滴~) 
