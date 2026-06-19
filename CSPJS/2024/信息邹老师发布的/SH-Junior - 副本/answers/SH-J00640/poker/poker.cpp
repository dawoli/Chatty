#include<fstream>
#include<string>
std::ifstream fin("poker.in");
std::ofstream fout("poker.out");
int n;
bool usedd[15],usedc[15],usedh[15],useds[15];
int main(){
	fin>>n;
	int cnt=0;
	for(int i=0;i<n;i++){
		std::string s;
		fin>>s;
		if(s[1]=='A') s[1]='1';
		if(s[1]=='T') s[1]='10';
		if(s[1]=='J') s[1]='11';
		if(s[1]=='Q') s[1]='12';
		if(s[1]=='K') s[1]='13';
		if(s[0]=='D'){
			if(usedd[s[1]-'0']==0){
				cnt++;
				usedd[s[1]-'0']=1;
			}
		}
		if(s[0]=='C'){
			if(usedc[s[1]-'0']==0){
				cnt++;
				usedc[s[1]-'0']=1;
			}
		}
		if(s[0]=='H'){
			if(usedh[s[1]-'0']==0){
				cnt++;
				usedh[s[1]-'0']=1;
			}
		}
		if(s[0]=='S'){
			if(useds[s[1]-'0']==0){
				cnt++;
				useds[s[1]-'0']=1;
			}
		}
	}
	fout<<52-cnt;
	return 0;
} 
