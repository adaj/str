/*
 *  ordenacao.cpp
 *
 *
 *  Created by Luiz Affonso Guedes on 06/03/17.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

// UFRN-CT-DCA
// Programa: programa para ordenação de um vetor

// Manipulação de tempo em c,c++
// Programa: programa que usa manipuladores de tempo para
// medir o desempenho de algoritmos de ordenação


#include <cstdlib>   //qsort
#include <time.h>   // clock(),time()
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()
#include <fstream>
using namespace std;


//Vetores usados pelos métodos de ordenação
int *vetorQuickSort;
int *vetorBubbleSort;
int tamanho;

//Função usada pelo qsort para comparar dois numeros
int compare_ints( const void* a, const void* b ) {
	int* arg1 = (int*) a;
	int* arg2 = (int*) b;
	if( *arg1 < *arg2 ) return -1;
	else if( *arg1 == *arg2 ) return 0;
	else return 1;
}

//Algoritmos de ordenação bubble sort
void bubbleSort(int *vetor, int tamanho) {
	int aux;
	for (int i = 0; i < tamanho-1; i++) {
		for (int j = 0; j < tamanho-1; j++) {
			if (vetor[j] > vetor[j+1]) {
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}

//Observe que os números são gerados aleatoriamente baseados
//em uma semente. Se for passado a mesma semente, os
//números aleatórios serão os mesmos
void criarVetor(int tamanhoVetor, int semente){
	srand (semente);
	vetorQuickSort = new int[tamanhoVetor];
	vetorBubbleSort = new int[tamanhoVetor];
	for (int i=0;i<tamanhoVetor;i++){
		vetorQuickSort[i] =  rand()%100000;
        vetorBubbleSort[i] = vetorQuickSort[i]; // utilizar os mesmos valores
		//vetorBubbleSort[i] = rand()%100000;
	}
}


int main ()
{

	clock_t start, qsort_t, bsort_t;
	int samples = 3;
	int ny[samples] = {1000,10000,100000};
	int qx[samples];
	int bx[samples];
	ofstream file;


	//printf("\nStart time: %ld\n",start);

	for (int i=0; i<samples; i++){
		//Criar vetor com elementos aleatorios[0,100000]
		criarVetor(ny[i],23);

		printf("Array size: %d\n",ny[i]);
		//Ordenar utilizando quickSort
		start = clock();
		qsort (vetorQuickSort, ny[i], sizeof(int), compare_ints);
		qsort_t = clock() - start;
		printf("QuickSort delta time: %ld micros\n",qsort_t);
		//Ordenar utilizando bubleSort
		start = clock();
		bubbleSort(vetorBubbleSort,ny[i]);
		bsort_t = clock() - start;
		printf("BubbleSort delta time: %ld micros\n\n",bsort_t);

		qx[i] = qsort_t;
		bx[i] = bsort_t;
	}

	file.open("ord_data.txt");
	file << "#STR - Sistemas de Tempo Real : Tarefa 1.2\n";
	file << "#BubbleSort vs QuickSort cpu time usage (by clock() function)\n";
	file << "#Columns: samples quicksort_time(ms) bubblesort_time(ms)\n";

	for (int i=0; i<samples; i++){
		file << ny[i] << " " << qx[i] << " " << bx[i] << "\n";
	}
	file.close();

	printf("Calculando histogramas...\n");
	//Histograms
	file.open("hist.dat");
	file << "#STR - Sistemas de Tempo Real : Tarefa 1.2\n";
	file << "#cpu time usage histogram\n";
	file << "#Columns: quicksort_time(ms) bubblesort_time(ms)\n";

	for (int j=0; j<100; j++){
		//Criar vetor com 100 elementos aleatorios[0,100000]
		criarVetor(100,23);

		//Ordenar utilizando quickSort
		start = clock();
		qsort (vetorQuickSort, 100, sizeof(int), compare_ints);
		qsort_t = clock() - start;

		start = clock();
		bubbleSort(vetorBubbleSort,100);
		bsort_t = clock() - start;

		file << qsort_t << " " << bsort_t << "\n";
	}
	file.close();


	return 0;

}
