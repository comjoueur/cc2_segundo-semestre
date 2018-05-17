#include <iostream>
using namespace std;
class cubo{
  int A[3][3][3];
  public:
  cubo();
  void push(int,int,int,char);
  void imprimir();
  bool completado();
  bool finish();
};
void tripleta(bool*,int*,int*,int*);
int main() {
  cubo A;
  bool f=1;
  bool jugador=0;
  while(!A.finish()&&f){
    int a,b,c;
    A.imprimir();
    if(!jugador)cout<<"turno jugador 1"<<endl;
    else cout<<"turno jugador 2"<<endl;
    cin>>a>>b>>c;
    if(!jugador)A.push(a,b,c,'x');
    else A.push(a,b,c,'o');
    if(A.completado()){
      f=0;
    }
    jugador=!jugador;
  }
  A.imprimir();
  if(f){
    if(jugador)cout<<"gano jugador 1"<<endl;
    else cout<<"gano jugador 2"<<endl;
  }
  else cout<<"empate"<<endl;
  return 0;
}
cubo::cubo(){
  for(int (*i)[3][3]=A;i<A+3;i++){
    for(int (*j)[3]=*i;j<*(i+1);j++){
      for(int *k=*j;k<*(j+1);k++){
        *k=0;
      }
    }
  }
}
void cubo::push(int x,int y,int z,char a){
  if(a=='o'){
    *(*(*(A+x)+y)+z)=1;
  }
  else{
    *(*(*(A+x)+y)+z)=2;
  }
}
void cubo::imprimir(){
  for(int (*i)[3][3]=A;i<A+3;i++){
    for(int (*j)[3]=*i;j<*(i+1);j++){
      for(int *k=*j;k<*(j+1);k++){
        if(*k==0){
          cout<<"?";
        }
        else if(*k==1){
          cout<<'o';
        }
        else {
          cout<<'x';
        }
      }
      cout<<endl;
    }
    cout<<endl;
  }
}
bool cubo::completado(){
  bool b=0;
  for(int (*i)[3][3]=A;i<A+3;i++){
    for(int (*j)[3]=*i;j<*(i+1);j++){
      for(int *k=*j;k<*(j+1);k++){
        b=b||(*k==0);
      }
    }
  }
  return !b && !finish();
}
bool cubo::finish(){
  bool rsp=0;
  tripleta(&rsp,**A,**A+1,**A+2);
  tripleta(&rsp,*((*A)+1),*((*A)+1)+1,*((*A)+1)+2);
  tripleta(&rsp,*((*A)+2),*((*A)+2)+1,*((*A)+2)+2);
  tripleta(&rsp,**A,*(*A+1),*(*A+2));
  tripleta(&rsp,*((*A))+1,*((*A)+1)+1,*((*A)+2)+1);
  tripleta(&rsp,*((*A)+0)+2,*((*A)+1)+2,*(*A+2)+2);
  tripleta(&rsp,**A,*(*A+1)+1,*(*A+2)+2);
  tripleta(&rsp,*(*A)+2,*(*A+1)+1,*(*A+2));
  return rsp;
}
void tripleta(bool *p,int *a,int *b,int *c){
  *p=*p||((*a==*b)&&(*b==*c)&&(*a>0));
}
