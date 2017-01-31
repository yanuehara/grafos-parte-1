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
#include <cfloat>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

#ifndef UTILS_H
#define UTILS_H

#define NUMVERTEX 10201
#define TAMMATRIX 101

float pointDistance(int x_inicial, int y_incial, int x_final, int y_final);

inline int correctCoordinates(int x, int y){
	return ((x+50)*TAMMATRIX)+(y+50);
}

struct Comparator
{
  bool operator()(const pair<int, float> &p1, const pair<int, float> &p2) const
  {
    return p1.second > p2.second;
  }
};

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
						addEdge(x, y+1, x+1, y); //Criando aresta diagonal invertida
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

		float dijkstra(int x_inicial, int y_incial, int x_final, int y_final){
			float dist[NUMVERTEX];
			int path[NUMVERTEX];
			priority_queue< pair<int, float>, vector<pair<int, float> >, Comparator > pq;

			int org = correctCoordinates(x_inicial, y_incial);
			int dest = correctCoordinates(x_final, y_final);

			for (int i = 0; i < NUMVERTEX; i++) {
				dist[i] = INT_MAX;
				path[i] = -1;
			}

			dist[org] = 0.0f;

			pq.push(make_pair(org, dist[org]));

			while(!pq.empty()){
				int u = pq.top().first;
				float w = pq.top().second;

				if(u == dest) break;

				pq.pop();

				for(int i = 0; i < NUMVERTEX; i++){
					if(grafo[u][i].distance == INT_MAX)
						continue;

					float alt = w + grafo[u][i].distance;
					if(alt < dist[i]){
						dist[i] = alt;
						path[i] = u;
						pq.push(make_pair(i, dist[i]));
					}
				}
			}

			return dist[dest];
		}
};

#endif
