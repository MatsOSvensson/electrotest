#include <stdio.h>
#include <stdlib.h>
#include "resistance.h"
#include "power.h"
#include "component.h"

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
    float power;
//    int array to be used when saving component values    
//    int *compChange;


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
//    Used later when components ready    
//    compChange = (int *)malloc(count * sizeof(int));
  
    //Uträkningar
    ohm = calc_resistance(count, coon, compArray);
    //placeholder, saved for power calc
    power = 500;
    //power = calc_power_r();
    //power = calc_power_i();
    //compChange = e_resistance();

    //Output av uträkningar
    printf("Ersättningsresistans:\n%0.1f ohm", ohm);
    printf("\nEffekt:\n%0.2f W", power);
    printf("\nErsättningsresistanser i E12-serien kopplade i serie:\n");

    for(int i = 0; i < count; i++){
     //placeholder, space saved for ersättningsresistanser
     printf("%d\n", (i + 1));
     // printf("\n%d", compChange[i]);

    }

    free(compArray);


  }
