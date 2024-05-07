ALGORITMO DE ORDENAMIENTO UTILIZANDO NÚMEROS ENTEROS POSTIVOS 

Este algoritmo de ordenación está diseñado para trabajar con números enteros positivos. En su inicio, solicita al usuario definir un rango de números, comenzando con el número más pequeño y terminando con el más grande. Posteriormente, mediante una función de generación de números aleatorios, se puede determinar cuántos dígitos se generarán en un archivo .TXT, separando cada número por un espacio.

Una vez establecido el rango y generado el archivo, se presenta un menú principal con diversas opciones, que incluyen la posibilidad de añadir, eliminar, visualizar los números en la lista o los contenidos del archivo .TXT. No obstante, la opción más relevante es la selección de un método de ordenación. Al elegir esta opción, se despliegan varios métodos de ordenación que permiten al usuario observar el tiempo que requiere el algoritmo para completar el proceso de ordenamiento, mostrando cada paso del mismo.
Los métodos de ordenación disponibles son:

1. Bubble Sort: 
La función `bubbleSort` que has proporcionado es una implementación del algoritmo de ordenamiento Bubble Sort adaptada para trabajar con una lista enlazada en lugar de un arreglo. Aquí te explico paso a paso qué hace esta función:

 **Inicialización de Variables**: La función comienza inicializando algunas variables:
   - `start`: Un objeto `high_resolution_clock` de la biblioteca `<chrono>` para medir el tiempo de ejecución del algoritmo.
   - `intercambiado`: Un booleano que se utiliza para controlar el bucle principal del algoritmo. Se establece en `false` al inicio de cada iteración y se cambia a `true` si se realiza algún intercambio durante la iteración actual.
   - `iteracion`: Un contador para llevar un registro de cuántas iteraciones ha realizado el algoritmo.

 **Impresión del Arreglo Inicial**: Antes de comenzar el ordenamiento, imprime el contenido de la lista enlazada para mostrar el estado inicial.

 **Bucle Principal del Algoritmo**: El algoritmo utiliza un bucle `do-while` para continuar ordenando la lista mientras se realicen intercambios. Dentro de este bucle:
   - Se itera sobre cada nodo de la lista, comparando el valor almacenado en el nodo actual (`temp`) con el valor del siguiente nodo (`temp->siguiente`).
   - Si el valor del nodo actual es mayor que el valor del siguiente nodo, se realizan los siguientes pasos:
     - Se intercambian los valores de los nodos utilizando la función `swap`.
     - Se establece `intercambiado` en `true` para indicar que se ha realizado un intercambio.
     - Se imprime el contenido de la lista después de la iteración actual para mostrar el progreso del ordenamiento.
   - Después de comparar todos los nodos, se avanza al siguiente nodo de la lista (`temp = temp->siguiente`).

 **Medición del Tiempo de Ejecución**: Una vez que el algoritmo ha terminado de ordenar la lista (es decir, no se han realizado más intercambios), se registra el tiempo final de ejecución utilizando otro objeto `high_resolution_clock`. Luego, se llama a una función `medirTiempo` (que no está definida en el fragmento proporcionado) para calcular y mostrar el tiempo total de ejecución del algoritmo.

 **Impresión del Arreglo Final**: Finalmente, se imprime el contenido de la lista enlazada después del ordenamiento para mostrar el resultado final.

void bubbleSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();
    
    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);
    
    bool intercambiado;
    int iteracion = 0;
    do {
        intercambiado = false;
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            int num1 = stoi(temp->dato);
            int num2 = stoi(temp->siguiente->dato);
            if (num1 > num2) {
                swap(temp->dato, temp->siguiente->dato);
                intercambiado = true;
                cout << "\n\tIteración " << ++iteracion << ": ";
                imprimirLista(cabeza);
            }
            temp = temp->siguiente;
        }
    } while (intercambiado);

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tArreglo después del Bubble Sort");
}

