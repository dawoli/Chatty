#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	long long n,d[15]={0},c[15]={0},h[15]={0},s[15]={0},sum=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		string m;
		cin>>m;
		if(m[0]=='D' && m[1]=='A') d[1]+=1;
		else if(m[0]=='D' && m[1]=='2') d[2]+=1;
		else if(m[0]=='D' && m[1]=='3') d[3]+=1;
		else if(m[0]=='D' && m[1]=='4') d[4]+=1;
		else if(m[0]=='D' && m[1]=='5') d[5]+=1;
		else if(m[0]=='D' && m[1]=='6') d[6]+=1;
		else if(m[0]=='D' && m[1]=='7') d[7]+=1;
		else if(m[0]=='D' && m[1]=='8') d[8]+=1;
		else if(m[0]=='D' && m[1]=='9') d[9]+=1;
		else if(m[0]=='D' && m[1]=='T') d[10]+=1;
		else if(m[0]=='D' && m[1]=='J') d[11]+=1;
		else if(m[0]=='D' && m[1]=='Q') d[12]+=1;
		else if(m[0]=='D' && m[1]=='K') d[13]+=1;
		else if(m[0]=='C' && m[1]=='A') c[1]+=1;
		else if(m[0]=='C' && m[1]=='2') c[2]+=1;
		else if(m[0]=='C' && m[1]=='3') c[3]+=1;
		else if(m[0]=='C' && m[1]=='4') c[4]+=1;
		else if(m[0]=='C' && m[1]=='5') c[5]+=1;
		else if(m[0]=='C' && m[1]=='6') c[6]+=1;
		else if(m[0]=='C' && m[1]=='7') c[7]+=1;
		else if(m[0]=='C' && m[1]=='8') c[8]+=1;
		else if(m[0]=='C' && m[1]=='9') c[9]+=1;
		else if(m[0]=='C' && m[1]=='T') c[10]+=1;
		else if(m[0]=='C' && m[1]=='J') c[11]+=1;
		else if(m[0]=='C' && m[1]=='Q') c[12]+=1;
		else if(m[0]=='C' && m[1]=='K') c[13]+=1;
		else if(m[0]=='H' && m[1]=='A') h[1]+=1;
		else if(m[0]=='H' && m[1]=='2') h[2]+=1;
		else if(m[0]=='H' && m[1]=='3') h[3]+=1;
		else if(m[0]=='H' && m[1]=='4') h[4]+=1;
		else if(m[0]=='H' && m[1]=='5') h[5]+=1;
		else if(m[0]=='H' && m[1]=='6') h[6]+=1;
		else if(m[0]=='H' && m[1]=='7') h[7]+=1;
		else if(m[0]=='H' && m[1]=='8') h[8]+=1;
		else if(m[0]=='H' && m[1]=='9') h[9]+=1;
		else if(m[0]=='H' && m[1]=='T') h[10]+=1;
		else if(m[0]=='H' && m[1]=='J') h[11]+=1;
		else if(m[0]=='H' && m[1]=='Q') h[12]+=1;
		else if(m[0]=='H' && m[1]=='K') h[13]+=1;
		else if(m[0]=='S' && m[1]=='A') s[1]+=1;
		else if(m[0]=='S' && m[1]=='2') s[2]+=1;
		else if(m[0]=='S' && m[1]=='3') s[3]+=1;
		else if(m[0]=='S' && m[1]=='4') s[4]+=1;
		else if(m[0]=='S' && m[1]=='5') s[5]+=1;
		else if(m[0]=='S' && m[1]=='6') s[6]+=1;
		else if(m[0]=='S' && m[1]=='7') s[7]+=1;
		else if(m[0]=='S' && m[1]=='8') s[8]+=1;
		else if(m[0]=='S' && m[1]=='9') s[9]+=1;
		else if(m[0]=='S' && m[1]=='T') s[10]+=1;
		else if(m[0]=='S' && m[1]=='J') s[11]+=1;
		else if(m[0]=='S' && m[1]=='Q') s[12]+=1;
		else if(m[0]=='S' && m[1]=='K') s[13]+=1;
		}
	for(int i=1;i<=13;++i){
		if(d[i]==0) sum+=1;
		if(c[i]==0) sum+=1;
		if(h[i]==0) sum+=1;
		if(s[i]==0) sum+=1;
	}
	cout<<sum;
	return 0;
}
