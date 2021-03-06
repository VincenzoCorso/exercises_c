/*
	Esercizio 4b
	Implementare in C un programma che effettua lo scambio senza
	utilizzare una variabile di comodo (versione SOMMA e XOR).
*/
#include <stdio.h>

int main()
{
	// Prende in input due numeri interi.
	int a, b;
	printf("Inserisci due numeri interi: ");
	scanf("%d%d", &a, &b);
	
	// Stampa il contenuto delle variabili prima dello scambio.
	printf("Prima --> a: %d | b: %d\n", a, b);
	
	// Scambia il contenuto delle variabili, tramite lo XOR.
	a = (a & ~b) | (b & ~a);
	b = (a & ~b) | (b & ~a);
	a = (a & ~b) | (b & ~a);
	
	// Stampa il contenuto delle variabili dopo dello scambio.
	printf("Dopo --> a: %d | b: %d\n", a, b);
	
	return 0;
}