2. Selection Sort:

   La función `selectionSort` que has proporcionado es una implementación del algoritmo de ordenamiento Selection Sort adaptada para trabajar con una lista enlazada en lugar de un arreglo. Aquí te explico paso a paso qué hace esta función:

 **Inicialización de Variables**: La función comienza inicializando algunas variables:
   - `start`: Un objeto `high_resolution_clock` de la biblioteca `<chrono>` para medir el tiempo de ejecución del algoritmo.
   - `i`: Un puntero a un nodo que se utiliza para iterar sobre la lista enlazada. Comienza en la cabeza de la lista.
   - `min`: Un puntero a un nodo que se utiliza para almacenar el nodo con el valor mínimo encontrado en cada iteración del bucle interno.

 **Impresión del Arreglo Inicial**: Antes de comenzar el ordenamiento, imprime el contenido de la lista enlazada para mostrar el estado inicial.

 **Bucle Principal del Algoritmo**: El algoritmo utiliza un bucle `while` para iterar sobre cada nodo de la lista. Dentro de este bucle:
   - Se itera sobre cada nodo desde el nodo actual (`i`) hasta el final de la lista, buscando el nodo con el valor mínimo.
   - Si se encuentra un nodo con un valor menor que el valor mínimo actual (`num2 < num1`), se actualiza el puntero `min` para apuntar a este nuevo nodo mínimo.
   - Después de comparar todos los nodos, si el nodo mínimo encontrado no es el mismo que el nodo actual (`min!= i`), se realizan los siguientes pasos:
     - Se imprime un mensaje indicando que se va a intercambiar los valores de los nodos.
     - Se intercambian los valores de los nodos utilizando la función `swap`.
   - Después de encontrar el nodo mínimo y posiblemente realizar un intercambio, se avanza al siguiente nodo de la lista (`i = i->siguiente`).
   - Se imprime el contenido de la lista después de cada iteración para mostrar el progreso del ordenamiento.

 **Medición del Tiempo de Ejecución**: Una vez que el algoritmo ha terminado de ordenar la lista, se registra el tiempo final de ejecución utilizando otro objeto `high_resolution_clock`. Luego, se llama a una función `medirTiempo` (que no está definida en el fragmento proporcionado) para calcular y mostrar el tiempo total de ejecución del algoritmo.

void selectionSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();
    
    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);
    
    Nodo* i = cabeza;
    while (i != nullptr) {
        Nodo* min = i;
        Nodo* j = i->siguiente;
        while (j != nullptr) {
            int num1 = stoi(min->dato);
            int num2 = stoi(j->dato);
            if (num2 < num1) {
                min = j;
            }
            j = j->siguiente;
        }
        if (min != i) {
            cout << "\n\tIntercambiando " << i->dato << " y " << min->dato << endl;
            swap(i->dato, min->dato);
        }
        i = i->siguiente;
        cout << "\n\tArreglo parcial: ";
        imprimirLista(cabeza);
    }

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tArreglo después del Selection Sort");
}


3. Insertion Sort

   La función `insertionSort` que has proporcionado es una implementación del algoritmo de ordenamiento Insertion Sort adaptada para trabajar con una lista enlazada en lugar de un arreglo. Aquí te explico paso a paso qué hace esta función:

 **Inicialización de Variables**: La función comienza inicializando algunas variables:
   - `start`: Un objeto `high_resolution_clock` de la biblioteca `<chrono>` para medir el tiempo de ejecución del algoritmo.
   - `i`: Un puntero a un nodo que se utiliza para iterar sobre la lista enlazada, comenzando desde el segundo nodo (ya que el primer nodo es considerado ya ordenado).
   - `key`: Una variable que almacena el valor del nodo actual que se está insertando en su posición correcta dentro de la lista ordenada.
   - `j`: Un puntero a un nodo que se utiliza para iterar sobre la lista desde el nodo actual hasta el final, buscando la posición correcta para insertar el nodo actual.
   - `prev`: Un puntero a un nodo que se utiliza para mantener un seguimiento del nodo anterior al nodo actual, permitiendo reemplazar el valor del nodo anterior con el valor del nodo actual cuando se encuentre la posición correcta para insertar el nodo actual.

 **Impresión del Arreglo Inicial**: Antes de comenzar el ordenamiento, imprime el contenido de la lista enlazada para mostrar el estado inicial.

 **Bucle Principal del Algoritmo**: El algoritmo utiliza un bucle `while` para iterar sobre cada nodo de la lista, comenzando desde el segundo nodo. Dentro de este bucle:
   - Se itera sobre cada nodo desde el nodo actual (`i`) hasta el final de la lista, buscando la posición correcta para insertar el nodo actual (`key`).
   - Mientras se encuentren nodos con valores menores que el valor del nodo actual (`stoi(j->dato) < stoi(key)`), se mueve el valor del nodo actual al nodo anterior (`prev->dato = j->dato; prev = j; j = j->siguiente;`).
   - Una vez que se encuentra la posición correcta, se inserta el valor del nodo actual en esa posición (`prev->dato = key;`).
   - Después de insertar el nodo actual, se avanza al siguiente nodo de la lista (`i = i->siguiente`).
   - Se imprime el contenido de la lista después de cada iteración para mostrar el progreso del ordenamiento.

 **Medición del Tiempo de Ejecución**: Una vez que el algoritmo ha terminado de ordenar la lista, se registra el tiempo final de ejecución utilizando otro objeto `high_resolution_clock`. Luego, se llama a una función `medirTiempo` (que no está definida en el fragmento proporcionado) para calcular y mostrar el tiempo total de ejecución del algoritmo.




   void insertionSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();

    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);

    Nodo* i = cabeza->siguiente;
    while (i != nullptr) {
        string key = i->dato;
        Nodo* j = i->siguiente;
        Nodo* prev = i;
        while (j != nullptr && stoi(j->dato) < stoi(key)) {
            prev->dato = j->dato;
            prev = j;
            j = j->siguiente;
        }
        prev->dato = key;
        i = i->siguiente;
        cout << "\n\tArreglo parcial: ";
        imprimirLista(cabeza);
    }

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tArreglo después del Insertion Sort");
}


