// ========================== PARTE 1/4 - Estudiante 1 ==========================
// Inclusión de la biblioteca estándar de entrada/salida
#include <iostream>
using namespace std;

// Definición de la estructura de un nodo del árbol genealógico
struct Nodo {
    int id;                         // Identificador único del miembro
    char nombre[50];                // Nombre del miembro
    char fechaNacimiento[20];      // Fecha de nacimiento
    char lugar[50];                // Lugar de origen
    char ocupacion[50];            // Ocupación del miembro
    Nodo* izquierda;               // Puntero al hijo izquierdo
    Nodo* derecha;                 // Puntero al hijo derecho

    // Constructor del nodo para inicializar los campos
    Nodo(int _id, char* _nombre, char* _fecha, char* _lugar, char* _ocupacion) {
        id = _id;
        copiarTexto(nombre, _nombre);
        copiarTexto(fechaNacimiento, _fecha);
        copiarTexto(lugar, _lugar);
        copiarTexto(ocupacion, _ocupacion);
        izquierda = NULL;
        derecha = NULL;
    }

    // Método auxiliar para copiar cadenas de caracteres
    void copiarTexto(char* destino, char* origen) {
        int i = 0;
        while (origen[i] != '\0' && i < 49) {
            destino[i] = origen[i];
            i++;
        }
        destino[i] = '\0'; // Asegura el fin de cadena
    }
};

// Clase que implementa el árbol genealógico
class ArbolGenealogico {
private:
    Nodo* raiz; // Nodo raíz del árbol

    // Método recursivo para agregar un nuevo nodo al árbol
    Nodo* agregarNodo(Nodo* nodo, int id, char* nombre, char* fecha, char* lugar, char* ocupacion) {
        if (nodo == NULL) {
            Nodo* nuevo = new Nodo(id, nombre, fecha, lugar, ocupacion);
            cout << "Miembro agregado exitosamente.\n";
            return nuevo;
        }
        if (id < nodo->id) {
            nodo->izquierda = agregarNodo(nodo->izquierda, id, nombre, fecha, lugar, ocupacion);
        } else if (id > nodo->id) {
            nodo->derecha = agregarNodo(nodo->derecha, id, nombre, fecha, lugar, ocupacion);
        } else {
            cout << "ERROR: ID " << id << " ya existe.\n";
        }
        return nodo;
    }

