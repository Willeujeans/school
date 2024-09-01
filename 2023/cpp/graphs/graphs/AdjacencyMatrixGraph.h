//AdjacencyMatrixGraph Method
//[ ][A][B][C]
//[A][0][1][1]
//[B][1][0][0]
//[C][1][0][0]
#ifndef ADJACENCYMATRIXGRAPH_H
#define ADJACENCYMATRIXGRAPH_H

#include "DirectedGraph.h"

class AdjacencyMatrixGraph : public DirectedGraph {
protected:
   std::vector<Vertex*> vertices;
   
    // If matrixRows[X][Y] is true, then an edge exists from vertices[X] to vertices[Y]
    //When accessing the matrixRows theres an ERROR, I think I'm accessing something that doesn't exist
    //Why can't I declare matrixRows[x][y] = false; it still throws an error, is the memory not allocated?
    //I think I need to allocate something there but I'm not sure
    //Bad access, I'm trying to access something that doesn't exist
    
   std::vector<std::vector<bool>> matrixRows;
    //we use virtual here because we call the functions the same thing, but because they must do different things we give the compiler the choice based on which type of graph we call the method on.
public:
   virtual ~AdjacencyMatrixGraph() {
      for (Vertex* vertex : vertices) {
         delete vertex;
      }
   }

   // Creates and adds a new vertex to the graph, provided a vertex with the
   // same label doesn't already exist in the graph. Returns the new vertex on
   // success, nullptr on failure.
   virtual Vertex* AddVertex(std::string newVertexLabel) override {
       for(int i = 0; i < int(vertices.size()); i++){
           if (newVertexLabel == vertices[i]->GetLabel()){
               return nullptr;
           }
       }
       AdjacencyListVertex* newAdjacencyListVertex = new AdjacencyListVertex(newVertexLabel);
       vertices.push_back(newAdjacencyListVertex);
       matrixRows.resize(vertices.size());
       // Resize each row to have the specified number of columns and initialize elements
       for (int i = 0; i < int(vertices.size()); ++i) {
           matrixRows[i].resize(vertices.size(), false);
       }
       return newAdjacencyListVertex;
   }
   
    // Adds a directed edge from the first to the second vertex. If the edge
    // already exists in the graph, no change is made and false is returned.
    // Otherwise the new edge is added and true is returned.
   virtual bool AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex) override {
       int fromPosition = -1;
       int toPosition = -1;
       for(int i = 0; i < int(vertices.size()); i++){
           if (fromVertex->GetLabel() == vertices[i]->GetLabel()){
               fromPosition = i;//Position of fromVertex in storage
           }
       }
       for(int j = 0; j < int(vertices.size()); j++){
           if (toVertex->GetLabel() == vertices[j]->GetLabel()){
               toPosition = j;//Position of toVertex in storage
           }
       }
       if(fromPosition < 0 or toPosition < 0){
           return false;
       }
       std::cout << "("<< fromPosition << ","<< toPosition <<")" << std::endl;
       
       if(matrixRows[fromPosition][toPosition] == true){
           return false;
       }
       matrixRows[fromPosition][toPosition] = true;
       return true;
   }
    
   // Returns a vector of edges with the specified fromVertex.
   virtual std::vector<Edge> GetEdgesFrom(Vertex* fromVertex) override {
       std::vector<Edge> edgeList;
       int fromPosition = -1;
       for(int i = 0; i < int(vertices.size()); i++){
           if (fromVertex->GetLabel() == vertices[i]->GetLabel()){
               fromPosition = i;//Position of fromVertex in storage
           }
       }
       if(fromPosition < 0){
           return edgeList;
       }
       for(int k = 0; k < int(matrixRows.size()); k++){
           if(matrixRows[fromPosition][k] == true){
               Edge myEdge(vertices[fromPosition],vertices[k]);
               edgeList.push_back(myEdge);
           }
       }

       return edgeList;
   }
    
   // Returns a vector of edges with the specified toVertex.
   virtual std::vector<Edge> GetEdgesTo(Vertex* toVertex) override {
       std::vector<Edge> edgeList;
       int toPosition = -1;
       for(int i = 0; i < int(vertices.size()); i++){
           if (toVertex->GetLabel() == vertices[i]->GetLabel()){
               toPosition = i;//Position of fromVertex in storage
           }
       }
       if(toPosition < 0){
           return edgeList;
       }
       
       //we now have the position of where our toVertex is stored
       for(int n=0; n < int(matrixRows.size()); n++){
            if(matrixRows[n][toPosition] == true ){
                Edge myEdge(vertices[n],vertices[toPosition]);
                edgeList.push_back(myEdge);
            }
       }

       return edgeList;
   }
    
   // Returns a vertex with a matching label, or nullptr if no such vertex exists
   virtual Vertex* GetVertex(std::string vertexLabel) override {
       for(int i = 0; i < int(vertices.size()); i++){
           if (vertices[i]->GetLabel() == vertexLabel){
               return vertices[i];
           }
       }
       return nullptr;
   }
    
   // Returns true if this graph has an edge from fromVertex to toVertex
   virtual bool HasEdge(Vertex* fromVertex, Vertex* toVertex) override {
       int fromPosition = -1;
       for(int i = 0; i < int(vertices.size()); i++){
           if (fromVertex->GetLabel() == vertices[i]->GetLabel()){
               fromPosition = i;//Position of fromVertex in storage
           }
       }
       if(fromPosition < 0){
           return false;
       }
       int toPosition = -1;
       for(int i = 0; i < int(vertices.size()); i++){
           if (toVertex->GetLabel() == vertices[i]->GetLabel()){
               toPosition = i;//Position of fromVertex in storage
           }
       }
       if(toPosition < 0){
           return false;
       }
       if(matrixRows[fromPosition][toPosition] == true){
           return true;
       }
      return false;
   }
};

#endif