4. Merge Sort:

La implementación que has proporcionado es una versión del algoritmo de ordenamiento Merge Sort adaptada para trabajar con listas enlazadas. Este algoritmo divide la lista en dos mitades, las ordena recursivamente y luego las fusiona. A continuación, te explico paso a paso qué hace cada parte de este código:

### Función `mergeSort`

- **Inicialización de Variables**: Inicializa un objeto `high_resolution_clock` para medir el tiempo de ejecución del algoritmo.
- **Impresión del Arreglo Inicial**: Imprime el contenido de la lista enlazada antes de comenzar el ordenamiento.
- **Llamada a la Función Auxiliar**: Llama a la función `mergeSortHelper`, que es la implementación recursiva del algoritmo Merge Sort.
- **Medición del Tiempo de Ejecución**: Registra el tiempo final de ejecución y llama a una función `medirTiempo` para calcular y mostrar el tiempo total de ejecución del algoritmo.
- **Impresión del Arreglo Final**: Imprime el contenido de la lista enlazada después del ordenamiento.

### Función `mergeSortHelper`

- **División de la Lista**: Divide la lista en dos mitades. La primera mitad se divide hasta llegar a listas de longitud 1 o 0, y la segunda mitad se divide de manera similar.
- **Ordenamiento Recursivo**: Llama a sí misma para ordenar ambas mitades de la lista.
- **Fusión de Listas**: Llama a la función `merge` para fusionar las dos mitades ordenadas en una sola lista ordenada.

### Función `merge`

- **Impresión del Arreglo Inicial**: Imprime el contenido de la lista enlazada antes de comenzar la fusión.
- **Fusión de Listas**: Itera sobre las dos listas (izquierda y derecha) y compara sus elementos. Los elementos se añaden a una nueva lista (`temp`) en orden ascendente.
- **Manejo de Casos Especiales**: Si una de las listas se agota antes que la otra, los elementos restantes de la lista no vacía se añaden a la lista resultante.
- **Actualización de la Cabeza de la Lista**: Actualiza la cabeza de la lista original para apuntar a la cabeza de la lista resultante.
- **Impresión del Arreglo Después de Merge**: Imprime el contenido de la lista enlazada después de la fusión.



   void mergeSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();
    
    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);
    
    mergeSortHelper(cabeza);

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tArreglo después del Merge Sort");
}

void mergeSortHelper(Nodo*& cabeza) {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        return;
    }

    Nodo* medio = cabeza;
    Nodo* final = cabeza->siguiente;

    while (final != nullptr && final->siguiente != nullptr) {
        medio = medio->siguiente;
        final = final->siguiente->siguiente;
    }

    Nodo* mitad_derecha = medio->siguiente;
    medio->siguiente = nullptr;

    mergeSortHelper(cabeza);
    mergeSortHelper(mitad_derecha);

    merge(cabeza, cabeza, mitad_derecha);
    cout << "\n\tArreglo parcial: ";
    imprimirLista(cabeza);
}

void merge(Nodo*& cabeza, Nodo* izquierda, Nodo* derecha) {
    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);
    
    Nodo* temp = nullptr;
    Nodo* cabeza_temp = nullptr;

    while (izquierda != nullptr && derecha != nullptr) {
        if (stoi(izquierda->dato) <= stoi(derecha->dato)) {
            if (temp == nullptr) {
                temp = izquierda;
                cabeza_temp = izquierda;
            } else {
                temp->siguiente = izquierda;
                temp = temp->siguiente;
            }
            izquierda = izquierda->siguiente;
        } else {
            if (temp == nullptr) {
                temp = derecha;
                cabeza_temp = derecha;
            } else {
                temp->siguiente = derecha;
                temp = temp->siguiente;
            }
            derecha = derecha->siguiente;
        }
        cout << "\n\tArreglo parcial: ";
        imprimirLista(cabeza_temp);
    }

    if (izquierda != nullptr) {
        temp->siguiente = izquierda;
    } else if (derecha != nullptr) {
        temp->siguiente = derecha;
    }

    cabeza = cabeza_temp;

    cout << "\n\tArreglo después de merge: ";
    imprimirLista(cabeza);
}

