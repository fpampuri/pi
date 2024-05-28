
typedef struct stackCDT * stackADT;
typedef double elemType;
typedef int (*fnEquals)(elemType, elemType);

stackADT newStack(fnEquals);

void freeStack(stackADT stack);

int isEmpty(const stackADT stack);

void push(stackADT stack, elemType elem);

elemType pop(stackADT stack);

int sizeStack(const stackADT stack);

int belongs(const stackADT stack, elemType elem);