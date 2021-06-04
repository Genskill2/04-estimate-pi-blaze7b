#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int);

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}
float mc_pi(int x){
    float incircle=0;
    float total=0;
    float p,q,n,m,d,t;
    for(int i=0;i<x;i++){
         p =frandom();
         q =frandom();
         p =2*p-1;
         q =2*q-1;
         n =pow(p,2);
         m =pow(q,2);
         d =sqrt(n+m);
         if(d<=1){
             incircle+=1;}
        total+=1;}
    t =4*incircle/total;
    return t;
}


