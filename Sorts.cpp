#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm> 
#include <cctype>   
#include <queue>
#include <cmath> 

using namespace std;
using namespace std::chrono;

// Definición de la estructura de un nodo
struct Nodo {
    string dato;
    Nodo* siguiente;
};

// Declaraciones de funciones
vector<int> leerNumerosAleatorios(const string& nombreArchivo);
void reconstruirListaDesdeArchivo(Nodo*& cabeza, const string& nombreArchivo);
void imprimirLista(Nodo* cabeza);
void insertarElemento(Nodo*& cabeza, const string& elemento);
void eliminarElemento(Nodo*& cabeza, const string& elemento);
void liberarLista(Nodo*& cabeza);
void medirTiempo(high_resolution_clock::time_point start, high_resolution_clock::time_point stop, Nodo*& cabeza, const string& mensaje);
void bubbleSort(Nodo*& cabeza);
void selectionSort(Nodo*& cabeza);
void insertionSort(Nodo*& cabeza);
void merge(Nodo*& cabeza, Nodo* izquierda, Nodo* derecha);
void mergeSortHelper(Nodo*& cabeza);
void mergeSort(Nodo*& cabeza);
Nodo* partition(Nodo* cabeza, Nodo* fin, Nodo** newHead, Nodo** newEnd);
Nodo* quickSortHelper(Nodo* cabeza, Nodo* fin);
void quickSort(Nodo*& cabeza);
void bucketSort(Nodo*& cabeza);
void ordenarCubo(vector<int>& cubo);
int encontrarMaximo(Nodo* cabeza);
void shellSort(Nodo*& cabeza);
void countingSort(Nodo*& cabeza);
void radixSort(Nodo*& cabeza);
int obtenerDigito(const string& numero, int posicion);
void menuOrdenamiento(Nodo*& cabeza);
Nodo* getTail(Nodo* cabeza);
int obtenerNumero();

