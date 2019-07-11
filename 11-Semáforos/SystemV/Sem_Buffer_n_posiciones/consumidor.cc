#include "includes.h"
#include "Area.h"
#include "../Sem-posix/p_shm.h"
#include "../Sem-posix/p_sem.h"

int main(){
  Area * a;
  p_shm a51("Area51");
  a= static_cast <Area*>(a51.map(sizeof(Area)));
  p_sem prod("A51p",5);
  p_sem cons("A51c",0);
  Mensaje dato;
  cout<<"Consumiendo"<<endl;
  while (true){
    cons.wait();
    if (a->esUltimo()) break;
    dato=a->saca();
    cout<<"Leido<"<<dato.getDato()<<">"<<endl;
    cout<<"Consumiendo"<<endl;
    prod.post();
  }
  cout<<"Productor termina"<<endl;
  a51.del();
  prod.del();
  cons.del();
}
    