#include<bits/stdc++.h>
using namespace std;
int n,k,q=0,w=0;
struct p{
	int ri;
	bool att;
}r[100002];
bool cmp(p a,p b){
	if (a.ri !=b.ri ){
		return a.ri <b.ri;
	}
	return a.ri >b.ri;
}

int main (){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	k=n;
	for (int i=0;i<n;i++){
		cin>>r[i].ri;
		r[i].att=true;
		if (r[i].ri==1){
			q++;
		}
		if (r[i].ri==2){
			w++;
		}
	}
	if (q+w==n){
		if (q<w){
			cout<<w;
		}
		else{
			cout<<q;
		}
	}
	else{
		sort (r,r+n,cmp);
	for (int i=0;i-1<n;i++){
		int j=1;
		if (r[i].ri <r[n-1].ri&&r[n-1].att ==true){
			for (int c=1;c+i<n;c++){
			if (r[i].ri <r[i+j].ri&&r[i+j].att ==true){
				k--;
				r[i+j].att =false;
				break;
			}
			else{
				j++;
			}
		}
		
		}
		
	}
	cout<<k;
	}
	
	
	
	return 0;
}