5. Quicksort


La función `quickSort` es una implementación del algoritmo de ordenamiento rápido (QuickSort) en C++. Este algoritmo es un método eficiente para ordenar listas de elementos, especialmente cuando se trabaja con grandes conjuntos de datos. A continuación, te explico cada parte de la implementación:

### Función `quickSort`

- **Entrada**: Un puntero a un nodo que representa el inicio de una lista enlazada.
- **Salida**: Modifica la lista enlazada original para que esté ordenada.

 **Medición del tiempo**: Utiliza `high_resolution_clock` para medir el tiempo antes y después de la ejecución del algoritmo, lo cual es útil para evaluar su rendimiento.

 **Impresión del arreglo inicial**: Antes de comenzar el ordenamiento, imprime la lista enlazada actual para mostrar el estado inicial.

 **Llamada recursiva a `quickSortHelper`**: La lógica principal del QuickSort se encuentra en esta función. Aquí, se pasa la cabeza de la lista y la cola de la lista como argumentos.

 **Medición del tiempo después del ordenamiento**: Después de que el ordenamiento se completa, se mide nuevamente el tiempo y se imprime la lista ordenada para comparar con el estado inicial.

### Función `quickSortHelper`

- **Entrada**: Punteros a los nodos que representan el inicio y el final de una sublista de la lista enlazada.
- **Salida**: Modifica la sublista para que esté ordenada y devuelve el nuevo inicio de la sublista.

 **Base de la recursión**: Si la sublista está vacía o solo contiene un elemento, se retorna la sublista tal cual.

 **Partición**: Se llama a la función `partition` para dividir la sublista en dos partes basadas en un pivote. Los elementos menores que el pivote se colocan antes del pivote, y los mayores después.

 **Ordenamiento recursivo**: Se llama a `quickSortHelper` de manera recursiva para las dos partes de la sublista, asegurando que ambas estén ordenadas.

### Función `partition`

- **Entrada**: Punteros a los nodos que representan el inicio y el final de una sublista de la lista enlazada, así como punteros a los nuevos inicios y finales de las sublistas resultantes de la partición.
- **Salida**: Modifica la sublista y devuelve el pivote.

 **Selección del pivote**: El último elemento de la sublista se utiliza como pivote.

 **Reorganización de la sublista**: Los elementos de la sublista se reorganizan de manera que todos los elementos menores que el pivote estén antes del pivote, y todos los mayores después. Esto se logra intercambiando los elementos según sea necesario.

 **Actualización de los nuevos inicios y finales**: Se actualizan los punteros a los nuevos inicios y finales de las sublistas resultantes de la partición.

### Función `getTail`

- **Entrada**: Un puntero al nodo que representa el inicio de una lista enlazada.
- **Salida**: Un puntero al último nodo de la lista enlazada.



   void quickSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();
    
    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);
    
    cabeza = quickSortHelper(cabeza, getTail(cabeza));

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tArreglo después del Quick Sort");
}

Nodo* quickSortHelper(Nodo* cabeza, Nodo* fin) {
    if (!cabeza || cabeza == fin)
        return cabeza;

    Nodo* newHead = nullptr;
    Nodo* newEnd = nullptr;

    Nodo* pivote = partition(cabeza, fin, &newHead, &newEnd);

    if (newHead != pivote) {
        Nodo* temp = newHead;
        while (temp->siguiente != pivote)
            temp = temp->siguiente;
        temp->siguiente = nullptr;

        newHead = quickSortHelper(newHead, temp);

        temp = getTail(newHead);
        temp->siguiente = pivote;
    }

    pivote->siguiente = quickSortHelper(pivote->siguiente, newEnd);

    return newHead;
}