    // Encuentra el nodo con el ID menor (usado para reemplazos)
    Nodo* encontrarMenor(Nodo* nodo) {
        while (nodo->izquierda != NULL) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    // Método recursivo para eliminar un nodo dado su ID
    Nodo* quitarNodo(Nodo* nodo, int id) {
        if (nodo == NULL) return nodo;

        if (id < nodo->id) {
            nodo->izquierda = quitarNodo(nodo->izquierda, id);
        } else if (id > nodo->id) {
            nodo->derecha = quitarNodo(nodo->derecha, id);
        } else {
            if (nodo->izquierda == NULL && nodo->derecha == NULL) {
                delete nodo;
                return NULL;
            } else if (nodo->izquierda == NULL) {
                Nodo* temp = nodo->derecha;
                delete nodo;
                return temp;
            } else if (nodo->derecha == NULL) {
                Nodo* temp = nodo->izquierda;
                delete nodo;
                return temp;
            } else {
                Nodo* sucesor = encontrarMenor(nodo->derecha);
                nodo->id = sucesor->id;
                copiarTexto(nodo->nombre, sucesor->nombre);
                copiarTexto(nodo->fechaNacimiento, sucesor->fechaNacimiento);
                copiarTexto(nodo->lugar, sucesor->lugar);
                copiarTexto(nodo->ocupacion, sucesor->ocupacion);
                nodo->derecha = quitarNodo(nodo->derecha, sucesor->id);
            }
        }
        return nodo;
    }

    // ========================== PARTE 2/4 - Estudiante 2 ==========================

    // Recorrido en preorden
    void mostrarPreOrden(Nodo* nodo) {
        if (nodo != NULL) {
            mostrarDatos(nodo);
            mostrarPreOrden(nodo->izquierda);
            mostrarPreOrden(nodo->derecha);
        }
    }

    // Recorrido en inorden
    void mostrarEnOrden(Nodo* nodo) {
        if (nodo != NULL) {
            mostrarEnOrden(nodo->izquierda);
            mostrarDatos(nodo);
            mostrarEnOrden(nodo->derecha);
        }
    }

    // Recorrido en postorden
    void mostrarPostOrden(Nodo* nodo) {
        if (nodo != NULL) {
            mostrarPostOrden(nodo->izquierda);
            mostrarPostOrden(nodo->derecha);
            mostrarDatos(nodo);
        }
    }

    // Mostrar los datos de un nodo
    void mostrarDatos(Nodo* nodo) {
        cout << "================================\n";
        cout << "ID: " << nodo->id << "\n";
        cout << "Nombre: " << nodo->nombre << "\n";
        cout << "Fecha: " << nodo->fechaNacimiento << "\n";
        cout << "Lugar: " << nodo->lugar << "\n";
        cout << "Ocupacion: " << nodo->ocupacion << "\n";
        cout << "================================\n\n";
    }

    // Buscar existencia de un nodo por ID
    int buscarNodo(Nodo* nodo, int id) {
        if (nodo == NULL) return 0;
        if (id == nodo->id) return 1;
        else if (id < nodo->id) return buscarNodo(nodo->izquierda, id);
        else return buscarNodo(nodo->derecha, id);
    }

    // Retorna el nodo encontrado por ID
    Nodo* obtenerNodo(Nodo* nodo, int id) {
        if (nodo == NULL) return NULL;
        if (id == nodo->id) return nodo;
        else if (id < nodo->id) return obtenerNodo(nodo->izquierda, id);
        else return obtenerNodo(nodo->derecha, id);
    }

    // Elimina todos los nodos del árbol (libera memoria)
    void limpiarArbol(Nodo* nodo) {
        if (nodo != NULL) {
            limpiarArbol(nodo->izquierda);
            limpiarArbol(nodo->derecha);
            delete nodo;
        }
    }

    // Copia de texto entre arreglos (auxiliar)
    void copiarTexto(char* destino, char* origen) {
        int i = 0;
        while (origen[i] != '\0' && i < 49) {
            destino[i] = origen[i];
            i++;
        }
        destino[i] = '\0';
    }

    // Mostrar una rama completa desde un nodo
    void mostrarRama(Nodo* nodo) {
        if (nodo != NULL) {
            cout << "- " << nodo->nombre << " (ID: " << nodo->id << ")\n";
            mostrarRama(nodo->izquierda);
            mostrarRama(nodo->derecha);
        }
    }

    // Contar el número total de nodos en el árbol
    int contarMiembros(Nodo* nodo) {
        if (nodo == NULL) return 0;
        return 1 + contarMiembros(nodo->izquierda) + contarMiembros(nodo->derecha);
    }

    // Calcular la profundidad máxima del árbol
    int calcularProfundidad(Nodo* nodo) {
        if (nodo == NULL) return 0;
        int profIzq = calcularProfundidad(nodo->izquierda);
        int profDer = calcularProfundidad(nodo->derecha);
        return 1 + max(profIzq, profDer);
    }

    // ========================== PARTE 3/4 - Estudiante 3 ==========================

public:
    // Constructor del árbol
    ArbolGenealogico() {
        raiz = NULL;
    }

    // Destructor del árbol (libera memoria)
    ~ArbolGenealogico() {
        limpiarArbol(raiz);
    }

    // Agregar un miembro al árbol
    void agregar(int id, char* nombre, char* fecha, char* lugar, char* ocupacion) {
        raiz = agregarNodo(raiz, id, nombre, fecha, lugar, ocupacion);
    }

    // Eliminar un miembro
    int quitar(int id) {
        if (buscarNodo(raiz, id) == 1) {
            raiz = quitarNodo(raiz, id);
            return 1;
        }
        return 0;
    }

    // Mostrar árbol en diferentes recorridos
    void mostrarTodoPreOrden() {
        cout << "\n=== GENEALOGIA (Pre-orden) ===\n";
        if (raiz == NULL) cout << "El arbol esta vacio.\n";
        else mostrarPreOrden(raiz);
    }

    void mostrarTodoEnOrden() {
        cout << "\n=== GENEALOGIA (Ordenado por ID) ===\n";
        if (raiz == NULL) cout << "El arbol esta vacio.\n";
        else mostrarEnOrden(raiz);
    }

    void mostrarTodoPostOrden() {
        cout << "\n=== GENEALOGIA (Post-orden) ===\n";
        if (raiz == NULL) cout << "El arbol esta vacio.\n";
        else mostrarPostOrden(raiz);
    }

    // Buscar existencia de un miembro
    int buscar(int id) {
        return buscarNodo(raiz, id);
    }

    // Mostrar la información de un miembro específico
    void mostrarMiembro(int id) {
        Nodo* nodo = obtenerNodo(raiz, id);
        if (nodo != NULL) {
            cout << "\n=== INFORMACION DEL MIEMBRO ===\n";
            mostrarDatos(nodo);
        } else {
            cout << "Miembro con ID " << id << " no encontrado.\n";
        }
    }

    // Verificar si un miembro pertenece a la rama de otro
    int verificarRama(int idRama, int idMiembro) {
        Nodo* nodoRama = obtenerNodo(raiz, idRama);
        if (nodoRama == NULL) {
            cout << "La rama con ID " << idRama << " no existe.\n";
            return 0;
        }
        return buscarNodo(nodoRama, idMiembro);
    }

    // Mostrar todos los descendientes de un miembro
    void mostrarDescendientes(int idAncestro) {
        Nodo* nodo = obtenerNodo(raiz, idAncestro);
        if (nodo != NULL) {
            cout << "\n=== DESCENDIENTES DE " << nodo->nombre << " ===\n";
            cout << "Rama izquierda:\n";
            mostrarRama(nodo->izquierda);
            cout << "Rama derecha:\n";
            mostrarRama(nodo->derecha);
        } else {
            cout << "Ancestro con ID " << idAncestro << " no encontrado.\n";
        }
    }

    // Mostrar estadísticas del árbol
    void mostrarEstadisticas() {
        cout << "\n=== ESTADISTICAS DEL ARBOL ===\n";
        cout << "Total de miembros: " << contarMiembros(raiz) << "\n";
        cout << "Profundidad del arbol: " << calcularProfundidad(raiz) << "\n";
        cout << (raiz == NULL ? "Estado: Vacio\n" : "Estado: Con datos\n");
        cout << "\n";
    }

    // Verificar si el árbol está vacío
    int estaVacio() {
        return raiz == NULL ? 1 : 0;
    }
};

// ========================== PARTE 4/4 - Estudiante 4 ==========================

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "  ARBOL GENEALOGICO - CIVILIZACION\n";
    cout << "========================================\n";
    cout << "1. Mostrar arbol completo\n";
    cout << "2. Agregar nuevo miembro\n";
    cout << "3. Buscar miembro por ID\n";
    cout << "4. Eliminar miembro\n";
    cout << "5. Mostrar recorridos\n";
    cout << "6. Verificar pertenencia a rama\n";
    cout << "7. Mostrar descendientes\n";
    cout << "8. Estadisticas del arbol\n";
    cout << "0. Salir\n";
    cout << "========================================\n";
    cout << "Opcion: ";
}

