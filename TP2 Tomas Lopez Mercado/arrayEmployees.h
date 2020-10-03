
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

/** \brief Esta funcion pone el flag "isEmpty" en 0 en todas las posiciones del array
 * \param recibe un array de tipo Employee
 * \param recibe el limite del array para poder iterar
 * \return
 */
int limpiarArray(Employee arrayEmployees[], int limiteArray);


/** \brief Esta funcion genera el parametro ID de la estructura Employee para todas las pociciones del array
 * \param recibe un array de tipo Employee
 * \param recibe el limite del array para poder iterar
 * \return
 */
int generarID(Employee arrayEmployees[], int limiteArray);


/** \brief Imprime los datos de un solo empleado
 * \param recibe una posicion del array de la estructura Employee
 * \return
 */
int imprimirUnEmpleado(Employee arrayEmployees);


/** \brief Carga los datos de un solo empleado
 * \return Devuelve los datos correspondientes a todos los campos completos de la estructura Employee
 */
Employee cargarUnEmpleado();


/** \brief Devuelve una posicion vacia del array
 * \param recibe un array de tipo Employee
 * \param recibe el limite del array para poder iterar
 * \return devulve una posicion vacia del array
 */
int buscarPosicionVacia(Employee arrayEmployees[], int limiteArray);


/** \brief Carga los datos de empleados en las posiciones vacias que encuentre
 * \param recibe un array de tipo Employee
 * \param recibe el limite del array para poder iterar
 */
int cargarArrayEmpleados(Employee arrayEmployees[], int limiteArray);

/** \brief Imprimie una lista con las posiciones del array de tipo Employee que hayan sido cargadas
 * \param recibe un array de tipo Employee
 * \param recibe el limite del array para poder iterar
 */
int listarEmpleados(Employee arrayEmployees[], int limiteArray);

/** \brief Permite modificar un solo parametro de la estructura Employee en una posicion determinada por el ID
 * \param recibe un array de tipo Employee
 * \param recibe el limite del array para poder iterar
 * \return
 */
int modificarEmpleadoPorId(Employee arrayEmployees[], int idAModificar, int limiteArray);

/** \brief Localiza la posicion del array de una empleado mediante el ID
 * \param recibe un array de tipo Employee
 * \param recibe el id que se va a utilizar para buscar la posicion del array deseada
 * \param recibe el limite del array para poder iterar
 * \return
 */
int buscarEmpleadoPorId(Employee arrayEmployees[], int idBusqueda, int limiteArray);

/** \brief guarda las modificaciones que se hayan hecho en una determinada posicion del array
 * \param recibe un array de tipo Employee
 * \param recibe el ID del empleado el cual se va a querer modificar
 * \return devuelve la posicion modificada
 */
Employee modificarEmpleado(Employee arrayEmployees, int idAModificar);

/** \brief permite dar de baja un empleado mediante la busqueda de id
 * \param recibe un array de tipo Employee
 * \param recibe el id del empleado que se quiere dar de baja
 * \param recibe el limite del array para poder iterar
 * \return
 */
int eliminarEmpleadoPorId(Employee arrayEmployees[], int idBusqueda, int limiteArray);

/** \brief ordena los empleados por apellido y en caso de encontrar 2 apellidos iguales los ordena por sector
 * \param recibe un array de tipo employee
 * \param recibe la cantidad maxima del array para poder iterar
 * \return
 */
int OrdenarEmpleadosPorNombre (Employee arrayEmpleados[], int cantidad);

/** \brief calcula el salario promedio de todos los empleados cargados
 * \param recibe un array de tipo Employee
 * \param recibe una cantidad maxima del array para pdoer iterar
 * \return devuelve el salario promedio ya calculado
 */
float calcularSalarioPromedio(Employee arrayEmployees[], int limiteArray);

/** \brief calcula el salario total de todos los empleados cargados
 * \param recibe un array de tipo employee
 * \param recibe una cantidad maxima del array para poder iterar
 * \return devuelve el salario total calculado
 */
float calcularSalarioTotal(Employee arrayEmployees[], int limiteArray);
