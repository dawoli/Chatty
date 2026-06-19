#include<bits/stdc++.h>
using namespace std;
struct card{
	char flw;
	int num;
};

bool cmp(card a,card b){
	if (a.flw==b.flw){
		return a.num<=b.num;
	}
	else{
		if (a.flw=='D'){
		    return true;
	    }
	    else if (a.flw=='C' && b.flw!='D'){
		    return true;
	    }
	    else if (a.flw=='H' && b.flw!='D'&& b.flw!='C'){
		    return true;
	    }
	    else if (a.flw=='S' && b.flw!='D'&& b.flw!='C'&& b.flw!='H'){
		    return true;
	    }
		else{
			return false;
		}
	}
}
int main(){
	//freopen("poker.in","r",stdin);
	//freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	card a[n];
	for (int i=0;i<n;i++){
		string b;
		cin>>b;
		a[i].flw=b[0];
		if (b[1]-'0'>=0 || b[1]-'0'<=9){
			a[i].num=b[1]-'0';
		}
		else{
			if (b[1]=='T'){
				a[i].num=10;
			}
			else if (b[1]=='J'){
				a[i].num=10;
			}
			else if (b[1]=='Q'){
				a[i].num=10;
			}
			else if (b[1]=='K'){
				a[i].num=10;
			}
		}
	}
	int h=0,k=1,m=n;
	sort (a,a+n,cmp);
	for(;k<n;k++){
		if (a[h].flw==a[k].flw && a[h].num==a[k].num){
			continue;
		}
		else{
			h++;
			a[h].flw=a[k].flw;
			a[h].num=a[k].num;
			m--;
		}
	}
	cout<<52-m;
	return 0;
} 
