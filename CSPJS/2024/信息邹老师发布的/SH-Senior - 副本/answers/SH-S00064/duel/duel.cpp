#include<bits/stdc++.h>
using namespace std;
const int N=100009;
struct k{
	int i,j;
	bool ok=1,ex=1;
};
k t[N];
bool cmp(const k&a,const k&b){
	 return a.i<b.i; 
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,p,ans=0;
	cin>>n;
	//cout<<n<<endl;
	for(int m=1;m<=n;m++){
		cin>>p;
		t[m].i=p;
		t[m].j=p;
		//cout<<m<<" "<<t[m].i<<endl;
	}
	//for(int m=1;m<=n;m++)cout<<t[m].i<<" ";
	//cout<<endl;
	//cout<<n<<endl;
	//cout<<ans<<endl;
	sort(t+1,t+1+n,cmp);
	//cout<<n<<endl;
	//for(int m=1;m<=n;m++)cout<<t[m].i<<" ";
	//cout<<endl;
	int l=1,m=1;
	while(l<n&&m<=n){
		while(t[m].ex==0||t[m].ok==0) m++;
		while(t[l].ex==0) l++;
		//cout<<"l="<<l<<" "<<"m="<<m<<endl;
		if(t[m].i>t[l].j&&t[m].ok==1){
			t[m].ok=0;
			//cout<<m<<".ok=0"<<endl;
			t[l].ex=0;
			//cout<<l<<".ex=0"<<endl;
			t[l].ok=0;
			//cout<<l<<".ok=0"<<endl;
			if(m-l!=1)l=l+1;
			else l=l+2;
			m=l;
		}
		else m++;
		//cout<<endl;
	}
	ans=0;
	//cout<<n<<" "<<ans<<endl;
	for(int m=1;m<=n;m++){
		if(t[m].ex==1) ans++; 
	}
	cout<<ans;
	return 0;
}
