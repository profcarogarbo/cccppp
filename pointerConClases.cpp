//Programa que imprime varios casos para el manejo de pointers en C++

//fuentes:
//            https://www.tutorialspoint.com/cplusplus/cpp_strings.htm
//            https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Herencia



#include <iostream> //libreria basica
#include <cmath>    //libreria especializada para funciones matematicas
using namespace std; //libreria estandar para las impresiones
 


int glob;  //este es un ejemplo de definicion de variable global

#define PI 3.14159  //este es una ejemplo de CONSTANTE 


/* Para la declaracion de funciones
variableDeSalida=  se escribe el tipo de variable, solo puede ser una de las siguientes int, double, float
variablesDeEntrada= se escriben el tipo de variable y el nombre que se le quiere dar dentro de la funcion, para todas las cantidades que pretende manejar. Los tipos de variables pueden ser: int, double, float, int[], double[], float[], int[][], double[][], float[][], int*, double*, float*, int&, double&, float&,
 la sintaxis para la declaracion de funciones es

             variablesDeSalida nombreFuncion(variablesDeEntrada);

esto es lo mismo que decir
                 output functionName(input);
con la salvedad que el input pueden ser varias variables
*/


// DECLARACIONES : estas se hacen antes del main
//
int factorial(int a);
void dont_modify( double a);
void modify1( double *a);  //aqui la entrada es un apuntador a donde se almacena la variable a
void modify2( double &a); //aqui la entrada es la direccion en memoria de la variable a
void sine_func( double x[], double f[], int N);




// Definición de una clase base para vehiculos, este ejemplo es para definir clases y clases que llaman a otras clases
class VehiculoRodante
{
     public:
 // CICLO DE VIDA
 /* En este lugar se sitúan los constructores, los destructores, y/o los constructores copia */

 // OPERADORES
 /* Aquí van los métodos que se apliquen sobre operadores */

 // OPERACIONES
 /* Aquí van los métodos de esta clase que no sean ni de acceso ni de petición o tratamiento */

 /*
 * Función 'set_ruedas'
 * Recibe: num como int
 * Devuelve: void
 * Asigna al dato miembro 'mRuedas' el valor 'num'
 */
  void set_ruedas(int num)
  {
    this->mRuedas = num;
  }

 /*
 * Función 'get_ruedas'
 * Recibe: void
 * Devuelve: int
 * Devuelve el valor que hay dentro del dato miembro 'mRuedas'
 */
  int get_ruedas(void)
  {
    return this->mRuedas;
  }

 /*
 * Función 'set_pasajeros'
 * Recibe: num como int
 * Devuelve: void
 * Asigna al dato miembro 'mPasajeros' el valor 'num'
 */
 void set_pasajeros(int num)
 {
  this->mPasajeros = num;
 }

 /*
 * Función 'get_pasajeros'
 * Recibe: void
 * Devuelve: int
 * Devuelve el valor que hay dentro del dato miembro 'mPasajeros'
 */
 int get_pasajeros(void)
 {
  return this->mPasajeros;
 }

 // PETICIONES/TRATAMIENTOS
 /* Aquí van las funciones del tipo "Is", que generalmente devuelven true/false */

private:
 /* Generalmente en 'private' se sitúan los datos miembros */
 int mRuedas;
 int mPasajeros;
};

// Definición de una clase 'Camion' derivada de la clase base 'VehiculoRodante'.
class Camion : public VehiculoRodante
{

public:
 // CICLO DE VIDA
 /* En este lugar se sitúan los constructores, los destructores, y/o los constructores copia */

 // OPERADORES
 /* Aquí van los métodos que se apliquen sobre operadores */

 // OPERACIONES
 /* Aquí van los métodos de esta clase que no sean ni de acceso ni de petición o tratamiento */

 // ACCESO
 /* Aquí van las funciones de acceso a los datos miembro o variables propias del objeto */

 /*
 * Función 'set_carga'
 * Recibe: size como int
 * Devuelve: void
 * Asigna al dato miembro 'mCarga' el valor 'size'
 */
 void set_carga(int size)
 {
  this->mCarga = size;
 }

 /*
 * Función 'get_carga'
 * Recibe: void
 * Devuelve: int
 * Devuelve el valor que hay dentro del dato miembro 'mCarga'
 */
 int get_carga(void)
 {
  return this->mCarga;
 }


