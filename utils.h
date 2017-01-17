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

using namespace std;

#ifndef UTILS_H
#define UTILS_H

float pointDistance(int x_inicial, int y_incial, int x_final, int y_final);

class Edge{
	public:
		int origin;
		int destiny;
		int weight;

		Edge(int x, int y, int w){
			this->origin = x;
			this->destiny = y;
			this->weight = w;
		}

		bool operator==(const Edge& n1) const{
			if(n1.origin == this->origin && n1.destiny == this->destiny && n1.weight == this->weight)
				return true;
			return false;
		}
};

class Graph{
	private:
		vector< list<Edge> > grafo;
	public:
		Graph(int tam){
			this->grafo.clear();
			this->grafo.resize(tam);
		}

		void insertEdge(int x, int y, int w){
			Edge* toInsert = new Edge(x, y, w);
			grafo[x].push_back(*toInsert);
		}
};

#endif
