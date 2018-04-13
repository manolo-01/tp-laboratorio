#include <stdio.h>
#include <stdlib.h>
#include "file.h"
int hayNumeros(int banderaNumeroUno, int banderaNumeroDos);
int main()
{
    int opcion;
    int flagNumeroUno=1;
    int flagNumeroDos=1;
    do{
        int numeroUno;
        int numeroDos;
        int flag8=1;
        int resultado;
        float resultadoF;

      printf("1: Ingresar 1er operando, (A).\n");
      printf("2: Ingresar 2do operando, (B).\n");
      printf("3: Calcular la suma, (A+B).\n");
      printf("4: Calcular la resta, (A-B).\n");
      printf("5: Calcular la division, (A/B) .\n");
      printf("6: Calcular la multiplicacion, (A*B).\n");
      printf("7: Calcular el factorial (A!).\n");
      printf("8: Calcular todas las operaciones.\n");
      printf("9: Salir.\n");
      //getInt("seleccione una opcion: 1 a 9 \n","opcion invalida", 3,1,9,&opcion);

    if(getInt(" seleccione una opcion\n"," las opciones estan entre: 1 y 9 \n", 3,1,9,&opcion)==0)
    {
        printf(" ha elegido la opcion: %d \n", opcion);

        switch(opcion)
        {
        case(1):
            getInt("Ingrese el primer numero \n","el numero tiene que ser un entero \n",3,-32768,32767,&numeroUno);
            printf("ha ingresado el numero: %d \n", numeroUno);
            flagNumeroUno=0;
            break;
        case(2):
            getInt("ingrese el segundo numero \n","el numro tiene que ser entero \n",3,-32768,32767,&numeroDos);
            printf("ha ingresado el numero: %d \n", numeroDos);
            flagNumeroDos=0;
            break;

        case(8):
            flag8=0;
        case(3):
            if(hayNumeros(flagNumeroUno,flagNumeroDos)==0)
            {
               if(suma(numeroUno,numeroDos,&resultado)==0)
                printf("el resultado de la suma es: %d \n", resultado);
                else
                    printf("overflow \n");
            }
            if(flag8)
            break;
        case(4):
            if(hayNumeros(flagNumeroUno,flagNumeroDos)==0)
            {
                if(resta(numeroUno,numeroDos,&resultado)==0)
                printf("el resultado de la resta es: %d \n", resultado);
                else
                    printf("overflow \n");
            }
            if(flag8)
            break;
        case(5):
            if(hayNumeros(flagNumeroUno,flagNumeroDos)==0)
            {
                if(dividir(numeroUno,numeroDos,&resultadoF)==0)
                printf("el resultado de la division es: %.2f \n", resultadoF);
                else
                    printf("resultado indeterminado \n");
            }
            if(flag8)
            break;
        case(6):
            if(hayNumeros(flagNumeroUno,flagNumeroDos)==0)
            {
                if(multiplicar(numeroUno,numeroDos,&resultado)==0)
                printf("el resultado de la multiplicacion es: %d \n", resultado);
                else
                    printf("overflow \n");
            }
            if(flag8)
            break;

        case(7):
            if(flagNumeroUno==0)
            {
                int devolucionFuncion=factorial(numeroUno, &resultado);
                if(devolucionFuncion==0)
                printf("el factorial de %d es: %d \n",numeroUno,resultado);
                else if(devolucionFuncion==-1)
                printf("operacion invalida, el operando debe ser mayor a cero \n");
                else
                    printf("overflow \n");
            }
            else
            {
                printf("debe ingresar el primer numero \n\n");
            }
            break;
        /*case(8):
            if(hayNumeros(flagNumeroUno, flagNumeroDos)==0)
                {
                    suma(numeroUno, numeroDos, &resultado);
                    printf("suma= %d\n",resultado);
                     resta(numeroUno, numeroDos, &resultado);
                    printf("resta= %d\n",resultado);
                     dividir(numeroUno, numeroDos, &resultadoF);
                    printf("dividir= %f\n",resultadoF);
                     multiplicar(numeroUno, numeroDos, &resultado);
                    printf("producto= %d\n",resultado);
                     if(factorial(numeroUno, &resultado)==0)
                printf("el factorial de %d es: %d \n",numeroUno,resultado);
                else
                printf("operacion invalida, el operando debe ser mayor a cero \n");
                    printf("%d!= %d\n\n",numeroUno,resultado);
                }

            break;*/
        default:
            break;
        }
    }
    else
    {
        printf(" error \n");
    }
    }while(opcion!=9);

    return 0;
}
/** \brief la funcion se utiliza pra evaluar si los dos operandos estan cargados.
 *
 * \param int banderaNumeroUno cuando la variable es 0 se considera que el primer operando fue cargado.
 * \param int banderaNumeroDos cuando la variable es 0 se considera que el segundo operando fue cargado.
 * \return int retorno devuelve cero en caso de que los dos operandos esten cargados
 *
 */
int hayNumeros(int banderaNumeroUno, int banderaNumeroDos)
{
    int retorno=-1;
            if((banderaNumeroUno+banderaNumeroDos)==0)
                {
                retorno=0;
                }
            else if(banderaNumeroUno==1)
                {
                printf("debe ingesar el primer numero \n\n");
                }
            else
                {
                printf("debe ingresar el segundo numero \n\n");
                }
            return retorno;
}