 /*
 * Función 'Mostrar'
 * Recibe: void
 * Devuelve: void
 * Muestra por pantalla las ruedas, pasajeros y la capacidad de carga del objeto 'Camion'
 */
 void Mostrar(void);

 // PETICIONES/TRATAMIENTOS
 /* Aquí van las funciones del tipo "Is", que generalmente devuelven true/false */

private:
 /* Generalmente en 'private' se sitúan los datos miembros */
 int mCarga;
};

void Camion::Mostrar(void)
{
  std::cout << "ruedas: " << this->get_ruedas() << std::endl; //Notar que en este ejemplo el cout esta en linea con std. Como se hizo la declaración al comienzo es posible quitar el std 
 std::cout << "pasajeros: " << this->get_pasajeros() << std::endl;
 std::cout << "Capacidad de carga en pies cúbicos: " << this->get_carga() << std::endl; //tanto "/n" como endl sirven para imprimir un enter o cambio de linea
}






// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// ----------------- AQUI COMIENZA EL PROGRAMA ---- el main puede empezar también como
//         void main()

// main() is where program execution begins.
int main() {
  glob=1.0;  //aqui estamos modificando una variable global, que fue creada antes
    
  int a=2; //aqui estamos creando una variable nueva
    int b=1;
    int i,j,k;
    double c=a*b*0.3; //esta variable tambien puede ser de tipo float
    
    cout << "Hello World" << endl; // prints Hello World with an enter
    
    cout << glob << endl;
    cout << PI << endl;
    cout << c << endl;
    
    //loops in c++
    for(i=0;i<10;i++){ //aca la sintaxis es diferente a la de PYTHON
        cout << i <<"!="<< factorial(i) << endl;
    }
    
    // how NOT to  modify variables
    cout << "a before " << a << endl;
    dont_modify(a);
    cout << "a after " << a << endl;

    
    // how to  modify variables
    c=1.0;
    double d=2.0;
    cout << "c before " << c << endl;
    modify1(&c);// en este renglón llamo a una función void, entonces no tengo que asignar una varible al resultado -- notar que estoy enviando la direccion de c
    cout << "c after " << c << endl;
    
    cout << "d before " << d << endl;
    modify2(d);// en este renglón llamo a una función void, entonces no tengo que asignar una varible al reultado
    cout << "d after " << d << endl;
    
    int N=1000;
    double x[N];
    double f[N];
    
    for(int i=0; i< N; i++){
        x[i]=(i+1)*2*PI/N;
        
    }
    cout << "2pi=" << x[N-1] << endl;
    sine_func(x, f,  N); // en este renglón llamo a una función void, entonces no tengo que asignar una varible al reultado
    cout << "sin(2pi)=" << f[N-1] << endl; //en este print compruebo que f conservó los valores asignados en la función

    
    
    /// Para usar las clase definidas
   Camion Camion1;
    Camion Camion2; //notar que ya no debe estar alineado con lo escrito anteriormente
    
    Camion1.set_ruedas(18);
  Camion1.set_pasajeros(2);
  Camion1.set_carga(3200);

  Camion2.set_ruedas(6);
  Camion2.set_pasajeros(3);
  Camion2.set_carga(1200);

  Camion1.Mostrar();
  std::cout << std::endl;
  Camion2.Mostrar();
  std::cout << std::endl;
    
    
        return 0; // en caso de void main, solo finaliza con return; o simplemente sin return
}
//este termina el main












// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// --- Aqui comienza el desarrollo de las funciones. Esto puede ir antes del main



int factorial(int a){
    
    int res=1;
    if(a!=0){
        for(int i=1;i<a+1;i++){
            res*=i;
            
        }
    }
    return res;
}

void dont_modify( double a){
    a=a*2;
}

// las siguientes dos funciones son "sinonimas" en el sentido que hacen lo mismo, aunque se escriba diferente
void modify1( double *a){
    *a = *a*2;

}
void modify2( double &a){
    a = a*2;
    
}


// en esta funcion estamos llenando una variable de entrada, para que luego se pueda imprimir en el MAIN
void sine_func( double x[],double f[], int N){

    for(int i=0; i<N; i++){
        f[i]=sin(x[i]);
    
    }
}


// para entender mas sobre apuntadores lea tambien
// http://agora.pucp.edu.pe/inf2170681/8.htm

