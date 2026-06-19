#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int a,b;
	cin>>a;
	const int x[4]={0,1,0,-1};
	const int y[4]={1,0,-1,0};
	int m[a];
	for(b=0;b<a;b++){
		int c,d,e,g,h,i,j,k;
		cin>>c>>d>>e>>i>>j>>k;
		string n;
		char f[c+2][d+2];
		bool l[c+1][d+1];
		for(g=0;g<=c+1;g++){
			for(h=0;h<=d+1;h++){
				f[g][h]='x';
			}
		}
		for(g=1;g<=c;g++){
			cin>>n;
			for(h=1;h<=d;h++){
				f[g][h]=n[h-1];
				l[g][h]=false;
			}
		}
		l[i][j]=true;
		for(g=0;g<e;g++){
			if(f[i+x[k]][j+y[k]]=='x') k=(k+1)%4;
			else{
				i+=x[k];
				j+=y[k];
				l[i][j]=true;
			}
		}
		e=0;
		for(g=1;g<=c;g++){
			for(h=1;h<=d;h++){
				if(l[g][h]) e++;
			}
		}
		m[b]=e;
	}
	for(b=0;b<a;b++){
		cout<<m[b]<<endl;
	}
	return 0;
}