Nodo* partition(Nodo* cabeza, Nodo* fin, Nodo** newHead, Nodo** newEnd) {
    Nodo* pivote = fin;
    Nodo* prev = nullptr;
    Nodo* cur = cabeza;
    Nodo* tail = pivote;

    while (cur != pivote) {
        if (stoi(cur->dato) < stoi(pivote->dato)) {
            if ((*newHead) == nullptr)
                (*newHead) = cur;

            prev = cur;
            cur = cur->siguiente;
        } else {
            if (prev)
                prev->siguiente = cur->siguiente;

            Nodo* temp = cur->siguiente;
            cur->siguiente = nullptr;
            tail->siguiente = cur;
            tail = cur;
            cur = temp;
        }
        cout << "\n\tArreglo parcial: ";
        imprimirLista(cabeza);
    }

    if ((*newHead) == nullptr)
        (*newHead) = pivote;

    (*newEnd) = tail;

    return pivote;
}

Nodo* getTail(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != nullptr && temp->siguiente != nullptr) {
        temp = temp->siguiente;
    }
    return temp;
}


6. Bucket Sort
La explicación proporcionada sobre la función `quickSort` y sus componentes auxiliares (`quickSortHelper`, `partition`, y `getTail`) es correcta y detallada. Sin embargo, parece haber una confusión en la pregunta, ya que la descripción se repite sin agregar nuevas citas o referencias externas. 

Para complementar la explicación con información adicional y citaciones relevantes, aquí hay algunos puntos adicionales que podrían ser útiles:

### Algoritmo QuickSort

El algoritmo QuickSort es uno de los algoritmos de ordenamiento más eficientes en términos de complejidad temporal promedio, siendo O(n log n) en el mejor y peor caso. Su eficiencia radica en su capacidad para reducir el tamaño del problema de manera recursiva, dividiendo la lista en dos sublistas más pequeñas y ordenando estas de manera independiente. La clave del algoritmo es la elección del pivote, que puede influir significativamente en su rendimiento.

### Selección del Pivote

La selección del pivote es un aspecto crítico del algoritmo QuickSort. En la implementación proporcionada, el último elemento de la sublista se utiliza como pivote. Esta elección es simple pero no siempre óptima, ya que puede llevar a un rendimiento subóptimo en listas con muchos duplicados o listas casi ordenadas. Otras estrategias comunes incluyen el uso del primer elemento, el elemento medio, o incluso un pivote aleatorio.

### Medición del Tiempo

La medición del tiempo antes y después de la ejecución del algoritmo es una práctica común en la evaluación del rendimiento de algoritmos. En C++, `high_resolution_clock` de la biblioteca `<chrono>` proporciona una forma precisa de medir el tiempo transcurrido. Esta técnica es útil para comparar el rendimiento de diferentes implementaciones de algoritmos o para entender cómo factores como el tamaño de la entrada o la distribución de los datos afectan el tiempo de ejecución.

### Implementación en Listas Enlazadas

La implementación del QuickSort en listas enlazadas presenta desafíos únicos en comparación con la implementación en arrays. Por ejemplo, la partición debe ser adaptada para trabajar con punteros a nodos en lugar de índices de array. Además, la manipulación de la lista enlazada durante la partición (como la reorganización de los nodos) requiere una atención especial para mantener la integridad de la estructura de la lista.

### Referencias

- **Algoritmo QuickSort**: "Introduction to Algorithms" por Cormen, Leiserson, Rivest, y Stein (CLRS), Capítulo 7.3.
- **Selección del Pivote**: "The Art of Computer Programming" por Donald Knuth, Vol. 3, Capítulo 5.2.3.
- **Medición del Tiempo**: Documentación oficial de C++ en `<chrono>`.

// Función para encontrar el valor máximo en la lista
int encontrarMaximo(Nodo* cabeza) {
    int maximo = stoi(cabeza->dato); // Convertir la primera cadena a entero
    Nodo* temp = cabeza->siguiente;
    while (temp) {
        int valor = stoi(temp->dato); // Convertir la cadena actual a entero
        if (valor > maximo) { // Comparar como enteros
            maximo = valor; // Actualizar el máximo si es necesario
        }
        temp = temp->siguiente;
    }
    return maximo;
}

