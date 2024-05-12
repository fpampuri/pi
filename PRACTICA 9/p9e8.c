/* ACK ( 0,N ) = N + 1
ACK ( M,0 ) = ACK ( M - 1, 1 )
ACK ( M,N ) = ACK ( M - 1, ACK ( M , N - 1 ) )
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int ackRec(int num1, int num2);

int ack(int num1, int num2){
    if(num1 < 0 || num2 < 0)
        return -1;
    return ackRec(num1, num2);
}

int ackRec(int n1, int n2){
    if(n1 == 0)
        return n2+1;
    if(n2 == 0)
        return ackRec(n1-1, 1);
    else return ackRec(n1-1, ackRec(n1, n2-1));
}
