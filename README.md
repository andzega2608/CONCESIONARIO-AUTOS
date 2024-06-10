# Concesionario Autos
El presente proyecto trata sobre un concesionario de vehículos de todo tipo, como ser automóviles, buses de transporte y motocicletas de todo tipo. De ese modo, el programa principal se encarga de generar una estructura de clases con el fin de poder indicar las características de cada vehículo. Por ejemplo, los automóviles pueden presentar características como número de puertas, el tipo de caja (manual o automática) y si posee techo panorámico. Por otro parte, los buses se caracterizan por tener en cuenta la capacidad de pasajeros que pueden llevar, así también como el tipo de caja del mismo. Para el caso de las motocicletas, estás solo podrán ser del tipo deportivas o no. Es importante mencionar que cada una de estas clases heredarán atributos y métodos de una clase padre como la será la clase Vehículo, esta incluirá como atributos marca, modelo, kilometraje, color, tipo de energía (gasolina, diésel o eléctrico) y esencialmente el precio.   
## Funcionalidad
El programa permitirá agregar vehículos con sus respectivas características. Adicionalmente, será capaz de mostrar las características de cada vehículo y a partir de ello, calcular el precio en dólares americanos USD. Del mismo modo, el programa será que capaz de mostrar todo el catálogo que posee el concesionario. Asimismo, se podrá realizar una búsqueda filtrada acorde al tipo de vehículos, por ejemplo, si solo se quiere obtener información de los buses disponibles dentro de la compañía se podrá realizar. Adicionalmente, el programa será capaz de realizar una búsqueda entre los vehículos según una característica específica dada por el usuario, como ser buscar vehículos según una determinada marca, o incluso buscar vehículos según un determinado rango de precio. 
## Consideraciones
El programa será construido netamente con el lenguaje C++ standard y correrá solo en consola. 
compilar con: "g++ Vehiculo.h Concesionario.h Main.cpp"
correr en linux: "/a.out"
correr en windows: "a.exe"

Del mismo es importante mencionar que el programa incluye algunos ejemplos de vehículos definidos por default, De ese modo, es importante considerar que estos son inventados con el objetivo de poder realizar pruebas de funcionalidad con el programa. Por lo cual, es importe tomar en cuenta lo anterior, se va a emplear el programa en producción. 
Adicionalmente, el programa consta de un menú, cuyas opciones son las siguientes: 
1. Agregar auto
2. Agregar bus
3. Agregar motocicleta
4. Mostrar todo el catálogo
5. Mostrar por tipo de vehículo
6. Mostrar por marca y kilometraje
7. Mostrar por precio
8. Salir

Mediante estas, se podrá agregar un nuevo vehículo, así también se podrá realizar una búsqueda acorde a algunas características de los vehículos. 
## Restricciones
Algunos casos que generen que el programa deje de funcionar es la introducción incorrecta del tipo de datos. Es importante entender que cada constructor requiere un determinado tipo de dato, como ser enteros, valores flotantes, cadenas de caracteres e incluso el mismo programa requiere valores booleanos. Si se introduce un tipo de valor erróneo en un constructor, método o en otras funciones el programa sufrirá problemas. Del mismo modo, es importante tener en cuenta la longitud del vector Vehiculos[] creado para almacenar los datos de los vehículos, ya que en caso que se supere dicha longitud se crearán datos basura. La longitud definida por el programa es de 200 vehículos, en caso que se supere, habrá un desbordamiento de datos. 

Dejando de lado lo mencionado anteriormente, es importante tener muy en cuenta la entrada de datos al momento de realizar una búsqueda específica según alguna característica específica. En caso que se quiera filtrar el catálogo según la marca, es importante introducir el nombre respetando letras mayúsculas y minúsculas. Esto debido a que programa toma en cuenta el uso de estas. Por ejemplo, si una quiere filtrar autos de la marca "Audi" o "Mercedes Benz", se debe introducir estos datos exactamente de la forma anterior. Esto debido a que, si se introduce "audi" o "mercedes benz", el programa no encontrará coincidencias por lo que indicará que no hay vehículos de ese tipo de auto. Lo mismo ocurre al momento de realizar una búsqueda de los vehículos según el tipo de los mismo. Para poder realizar la búsqueda se debe introducir "Auto", "Bus" o "Motocicleta". Caso contrario el programa no funcionará de la manera correcta y no realizará la búsqueda que se quiere realizar.    
## Correcciones
En el apartado de correcciones, en un principio se aplicó de una manera ineficaz el tema de sobreescritura. El problema fue que en la clase padre class Vehiculo los métodos que se están sobrescribiendo (calcular_precio(), mostrar_caracteristicas()) no se definieron previamente. De ese modo, con el fin de corregir lo mencionado anteriormente, se implementó el concepto de polimorfismo y clases abstractas. Es decir, la clase padre se definió como clase abstracta. Por tanto, ambos métodos se definieron de la siguiente forma. 

virtual int calcular_precio() = 0;
virtual string mostrar_caracteristicas() = 0;

Adicionalmente, es importante mencionar que, los métodos anteriores fueron sobreescritos en las respectivas clases hijas Auto, Bus y Motocicleta. 

Otra corrección que se realizó fue en el Main.cpp al generar una búsqueda según la marca de los vehículos. Pues, existen marcas como Mercedes Benz, la cual consta de dos palabras. De esa forma al momento de filtrar acorde a dicha marca, el programa presentaba un error por el tema de la tecla “space”. De esa forma, con el fin de poder solucionar dicho error, se implementó la función getline(cin, marca). Mediante esto, se soluciona dicho problema. 
