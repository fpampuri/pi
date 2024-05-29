

typedef struct imagCDT * imagADT;

imagADT nuevoIm(double real, double imag);

double parteReal(imagADT z);

double parteImag(imagADT z);

imagADT suma(imagADT z, imagADT w);

imagADT resta(imagADT z, imagADT w);

imagADT mult(imagADT z, imagADT w);

imagADT conjugado(imagADT z);

double norma(imagADT z);

void liberaIm(imagADT z);
