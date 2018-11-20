#include <stdio.h>
#include "resistance.h"

/*
En funktion som tar använder sig av tre parametrar för att
ta reda på antal komponenter, serie eller parallell-koppling
och tar även in en array med dessa kopplingar.

Funktionen gör några mindre kontroller efter vägen om fel uppstår
och skickar sen tillbaka den totala resitansen
*/

float calc_resistance(int count, char coon, float *array){

  float res = 0;

//Om arrayen är tom skickas returvärde -1
  if(sizeof(array) == 0){
  
    return -1;

  }

//Om det rör sig om en seriekoppling läggs dessa ihop
//och resultatet skickas tillbaka
  if(coon == 's' || coon == 'S'){

    for(int i = 0; i < count; i++){
    
      res = res + array[i];

    } 

    return res;
    

  }

//Om det rör sig om en parallellkoppling görs beräkningarna
//enligt den metoden och resultatet skickas tillbaka
  else if(coon == 'p' || coon == 'P'){


    for(int i = 0; i < count; i++){

//Om något motstånd visar sig vara noll vid parallellkoppling
//returneras 0
        if(array[i] == 0){
 
          return 0;

        }       

        res = res + 1 / array[i];        
        
      }
      
      res = 1 / res;
     
      return res;

  }

//Om medföljande char ej är ett s eller p skickas -1 tillbaka
  else {

    return -1;

  }

}
