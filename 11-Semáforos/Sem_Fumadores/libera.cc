#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
using namespace std;

int main(int argc, char * argv[]){
  sv_sem papel("papel",0);
  sv_sem tabaco("tabaco",0);
  sv_sem fosforos("fosforos",0);
  papel.del();
  tabaco.del();
  fosforos.del();
}