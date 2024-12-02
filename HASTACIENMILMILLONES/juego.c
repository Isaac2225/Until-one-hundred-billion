#include <stdio.h>
#include "myconio.h"
#include <locale.h>

#define SALIR  'd'
#define SALIRJ 'a'
#define SALIRR  7
#define MAX    100000000000
#define MAXP   100

void mostrarOp(char*);
void obtenerOp(char*);
int tratarOp(char*, int*, int*);
int jugar(int*, int*);
int canjear (int*, int*);

void mostrarOp(char *op){
    gotoxy(0,10);
    textcolor(9);
    printf("\t\t\t\t\t\t\t\t====HASTA CIEN-MIL MILLONES====\n");
    textcolor(11);
    printf("\t\t\t\t\t\t\t\ta) Jugar\n");
    printf("\t\t\t\t\t\t\t\tb) Tienda de mejoras\n");
    printf("\t\t\t\t\t\t\t\tc) Instrucciones\n");
    printf("\t\t\t\t\t\t\t\td) Salir");
}
void obtenerOp(char *op){
    *op=getch();
}
int jugar(int *cont_p, int *enc){
    char tecla='\0';
    int cont=0;
    int n=0;
    int mejora=*enc; //Mejora toma por valor la mejora comprada en la función 'canjear'.
    textcolor(4);
    printf("\t\t\t\t\t\t\t\tSi quieres salir pulsa la tecla 'a'.\n");
    do{
        while(cont<=MAX&&tecla!=SALIRJ){
            gotoxy(20,10);
            textcolor(14);
            printf("\t\t\t\t\t\t\t\t%d\r", cont);
            tecla=getch();
            if(tecla!=SALIRJ){
                cont+=mejora;   //El contador augmentará según la mejora comprada.
                if(cont%MAXP==0){
                    (*cont_p)++;
                }
            }
            textcolor(4);
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPuntos:%d\r", *cont_p);
        }
    }while(tecla!=SALIRJ&&cont<MAX);
    system("CLS");
    if(cont>=MAX&&tecla!=SALIRJ){
        printf("\t\t\t\t\t\t\t\t¡¡¡Lo has conseguido!!!");
    }
    else{
        n=3;
        while(n>=0){
            system("CLS");
            textcolor(9);
            printf("\t\t\t\t\t\t\t\tVolviendo al menú en %d", n);
            if(n==0){
                system("CLS");
                printf("\t\t\t\t\t\t\t\tPresiona cualquier tecla para volver.");
            }
            n--;
            sleep(1);
        }

    }
    return *cont_p; //Tiene que devolver los puntos para poder canjearlos en esa función.
}
int canjear(int *cont_p, int *enc){
    int compra=0;
    int enco=0;
    int num=0;
    do{
        textcolor(12);
        printf("\t\t\t\t\t\t\tPuntos:%d\n\n", *cont_p);
        textcolor(1);
        printf("\t\t\t\t\t\t\t====MEJORAS ESTANDAR====\n");
        textcolor(9);
        printf("\t\t\t\t\t\t\t1) De 10 en 10: 10 puntos\n");
        printf("\t\t\t\t\t\t\t2) De 50 en 50: 50 puntos\n");
        printf("\t\t\t\t\t\t\t3) De 100 en 100: 100 puntos\n\n");
        textcolor(5);
        printf("\t\t\t\t\t\t\t====MEJORAS PREMIUM====\n");
        textcolor(13);
        printf("\t\t\t\t\t\t\t4) De 1000 en 1000: 1000 puntos\n");
        printf("\t\t\t\t\t\t\t5) De 5000 en 5000: 5000 puntos\n");
        printf("\t\t\t\t\t\t\t6) De 1000000 en 1000000: 1000000 puntos\n\n");
        textcolor(4);
        printf("\t\t\t\t\t\t\t¡¡ATENCIÓN!! Solo se puede tener una mejora a la vez. Elige con cuidado.");
        printf("\n\t\t\t\t\t\t\tSi Intentas comprar una mejora sin puntos, se te borrará la mejora que ya tenías.");
        printf("\n\t\t\t\t\t\t\tA partir de haber comprado una mejora premium, tus mejoras se irán acumulando. INCLUSO las estandar.");
        textcolor(15);
        printf("\n\n\t\t\t\t\t\t\tSi quieres salir sin comprar, pulsa la tecla '7'.");
        textcolor(14);
        printf("\n\n\t\t\t\t\t\t\tSelecciona la compra o '7' para salir: ");
        scanf("\t\t\t\t\t\t\t%d", &compra);

        if(compra==1&&*cont_p>=10){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tCompra finalizada.");
            *enc=10;
            *cont_p-=10;
        }else if(compra==1&&*cont_p<10){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tNo tienes suficientes puntos para comprar la ventaja.");
            *enc=1;
        }
        if(compra==2&&*cont_p>=50){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tCompra finalizada.");
            *enc=50;
            *cont_p-=50;
        }else if(compra==2&&*cont_p<50){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tNo tienes suficientes puntos para comprar la ventaja.");
            *enc=1;
        }
        if(compra==3&&*cont_p>=100){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tCompra finalizada.");
            *enc=100;
            *cont_p-=100;
        }else if(compra==3&&*cont_p<100){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tNo tienes suficientes puntos para comprar la ventaja.");
            *enc=1;
        }
        if(compra==4&&*cont_p>=1000){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tCompra finalizada.");
            if(*enc>=1000){
                enco=1;
            }
            if(enco){
                *enc=*enc+1000;
            }
            else{
                *enc=1000;
            }
            *cont_p-=1000;
        }else if(compra==4&&*cont_p<1000){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tNo tienes suficientes puntos para comprar la ventaja.");
            *enc=1;
        }
        if(compra==5&&*cont_p>=5000){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tCompra finalizada.");
            if(*enc>=5000){
                enco=1;
            }
            if(enco){
                *enc=*enc+5000;
            }
            else{
                *enc=5000;
            }
            *cont_p-=5000;
        }else if(compra==5&&*cont_p<5000){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tNo tienes suficientes puntos para comprar la ventaja.");
            *enc=1;
        }
        if(compra==6&&*cont_p>=1000000){
            textcolor(4);
            printf("\n\nCompra finalizada.");
            if(*enc>=1000000){
                enco=1;
            }
            if(enco){
                *enc=*enc+1000000;
            }
            else{
                *enc=1000000;
            }
            *cont_p-=1000000;
        }else if(compra==6&&*cont_p<1000000){
            textcolor(4);
            printf("\n\n\t\t\t\t\t\t\t\tNo tienes suficientes puntos para comprar la ventaja.");
            *enc=1;
        }
        if(compra==SALIRR){
            num=3;
            while(num>=0){
                system("CLS");
                textcolor(9);
                printf("\t\t\t\t\t\t\tVolviendo al menú en %d", num);
                if(num==0){
                    system("CLS");
                    printf("\t\t\t\t\t\t\tPresiona cualquier tecla para volver.");
                }
                num--;
                sleep(1);
            }
        }
        return *cont_p, *enc; //Tiene que devolver el valor de los puntos una vez hecha la compra y el valor de la mejora comprada.
    }while(compra!=SALIRR);
}