// Función para mostrar el submenú de tipos de recorrido
void menuRecorridos() {
    cout << "\n=== TIPOS DE RECORRIDO ===\n";
    cout << "1. Pre-orden\n";
    cout << "2. En-orden (ordenado)\n";
    cout << "3. Post-orden\n";
    cout << "4. Todos los recorridos\n";
    cout << "Opcion: ";
}

// Función para pausar la ejecución hasta que el usuario presione Enter
void esperarEnter() {
    cout << "\nPresione Enter para continuar...";
    char c;
    do {
        c = cin.get();
    } while (c != '\n');
}

// Función principal del programa
int main() {
    ArbolGenealogico arbol;
    int opcion;
    int id, idRama, idMiembro;
    char nombre[50], fecha[20], lugar[50], ocupacion[50];
    int resultado;

    // Carga inicial de datos predefinidos
    cout << "========================================\n";
    cout << "  INICIALIZANDO DATOS DE EJEMPLO\n";
    cout << "========================================\n";

    // Miembro 1
    char n1[] = "Emperador_Xul";
    char f1[] = "1500-01-01";
    char l1[] = "Templo_Central";
    char o1[] = "Gobernante";
    arbol.agregar(10, n1, f1, l1, o1);

    // Miembro 2
    char n2[] = "Sacerdote_Kaal";
    char f2[] = "1530-05-12";
    char l2[] = "Templo_Norte";
    char o2[] = "Sacerdote";
    arbol.agregar(5, n2, f2, l2, o2);

    // Miembro 3
    char n3[] = "Princesa_Itzel";
    char f3[] = "1510-03-19";
    char l3[] = "Palacio_Real";
    char o3[] = "Nobleza";
    arbol.agregar(15, n3, f3, l3, o3);

    // Miembro 4
    char n4[] = "Guerrero_Balam";
    char f4[] = "1545-08-22";
    char l4[] = "Fortaleza";
    char o4[] = "Guerrero";
    arbol.agregar(3, n4, f4, l4, o4);

    // Miembro 5
    char n5[] = "Escriba_Akbal";
    char f5[] = "1535-12-05";
    char l5[] = "Biblioteca";
    char o5[] = "Escriba";
    arbol.agregar(7, n5, f5, l5, o5);

    cout << "Datos cargados correctamente.\n";
    esperarEnter();

    // Menú principal interactivo
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        switch(opcion) {
            case 1:
                arbol.mostrarTodoEnOrden(); // Mostrar árbol ordenado por ID
                esperarEnter();
                break;

            case 2:
                // Agregar nuevo miembro
                cout << "\n=== AGREGAR NUEVO MIEMBRO ===\n";
                cout << "ID: ";
                cin >> id;
                cin.ignore();
                cout << "Nombre: ";
                cin.getline(nombre, 50);
                cout << "Fecha (AAAA-MM-DD): ";
                cin.getline(fecha, 20);
                cout << "Lugar: ";
                cin.getline(lugar, 50);
                cout << "Ocupacion: ";
                cin.getline(ocupacion, 50);
                arbol.agregar(id, nombre, fecha, lugar, ocupacion);
                esperarEnter();
                break;

            case 3:
                // Buscar miembro
                cout << "\n=== BUSCAR MIEMBRO ===\n";
                cout << "ID a buscar: ";
                cin >> id;
                resultado = arbol.buscar(id);
                if (resultado == 1) {
                    cout << "Miembro encontrado!\n";
                    arbol.mostrarMiembro(id);
                } else {
                    cout << "Miembro no encontrado.\n";
                }
                esperarEnter();
                break;

            case 4:
                // Eliminar miembro
                cout << "\n=== ELIMINAR MIEMBRO ===\n";
                cout << "ID a eliminar: ";
                cin >> id;
                resultado = arbol.quitar(id);
                if (resultado == 1) {
                    cout << "Miembro eliminado.\n";
                } else {
                    cout << "Miembro no encontrado.\n";
                }
                esperarEnter();
                break;

            case 5:
                // Mostrar diferentes recorridos
                int subopcion;
                menuRecorridos();
                cin >> subopcion;
                switch(subopcion) {
                    case 1: arbol.mostrarTodoPreOrden(); break;
                    case 2: arbol.mostrarTodoEnOrden(); break;
                    case 3: arbol.mostrarTodoPostOrden(); break;
                    case 4:
                        arbol.mostrarTodoPreOrden();
                        arbol.mostrarTodoEnOrden();
                        arbol.mostrarTodoPostOrden();
                        break;
                    default: cout << "Opcion invalida.\n";
                }
                esperarEnter();
                break;

            case 6:
                // Verificar pertenencia a rama
                cout << "\n=== VERIFICAR PERTENENCIA ===\n";
                cout << "ID de la rama: ";
                cin >> idRama;
                cout << "ID del miembro: ";
                cin >> idMiembro;
                resultado = arbol.verificarRama(idRama, idMiembro);
                cout << (resultado ? "El miembro SI pertenece a la rama.\n" : "El miembro NO pertenece a la rama.\n");
                esperarEnter();
                break;

            case 7:
                // Mostrar descendientes
                cout << "\n=== MOSTRAR DESCENDIENTES ===\n";
                cout << "ID del ancestro: ";
                cin >> id;
                arbol.mostrarDescendientes(id);
                esperarEnter();
                break;

            case 8:
                // Mostrar estadísticas del árbol
                arbol.mostrarEstadisticas();
                esperarEnter();
                break;

            case 0:
                cout << "\nGracias por usar el sistema!\n";
                break;

            default:
                cout << "Opcion invalida.\n";
                esperarEnter();
        }
    } while (opcion != 0);

    return 0;
}