// Función para ordenar el arreglo utilizando el algoritmo Bucket Sort
void bucketSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();

    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);

    // Encontrar el valor máximo en la lista
    int maximo = encontrarMaximo(cabeza);
    cout << "\n\tValor máximo encontrado en la lista: " << maximo << endl;

    // Crear los cubos
    vector<vector<string>> cubos(maximo + 1);

    // Distribuir los elementos en los cubos
    Nodo* temp = cabeza;
    while (temp) {
        int indice = stoi(temp->dato);
        cout << "\n\tDistribuyendo " << temp->dato << " en el cubo " << indice << endl;
        cubos[indice].push_back(temp->dato);
        temp = temp->siguiente;
    }

    // Mostrar los cubos después de la distribución
    cout << "\n\tCubos después de la distribución:" << endl;
    for (size_t i = 0; i < cubos.size(); ++i) {
        cout << "\tCubo " << i << ": ";
        for (const string& dato : cubos[i]) {
            cout << dato << " ";
        }
        cout << endl;
    }

    // Ordenar los elementos dentro de cada cubo utilizando Bubble Sort
    for (size_t i = 0; i < cubos.size(); ++i) {
        if (!cubos[i].empty()) {
            cout << "\n\tOrdenando elementos dentro del cubo " << i << " utilizando Bubble Sort" << endl;
            // Ordenar los elementos dentro del cubo utilizando Bubble Sort
            for (size_t j = 0; j < cubos[i].size() - 1; ++j) {
                for (size_t k = 0; k < cubos[i].size() - j - 1; ++k) {
                    if (stoi(cubos[i][k]) > stoi(cubos[i][k + 1])) {
                        swap(cubos[i][k], cubos[i][k + 1]);
                    }
                }
            }
            cout << "\tCubo " << i << " después de ordenar: ";
            for (const string& dato : cubos[i]) {
                cout << dato << " ";
            }
            cout << endl;
        }
    }

    // Reconstruir la lista a partir de los cubos ordenados
    temp = cabeza;
    for (auto& cubo : cubos) {
        for (const string& dato : cubo) {
            temp->dato = dato;
            temp = temp->siguiente;
        }
    }

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tArreglo después del Bucket Sort");
}


   
7. Shell Sort

La función `shellSort` implementa el algoritmo de ordenamiento Shell Sort en una lista enlazada. Shell Sort es una variante del algoritmo de ordenamiento por inserción que mejora su eficiencia al permitir el movimiento de elementos no adyacentes. A continuación, se detalla la lógica de la función:

### Inicio y Medición del Tiempo

- **Inicio del medidor de tiempo**: Se inicia el medidor de tiempo utilizando `high_resolution_clock` para poder calcular el tiempo de ejecución del algoritmo.

### Impresión del Arreglo Inicial

- **Impresión de la lista enlazada**: Se imprime la lista enlazada actual para mostrar el estado inicial antes de aplicar el algoritmo de ordenamiento.

### Conteo de Elementos

- **Conteo de elementos**: Se cuenta la cantidad de elementos en la lista enlazada para determinar el tamaño de la lista y para usarlo en el algoritmo de Shell Sort.

### Conversión a Vector

- **Conversión a vector**: La lista enlazada se convierte en un vector de strings para facilitar el acceso aleatorio a los elementos, lo cual es necesario para aplicar el algoritmo de Shell Sort de manera efectiva.

### Aplicación del Algoritmo Shell Sort

- **Inicialización de la brecha**: Se establece la brecha inicial como la mitad del número total de elementos. La brecha es el paso que se utiliza para mover los elementos en el algoritmo.

- **Bucle principal del algoritmo**: Mientras la brecha sea mayor que 0, se realiza un bucle que itera sobre cada elemento de la lista, moviéndolo hacia atrás en la lista si es necesario para mantener el orden. La brecha se reduce a la mitad en cada iteración.

- **Iteración y visualización**: En cada iteración, se muestran los elementos de la lista para visualizar el proceso de ordenamiento. Esto ayuda a entender cómo el algoritmo está reorganizando los elementos.

### Actualización de la Lista Enlazada

- **Actualización de la lista enlazada**: Finalmente, se actualiza la lista enlazada con los elementos ordenados. Esto implica recorrer el vector de elementos ordenados y asignar cada elemento al nodo correspondiente en la lista enlazada.

### Fin y Medición del Tiempo

- **Fin del medidor de tiempo**: Se registra el tiempo final utilizando el medidor de tiempo iniciado al principio.

- **Impresión del arreglo después del Shell Sort**: Se imprime la lista enlazada final para mostrar el resultado del ordenamiento.



   void shellSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();

    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);

    // Contar la cantidad de elementos en la lista
    int contador = 0;
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        contador++;
        temp = temp->siguiente;
    }

    // Convertir la lista enlazada a un vector para facilitar el acceso aleatorio
    vector<string> elementos;
    temp = cabeza;
    while (temp != nullptr) {
        elementos.push_back(temp->dato);
        temp = temp->siguiente;
    }

    // Aplicar el algoritmo de Shell Sort con paso a paso
    int brecha = contador / 2;
    int iteracion = 1; // Contador de iteraciones
    while (brecha > 0) {
        for (int i = brecha; i < contador; i++) {
            string temp = elementos[i];
            int j = i;
            while (j >= brecha && elementos[j - brecha] > temp) {
                elementos[j] = elementos[j - brecha];
                j -= brecha;
            }
            elementos[j] = temp;

            // Mostrar el estado actual del arreglo en cada iteración
            cout << "\n\tIteración " << iteracion++ << ", brecha = " << brecha << ": ";
            for (const string& elemento : elementos) {
                cout << elemento << " ";
            }
            cout << endl;
        }
        brecha /= 2;
    }

    // Actualizar la lista enlazada con los elementos ordenados
    temp = cabeza;
    for (const string& elemento : elementos) {
        temp->dato = elemento;
        temp = temp->siguiente;
    }

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tArreglo después del Shell Sort");
}


