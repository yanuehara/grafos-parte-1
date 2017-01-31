/********************************************************
*
* Flavio Shinzato
* Yan Uehara
*
* Trabalho 1 de Grafos
* Prof. Said Sadique
***********************************************************/
#include  "utils.h"

float pointDistance(int x_inicial, int y_inicial, int x_final, int y_final){
	return sqrt( pow(x_final-x_inicial,2) + pow(y_final - y_inicial, 2) );
}
