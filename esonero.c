/*Breve descrizione del programma:
Questa è una simulazione della cifratura RC4;
ha la possibilità di scegliere due opzioni digitando 1 o 2:
se digita "1" cifrerà il suo testo con una chiave scelta da lei;
se digita "2" cifrerà il suo testo con una chiave randomica;
per cifrare è stata usata una cifratura in esadecimale, quindi quando stamperà
la stringa di cifratura vedrà valori in esadecimale*/
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
//nella funzione1 inserisce la sua chiave che poi cifrerà il testo
void funzione1(char k1[128]);
int s,lunghezza2,lunghezza,lun3,lunghezza4;
int main(){
  char txt[128];
  char chiavepersonale[128];
  char chiaverandomica[128];
  char testocifrato[128];
  time_t t;
  int scelta, lunghezza,lunghezza2,lunghezza3;
  //queste variabili sono state utilizzate come debugger
//  char z, y, x;
  printf("scrivi il tuo messaggio da criptare\n");
  fgets(txt, 127, stdin);
    lunghezza = strlen(txt);
  txt [lunghezza-1] = '\0';
  lunghezza = strlen (txt);
  //printf("%d\n", lunghezza);
  printf("Ora digita 1 o 2 per criptare il messaggio\n");
  printf(" se inserirà un messaggio di lunghezza maggiore della chiave\n");
  printf(" da lei scelta il programma terminerà\n");
  scanf("%d",&scelta);
  //printf("%d",s);
      if (scelta == 1){
          printf(" scelta1\n ");
          fgets(chiavepersonale, 128, stdin);
          funzione1(chiavepersonale);
          lunghezza2 = strlen (chiavepersonale);
          chiavepersonale [lunghezza2-1] ='\0';
          //printf("%d",lunghezza);
                if (lunghezza > lunghezza2){
                  printf("chiave non corretta inserisci nuova chiave\n");
                }
                if(lunghezza <= lunghezza2){
                  printf("inizio criptazione\n");
                    printf("cifrazione in esadecimale è...");
                    for(size_t i = 0; i < lunghezza && i < lunghezza2; i++){
                      testocifrato[i] = txt[i] ^ chiavepersonale[i];
                      printf("%X", testocifrato[i]);
                    }
                    printf("\n");
                    printf("fine criptazione\n");
                    printf("inizio decriptazione\n");
                    printf("il messaggio era...");
                    for (size_t i = 0; i < lunghezza && i < lunghezza2; i++){
                      txt[i] = testocifrato[i] ^ chiavepersonale[i];
                      printf("%c", txt[i]);
                    }
                    printf("\n");
                    printf("fine decriptazione\n");
              }
    }
   //se sceglie la seconda scelta cifrerà il suo testo con una chiave randomica che avrà la stessa lunghezza del suo testo
      if(scelta == 2){
        printf(" scelta2\n ");
        srand( (unsigned) time (&t) );
          for(int i = 0 ; i <= lunghezza ; i++){
            chiaverandomica[i] = rand() % 96;
            chiaverandomica[i] = chiaverandomica[i] + 32;
            //lun3  = strlen(chiaverandomica);
            //printf("%d\n",lun3);
          }
        printf(" %s\n ", chiaverandomica);
        lunghezza3 = strlen (chiaverandomica);
            if (lunghezza3 >= lunghezza){
              printf("inizio criptazione\n");
            //  printf(" %s\n",m);
            //  printf(" %s\n",k2);
            printf("cifrazione in esadecimale è...");
            for(size_t i = 0; i <= lunghezza && i <= lunghezza3; i++){
              testocifrato[i] = txt[i] ^ chiaverandomica[i];
              printf( "%X", testocifrato[i] );
            }
              printf(" \n ");
            printf(" fine criptazione\n ");
            printf(" inizio decriptazione\n ");
            printf(" il messaggio era... ");
            for (size_t i = 0; i <= lunghezza && i <= lunghezza3; i++){
              txt[i] = testocifrato[i] ^ chiaverandomica[i];
              printf( "%c" , txt[i] );
            }
            printf( "\n" );
        printf("Fine decriptazione\n");
          }
       }
     }

void funzione1 (char chiavepersonale[128]){
 //int lunghezza2;
 printf("digita la tua chiave\n");
 fgets( chiavepersonale, 128, stdin );
// lunghezza2 = strlen(chiavepersonale);
}
