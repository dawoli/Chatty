#include<bits/stdc++.h>
using namespace std;
char* p[]={"C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CA", "CJ", "CK", "CQ", "CT", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DA", "DJ", "DK", "DQ", "DT", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HA", "HJ", "HK", "HQ", "HT", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "SA", "SJ", "SK", "SQ", "ST"};
bitset<52> usage;
int cmp(char** a,char** b){
	return strcmp(*a,*b);
}
void init(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
}
int main(){
	init(); 
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char s[5];
		scanf("%s",s);
		char* ps=s;
		char** r = (char**) bsearch(&ps,p,52,sizeof(string),reinterpret_cast<int(*)(const void*,const void*)>(cmp)); 
		usage[r-p]=true;
	}
	cout<<52-usage.count()<<endl;
} 
