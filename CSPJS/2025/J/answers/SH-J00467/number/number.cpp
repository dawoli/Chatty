#include<bits/stdc++.h>
using namespace std;
string str;
int a[21];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9'&&str[i]>='0'){
			
			if(str[i]=='0'){
	        	a[0]++;
		    }
			else if(str[i]=='1'){
				a[1]++;
			}
			else if(str[i]=='2'){
				a[2]++;
			}
			else if(str[i]=='3'){
				a[3]++;
			}
			else if(str[i]=='4'){
				a[4]++;
			}
			else if(str[i]=='5'){
				a[5]++;
			}
			else if(str[i]=='6'){
				a[6]++;
			}
			else if(str[i]=='7'){
				a[7]++;
			}
			else if(str[i]=='8'){
				a[8]++;
			}
			else if(str[i]=='9'){
				a[9]++;
			}
	    }
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	
	fclose(stdout);
	fclose(stdin);
	return 0;
}
