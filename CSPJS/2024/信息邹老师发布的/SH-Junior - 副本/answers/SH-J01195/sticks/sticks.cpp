#include<iostream>
#include<fstream>
std::ifstream fin("sticks.in");
std::ofstream fout("sticks.out");
int main(){
	int amount;
	std::cin>>amount;
	int s[amount];
	for(int i=1;i<=amount;i++){
		std::cin>>s[i];
		if(s[i]<2){
			s[i]=-1;
		}
	}
	for(int i=1;i<=amount;i++){
		if(s[i]<=7){
			if(s[i]==2)s[i]=1;
			if(s[i]==3)s[i]=7;
			if(s[i]==4)s[i]=4;
			if(s[i]==5)s[i]=2;
			if(s[i]==6)s[i]=6;
			if(s[i]==7)s[i]=8;
		}
		else{
			if(s[i]<10 && s[i]>7){
				s[i]-2;				
			    if(s[i]==2)s[i]=1+10;
			    if(s[i]==3)s[i]=7+10;
			    if(s[i]==4)s[i]=4+10;
			    if(s[i]==5)s[i]=2+10;
			    if(s[i]==6)s[i]=6+10;
			    if(s[i]==7)s[i]=8+10;		
			}
			else if(s[i]<=20 && s[i]>=10){
				if(s[i]==11)s[i]=26;
				else if(s[i]==12)s[i]=28;
				else if(s[i]==13)s[i]=68;
				else if(s[i]==14)s[i]=88;
				else if(s[i]==15)s[i]=176;
				else if(s[i]==16)s[i]=188;
				else if(s[i]==17)s[i]=228;
				else if(s[i]==18)s[i]=268;
				else if(s[i]==20)
				s[i]=688;
				else if(s[i]==19)
				s[i]=288;
			}
		}
	}
	for(int i=1;i<=amount;i++){
		std::cout<<s[i]<<"\n";
	}
}
