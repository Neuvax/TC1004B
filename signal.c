#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void hola(int signalNumb){
    printf("Recibi la señal %d ", signalNumb);
}

int cond;
void terminarWhile(ont sigNumber){
    printf("Terminando while ");
    cond = 0;
}

int main(){
    signal(12, terminarWhile);
    signal(2, hola);
    int cond = 1;
    while(cond == v1){
        printf("trabajando\n");
        sleep(1);
    }
    printf("Aquí nunca llega");
    return 0;
}