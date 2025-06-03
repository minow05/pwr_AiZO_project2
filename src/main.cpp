#include <iostream>
#include "../include/algorithms/path/FordBellmanAlgorithm.h"
#include "../include/algorithms/path/DijkstraAlgorithm.h"
#include "../include/graph/AdjacencyMatrix.h"
#include "../include/graph/AdjacencyList.h"
#include "../include/algorithms/MST/PrimAlgorithm.h"
#include "../include/algorithms/MST/KruskalAlgorithm.h"
int main(){

    AdjacencyMatrix graph(10, true, 60);
    FordBellmanAlgorithm algorithm(&graph);
    algorithm.run(0, 9);
    std::cout << algorithm.getResult();

    auto primex = [](Graph &graph){
        FordBellmanAlgorithm prim (&graph);
        prim.run(0, graph.getNumberOfVertices() - 1);
        std::cout << prim.getResult() << "\n";
    };

    auto exec = [](Graph &graph){
        DijkstraAlgorithm alg (&graph);
        alg.run(0, graph.getNumberOfVertices() - 1);
        std::cout << alg.getResult() << '\n';
    };

    int i = 0;
    while (i < 1000){
        i += 100;
        std::vector<std::shared_ptr<Graph>> graphs = {
//                std::make_shared<AdjacencyMatrix>(i, false, 20),
                std::make_shared<AdjacencyMatrix>(i, true, 20),
//                std::make_shared<AdjacencyMatrix>(i, false, 60),
                std::make_shared<AdjacencyMatrix>(i, true, 60),
//                std::make_shared<AdjacencyMatrix>(i, false, 99),
                std::make_shared<AdjacencyMatrix>(i, true, 99),

//                std::make_shared<AdjacencyList>(i, false, 20),
                std::make_shared<AdjacencyList>(i, true, 20),
//                std::make_shared<AdjacencyList>(i, false, 60),
                std::make_shared<AdjacencyList>(i, true, 60),
//                std::make_shared<AdjacencyList>(i, false, 99),
                std::make_shared<AdjacencyList>(i, true, 99)
        };



        for (const auto& graph : graphs) {
            if (graph->isDirected()){
                primex(*graph);
            }
        }
    }
    return 0;
}


