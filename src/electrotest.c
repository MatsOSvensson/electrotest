#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resistance.h"
#include "power.h"
#include "component.h"


/*

  Huvudprogram som tar in uppgfiter från användaren,
  kallar funktioner från bibliotek och sedan
  gör uträkningar som ger svar till användaren

*/
int main(){

  /*

    Variabler

  */
     
  int count;
  char coon;
  float volt;
  float comp;
  float *compArray;
  float ohm;
  float power;
  float *components_e12;
  
  // Upp till 3 ersättningsresistancer kan det bli tal om
  const int e12_resistance_array_size = 3;

  // antal e12 resistancer
  int count_e12 = 0;

  //    int array to be used when saving component values    
  //    int *compChange;


  /*
    Värden från användaren
  */
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
  
  /*

    Räkna ut ersättnings resistancs värde

  */
  ohm = calc_resistance(count, coon, compArray);



  /*

    Räkna ut effekt

  */
  power = calc_power_r(volt, ohm);
  
  // Anrop och utskrift av den andra funktionen 
  //printf("power (current) %0.2f", calc_power_i(volt, (volt/ohm)));
  




  /*

    Räkna ut ersättnings resistanser från E12 serien

  */

  // allokera array och fyll med nollor
  components_e12 = malloc(e12_resistance_array_size * sizeof(float));
  memset(components_e12, 0, e12_resistance_array_size * sizeof(float));

  // Räkna ut
  count_e12 = e_resistance(ohm, components_e12);





  /*

    Output av uträkningar

  */

  printf("Ersättningsresistans:\n%0.1f ohm", ohm);
  if(power < 0) {
    printf("\nVolt och/eller resistansen är 0, ingen mening att räkna ut effekten!");
  } else {
    printf("\nEffekt:\n%0.2f W", power);
  }
  
  printf("\nErsättningsresistanser i E12-serien kopplade i serie:\n");

  for(int i = 0; i < count_e12; i++){
    printf("%d\n", (int)components_e12[i]);
  }




  /*
 
    Städar upp
 
  */
  free(compArray);
  free(components_e12);

  return 0;

}

