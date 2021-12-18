#include<iostream>
#include"Node.h"
#include"PriorityQueue.h"
using namespace std;

class HuffmanTree
{
   class HuffmanNode
   {
      char letter;
      int frequency;
      HuffmanNode* left;
      HuffmanNode* right;
      HuffmanNode(char letter, int frequency, HuffmanNode* left, HuffmanNode* right)
      {
         this->letter=letter;
         this->frequency= frequency;
         this->left=left;
         this->right=right;
      }
   }



public:
   Node* buildTree(PriorityQueue*pq);
   string getHuffmanCode(char alpha);











};



Node* HuffmanTree:: buildTree(PriorityQueue*pq)
{

   while(pq->isempty()==false)
   {
      HuffmanNode node1=pq.dequeue();
      HuffmanNode node2=pq.dequeue();
   }




}


