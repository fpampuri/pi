#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int balance(char * s){
    if(*s == 0)
        return 0;
    if(*s == '(')
        return -1 + balance(s + 1);
    else if(*s == ')')
        return 1 + balance(s+1);
    else
        return balance(s+1);
}

int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}