8. Counting Sort

La función `countingSort` implementa el algoritmo de ordenamiento Counting Sort en una lista enlazada. Counting Sort es un algoritmo de ordenamiento eficiente que funciona contando la frecuencia de cada elemento en la lista y luego reconstruyendo la lista basándose en estos conteos. A continuación, se detalla la lógica de la función:

### Inicio y Medición del Tiempo

- **Inicio del medidor de tiempo**: Se inicia el medidor de tiempo utilizando `high_resolution_clock` para poder calcular el tiempo de ejecución del algoritmo.

### Impresión del Arreglo Inicial

- **Impresión de la lista enlazada**: Se imprime la lista enlazada actual para mostrar el estado inicial antes de aplicar el algoritmo de ordenamiento.

### Obtención del Rango

- **Obtener el mínimo y el máximo valor**: Se utiliza la función `obtenerMinimoMaximo` para determinar el rango de valores en la lista. Esto es necesario para crear el vector de frecuencias.

### Creación del Vector de Frecuencias

- **Inicialización del vector de frecuencias**: Se crea un vector de frecuencias con un tamaño igual al rango de valores en la lista, inicializado en cero.

### Conteo de Frecuencias

- **Contar la frecuencia de cada elemento**: Se recorre la lista enlazada, incrementando el conteo correspondiente en el vector de frecuencias para cada valor encontrado.

### Mostrar Frecuencias

- **Visualización de las frecuencias**: Se muestra el vector de frecuencias y los valores correspondientes para ayudar a entender el proceso de ordenamiento.

### Reconstrucción de la Lista Ordenada

- **Reconstrucción de la lista**: Se recorre nuevamente la lista enlazada, asignando a cada nodo el valor correspondiente basado en el vector de frecuencias. Esto efectivamente ordena la lista.

### Fin y Medición del Tiempo

- **Fin del medidor de tiempo**: Se registra el tiempo final utilizando el medidor de tiempo iniciado al principio.

- **Impresión del arreglo después del Counting Sort**: Se imprime la lista enlazada final para mostrar el resultado del ordenamiento.



// Función para obtener el mínimo y el máximo valor en la lista
void obtenerMinimoMaximo(Nodo* cabeza, int& minimo, int& maximo) {
    minimo = stoi(cabeza->dato);
    maximo = stoi(cabeza->dato);
    Nodo* temp = cabeza->siguiente;
    while (temp) {
        int valor = stoi(temp->dato);
        if (valor < minimo) {
            minimo = valor;
        } else if (valor > maximo) {
            maximo = valor;
        }
        temp = temp->siguiente;
    }
}

