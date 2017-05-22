#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex1, mutex2, mutex3;
int l1=0, l2=0, l3=0, l4=0, l5=0, l6=0;
//float valor_adc;

void *trilho(void* x_void_ptr);
//void *read_adc();

int main(){
  int n_trens = 3;
  pthread_t trem[n_trens];
  int i,j, trem_id[n_trens];

  /*
  pthread_t thr_adc;
  if (pthread_create(&thr_adc, NULL, read_adc, NULL) != 0){
    perror("Thread creation fail");
    exit(EXIT_FAILURE);
  }
  */

  for (i=0; i<n_trens; i++){
    trem_id[i] = i+1;
    if (pthread_create(&trem[i], NULL, trilho, &trem_id[i]) != 0){
      perror("Thread creation fail");
      exit(EXIT_FAILURE);
    }
  }

  for (j=0; j<n_trens; j++){
    if(pthread_join(trem[j], NULL)) {
      perror("Thread join fail");
      exit(EXIT_FAILURE);
    }
  }

  printf("main: End of threads!\n");
}

void *trilho(void* x_void_ptr){
  int x = *((int *)x_void_ptr); //recebendo como inteiro
  int t[3];
  pthread_mutex_t mut[2];
  printf("sou o trem %d\n", x);

  if (x==1){
    t[0] = l1;
    t[1] = l2;
    t[2] = l3;
    mut[0] = mutex1;
    mut[1] = mutex3;
  }
  else if (x==2){
    t[0] = l4;
    t[1] = l5;
    t[2] = l2;
    mut[0] = mutex2;
    mut[1] = mutex1;
  }
  else if (x==3){
    t[0] = l6;
    t[1] = l3;
    t[2] = l5;
    mut[0] = mutex3;
    mut[1] = mutex2;
  }
  else{
    perror("Trem id invalido!");
    exit(EXIT_FAILURE);
  }

  while(1){
    t[0] = 1;
    sleep(2);
    t[0] = 0;
    printf("sou o trem %d e estou esperando o meu trilho 1 \n", x);
    pthread_mutex_lock(&mut[0]);
    printf("sou o trem %d e entrei no meu trilho 1 \n", x);
    t[1] = 1;
    sleep(2);
    t[1] = 0;
    pthread_mutex_unlock(&mut[0]);
    printf("sou o trem %d e sai do meu trilho 1, o proximo pode pegar... \n", x);
    printf("sou o trem %d e estou esperando o meu trilho 2 \n", x);
    pthread_mutex_lock(&mut[1]);
    printf("sou o trem %d e entrei no meu trilho 2 \n", x);
    t[2] = 1;
    sleep(2);
    t[2] = 0;
    pthread_mutex_unlock(&mut[1]);
    printf("sou o trem %d e sai do meu trilho 2, o proximo pode pegar... \n", x);
    printf("sou o trem %d JA RODEI MAIS UMA VEZ\n", x);
  }


  return NULL;
}
