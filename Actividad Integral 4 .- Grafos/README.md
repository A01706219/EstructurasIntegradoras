Activiad integral 4

Las mejoras de esta entrega fueron arreglar los problemas de compilación y añadir una nueva funcion que sirve para meter un nuevo personaje.

De la complejidad tenemos 3 funciones. La primera es la de siempre que recorre todo el archivo y lo pasa a un grafo teniendo una complejidad de O(n). 
La segunda es la función de buscar un personaje y de igual forma tiene complejidad de O(n) porque lo tiene que recorrer hasta encontrar el valor buscado.
Finalmente tenemos la función de añadir un nuevo personaje y como recorre todo el archivo hasta el final tenemos que la complejidad es O(n) donde n
es la longitud del archivo.

//Casos de prueba primera funcion:
        //Caso 1: La primera funcion unicamente despliega el grafo y el unico caso de prueba es desplegarlo
        
//Casos de prueba segunda funcion:
        //Caso 1: vec.find(aang) asi se vería la funcion y despues de buscar en el grafo encontraria el personaje
        //y lo regresaria como "El personaje es: aang tiene 112 avatar" que es el nombre, la edad y el elemento
        //Caso 2: vec.find(yue) asi se vería la funcion y despues de buscar en el grafo encontraria el personaje
        //y lo regresaria como "El personaje es: yue tiene 16 agua" que es el nombre, la edad y el elemento
        
        //Casos de prueba tercera funcion:
        //Caso 1: vec.meterNodo(shue, 38, tierra); en este caso meteriamos los datos al archivo
        //y al grafo y se le da su numero propio.
        //Caso 2: vec.meterNodo(long, 32, aire); en este caso meteriamos los datos al archivo
        //y al grafo y se le da su numero propio.