// Función para ordenar el arreglo utilizando el algoritmo Counting Sort
void countingSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();

    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);

    // Obtener el mínimo y el máximo valor en la lista
    int minimo, maximo;
    obtenerMinimoMaximo(cabeza, minimo, maximo);
    int rango = maximo - minimo + 1;

    // Crear un arreglo de frecuencias y inicializarlo en cero
    vector<int> frecuencias(rango, 0);

    // Contar la frecuencia de cada elemento en la lista
    Nodo* temp = cabeza;
    while (temp) {
        int valor = stoi(temp->dato);
        frecuencias[valor - minimo]++;
        temp = temp->siguiente;
    }

    // Mostrar los pasos del algoritmo
    cout << "\n\tCrear una lista de recuentos para cada valor único en la lista de entrada:" << endl;
    cout << "\n\tcount = [";
    for (int i = 0; i < rango; ++i) {
        cout << frecuencias[i];
        if (i < rango - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    // Mostrar a qué valor se refiere cada recuento
    cout << "\t  # val: ";
    for (int i = 0; i < rango; ++i) {
        cout << minimo + i << "  ";
    }
    cout << endl;

    // Reconstruir la lista con los elementos ordenados
    cout << "\n\tRevisar la lista de entrada e iterar el índice para cada valor:" << endl;
    cout << "\n\toutput = [";
    temp = cabeza;
    int i = 0;
    while (temp) {
        while (frecuencias[i] == 0) {
            i++;
        }
        temp->dato = to_string(i + minimo);
        frecuencias[i]--;
        cout << temp->dato;
        if (temp->siguiente != nullptr) {
            cout << ", ";
        }
        temp = temp->siguiente;
    }
    cout << "]" << endl;

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tArreglo después del Counting Sort");
}


9. Radix Sort

La función `radixSort` implementa el algoritmo de ordenamiento Radix Sort en una lista enlazada. Radix Sort es un algoritmo de ordenamiento no comparativo que ordena los elementos en base a sus dígitos individuales. A continuación, se detalla la lógica de la función:

### Inicio y Medición del Tiempo

- **Inicio del medidor de tiempo**: Se inicia el medidor de tiempo utilizando `high_resolution_clock` para poder calcular el tiempo de ejecución del algoritmo.

### Impresión del Arreglo Inicial

- **Impresión de la lista enlazada**: Se imprime la lista enlazada actual para mostrar el estado inicial antes de aplicar el algoritmo de ordenamiento.

### Preparación para el Radix Sort

- **Lista de colas**: Se crea un vector de colas, una para cada posible valor de dígito (del 0 al 9). Estas colas se utilizarán para agrupar los elementos por su dígito en cada iteración.

- **Determinar el número máximo de dígitos**: Se recorre la lista enlazada para determinar el número máximo de dígitos en los números presentes. Esto es necesario para saber cuántas iteraciones del algoritmo se necesitan.

### Iteración por Dígitos

- **Iterar sobre cada dígito**: Para cada dígito, desde el menos significativo hasta el más significativo, se realiza lo siguiente:
  
  - **Asignar elementos a las colas**: Se recorre la lista enlazada, extrayendo el dígito en la posición actual de cada número y asignando el número completo a la cola correspondiente al dígito.

  - **Reconstruir la lista enlazada**: Se recorren las colas en orden ascendente de dígito, tomando los elementos de cada cola y reconstruyendo la lista enlazada con estos elementos. Esto efectivamente ordena los números por el dígito actual.

### Fin y Medición del Tiempo

- **Fin del medidor de tiempo**: Se registra el tiempo final utilizando el medidor de tiempo iniciado al principio.

- **Impresión del tiempo de ejecución**: Se imprime el tiempo de ejecución del algoritmo.

### Función `obtenerDigito`

- **Función auxiliar**: Esta función extrae el dígito en una posición específica de un número representado como una cadena. Si la posición está fuera del rango, devuelve 0.



   // Función para obtener el dígito en una posición específica de un número representado como una cadena
int obtenerDigito(const string& numero, int posicion) {
    if (posicion >= 0 && posicion < numero.length()) {
        // Obtén el dígito de la posición indicada
        return numero[posicion] - '0';
    } else {
        // Si la posición está fuera del rango, devuelve 0
        return 0;
    }
}

//-- ordena sobre el último número entero.

void radixSort(Nodo*& cabeza) {
    auto start = high_resolution_clock::now();

    cout << "\n\tArreglo inicial: ";
    imprimirLista(cabeza);

    // Lista de colas para almacenar los números en cada dígito
    vector<queue<int>> colas(10);

    // Obtener el número máximo de dígitos
    int maxDigitos = 0;
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        maxDigitos = max(maxDigitos, (int)log10(stod(temp->dato)) + 1);
        temp = temp->siguiente;
    }

    // Iterar sobre cada dígito, comenzando desde el menos significativo
    for (int i = 0; i < maxDigitos; ++i) {
        // Asignar elementos a las colas basadas en el dígito actual
        temp = cabeza;
        while (temp != nullptr) {
            int digito = obtenerDigito(temp->dato, i);
            colas[digito].push(stoi(temp->dato));
            temp = temp->siguiente;
        }

        // Reconstruir la lista enlazada usando los elementos de las colas
        temp = cabeza;
        cout << "\n\tPasada con dígito " << i + 1 << ":" << endl;
        for (int j = 0; j < 10; ++j) {
            cout << " Cola " << j << ": ";
            while (!colas[j].empty()) {
                temp->dato = to_string(colas[j].front());
                cout << temp->dato << " ";
                colas[j].pop();
                temp = temp->siguiente;
            }
            cout << endl;
        }
    }

    auto stop = high_resolution_clock::now();
    medirTiempo(start, stop, cabeza, "\n\tTiempo de ejecución:");
}



    
