#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size == 0){
    return NULL;
  }
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size+1 > pq->capac)
  {
    pq->capac = ((pq->capac)*2)+1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray,pq->capac*sizeof(heapElem));
  }
  int aux = pq->size;
  while(aux>0 && pq->heapArray[(aux-1)/2].priority < priority)
  {
    pq->heapArray[aux] = pq->heapArray[(aux-1)/2];
    aux = (aux-1)/2;
  }
  pq->heapArray[aux].priority = priority;
  pq->heapArray[aux].data = data;
  pq->size++;
}


void heap_pop(Heap* pq){
  pq->size--;
  pq->heapArray[0] = pq->heapArray[pq->size];
  heapElem* aux = (heapElem*)malloc(sizeof(heapElem));
  aux = pq->heapArray[1];
  Heap* prioridad= pq->heapArray[0].priority;

  while(aux <= pq->size && pq->heapArray[aux].priority > prioridad || aux+1 <= pq->size && pq->heapArray[aux+1].priority > prioridad)
  {
    heapElem *temp = pq->heapArray[(aux-1)/2];
    if(aux+1 <= pq->size && pq->heapArray[aux+1].priority > priority) aux++;
    pq->heapArray[(aux-1)/2] = pq->heapArray[aux];
    pq->heapArray[aux] = temp;
    aux = aux*2+1;
    
  }
  
}

Heap* createHeap(){
  Heap* new = (Heap*)malloc(sizeof(Heap));
  new->heapArray = (heapElem*)malloc(3*sizeof(heapElem));
  new->size = 0;
  new->capac = 3;
  return new;
   
}
