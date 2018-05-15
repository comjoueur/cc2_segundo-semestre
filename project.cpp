#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int change(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
class matriz{
  int f=3,c=3;
  int arr[4][4];
  public:
  matriz(){
    for(int (*p)[4]=arr;p<arr+4;p++){
	  	for(int *y=*p;y<*p+4;y++){
	  		*y=((y-*p))+(4*(p-arr));
	  	}
  	}
  	*(*(arr+f)+c)=-1;
  	int i=0,x;
	  srand(time(NULL));
    while(i++!=200){
		  x=(rand()%4);
  		if(x==0 && c>0){
  			change(*(arr+f)+c,*(arr+f)+c-1);--c;
  		}
  		else if(x==1 && c<3){
  			change(*(arr+f)+c,*(arr+f)+c+1);++c;
  		}
  		else if(x==2 && f>0){
  			change(*(arr+f)+c,*(arr+f-1)+c);--f;
  		}
  		else if(x==3 && f<3){
  			change(*(arr+f)+c,*(arr+f+1)+c);++f;
  		}
  	}
  }
  void print(){
    for(int (*i)[4]=arr;i<arr+4;i++){
      for(int *j=*i;j<*(i+1);j++){
        if(*j!=-1){
          if(*j<10){cout<<0;}
          cout<<*j;
        }
        else cout<< "  ";
        if(j==*i+3)cout<<endl;
        else cout<<" ";
      }
    }
  }
  void mov(char n){
    if(n=='w' && f<3){
			change(*(arr+f)+c,*(arr+f+1)+c);++f;
		}
		else if(n=='s' && f>0){
			change(*(arr+f)+c,*(arr+f-1)+c);--f;
		}
		else if(n=='a' && c<3){
			change(*(arr+f)+c,*(arr+f)+c+1);++c;
		}
		else if(n=='d' && c>0){
			change(*(arr+f)+c,*(arr+f)+c-1);--c;
		}
  }
  bool fin(){
    bool b=0;
    for(int (*p)[4]=arr;p<arr+4;p++){
			for(int *y=*p;y<*(p+1);y++){
				if(!((p-arr)==3 && (*p-y==3))&& (y-*p)+4*(p-arr)==*y)b=b||0;
				else if(p-arr==3 && (*p-y==3) && *y==-1)b=b||0;
				else b=1;
			}
		}
		return b;
  }
};
int main(){
	matriz x;
	x.print();
	char c;
	while(x.fin()){
	  cin>>c;
	  x.mov(c);
	  x.print();
	}
	return 0;
}
