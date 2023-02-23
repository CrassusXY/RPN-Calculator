#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "moduly.h"

/*Sprawdzenie czy stos jest pusty*/
int isempty(stack_t *stos){
    if(stos->head!=NULL){   //jesli stos nie jest pusty, 
        return 1;
    }
    else{
        return 0;
    }
}

/*Push*/
void push(stack_t *stos, int liczba){
    lelem_t *new = (lelem_t*) malloc(sizeof(lelem_t));      //alokuje pamiec dla nowej struktury lelem_t
    new->dana=liczba;                                       //w jej czesc z intem wpisuje liczbe
    new->nxt=stos->head;                                    //jej wskaznik ustawiam na to, co obecnie wskazuje head
    stos->head=new;                                         //wskaznik head ustawiam na new
}

/*Pop*/
void pop(stack_t *stos, int *out){
    if(isempty(stos)==1){       //jesli stos nie jest pusty
        lelem_t *pom;           //tworze pomocnicza strukture lelem_t
        pom=stos->head;         //wskaznik na pomocnicza wskazuje teraz na to, na co wskazywal head
        *out=pom->dana;         //do out wpisuje liczbe przechowywana w tym na co wskazuje teraz pom
        stos->head=pom->nxt;    //head wskazuje teraz na nastepny element
    }
    else{
        fprintf(stderr,"Stos pusty!\n");
    }
}

/*Print*/
void print(stack_t *stos){
    int wyswietlana;
    if(isempty(stos)==1){                   //jesli cos jest na stosie
        pop(stos, &wyswietlana);            //popuje to
        printf("%d\n", wyswietlana);        //drukuje to
        push(stos, wyswietlana);            //wrzucam na stos
    }
    else{                                   //jak nie ma nic na stosie, wyswietlam komunikat
        fprintf(stderr, "Nie mozna wyswietlic liczby z pustego stosu!\n");
    }
}

/*Czyszczenie*/
void clear(stack_t *stos){
    int sciagnieta;
    int i;
    for(i=0; i<MAX; i++){
        if(isempty(stos)==1){           //jesli cos jest na stosie 
            pop(stos, &sciagnieta);     //sciagam to
        }
        else{                           //jak nie ma
            break;                      //wychodze z petli
        }
    }

}

/*Wypisanie calego stosy*/
void print_full(stack_t *stos){
    int tab[MAX];               //tablica pomocnicza do przechowywania wartosci wypisywanych 
    int sciagnieta;
    int i;
    for(i=0; i<MAX; i++){ 
        if(isempty(stos)==1){               //sprawdzam czy stos jest pusty
            pop(stos, &sciagnieta);         //popuje wartosc 
            tab[i]=sciagnieta;              //zapisuje ja do tablicy
            printf("%d\n", sciagnieta);     //printuje ja
        }
        else{                               //wychodze z petli jak stos jest pusty
            break;
        }
    }
    i=i-1;                                  //odejmuje od liczby przebiegow petli przebieg w ktorym petla zrobila break
    for(i=i; i>=0; i--){                    //wrzucam na stos wartosci z tablicy
        push(stos, tab[i]);
    }
}

/*Zamiana*/
void zamien(stack_t *stos){
    int a, b;
    if(isempty(stos)==1){       //jesli stos nie jest pusty
        pop(stos, &a);          //sciagam wartosc
        if(isempty(stos)==1){   //jesli stos dalej nie jest pusty
            pop(stos, &b);      //sciagam druga wartosc
            push(stos, a);      //pushuje je w odwrotnej kolejnosci
            push(stos, b);
        }
        else{                   //jesli nie ma drugiego elementu
            push(stos, a);      //wrzucam ponownie pierwsza wartosc
        }
    }   
}

/*Duplikacja*/
void duplikuj(stack_t *stos){
    int duplikowana;
    if(isempty(stos)==1){   //jesli cos jest na stosie
        pop(stos, &duplikowana);    //sciagam to
        push(stos, duplikowana);    //wrzucam dwa razy
        push(stos, duplikowana);
    }
}

/*Dodawanie*/
void dodaj(stack_t *stos){
    int out;
    int a, b, wynik;
    if(isempty(stos)==1){           //jesli stos nie jest pusty
        pop(stos, &out);            //sciagam wartosc
        a=out;                      //przypisuje sciagnieta wartosc do pomocniczej
        if(isempty(stos)==1){       //jesli stos dalej nie jest pusty
            pop(stos, &out);        //sciagam druga wartosc
            b=out;                  //przypisuje kolejna sciagnieta do drugiej pomocniczej
            wynik=a+b;              //obliczenia
            push(stos, wynik);      //wrzucam na stos wynik
        }
        else{                       //jesli nie ma drugiej liczby na stosie
            push(stos, a);          //wrzucam ponownie pierwsza
        }
    }   
}

/*Odejmowanie*/
void odejmij(stack_t *stos){
    int out;
    int a, b, wynik;
    if(isempty(stos)==1){           //jesli stos nie jest pusty
        pop(stos, &out);            //sciagam wartosc
        a=out;                      //przypisuje sciagnieta wartosc do pomocniczej
        if(isempty(stos)==1){       //jesli stos dalej nie jest pusty
            pop(stos, &out);        //sciagam druga wartosc
            b=out;                  //przypisuje kolejna sciagnieta do drugiej pomocniczej
            wynik=b-a;              //obliczenia
            push(stos, wynik);      //wrzucam na stos wynik
        }
        else{                       //jesli nie ma drugiej liczby na stosie
            push(stos, a);          //wrzucam ponownie pierwsza
        }
    } 
}

/*Mnozenie*/
void pomnoz(stack_t *stos){
    int out;
    int a, b, wynik;
    if(isempty(stos)==1){           //jesli stos nie jest pusty
        pop(stos, &out);            //sciagam wartosc
        a=out;
        if(isempty(stos)==1){       //jesli stos dalej nie jest pusty
            pop(stos, &out);        //sciagam druga wartosc
            b=out;
            wynik=a*b;              //obliczenia
            push(stos, wynik);      //wrzucam na stos wynik
        }
        else{                       //jesli nie ma drugiej liczby na stosie
            push(stos, a);          //wrzucam ponownie pierwsza
        }
    } 
}

/*Dzielenie*/
void podziel(stack_t *stos){
    int out;
    int a, b, wynik;
    if(isempty(stos)==1){           //jesli stos nie jest pusty
        pop(stos, &out);            //sciagam pierwsza wartosc
        a=out;
        if(isempty(stos)==1){       //jesli stos dalej nie jest pusty
            pop(stos, &out);        //sciagam druga wartosc
            b=out;
            if(a==0){               //wyjatek dla dzielenia przez 0
                printf("Nie wolno dzielić przez zero!!\n");
            }
            else{
                wynik=b/a;          //obliczenia
                push(stos, wynik);  //wrzucam wynik
            }
        }
        else{                       //jesli nie ma drugiej liczby na stosie
            push(stos, a);          //wrzucam ponownie pierwsza
        }
    }
}
