/**********************************************************
*
* Flavio Shinzato
* Yan Uehara
*
* Trabalho 1 de Grafos
* Prof. Said Sadique
*
* main.cpp
* Arquivo principal
*
***********************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "utils.h"

using namespace std;

int main(int argc, char* argv[]){
	int x_inicial, y_inicial, x_final, y_final, n_obstaculos;
	int x_obstaculo, y_obstaculo;

	while(true){
		Graph *grafo = new Graph(); //Instancia um grafo e cria todas as arestas possíveis
		cin >> x_inicial >> y_inicial >> x_final >> y_final >> n_obstaculos;
		if(x_inicial == x_final && x_inicial == 0 && y_final == y_inicial && y_final == 0 && n_obstaculos == 0)
			break;

		for(int i = n_obstaculos; i != 0; i--){
			cin >> x_obstaculo >> y_obstaculo;
			grafo->removeVertex(x_obstaculo, y_obstaculo); //Remove os obstáculos
		}

		//Chama o método disjkstra e retorna o resultado
		float dist = grafo->dijkstra(x_inicial, y_inicial, x_final, y_final);

		//Seta a precisão para duas casas decimais
		cout << fixed << setprecision(2);
		cout << dist << endl;

		delete grafo; //Deleta o grafo
	}
}
