# Concesionario Autos
El presente proyecto trata sobre un concesionario de vehículos de todo tipo, como ser automóviles, buses de transporte y motocicletas de todo tipo. De ese modo, el programa principal se encarga de generar una estructura de clases con el fin de poder indicar las características de cada vehículo. Por ejemplo, los automóviles pueden presentar características como número de puertas, el tipo de caja (manual o automática) y si posee techo panorámico. Por otro parte, los buses se caracterizan por tener en cuenta la capacidad de pasajeros que pueden llevar, así también como el tipo de caja del mismo. Para el caso de las motocicletas, estás solo podrán ser del tipo deportivas o no. Es importante mencionar que cada una de estas clases heredarán atributos y métodos de una clase padre como la será la clase Vehículo, esta incluirá como atributos marca, modelo, kilometraje, color, tipo de energía (gasolina, diésel o eléctrico) y esencialmente el precio.   
## Funcionalidad
El programa permitirá agregar vehículos con sus respectivas características. Adicionalmente, será capaz de mostrar las características de cada vehículo y a partir de ello, calcular el precio en dólares americanos USD. Del mismo modo, el programa será que capaz de mostrar todo el catálogo que posee el concesionario. Asimismo, se podrá realizar una búsqueda filtrada acorde al tipo de vehículos, por ejemplo, si solo se quiere obtener información de los buses disponibles dentro de la compañía se podrá realizar. Adicionalmente, el programa será capaz de realizar una búsqueda entre los vehículos según una característica específica dada por el usuario, como ser buscar vehículos según una determinada marca, o incluso buscar vehículos según un determinado rango de precio. 
## Consideraciones
El programa será construido netamente con el lenguaje C++ standard y correrá solo en consola. 
## Restricciones
Algunos casos que generen que el programa deje de funcionar es la introducción incorrecta del tipo de datos. Es importante entender que cada constructor requiere un determinado tipo de dato, como ser enteros, valores flotantes, cadenas de caracteres e incluso el mismo programa requiere valores booleanos. Si se introduce un tipo de valor erróneo en un constructor, método o en otras funciones el programa sufrirá problemas. Del mismo modo, es importante tener en cuenta la longitud del vector Vehiculos[] creado para almacenar los datos de los vehículos, ya que en caso que se supere dicha longitud se crearán datos basura. La longitud definida por el programa es de 200 vehículos, en caso que se supere, habrá un desbordamiento de datos. 
Dejando de lado lo mencionado anteriormente, es importante tener muy en cuenta la entrada de datos al momento de realizar una búsqueda específica según alguna característica específica. En caso que se quiera filtrar el catálogo según la marca, es importante introducir el nombre respetando letras mayúsculas y minúsculas. Esto debido a que programa toma en cuenta el uso de estas. Por ejemplo, si una quiere filtrar autos de la marca "Audi" o "Mercedes Benz", se debe introducir estos datos exactamente de la forma anterior. Esto debido a que, si se introduce "audi" o "mercedes benz", el programa no encontrará coincidencias por lo que indicará que no hay vehículos de ese tipo de auto. Lo mismo ocurre al momento de realizar una búsqueda de los vehículos según el tipo de los mismo. Para poder realizar la búsqueda se debe introducir "Auto", "Bus" o "Motocicleta". Caso contrario el programa no funcionará de la manera correcta y no realizará la búsqueda que se quiere realizar.    