int tratarOp(char *op, int *cont_p, int *enc){
    char sal='\0';
    switch(*op)
    {
        case 'a':
            enc=jugar(cont_p, enc); //Pasar el valor de la mejora y darle valor al contador de puntos.
            sal=getch();
            break;
        case 'b':
            *cont_p, *enc=canjear(cont_p, enc); //Pasar la mejora y los puntos por referencia para poder canjearlos.
            sal=getch();
            break;
        case 'c':
            textcolor(1);
            printf("\t\t\t\t\t\t\t\t====INSTRUCCIONES====\n\n");
            textcolor(3);
            printf("El objetivo de este juego es conseguir llegar hasta la impresionante cifra de '100000000000'");
            printf(" manteniendo pulsado una tecla. \n¿Parece tedioso verdad? Spoiler, lo és. Pero en la opción de 'comprar mejoras',");
            printf("\n puedes comprar algunas mejoras para hacer más ameno el trayecto hasta los cien-mil millones.\n");
            printf("Para comprar estas mejoras necesitarás puntos, \npuntos que irás acumulando cada vez que llegues a un múltiplo de '100', ");
            printf("es decir, '100', '200', '300'...\n");
            textcolor(4);
            printf("ATENCION: ");
            textcolor(3);
            printf("Si intentas comprar algo sin los puntos necesarios, no solo\nno podras si no que a demás se te penalizará borrandote la mejora.");
            printf("¡¡Juega con estrategia para ser el más rápido en llegar a cien-mil millones!!");
            sal=getch();
            break;
        case 'd':
            break;
        default:
            printf("Tecla incorrecta, vuelve a probar.");
            sal=getch();
            break;

    }
    return *cont_p;
}

int main (void){
    setlocale(LC_CTYPE, "spanish");
    int cont_p=0;
    int enc=1;
    char op='\0';
    do{
        mostrarOp(&op);
        obtenerOp(&op);
        system("CLS");
        cont_p=tratarOp(&op, &cont_p, &enc);
        system("CLS");
    }while(op!=SALIR);
}
