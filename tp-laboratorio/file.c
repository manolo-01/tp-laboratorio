#include <stdio.h>
#include <stdlib.h>

/** \brief solicita un numero entero y lo retorna.
 *
 * \param
 * \param
 * \return numero entero ingresado por elsuario.
 *
 */
int ingresarNumeroEntero()
{
    int retorno=-1;
    int numero;
    int rtaScanf;
    do
    {
        fflush(stdin);
        printf("ingrese un numero entero \n");
        rtaScanf=scanf("%d", &numero);
        if(rtaScanf!=1)
        {
            printf("solo numeros! \n");
        }
    }while(rtaScanf==0);
   printf("ha ingresado el numero %d \n", numero);

    return retorno;
}
/** \brief recibe dos numeros enteros y calcula la suma de ellos.
 *
 * \param numeroSumaUno primer numero entero a sumar.
 * \param numeroSumaDos segundo numero entero a sumar.
 * \return retorna el resultado de la suma.
 *
 */

int sumar(int numeroSumaUno, int numeroSumaDos, int *resultado)
{
    int flag=1;
   long sumaAuxiliar;
   sumaAuxiliar=numeroSumaUno+numeroSumaDos;
   if(sumaAuxiliar<MAXINT)
   {
        *resultado=sumaAuxiliar;
       flag=0;
   }
   return flag;
}
/** \brief recibe dos numeros enteros y calcula la resta.
 *
 * \param numeroRestaUno numero entero a restar.
 * \param numeroRestaDos numero entero que sustrae.
 * \return retorna la diferencia entre los ds numeros.
 *
 */

int restar(int numeroRestaUno, int numeroRestaDos, int *resultado)
{
    int flag=1;
    long restaAuxiliar;
    restaAuxiliar=numeroRestaUno-numeroRestaDos;
    if(restaAuxiliar>-MININT)
    {
        *resultado=restaAuxiliar;
        flag=0;
    }
    return flag;
}
/** \brief recibe dos numeros enteros y calcula el producto.
 *
 * \param multiplicadorUno primer factor de la operacion.
 * \param multiplicadorDos segundo factor de la operacion.
 * \return retorna el resulado de la multplicacion.
 *
 */

int multiplicar(int multiplicadorUno, int multiplicadorDos, int *resultado)
{
    int flag=1;
    long productoAuxiliar;
    productoAuxiliar=multiplicadorUno*multiplicadorDos;
    if(productoAuxiliar<MAXINT)
    {
        *resultado=productoAuxiliar;
        flag=0;
    }
    return flag;
}
/** \brief recibe dos numeros y calcula la relacion entre ellos.
 *
 * \param dividendo numero a dividir.
 * \param divisor numero para fraccionar el dividendo.
 * \return retorna el resultado de la division entre los dos numeros ingresados.
 *
 */

float dividir(int dividendo, int divisor, float *resultado)
{
    int flag=1;
    if(divisor!=0)
    {
        *resultado=(float)dividendo/divisor;
        flag=0;
        //printf("\n prueba dividendo %d \n",dividendo);
        //printf("\n prueba divisor %d \n",divisor);
        //printf("\n prueba resultado %.2f \n",*resultado);
    }
    return flag;
}
int factorial(int numero, int *resultado)
{
int retorno=-1;
int i;
int auxFactorial=1;
if (numero>0)
{
for(i=1;i<=numero;i++)
auxFactorial=auxFactorial*i;
*resultado=auxFactorial;
retorno=0;
}
return retorno;
}
