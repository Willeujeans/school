//AdjacencyList Method
//[A]->[B][C]
//[B]->[A]
//[C]->[A]
#ifndef ADJACENCYLISTGRAPH_H
#define ADJACENCYLISTGRAPH_H

#include "DirectedGraph.h"
#include "AdjacencyListVertex.h"

class AdjacencyListGraph : public DirectedGraph {
protected:
   std::vector<AdjacencyListVertex*> vertices;
   
public:    
    //when AdjacencyListGraph is initilized it will ALWAYS start with no verticies
    virtual ~AdjacencyListGraph() {
        for (AdjacencyListVertex* vertex : vertices) {
            delete vertex;
        }
    }

    //COMPLETED
    //Checks if label doesn't already exist in the graph
    //Creates and adds a new vertex to the graph
    //Returns the new vertex on success
    //Returns nullptr on failure
    virtual Vertex* AddVertex(std::string newVertexLabel) override {
        for(int unsigned long n = 0; n < vertices.size(); n ++){
            if(newVertexLabel == vertices[n]->GetLabel()){
                return nullptr;
            }
        }
        //new AdjacencyListVertex(newVertexLabel) will create a AdjacencyListVertex class which is inherits from a vertex
       AdjacencyListVertex* newAdjacencyListVertex = new AdjacencyListVertex(newVertexLabel);
       vertices.push_back(newAdjacencyListVertex);
       return newAdjacencyListVertex;
   }
    
    
   // Adds a directed edge from the first to the second vertex. If the edge
   // already exists in the graph, no change is made and false is returned.
   // Otherwise the new edge is added and true is returned.
   virtual bool AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex) override {
       for(int unsigned long n = 0; n < vertices.size(); n ++){//cycling through the stored vertices
           if(fromVertex->GetLabel() == vertices[n]->GetLabel()){//searching for a match
               for(int unsigned long m = 0; m < vertices[n]->adjacent.size(); m++){//cycling through the adjacency list of stored vertices
                   if(vertices[n]->adjacent[m]->GetLabel() == toVertex->GetLabel()){//if theres already a connection to that node
                       return false;
                   }
               }
               vertices[n]->adjacent.push_back(toVertex);
               return true;
           }
       }
       //fromVertex->adjacent.push_back(toVertex);
       return false;
   }
    
    
   // Returns a vector of edges with the specified fromVertex.
   virtual std::vector<Edge> GetEdgesFrom(Vertex* fromVertex) override {
       //Get label from fromVertex
       std::vector<Edge> edgeVector = {};
       for(int unsigned long n = 0; n < vertices.size(); n ++){//Cycling through the storage of vertices
           if(fromVertex->GetLabel() == vertices[n]->GetLabel()){//Searching to find a matching vertex we stored
               for(int unsigned long m = 0; m < vertices[n]->adjacent.size(); m++){//Cycling through the adjacency list within the stored vertices
                   Edge myedge = Edge(fromVertex, vertices[n]->adjacent[m]);
                   edgeVector.push_back(myedge);
               }
           }
       }
       return edgeVector;
   }
    
   // Returns a vector of edges with the specified toVertex.
   virtual std::vector<Edge> GetEdgesTo(Vertex* toVertex) override {
       std::vector<Edge> edgeVector;
       for(int unsigned long n = 0; n < vertices.size(); n ++){//cycles through the stored vertices
           if(toVertex->GetLabel() != vertices[n]->GetLabel()){
               for(int unsigned long m = 0; m < vertices[n]->adjacent.size(); m++){//cycles through the adjacency list within the stored vertices
                   if(vertices[n]->adjacent[m]->GetLabel() == toVertex->GetLabel()){
                       Edge myedge = Edge(vertices[n], toVertex);
                       edgeVector.push_back(myedge);
                   }
               }
           }
       }
       return edgeVector;
   }
    
   // Returns a vertex with a matching label, or nullptr if no such vertex
   // exists
   virtual Vertex* GetVertex(std::string vertexLabel) override {
       for(int unsigned long n = 0; n < vertices.size(); n ++){
           if(vertexLabel == vertices[n]->GetLabel()){
               return vertices[n];
           }
       }
      return nullptr;
   }
    
   // Returns true if this graph has an edge from fromVertex to toVertex
   virtual bool HasEdge(Vertex* fromVertex, Vertex* toVertex) override {
       for(int unsigned long n = 0; n < vertices.size(); n ++){//cycles through the stored vertices
           if(fromVertex->GetLabel() == vertices[n]->GetLabel()){//searches for a match
               for(int unsigned long m = 0; m < vertices[n]->adjacent.size(); m++){//cycles through the adjacency list within the stored vertices
                   if(vertices[n]->adjacent[m]->GetLabel() == toVertex->GetLabel()){
                       return true;
                   }
               }
           }
       }
      return false;
   }
};

#endif
