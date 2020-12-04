Activiad integral 2

El programa es una continuación del proyecto pasado y lo que buscamos es añadir un menu con multiples opciones para el usuario. La primera opción es que tomamos todos los valores de un archivo y los guardamos en una lista para posteriormente desplegarlas en un nuevo archivo. También tenemos las opciones de buscar y añadir un nuevo personaje de la serie Avatar.

Cambios en la entrega Los cambios fueron que ahora en vez de usar un vector para guardar los elementos usamos una lista y apuntadores.

Analisis de complejidad Al desplegar los valores en la lista usamos una complejidad de O(n) ya que solo tiene que recorrer el archivo con cantidad de lineas n. La función de añadir igualmente tiene una complejidad de O(n) porque añade la nueva edad al final de la lista con elementos n para finalmente desplegarlas en el nuevo archivo. Y finalmente 
la función de buscar tiene una complejidad de O(n) porque pasa por toda la lista hasta encontrar el dato y regresar los 3 valores.

 //Casos de prueba primera funcion:
    //Caso 1: Solo hay una opcion que despliega la lista
     //Casos de prueba segunda funcion:
      //Caso 1: si nombreBuscado se pone como aang te dira que es aang 14 avatar. buscarPersonaje(archivo, aang)
      //Caso 2: si nombreBuscado se pone como katara te dira que es katara 14 agua. buscarPersonaje(archivo, katara)
      //Casos de prueba tercera funcion:
      //Caso 1: Meteremos al personaje xin de 52 anios de edad y elemento de fuego.
      //nuevoNombre seria xin
      //nuevaEdad seria 52
      //nuevoElemento seria fuego
      //La funcion quedaria como lista.meterPersonaje(xin, 52, fuego);
      //Caso 2: Meteremos al personaje azula de 14 anios de edad y elemento de fuego.
      //nuevoNombre seria azula
      //nuevaEdad seria 14
      //nuevoElemento seria fuego
      //La funcion quedaria como lista.meterPersonaje(azula, 14, fuego);
