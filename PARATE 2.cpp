    void mostrarPreOrden(Nodo* nodo) {
        if (nodo != NULL) {
            mostrarDatos(nodo);
            mostrarPreOrden(nodo->izquierda);
            mostrarPreOrden(nodo->derecha);
        }
    }
    
    void mostrarEnOrden(Nodo* nodo) {
        if (nodo != NULL) {
            mostrarEnOrden(nodo->izquierda);
            mostrarDatos(nodo);
            mostrarEnOrden(nodo->derecha);
        }
    }
    
    void mostrarPostOrden(Nodo* nodo) {
        if (nodo != NULL) {
            mostrarPostOrden(nodo->izquierda);
            mostrarPostOrden(nodo->derecha);
            mostrarDatos(nodo);
        }
    }
    
    void mostrarDatos(Nodo* nodo) {
        cout << "================================\n";
        cout << "ID: " << nodo->id << "\n";
        cout << "Nombre: " << nodo->nombre << "\n";
        cout << "Fecha: " << nodo->fechaNacimiento << "\n";
        cout << "Lugar: " << nodo->lugar << "\n";
        cout << "Ocupacion: " << nodo->ocupacion << "\n";
        cout << "================================\n\n";
    }
    
    int buscarNodo(Nodo* nodo, int id) {
        if (nodo == NULL) {
            return 0;
        }
        
        if (id == nodo->id) {
            return 1;
        }
        else if (id < nodo->id) {
            return buscarNodo(nodo->izquierda, id);
        }
        else {
            return buscarNodo(nodo->derecha, id);
        }
    }
    
    Nodo* obtenerNodo(Nodo* nodo, int id) {
        if (nodo == NULL) {
            return NULL;
        }
        
        if (id == nodo->id) {
            return nodo;
        }
        else if (id < nodo->id) {
            return obtenerNodo(nodo->izquierda, id);
        }
        else {
            return obtenerNodo(nodo->derecha, id);
        }
    }
    
    void limpiarArbol(Nodo* nodo) {
        if (nodo != NULL) {
            limpiarArbol(nodo->izquierda);
            limpiarArbol(nodo->derecha);
            delete nodo;
        }
    }
    
    void copiarTexto(char* destino, char* origen) {
        int i = 0;
        while (origen[i] != '\0' && i < 49) {
            destino[i] = origen[i];
            i++;
        }
        destino[i] = '\0';
    }
    
    void mostrarRama(Nodo* nodo) {
        if (nodo != NULL) {
            cout << "- " << nodo->nombre << " (ID: " << nodo->id << ")\n";
            mostrarRama(nodo->izquierda);
            mostrarRama(nodo->derecha);
        }
    }
    
    int contarMiembros(Nodo* nodo) {
        if (nodo == NULL) return 0;
        return 1 + contarMiembros(nodo->izquierda) + contarMiembros(nodo->derecha);
    }
    
    int calcularProfundidad(Nodo* nodo) {
        if (nodo == NULL) return 0;
        int profIzq = calcularProfundidad(nodo->izquierda);
        int profDer = calcularProfundidad(nodo->derecha);
        if (profIzq > profDer) {
            return 1 + profIzq;
        } else {
            return 1 + profDer;
        }
    }
