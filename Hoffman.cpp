///huffman coding

#include<bits/stdc++.h>
using namespace std;

class Huffman
{
public:
    char data;
    int freq;
    Huffman* left;
    Huffman* right;
    Huffman() {  };
    Huffman(char d ,int f) : data(d), freq(f) , right(NULL), left(NULL) {  };

};

class Comp
{
public:
    bool operator()(Huffman* a, Huffman* b){
        return a->freq > b->freq;
    }
};

void printCodes(Huffman* nd, string str)
{
    if(nd==NULL) return;
    if(nd->data!='#') cout<<nd->data<<" : "<<str<<endl;
    printCodes(nd->left,str+'0');
    printCodes(nd->right,str+'1');
}

void huffmanCoding(char ara[], int freq[],int n)
{
     priority_queue<Huffman*, vector<Huffman*>, Comp> mnHeap;
     Huffman *left, *right, *top;
     for(int i=0;i<n;i++){
        mnHeap.push(new Huffman(ara[i],freq[i]));
     }
     while(mnHeap.size()!=1){
          left = mnHeap.top();
          mnHeap.pop();
          right = mnHeap.top();
          mnHeap.pop();
          top= new Huffman('#',left->freq+right->freq);
          top->left=left;
          top->right=right;
          mnHeap.push(top);
     }
     printCodes(mnHeap.top(),"");
}

int main()
{
    char ara[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    huffmanCoding(ara,freq,6);

    return 0;
}

