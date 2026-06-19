#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
	int ma(){
		return max(max(this->x,this->y),this->z);
	}
	int mi(){
		return min(min(this->x,this->y),this->z);
	}
	int second(){
		return this->x+this->y+this->z-this->ma()-this->mi();
	}
	int lose(){
		return this->ma()-this->second();
	}
	int indma(){
		int n=this->ma();
		if(n==this->x)return 1;
		if(n==this->y)return 2;
		if(n==this->z)return 3;
		return -1;
	}
	int indse(){
		int n=this->second();
		int ma=this->indma();
		if(n==this->x&&ma!=1)return 1;
		if(n==this->y&&ma!=2)return 2;
		if(n==this->z&&ma!=3)return 3;
		return -1;
	}
	bool operator<(node&b){
		return this->lose() > b.lose();
	}
}a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int j1,j2,j3;
			cin>>j1>>j2>>j3;
			a[i]={j1,j2,j3};
		}
		sort(a,a+n);
		int j[5]={0};
		long long ans=0;
		for(int i=0;i<n;i++){
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;;
			int ma=a[i].indma();
			//cout<<j[ma]<<" "<<n/2<<endl;
			if(j[ma]<n/2){
				j[ma]++;
				ans+=a[i].ma();
			}
			else{
				int se=a[i].indse();
				j[se]++;
				ans+=a[i].second();
			}
		}
		cout<<ans<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
