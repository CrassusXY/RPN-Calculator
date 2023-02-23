#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "moduly.h"

int main(){
    stack_t stos; 
    stos.head=NULL;             //ustawiam wskaznik glowy na NULL
    char przetwarzany[MAX];     //char do przetwarzania strumienia wejsciowego
    int i;                      //int do petli
    int out=0;                  //int pomocniczy do przechowywania liczby sciagnietej przez pop
    int wczytywana;             //int do przechowywania wartosci liczby do push
    
    do{                         //petla wykonujaca sie dopoki uzytkownik nie wprowadzi q
        scanf("%s", przetwarzany);      //skanuje strumien wejsciowy
        
        for (i=0; i<strlen(przetwarzany); i++){     //for wykonujacy sie przez dlugosc strumienia wejsciowego
            if(isdigit(przetwarzany[i])!=0){            //jesli argument jest liczba
                wczytywana=atoi(przetwarzany);          //do wczytywanej wczytuje liczbe wejsciowa
                
                while(isdigit(przetwarzany[i])!=0){     //zabezpieczenie przed wielokrotnym wczytywaniem liczb wielocyfrowych
                    i++;
                }
                push(&stos, wczytywana);                //push wejscia
            }  
            else{                                       //jesli nie jest to liczba
                switch (przetwarzany[i])                //przetwarzanie poszczegolnych elementow strumienia
                {
                case '+':                               //dodawanie
                    dodaj(&stos);
                    break;
                case '-':                               //odejmowanie
                    if(isdigit(przetwarzany[i+1])==0){  //jesli nastepna nie jest liczba
                        odejmij(&stos);                 //odejmowanie
                    }
                    break;
                case '*':
                    pomnoz(&stos);                      //mnozenie
                    break; 
                case '/':
                    podziel(&stos);                     //dzielenie
                    break;
                case 'P':
                    pop(&stos, &out);                   //zrzucam liczbe ze stosu
                    break;
                case 'p':
                    print(&stos);                       //wywoluje print
                    break;
                case 'f':
                    if(isempty(&stos)==1){              //printfull jesli stos nie jest pusty 
                        print_full(&stos);
                    }
                    else{
                        printf("Nie mozna wyswietlic liczby z pustego stosu!\n");
                    }
                    break;
                case 'd':
                    duplikuj(&stos);                    //duplikowanie 
                    break;
                case 'r':
                    zamien(&stos);                      //zmien
                    break;
                case 'c':
                    clear(&stos);                       //czyszczenie
                    break;
                case 'q':                               //koniec programu
                    printf("Koniec pracy programu\n");
                    break;
                default: 
                    printf("Nieznany symbol!\n");
                }
            } 
        }
    }while(strcmp(przetwarzany, "q")!=0);           //wykonujace sie tak dlugo, jak nie pojawi sie q
}

/* Lukasz Walczak 
Program przetestowanty na komputerze lokalnym oraz diablo.
Program dziala poprawnie dla liczb trzycyfrowych dodatnich oraz ujemnych.

Wczytywanie liczb dziala poprawnie, wczytywanie liczb ujemnych rozwiazalem tak, ze jesli mam znak -, to funkcja odejmij sprawdza,
czy nastepny argument jest liczba. W momencie jak nie jest, wykonuje sie dalej, inaczej sie nie wykonuje.

Sprawdzilem roznie scenariusze, wszelkie proby dzialan na stosie, ktory nie ma odpowiedniej liczby elementow(np. wpisanie 1 1 + +) koncza sie bledem.

Kazda z funkcji matematycznych sprawdzilem dla liczb dodatnich i ujemnych, wynik za kazdym razem byl pozytywny.
Dodalem rowniez wyjatek, dla proby dzielenia przez zero oczywiscie.

Podobnie bylo w przypadku czysczenia, duplikowania, zmiany elementow, printowania, popowania jednego elementu,
fullprinta. Kazda z funkcji zostala sprawdzona na roznych zestawach liczby. Za kazdym razem program dawal oczekiwany wynik.

Zatem moge stwierdzic, ze program dziala poprawnie :) 
*/