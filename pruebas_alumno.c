#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_vacia() {
	printf("\t\tINICIO DE PRUEBAS PILA VACIA\t\t\n");
	/* Creo la estructura pila*/
	pila_t* pila= pila_crear();
	
	/*Inicio de las pruebas*/
	print_test("Creación de la pila", pila != NULL);
	print_test("La pila está vacia", pila_esta_vacia(pila));
	
	/*Destruyo la estructura de la pila*/
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
	printf("\n");
}

void prueba_pila_con_algunos_elementos() {
	printf("\t\tINICIO DE PRUEBAS PILA CON ALGUNOS ELEMENTOS\t\t\n");
	/* Creo la estructura pila y declaro variables*/
	pila_t* pila= pila_crear();
	int vector[10]={1,2,3,4,5,6,7,8,9,10};
	bool resultado = true;
	
	/*Inicio de las pruebas*/
	print_test("Creación de la pila", pila != NULL);
	print_test("La pila está vacia", pila_esta_vacia(pila));
	
	/*Apilo los elementos del vector en la pila*/
	for(int i= 0; i < 10; i++) {
		resultado &= pila_apilar(pila, vector+i);
	}
	
	print_test("Los 10 elementos fueron apilados", resultado);
	print_test("La pila no está vacia", !pila_esta_vacia(pila));
	print_test("Ver tope", pila_ver_tope(pila) == vector+9);
	print_test("Desapilar tope", pila_desapilar(pila) == vector+9);
	
	/*Destruyo la estructura pila*/
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
	printf("\n");
}

void prueba_apilar_distintos_vectores() {
	printf("\t\tINICIO DE PRUEBAS APILAR CON DISTINTOS VECTORES\t\t\n");
	/*Creo la estructura pila y declaro variables*/
	pila_t* pila= pila_crear();
	int vector[10]= {1,2,3,4,5,6,7,8,9,10};
	char letras[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
	bool resultado= true;
	
	/*Inicio de las pruebas*/
	print_test("Creación de la pila", pila != NULL);
	print_test("La pila está vacia", pila_esta_vacia(pila));
	
	/*Apilo los elementos del vector en la pila*/
	for(int i= 0; i < 10; i++) {
		resultado &= pila_apilar(pila, vector+i);
	}
	
	print_test("Los 10 elementos fueron apilados", resultado);
	
	/*Apilo los elementos del vector letras en la pila*/
	resultado= true;
	for(int i= 0; i < 26; i++) {
		resultado &= pila_apilar(pila, letras+i);
	}
	
	print_test("Los 26 elementos fueron apilados", resultado);
	print_test("Ver tope", pila_ver_tope(pila) == letras+25);
	
	/*Desapilo los elementos de la pila*/
	resultado= true;
	for(int i= 25; i >= 0; i--) {
		resultado &= (pila_desapilar(pila) == letras+i);
	}
	
	print_test("Se desapilaron 26 elementos", resultado);
	
	resultado= true;
	for(int i= 9; i >= 0; i--) {
		resultado &= (pila_desapilar(pila) == vector+i);
	}
	
	print_test("Se desapilaron 10 elementos", resultado);
	
	/*Destruyo la estructura de la pila*/
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
	printf("\n");
}

void prueba_volumen_pila() {
	printf("\t\tINICIO DE PRUEBAS DE VOLUMEN\t\t\n");
	/*Creo la estructura pila y declaro variables*/
	pila_t* pila= pila_crear();
	int tope= 1000, i;
	bool resultado= true;
	
	/*Inicio de las pruebas*/
	print_test("Creación de la pila", pila != NULL);
	print_test("La pila está vacia", pila_esta_vacia(pila));
	
	/*Apilo los 1000 elementos en la pila*/
	for(i= 0; i < tope; i++) {
		resultado &= pila_apilar(pila, &i);
	}
	
	print_test("Los 1000 elementos fueron apilados", resultado);
	
	/*Desapilo los elementos de la pila*/
	resultado= true;
	for(i= 999; i >= 0; i--) {
		resultado &= (pila_desapilar(pila) == &i);
	}
	
	print_test("Se desapilaron 1000 elementos", resultado);
	
	/*Destruyo la estructura pila*/
	pila_destruir(pila);
	print_test("La pila fue destruida", true);
	printf("\n");
}

void pruebas_pila_alumno() {
    prueba_pila_vacia();
    prueba_pila_con_algunos_elementos();
    prueba_apilar_distintos_vectores();
    prueba_volumen_pila();
}
