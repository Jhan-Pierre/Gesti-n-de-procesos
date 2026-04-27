#include <stdio.h>
#include <fcntl.h>      // para usar open() y write()
#include <sys/stat.h>   // para mode_t
#include <sys/file.h>   // Librería necesaria para flock
#include <unistd.h>     // para usar close() y write()

// ANTES DE EJECUTAR: rm r2.txt && touch r2.txt

int main(void){
        int open_flags   = O_RDWR | O_APPEND;   // read/write + create + append
        int fd = open("r2.txt", open_flags);
        int fd2 = 0;

        // Bloquear archivo
        printf("Locking file r2.txt with LOCK_EX...\n");
        // <<< Colocar aqui el codigo para bloquear r2.txt >>>
        flock(fd, LOCK_EX);

        int opc=0;

        while(opc!=2){
                printf("(1) Grabar r1 & r2 (2) Salir: ");
                scanf("%d",&opc);
                if (opc == 1){
                        // alterar archivo
                        write(fd, "Hello World!\n",14 );

                        printf("Trying lock r1.txt file...\n");
                        fd2 = open("r1.txt", open_flags);
                        // <<< Colocar aqui el codigo para bloquear r1.txt >>>
                        flock(fd2, LOCK_EX);
                        printf("File r1.txt locked successfully!\n");
                }
        }

        printf("Unlocking file...\n");
        // <<< Colocar aqui el codigo para desbloquear r2.txt >>>
        flock(fd, LOCK_UN);
        // <<< Colocar aqui el codigo para desbloquear r1.txt >>>
        if (fd2 > 0) flock(fd2, LOCK_UN);

        close(fd);
        close(fd2);

        printf("Program finished\n");

        return 0;
}