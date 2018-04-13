#include <stdio.h>
#include <stdlib.h>
#define MAXINT 32767
#define MININT -32768

int main()
{
    int numeroUno;
    int numeroDos;
    char operador;
    int total;
    float totalD;
    int flag=0;

    numeroUno=ingresarNumeroEntero();
    numeroDos=ingresarNumeroEntero();
    do
    {
    printf("ingrese un operador para calcular \n");
    fflush(stdin);
    scanf("%c", &operador);
    switch(operador)
    {
    case('+'):
        if(sumar(numeroUno, numeroDos, &total)==0)
        {
            printf("el resultado de la suma es: %d \n", total);
            flag=0;
        }
        else
        {
            printf("OVERFLOW \n");
        }
        break;
    case('-'):
        if(restar(numeroUno, numeroDos, &total)==0)
        {
            printf("el resultado de la resta es: %d \n", total);
            flag=0;
        }
        else
        {
            printf("OVERFLOW \n");
        }
        break;
    case('*'):
        if(multiplicar(numeroUno, numeroDos, &total)==0)
        {
            printf("el resulado de la multiplicacion es: %d", total);
            flag=0;
        }
        else
        {
            printf("OVERFLOW \n");
        }
        break;
    case('/'):
        if(dividir(numeroUno, numeroDos, &totalD)==0)
        {
            printf("el resultado de la division es: %.2f \n", totalD);
            flag=0;
        }
        else
        {
           printf("resultado indeterminado \n");
        }
        break;
    default:
        {
            printf("operador invalido \n");
        flag=1;
        }
    }
    }while(flag==1);

    return 0;
}
