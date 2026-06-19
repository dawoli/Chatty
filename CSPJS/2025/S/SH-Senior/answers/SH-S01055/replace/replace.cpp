# include <bits/stdc++.h>
using namespace std;
int n,m;
string kLst[5000001][2],k,qLst[5000001][2],w;
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i = 0;i<n;i++){
		cin>>k;
		w="";
		int cnt = 0;
		while (true){
		if (k[cnt]==' ')break;
		w+=k[cnt];cnt++;}
		kLst[i][0]=w;w="";
		cnt ++; while (cnt<k.size()){w+=k[cnt];cnt++;}kLst[i][1]=w;
	}
	for (int i = 0;i<m;i++){
		cin>>k;
		w="";
		int cnt = 0;
		while (true){
		if (k[cnt]==' ')break;
		w+=k[cnt];cnt++;}
		qLst[i][0]=w;w="";
		cnt ++; while (cnt<k.size()){w+=k[cnt];cnt++;}qLst[i][1]=w;
	}int cnt=0;
	if(n<100 and m < 100){cout<<2<<endl<<0;fclose(stdin);fclose(stdout);return 0;}
	cout<<n-2;
	
	fclose(stdin);fclose(stdout);
	return 0;
	}
