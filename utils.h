/**********************************************************
*
* Flavio Shinzato
* Yan Uehara
*
* Trabalho 1 de Grafos
* Prof. Said Sadique
*
* utils.h
* Arquivo com a definição de classes e funções auxiliares
*
***********************************************************/

#include <math.h>
#include <vector>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

#ifndef UTILS_H
#define UTILS_H

#define NUMVERTEX 10201
#define TAMMATRIX 101

/*
 As funções e métodos em geral assumem que o valor INT_MAX representa
 ou a distância infinita ou a inexistência da aresta a depender da função/método
*/

//Função para calcular a distância entre dois pontos
float pointDistance(int x_inicial, int y_incial, int x_final, int y_final);

//Função para transformar um (x, y) no range 0 - 10201
inline int correctCoordinates(int x, int y){
	return ((x+50)*TAMMATRIX)+(y+50);
}

//Struct para poder sobrecarregar o operador > para o tipo pair<int, float>
// considerando o float como item de comparação
//Para ser usado na fila de prioridades
struct Comparator
{
  bool operator()(const pair<int, float> &p1, const pair<int, float> &p2) const
  {
    return p1.second > p2.second;
  }
};

//Classe Edge para guardar a distância entre dois vértices
class Edge{
	public:
		float distance;

		//Construtor para iniciar a distância como infinita
		Edge(){
			this->distance = INT_MAX;
		}
};

//Classe Graph para guardar um grafo
class Graph{
	private:
		//Guarda um grafo em uma matriz de adjacência com tamanho NUMVERTEX x NUMVERTEX
		vector< vector<Edge> > grafo;
	public:
		//Chama o construtor da variável grafo
		// e cria todas as arestas com as respectivas distâncias
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

		//Método para adicionar uma aresta
		void addEdge(int x_inicial, int y_inicial, int x_final, int y_final);

		//Método para remover um vértice do grafo
		void removeVertex(int x, int y);

		//Método que utiliza o algoritmo de djikstra para achar
		// a distância entre dois pontos
		float dijkstra(int x_inicial, int y_incial, int x_final, int y_final);
};

#endif
