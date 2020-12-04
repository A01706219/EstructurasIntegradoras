Actividad Integral 1 .- Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia)

Mi programa consiste en una lista modificable de todos los personajes de Avatar. Hay un menú donde tienes muchas opciones; puedes ver toda la lista de los personajes de un archivo de texto que se llama "personajesAvatar.txt", puedes ordenar esta lista con el sistema ASCII y guarda los cambios en "ejemplo.txt, buscar a un personaje o agregar un personaje nuevo. El archivo se lee y transforma cada línea a un vector para posteriormente modificarse con las funciones.

Análisis de complejidad

buscarPersonaje: El programa va buscando y comparando cada uno de los elementos hasta que encuentra el elemento elegido y es por eso que su complejidad es O(n) en el peor de los casos.

MergeSort: El programa va creando un árbol dividiendose en subgrupos y tiene una complejidad de O(nlog(n)) en el peor de los casos.


      //Casos de prueba primera funcion:
      //Caso 1: La primera funcion unicamente imprime el archivo y solo hay una opcion
      //Casos de prueba segunda funcion:
      //Caso 1: La segunda funcion igualmente solo hay una opcion de ordenar el archivo por orden alfabetico.
      //Casos de prueba tercera funcion:
      //Caso 1: Vamos a buscar al personaje zuko y la funcion unicamente recibe el nombre del personaje ya que asi los categoriza
      //La funcion nos regresará Nombre: zuko, Edad: 16, Elemento: fire
      //Caso 2: Vamos a buscar al personaje yue
      //La funcion nos regresará Nombre: yue, Edad: 16, Elemento: water
      //Casos de prueba cuarta funcion:
      //Caso 1: vamos a añadir al personaje korra con 18 anios de edad y elemento avatar
      //La funcion regresaria el txt con el archivo original y al final korra 18 avatar
