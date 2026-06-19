#include<bits/stdc++.h> 
using namespace std;

int n;
struct poker{
	char huase;
	char num;
};


bool cmp(poker p1,poker p2){
	if(p1.num==p2.num){
		return p1.huase>=p2.huase;
	}
	return p1.num>p2.num;
}

poker a[60];



int main(){
	
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].huase>>a[i].num;
		if(a[i].num>='2' and a[i].num<='9'){
			a[i].num+='A'-1;
		}else{
			if(a[i].num=='T'){
				a[i].num='J'; 
			}
			else if(a[i].num=='J'){
				a[i].num='K'; 
			}
			else if(a[i].num=='Q'){
				a[i].num='L'; 
			}
			else if(a[i].num=='K'){
				a[i].num='M'; 
			}
		}
	}
	sort(a,a+n,cmp);
	int use=1;
	char tempn=a[0].num,temps=a[0].huase;
	for(int i=1;i<n;i++){
		if(a[i].num==tempn and a[i].huase==temps){
			continue;
		}else{
			use++;
			tempn=a[i].num;temps=a[i].huase;
		}
	}
	cout<<52-use;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}