int main() {
    Nodo* cabeza = nullptr;
    int opcion;

    cout << "\n\n\t\t\tBIENVENIDO AL ALGORITMO DE ORDENAMIENTO UTILIZANDO NÚMEROS ENTEROS POSTIVOS\n\n" << endl;

    cout << "\n\tIngrese el rango inferior de números aleatorios: ";
    int rango_inferior = obtenerNumero(); // Utilizar la función para obtener un número
    cout << "\n\tIngrese el rango superior de números aleatorios: ";
    int rango_superior = obtenerNumero(); // Utilizar la función para obtener un número
    cout << "\n\t¿Cuántos números aleatorios desea generar?: ";
    int cantidad_numeros = obtenerNumero(); // Utilizar la función para obtener un número

    ofstream archivo("numeros.txt"); // Crear archivo

    srand(time(0)); // Semilla para números aleatorios

    for (int i = 0; i < cantidad_numeros; ++i) {
        int numero = rand() % (rango_superior - rango_inferior + 1) + rango_inferior;
        archivo << numero << " ";
    }
    archivo.close();

    reconstruirListaDesdeArchivo(cabeza, "numeros.txt");

    do {
        cout << endl << "\n\n\n\t \t MENU PRINCIPAL\n" << endl;
        cout << "\t1. Insertar elemento" << endl;
        cout << "\t2. Eliminar elemento" << endl;
        cout << "\t3. Ingresar al menú método de ordenamiento" << endl;
        cout << "\t4. Mostrar datos actuales" << endl;
        cout << "\t5. Mostrar números aleatorios del archivo" << endl;
        cout << "\t6. Restaurar lista original desde el archivo" << endl;
        cout << "\t7. Salir" << endl;
        cout << "\tIngrese su opción: ";
        opcion = obtenerNumero(); // Utilizar la función para obtener un número
        
        cout << endl;
        
        switch (opcion) {
            case 1: {
                string elemento;
                cout << "\tIngrese los elementos a insertar separados por espacios: ";
                getline(cin, elemento);
                insertarElemento(cabeza, elemento);
                break;
            }
            case 2: {
                string elemento;
                cout << "\tIngrese el elemento a eliminar: ";
                cin >> elemento;
                eliminarElemento(cabeza, elemento);
                break;
            }
            case 3: {
                menuOrdenamiento(cabeza);
                break;
            }
            case 4: {
                cout << "\tDatos actuales en la lista: ";
                imprimirLista(cabeza);
                break;
            }
            case 5: {
                cout << "\tNúmeros aleatorios del archivo: ";
                imprimirLista(cabeza);
                break;
            }
            case 6: {
                reconstruirListaDesdeArchivo(cabeza, "numeros.txt");
                cout << "\tLista original restaurada desde el archivo." << endl;
                break;
            }
            case 7:
                cout << "\tSaliendo del programa." << endl;
                liberarLista(cabeza); // Liberar memoria antes de salir
                break;
            default:
                cout << "\tOpción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}


// Función auxiliar para validar la entrada de números
int obtenerNumero() {
    while (true) {
        //cout << " Ingrese un número: ";
        int numero;
        cin >> numero;
        if (cin.fail()) { // Si la entrada no es un número
            cin.clear(); // Limpiar el flag de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida
            cout << "\n\tError: Debe ingresar un número. Intente de nuevo.... :" << endl;
            cout << "\n\tIngrese un número: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
            return numero; // Devolver el número válido
        }
    }
}


// --------------------- Función para leer números aleatorios de un archivo ---------------------
vector<int> leerNumerosAleatorios(const string& nombreArchivo) {
    vector<int> numeros;
    ifstream archivo(nombreArchivo);
    int numero;
    while (archivo >> numero) {
        numeros.push_back(numero);
    }
    archivo.close();
    return numeros;
}

// ---------------------  Función para reconstruir la lista desde un archivo ---------------------
void reconstruirListaDesdeArchivo(Nodo*& cabeza, const string& nombreArchivo) {
    liberarLista(cabeza);
    vector<int> numeros = leerNumerosAleatorios(nombreArchivo);
    for (int num : numeros) {
        insertarElemento(cabeza, to_string(num));
    }
}

// //---------------------  Función para imprimir la lista //--------------------- 
void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    cout << endl;
}

// //---------------------  Función para insertar un elemento al inicio de la lista //--------------------- 
void insertarElemento(Nodo*& cabeza, const string& elementos) {
    istringstream iss(elementos); // Crear un flujo de entrada a partir de la cadena de elementos
    string token;
    while (iss >> token) { // Leer cada token separado por espacios
        // Verificar si el token contiene solo dígitos
        if (all_of(token.begin(), token.end(), ::isdigit)) {
            Nodo* nuevoNodo = new Nodo;
            nuevoNodo->dato = token;
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
            cout << "\n\tElemento insertado: " << token << endl;
        } else {
            cout << "\n\tElemento no válido: " << token << ". No es un número entero positivo." << endl;
        }
    }
    cout << "\n\tArreglo después de insertar: ";
    imprimirLista(cabeza);
}

// //---------------------  Función para eliminar un elemento de la lista //--------------------- 
void eliminarElemento(Nodo*& cabeza, const string& elemento) {
    Nodo* temp = cabeza;
    Nodo* prev = nullptr;
    while (temp != nullptr && temp->dato != elemento) {
        prev = temp;
        temp = temp->siguiente;
    }
    if (temp == nullptr) {
        cout << "\n\tElemento no encontrado." << endl;
        return;
    }
    if (prev == nullptr) {
        cabeza = temp->siguiente;
    } else {
        prev->siguiente = temp->siguiente;
    }
    delete temp;
    cout << "\n\tElemento eliminado." << endl;
    cout << "\n\tArreglo después de eliminar: ";
    imprimirLista(cabeza);
}

// //---------------------  Función para liberar la memoria de la lista //--------------------- 
void liberarLista(Nodo*& cabeza) {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// //---------------------  Función para ordenar el arreglo utilizando el algoritmo Bubble Sort
void medirTiempo(high_resolution_clock::time_point start, high_resolution_clock::time_point stop, Nodo*& cabeza, const string& mensaje) {
    auto duration = duration_cast<microseconds>(stop - start);
    cout << mensaje << endl;
    cout << "\n\tArreglo resultante: ";
    imprimirLista(cabeza);
    cout << "\n\tTiempo de ejecución: " << duration.count() << " microsegundos" << endl;
}

//--------------------- Función para ordenar el arreglo utilizando el algoritmo bubbleSort ---------------------
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


//--------------------- Función para ordenar el arreglo utilizando el algoritmo Selection Sort---------------------

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


// --------------------- Función para ordenar el arreglo utilizando el algoritmo Insertion Sort ---------------------

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


//--------------------- Funciones para ordenar el arreglo utilizando el algoritmo Merge Sort ---------------------

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


//--------------------- Funciones para ordenar el arreglo utilizando el algoritmo Quick Sort ---------------------
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


//--------------------- Función para ordenar el arreglo utilizando el algoritmo Bucket Sort---------------------

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




//---------------------Función para ordenar el arreglo utilizando el algoritmo Shell Sort---------------------

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



// --------------------- Función para ordenar el arreglo utilizando el algoritmo Counting Sort ---------------------

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



// --------------------- Función para ordenar el arreglo utilizando el algoritmo Radix Sort ---------------------

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



// --------------------- Función para el segundo menú de opciones ---------------------
void menuOrdenamiento(Nodo*& cabeza) {
    int x;
    do {
        cout << endl << "\n\t\tBIENVENIDO AL MENÚ DE ORDENAMIENTOS" << endl;
        cout << "\n\tQué método va a utilizar: " << endl;
        cout << "\n\t1. Ordenar lista (Bubble Sort)" << endl;
        cout << "\n\t2. Ordenar lista (Selection Sort)" << endl;
        cout << "\n\t3. Ordenar lista (Insertion Sort)" << endl;
        cout << "\n\t4. Ordenar lista (Merge Sort)" << endl;
        cout << "\n\t5. Ordenar lista (Quick Sort)" << endl;
        cout << "\n\t6. Ordenar lista (Bucket Sort)" << endl;
        cout << "\n\t7. Ordenar lista (Shell Sort)" << endl;
        cout << "\n\t8. Ordenar lista (Counting Sort)" << endl;
        cout << "\n\t9. Ordenar lista (Radix Sort)" << endl;
        cout << "\n\t10. Volver al menú principal" << endl;
        cout << "\n\tIngrese una opción: ";
        x = obtenerNumero(); 
        
        cout << endl<< endl;
        
        switch (x) {
            case 1: {
                cout << "\n\tOrdenando lista con Bubble Sort..." << endl;
                bubbleSort(cabeza);
                break;
            }
            case 2: {
                cout << "\n\tOrdenando lista con Selection Sort..." << endl;
                selectionSort(cabeza);
                break;
            }
            case 3: {
                cout << "\n\tOrdenando lista con Insertion Sort..." << endl;
                insertionSort(cabeza);
                break;
            }
            case 4: {
                cout << "\n\tOrdenando lista con Merge Sort..." << endl;
                mergeSort(cabeza);
                break;
            }
            case 5: {
                cout << "\n\tOrdenando lista con Quick Sort..." << endl;
                quickSort(cabeza);
                break;
            }
            case 6: {
                cout << "\n\tOrdenando lista con Bucket Sort..." << endl;
                bucketSort(cabeza);
                break;
            }
            case 7: {
                cout << "\n\tOrdenando lista con Shell Sort..." << endl;
                shellSort(cabeza);
                break;
            }
            case 8: {
                cout << "\n\tOrdenando lista con Counting Sort..." << endl;
                countingSort(cabeza);
                break;
            }
            case 9: {
                cout << "\n\tOrdenando lista con Radix Sort..." << endl;
                radixSort(cabeza);
                break;
            }
            case 10:{
                cout << "\n\tVolviendo al menú principal" << endl;
                break;
            }
           default:
                cout << "\n\tOpción inválida. Intente de nuevo." << endl;
        }
    } while (x != 10);
}
