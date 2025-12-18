#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

# define MAX 10 //nb de thread
void * fonction ( void * arg )
{
printf ( " % d \ n " , * ( int *) arg ) ;
return NULL ;
}
void erreur ( char * msg )
{
perror ( msg ) ; exit (1) ;
}
int main ( int argc , char * argv [])
{
pthread_t tid [ MAX ] ; int i ;
for (i = 0 ; i < MAX ; i ++)
if ( pthread_create (& tid [ i ] , NULL , & fonction , ( void *) & i ) == -1)
erreur ( " pthread_create " ) ;
for (i = 0 ; i < MAX ; i ++)
if ( pthread_join ( tid [ i ] , NULL ) == -1)
erreur ( " pthread_join " ) ;
}