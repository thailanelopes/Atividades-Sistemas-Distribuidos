#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
 int main()
{
    int pid ;
printf("Eu sou o processo pai, PID = %d, e eu vou criar um filho.\n",getpid()) ;
pid = fork() ;
if(pid == -1) /* erro */
{
perror("E impossivel criar um filho") ;
exit(-1) ;
}
else if(pid == 0) /* filho */
{
printf("Eu sou o filho, PID = %d. Estou vivo mas vou dormir um pouco. Use o comando ps -l para conferir o meu estado e o do meu pai. Daqui a pouco eu acordo.\n",getpid()) ;
sleep(60) ;
printf("Sou eu de novo, o filho. Acordei mas vou terminar agora. Use ps -l novamente.\n") ;
exit(0) ;
}
else /* pai */
{
printf("Bem, agora eu vou esperar pelo término da execução do meu filho. Tchau!\n") ;
wait(NULL) ; /* pai esperando pelo término do filho */
}
}