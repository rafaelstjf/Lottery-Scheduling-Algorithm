/*
*  lottery.c - Implementacao do algoritmo Lottery Scheduling e sua API
*
*  Autores: SUPER_PROGRAMADORES_C
*  Projeto: Trabalho Pratico I - Sistemas Operacionais
*  Organizacao: Universidade Federal de Juiz de Fora
*  Departamento: Dep. Ciencia da Computacao
*
*
*/

#include "lottery.h"
#include <stdio.h>
#include <string.h>

//Nome unico do algoritmo. Deve ter 4 caracteres.
const char lottName[] = "LOTT";

//=====Funcoes Auxiliares=====
unsigned int randInterval(unsigned int min, unsigned int max)
{
	//creditos: theJPster (https://stackoverflow.com/questions/2509679/how-to-generate-a-random-integer-number-from-within-a-range)
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do
    {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}
//=====Funcoes da API=====

//Funcao chamada pela inicializacao do S.O. para a incializacao do escalonador
//conforme o algoritmo Lottery Scheduling
//Deve envolver a inicializacao de possiveis parametros gerais
//Deve envolver o registro do algoritmo junto ao escalonador
void lottInitSchedInfo()
{
	//...
}

//Inicializa os parametros de escalonamento de um processo p, chamada
//normalmente quando o processo e' associado ao slot de Lottery
void lottInitSchedParams(Process *p, void *params)
{
	//...
}

//Retorna o proximo processo a obter a CPU, conforme o algortimo Lottery
Process *lottSchedule(Process *plist)
{
	//...
	int num_max_tickets = 0;
	Process *it = plist;
	//realiza a soma de todos os processos com estado diferente de bloqueado e terminando
	while (it != NULL)
	{
		if (processGetStatus(it) != PROC_WAITING && processGetStatus(it) != PROC_TERMINATING)
		{
			LotterySchedParams *param = processGetSchedParams(it);
			num_max_tickets+= param->num_tickets;
		}
		it = processGetNext(it);
	}
	it = plist;
	int drawn_ticket = randInterval(0, num_max_tickets);
	while (it != NULL)
	{
		if (processGetStatus(it) != PROC_WAITING && processGetStatus(it) != PROC_TERMINATING)
		{
			LotterySchedParams *param = processGetSchedParams(it);
			num_max_tickets+= param->num_tickets;
		}
		it = processGetNext(it);
	}
	return NULL;
}

//Libera os parametros de escalonamento de um processo p, chamada
//normalmente quando o processo e' desassociado do slot de Lottery
//Retorna o numero do slot ao qual o processo estava associado
int lottReleaseParams(Process *p)
{
	//...
	return 0;
}

//Transfere certo numero de tickets do processo src para o processo dst.
//Retorna o numero de tickets efetivamente transfeirdos (pode ser menos)
int lottTransferTickets(Process *src, Process *dst, int tickets)
{
	//...
	return 0;
}