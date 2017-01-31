/**********************************************************
*
* Flavio Shinzato
* Yan Uehara
*
* Trabalho 1 de Grafos
* Prof. Said Sadique
*
* utils.cpp
* Arquivo com a implementação de classes e funções auxiliares
*
***********************************************************/

#include  "utils.h"

float pointDistance(int x_inicial, int y_inicial, int x_final, int y_final){
	return sqrt( pow(x_final-x_inicial,2) + pow(y_final - y_inicial, 2) );
}

//Método para adicionar uma aresta
void Graph::addEdge(int x_inicial, int y_inicial, int x_final, int y_final){
	//Corrige a coordenada do vértice de origem
	int org = correctCoordinates(x_inicial, y_inicial);

	//Corrige a coordenada do vértice de destino
	int dest = correctCoordinates(x_final, y_final);

	//Insere uma aresta com a distância entre os dois vértices
	grafo[org][dest].distance = grafo[dest][org].distance = pointDistance(x_inicial, y_inicial, x_final, y_final);
}

//Método para remover um vértice do grafo
void Graph::removeVertex(int x, int y){
	//Corrige a coordenada
	int vertex = correctCoordinates(x, y);

	//Inicializa as arestas como infinito
	for(int i = 0; i < NUMVERTEX; i++){
		grafo[vertex][i].distance = INT_MAX;
		grafo[i][vertex].distance = INT_MAX;
	}
}

//Método que utiliza o algoritmo de djikstra para achar
// a distância entre dois pontos
float Graph::dijkstra(int x_inicial, int y_incial, int x_final, int y_final){
	//Vetor que guarda a distância entre o vértice inicial e os vértices do grafo
	// inializado como infinito
	vector<float> dist(NUMVERTEX, INT_MAX);

	//Lista de prioridades para escolher a próxima aresta no algoritmo dijkstra
	priority_queue< pair<int, float>, vector<pair<int, float> >, Comparator > pq;

	//Corrige a coordenada
	int org = correctCoordinates(x_inicial, y_incial);
	int dest = correctCoordinates(x_final, y_final);

	//A distância da origem para a origem é 0
	dist[org] = 0.0f;

	//Adiciona a aresta na fila de prioridades com a ordem igual a sua distância
	pq.push(make_pair(org, dist[org]));

	//Enquanto a fila não for vazia
	while(!pq.empty()){
		//Obtém o primeiro elemento da lista (o que contém a menor distância)s
		int u = pq.top().first; //É o vértice origem
		float w = pq.top().second; //É a distancia desse vértice até a origems

		//Se u é o destino a distância foi encontrada e o laço termina
		if(u == dest) break;

		//Remove e elimina a aresta da fila
		pq.pop();

		//Relaxação da aresta (u i)
		for(int i = 0; i < NUMVERTEX; i++){
			//Testa se a aresta existe, se não o laço passa para o próximo vértice
			if(grafo[u][i].distance == INT_MAX)
				continue;

			//Calcula a distância de da origem até i passando pela aresta (u i)
			float alt = w + grafo[u][i].distance;
			if(alt < dist[i]){
				//Se a distância até a aresta i, passando por u é menor
				// do que a distância atuals, atualiza o vetor distância com a nova distância
				dist[i] = alt;

				//Insere o vértice i, com ordem igual a sua distância
				pq.push(make_pair(i, dist[i]));
			}
		}
	}

	//Retorna a distância do vértice de origem até o vértice de destino
	return dist[dest];
}
