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
printf("Eu sou o filho, PID = %d. Estou vivo mas vou dormir um pouco. Enquanto isso, use o comando ps -l para conferir o
meu PID, o meu estado (S=sleep), o PID do meu pai e o estado do meu pai (R=running). Daqui a pouco eu acordo.\n",getpid()) ;
sleep(20) ; //vc também pode “matá-lo” via terminal … assim o proc não vai imprimir essa mensagem abaixo*/
printf("Acordei! Vou terminar agora. Confira novamente essas informações. Nãããooooooo!!! Vou virar um zumbi!!!\n") ;
exit(0) ;
}
else /* pai */
{
printf(“agora estou entrando em um loop infinito. Tchau!\n") ;
for(;;) ; /* pai bloqueado em loop infinito */
}
}

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
printf("Eu sou o filho, PID = %d. Estou vivo mas vou dormir um pouco. Enquanto isso, use o comando ps -l para conferir o meu PID, o meu estado (S=sleep), o PID do meu pai e o estado do meu pai (R=running). Daqui a pouco eu acordo.",getpid()) ;
sleep(20) ; //vc também pode “matá-lo” via terminal … assim o proc não vai imprimir essa mensagem abaixo*/
printf("Acordei! Vou terminar agora Confira novamente essas informações Nãããooooooo!!! Vou virar um zumbi!!!") ;
exit(0) ;
}
else /* pai */
{
printf("agora estou entrando em um loop infinito Tchau!") ;
for(;;) ; /* pai bloqueado em loop infinito */
}
}