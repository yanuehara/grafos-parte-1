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
		}
};

#endif
