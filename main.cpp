/**********************************************************
*
* Flavio Shinzato
* Yan Uehara
*
* Trabalho 1 de Grafos
* Prof. Said Sadique
***********************************************************/

#include <cstdlib>
#include <iostream>

#include "utils.h"

using namespace std;

int main(int argc, char* argv[]){
	int x_inicial, y_inicial, x_final, y_final, n_obstaculos;
	int x_obstaculo, y_obstaculo;

	while(true){
		Graph *grafo = new Graph();
		cin >> x_inicial >> y_inicial >> x_final >> y_final >> n_obstaculos;
		if(x_inicial == x_final && x_inicial == 0 && y_final == y_inicial && y_final == 0 && n_obstaculos == 0)
			break;

		for(int i = n_obstaculos; i != 0; i--){
			cin >> x_obstaculo >> y_obstaculo;
			grafo->removeVertex(x_obstaculo, y_obstaculo);
		}
		float dist = grafo->dijkstra(x_inicial, y_inicial, x_final, y_final);
		cout << dist << endl;

		delete grafo;
	}
}
