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
  int f,c;
  int arr[4][4];
  public:
  void arreglado();
  matriz();
  void print();
  void mov(char);
  bool fin();
};
void matriz::arreglado(){
  for(int (*p)[4]=arr;p<arr+4;p++){
	  for(int *y=*p;y<*p+4;y++){
	 		*y=((y-*p))+(4*(p-arr));
  	}
  }
  f=3;c=3;
  *(*(arr+f)+c)=-1;
}
matriz::matriz(){
  arreglado();
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
void matriz::print(){
  for(int (*i)[4]=arr;i<arr+4;i++){
    for(int *j=*i;j<*(i+1);j++){
      if(*j!=-1){
        if(*j<10){
          cout<<0;
        }
        cout<<*j;
      }
      else{
        cout<< "  ";
      }
      if(j==*i+3){
        cout<<endl;
      }
      else{
        cout<<" ";
      }
    }
  }
}
void matriz::mov(char n){
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
bool matriz::fin(){
  bool b=0;
  for(int (*p)[4]=arr;p<arr+4;p++){
		for(int *y=*p;y<*(p+1);y++){
			if(!((p-arr)==3 && (y-*p==3))&& (y-*p)+4*(p-arr)==*y){
			  b=b||0;
			}
			else if(p-arr==3 && (y-*p==3) && *y==-1){
			  b=b||0;
			}
			else{
			  b=1;
			}
		}
	}
	return b;
}
int main(){
	matriz x;
	x.print();
	char c;
	while(x.fin()){
	  cin>>c;
	  x.mov(c);
	  x.print();
	}
	cout<<"ganaste"<<endl;
	return 0;
}
