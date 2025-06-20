Proceso Arbol_Binario
	
    Dimension valores[100], izq[100], der[100]
    Definir valores, izq, der Como Entero
	
    Definir nodoRaiz, totalNodos, nuevoValor Como Entero
    Definir opcion, actual, nuevoNodo Como Entero
	
    nodoRaiz <- -1
    totalNodos <- 0
	
    Repetir
        Escribir ""
        Escribir "======= MENÚ DEL ÁRBOL BINARIO ======="
        Escribir "1. Insertar nodo"
        Escribir "2. Recorrido Inorden"
        Escribir "3. Recorrido Preorden"
        Escribir "4. Recorrido Postorden"
        Escribir "5. Salir"
        Escribir "Seleccione una opción: "
        Leer opcion
		
        Segun opcion Hacer
            1:
                Escribir "Ingrese valor del nodo:"
                Leer nuevoValor
				
                totalNodos <- totalNodos + 1
				valores[totalNodos] <- nuevoValor
				izq[totalNodos] <- -1
				der[totalNodos] <- -1
				nuevoNodo <- totalNodos
				
				Si nodoRaiz = -1 Entonces
					nodoRaiz <- nuevoNodo
				Sino
					Insertar(nodoRaiz, nuevoNodo, valores, izq, der)
				FinSi
				
            2:
				Si nodoRaiz = -1 Entonces
					Escribir "Árbol vacío"
				Sino
					Escribir "Recorrido Inorden:"
					Inorden(nodoRaiz, valores, izq, der)
				FinSi
			3:
				Si nodoRaiz = -1 Entonces
					Escribir "Árbol vacío"
				Sino
					Escribir "Recorrido Preorden:"
					Preorden(nodoRaiz, valores, izq, der)
				FinSi
			4:
				Si nodoRaiz = -1 Entonces
					Escribir "Árbol vacío"
				Sino
					Escribir "Recorrido Postorden:"
					Postorden(nodoRaiz, valores, izq, der)
				FinSi
				
            5:
                Escribir "Programa finalizado."
				
            De Otro Modo:
                Escribir "Opción no válida. Intente de nuevo."
        FinSegun
    Hasta Que opcion = 5
	
FinProceso

SubProceso Insertar(actual, nuevoNodo, valores, izq, der)
		Si valores[nuevoNodo] < valores[actual] Entonces
			Si izq[actual] = -1 Entonces
				izq[actual] <- nuevoNodo
			Sino
				Insertar(izq[actual], nuevoNodo, valores, izq, der)
			FinSi
		Sino
			Si der[actual] = -1 Entonces
				der[actual] <- nuevoNodo
			Sino
				Insertar(der[actual], nuevoNodo, valores, izq, der)
			FinSi
		FinSi
FinSubProceso

SubProceso Inorden(nodo, valores, izq, der)
    Si nodo <> -1 Entonces
        Inorden(izq[nodo], valores, izq, der)
        Escribir "Valor: ", valores[nodo]
        Inorden(der[nodo], valores, izq, der)
    FinSi
FinSubProceso

SubProceso Preorden(nodo, valores, izq, der)
    Si nodo <> -1 Entonces
        Escribir "Valor: ", valores[nodo]
        Preorden(izq[nodo], valores, izq, der)
        Preorden(der[nodo], valores, izq, der)
    FinSi
FinSubProceso

SubProceso Postorden(nodo, valores, izq, der)
    Si nodo <> -1 Entonces
        Postorden(izq[nodo], valores, izq, der)
        Postorden(der[nodo], valores, izq, der)
        Escribir "Valor: ", valores[nodo]
    FinSi
FinSubProceso




