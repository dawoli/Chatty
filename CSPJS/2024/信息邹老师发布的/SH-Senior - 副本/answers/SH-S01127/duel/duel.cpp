#include<bits/stdc++.h>

using namespace std;
/*
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
:)
*/
int n,a[100010],MIN,MAX,ans,b[100010],q;

int in(){
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	return 0;
}

int mb(){
	for(int i = 1;i<=n;i++) {
		b[a[i]]++;
	}
	return 0;
}

int getans (){
	for(int i = 1;i<=n;i++) {
		ans += b[i];
	}
	return 0;
}

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	in();
	sort(a+1,a+n+1);
	MAX = a[n];
	mb();
	for(int i = 1;i<=MAX;i++) {
		//cout<<"i:"<<i;
		for(int l = i+1;l<=MAX+0;l++) {
			if(b[i] == 0){
				//cout<<"break"<<endl;
				break;//b1(no
			}
			//cout<<"j:"<<l<<' '<<b[l]<<endl;
			if(b[l] != 0){
				if(b[l] > b[i]){
					//q = b[l];
					q = b[l]-b[i];
					b[i] = 0;
					for(int j = i;j>=1;j--) {
						if(q != 0){
							b[j] = b[l]>=b[j]?0:b[j]-b[l];
							q = b[l]>=b[j]?0:b[j]-b[l];
						}
					}
				}
				if(b[l] == b[i]){
					b[i] = 0;
				}
				if(b[l]<b[i]){
					b[i] = b[i]-b[l];//l47´¦Àí 
				}
			}
		}
	}
	getans();
	cout<<ans;
	return 0;
}
