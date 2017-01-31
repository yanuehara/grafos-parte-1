/**********************************************************
*
* Flavio Shinzato
* Yan Uehara
*
* Trabalho 1 de Grafos
* Prof. Said Sadique
***********************************************************/

#include <math.h>
#include <vector>
#include <list>
#include <climits>

using namespace std;

#ifndef UTILS_H
#define UTILS_H

#define NUMVERTEX 10201
#define TAMMATRIX 101

float pointDistance(int x_inicial, int y_incial, int x_final, int y_final);

inline int correctCoordinates(int x, int y){
	return (x+50)*TAMMATRIX+(y+50);
}

class Edge{
	public:
		float distance;

		Edge(){
			this->distance = INT_MAX;
		}
};

class Graph{
	private:
		vector< vector<Edge> > grafo;
	public:
		Graph() : grafo(NUMVERTEX, vector<Edge>(NUMVERTEX)){
			for (int x = -50; x <= 50; x++) {
				for (int y = -50; y <= 50; y++) {
					if(x == 50 && y == 50 ) {	
					}

					else if(y == 50) {
						addEdge(x, y, x+1, y);
					}

					else if(x == 50) {
						addEdge(x, y, x, y+1);
					}

					else/*(x != 50 && y != 50)*/ {
						addEdge(x, y, x, y+1); //Criando aresta para cima
						addEdge(x, y, x+1, y); //Criando aresta para direita
						addEdge(x, y, x+1, y+1); //Criando aresta diagonal direita para cima
					}
				}
			}
		}

		void addEdge(int x_inicial, int y_inicial, int x_final, int y_final){
			int org = correctCoordinates(x_inicial, y_inicial);
			int dest = correctCoordinates(x_final, y_final);
			grafo[org][dest].distance = grafo[dest][org].distance = pointDistance(x_inicial, y_inicial, x_final, y_final);
		}

		void removeVertex(int x, int y){
			int vertex = correctCoordinates(x, y);
			for(int i = 0; i < NUMVERTEX; i++){
				grafo[vertex][i].distance = INT_MAX;
				grafo[i][vertex].distance = INT_MAX;
			}
		}
};

#endif
