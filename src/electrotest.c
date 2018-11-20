#include <stdio.h>
#include <stdlib.h>
#include "resistance.h"

/*
Huvudprogram som tar in uppgfiter från användaren,
kallar funktioner från bibliotek och sedan
gör uträkningar som ger svar till användaren
*/

  void main(){
     
    int count;
    char coon;
    float volt;
    float comp;
    float *compArray;
    float ohm;


//Värden från användaren
    printf("Ange spänningskälla i V: ");
    scanf("%f", &volt);
    printf("Ange koppling[S | P]: ");
    scanf(" %c", &coon);
    printf("Antal komponenter: ");
    scanf("%d", &count);
    
    compArray = (float *)malloc(count * sizeof(float));    

    for(int i = 0; i < count; i++){
      printf("Komponent %d i ohm: ", (i + 1));
      scanf("%f", &comp);
      compArray[i] = comp;
    }
    
    ohm = calc_resistance(count, coon, compArray);
 
    printf("Ersättningsresistans:\n%0.1f ohm", ohm);
    printf("\nEffekt:\n");
    printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");

    for(int i = 0; i < count; i++){

      printf("\n");

    }

    free(compArray);


  }
