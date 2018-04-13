#include <stdio.h>
#include <stdlib.h>
/** \brief
 *
 * \param char *mensaje da informacion acerca de lo que se debe ingresar por teclado
 * \param char *mensajeError indica que se cometio un error en la carga de datos
 * \param int reintentos cantidad de veces en las que se puede cometer un error al cargar la informcion
 * \param int minimo primer valor de referencia para validar lo que se ingresa
 * \param int maximo segundo valor de reerencia para la validacion de lo que se ingresa
 * \param int *resultado devuelve -1 cuando se hayan us
 * \return int retorno devuelve -1 cuando se haya superado ellimite de ingresos erroneos
 *
 */
int getInt(char *mensaje, char *mensajeError, int reintentos, int minimo, int maximo, int* resultado)
{
    int retorno=-1;
    int dato;
    int rtaScanf;
    do
    {
        reintentos--;
        printf("%s\n", mensaje);
	fflush(stdin);
        rtaScanf=scanf("%d", &dato);
	if(rtaScanf!=1)
	{
	printf("solo numeros! \n");
	continue;
	}
        if(dato<=maximo && dato>=minimo)
        {
        *resultado=dato;
        retorno=0;
        break;
        }
        printf("%s", mensajeError);
    }while(reintentos>=0);

    return retorno;
}

/** \brief la funcion permite obtener un caracter entre dos definidos a partir de distintos parametros
 *
 * \param char *mensaje da informacion acerca de lo que hay que ingresar por teclado
 * \param char *mensajeError indica que se cometio un error en la carga dedatos
 * \param int reintentos numero entero que indica va a ser el limite para los intento de carga de de los datos
 * \param char opcionA primer caracter de referencia para validar los datos a inresar
 * \param char opcionB segundo caracter de referencia para la validacion de datos
 * \param char *resultado direccion  de memoria de la variable donde se guardara el resulado de la suma
 * \return int retorno devuelve -1 luego de superar el limite de ingresos erroneos
 *
 */
int getChar(char *mensaje, char *mensajeError, int reintentos, char opcionA, char opcionB, char* resultado)
{
    int retorno=-1;
    char dato;
    printf("opcionA: %c", opcionA);
    printf("opcionB: %c", opcionB);
    //int rtaScanf;
    do
    {
        reintentos--;
        printf("%s\n", mensaje);
        fflush(stdin);
        scanf("%c", &dato);
        printf("ha ingresado: %c", dato);


        if(dato==opcionA)
        {
        *resultado=dato;
        retorno=0;
        break;
        }
        if(dato==opcionB)
        {
        *resultado=dato;
       retorno=0;
       break;
        }
        printf("%s", mensajeError);
    }while(reintentos>0);

    return retorno;
}


/** \brief recibe dos numeros enteros y calcula la suma de ellos.
 *
 * \param int numeroSumaUno primer numero entero a sumar.
 * \param int numeroSumaDos segundo numero entero a sumar.
 * \param int *resultado direccion de memoria de la variable donde se guardara el resultado de la suma
 * \return int retorno devuelve -1 en caso de desbordamiento.
 *
 */


int suma(int numeroUno, int numeroDos, int*resultado)
{
    int retorno=-1;
    long sumaAuxiliar;
    sumaAuxiliar=numeroUno+numeroDos;
    if(sumaAuxiliar<32767 &&  sumaAuxiliar>-32768)
    {
       *resultado=sumaAuxiliar;
       retorno=0;
    }
    return retorno;
}
/** \brief la funcion realiza la resta entre dos enteros
 *
 * \param int numeroUno primer valor para operar
 * \param int numeroDos segundo valor para realizar la operacion
 * \param int *resultado direccion de memoria de la variable donde se guardara el resultado de la resta
 * \return int devuelve -1 en caso de desbordamiento
 *
 */
int resta(int numeroUno, int numeroDos, int*resultado)
{
    int retorno=-1;
    long restaAuxiliar;
    restaAuxiliar=numeroUno-numeroDos;
    if(restaAuxiliar<32767 &&  restaAuxiliar>-32768)
    {
       *resultado=restaAuxiliar;
       retorno=0;
    }
    return retorno;
}
/** \brief la funcion calcula el producto entre dos valores.
 *
 * \param int numeroUno variable entera que tiene elprimr valor para multiplicar.
 * \param int numeroDos  variable ntera que tiene el segundo valor a multiplicar
 * \param int*resultado direcion de memoria de la variable donde se cargara el resultado.
 * \return int retorno devuelve informacion acerca del resultado,-1 cuando se produjo un desbordamiento
 *
 */
int multiplicar(int numeroUno, int numeroDos, int*resultado)
{
    int retorno=-1;
    long productoAuxiliar;
    productoAuxiliar=numeroUno*numeroDos;
    if(productoAuxiliar<32767 &&  productoAuxiliar>-32768)
    {
       *resultado=productoAuxiliar;
       retorno=0;
    }
    return retorno;
}
/** \brief la funcion calcula la division entre dos valores
 *
 * \param int numeroUno divisor de la division
 * \param int numeroDos dividendo de la division
 * \param float *resultado direccion de memoria donde hay que cargar el resultado de la division
 * \return int retorno se utiliza para informar si la operacion es posible, -1 cuando el divisor es cero.
 *
 */
int dividir(int numeroUno, int numeroDos, float *resultado)
{
    int retorno=-1;
    if(numeroDos!=0)
    {
        *resultado=(float)numeroUno/numeroDos;
        retorno=0;
    }
    return retorno;
}
/** \brief la funcion calcula el factorial del valor de una variable entera
 *
 * \param int numero variable entera que tiene cargado el valor a calcular.
 * \param int *resultado direccion de memoria donde hay que cargar el factorial de numero.
 * \return int retorno la funcion retorna 0 encaso de que la operacion sea valida y -1 cuando hay un error.
 *
 */
int factorial(int numero, int *resultado)
{
	int retorno=-1;
	int i;
	long auxFactorial=1;
	if (numero>0)
	{
        for(i=1;i<=numero;i++)
        auxFactorial=auxFactorial*i;
        if(auxFactorial<32767)
        {
        *resultado=auxFactorial;
        retorno=0;
        }
        retorno=-2;
	}
	return retorno;
}
