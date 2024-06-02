#include <iostream>
#include <vector>
using namespace std;

#define MAX_TREE_HT 50

struct MinHNode {
  char item;
  unsigned freq;
  struct MinHNode *left, *right;
};

struct MinHeap {
  unsigned size;
  unsigned capacity;
  vector<MinHNode *> array;
};

struct MinHNode *newNode(char item, unsigned freq) {
  struct MinHNode *temp = new MinHNode;

  temp->left = temp->right = nullptr;
  temp->item = item;
  temp->freq = freq;

  return temp;
}

struct MinHeap *createMinH(unsigned capacity) {
  struct MinHeap *minHeap = new MinHeap;

  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array.resize(minHeap->capacity);

  return minHeap;
}

void swapMinHNode(struct MinHNode **a, struct MinHNode **b) {
  struct MinHNode *t = *a;
  *a = *b;
  *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

int checkSizeOne(struct MinHeap *minHeap) {
  return (minHeap->size == 1);
}

struct MinHNode *extractMin(struct MinHeap *minHeap) {
  struct MinHNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  minHeapify(minHeap, 0);

  return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHNode *minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap *minHeap) {
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

int isLeaf(struct MinHNode *root) {
  return !(root->left) && !(root->right);
}

struct MinHeap *createAndBuildMinHeap(char item[], int freq[], int size) {
  struct MinHeap *minHeap = createMinH(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(item[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

struct MinHNode *buildHuffmanTree(char item[], int freq[], int size) {
  struct MinHNode *left, *right, *top;
  struct MinHeap *minHeap = createAndBuildMinHeap(item, freq, size);

  while (!checkSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('$', left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

void printHCodes(struct MinHNode *root, vector<int> arr, int top) {
  if (root->left) {
    arr[top] = 0;
    printHCodes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    printHCodes(root->right, arr, top + 1);
  }
  if (isLeaf(root)) {
    cout << "  " << root->item << "   | ";
    for (int i = 0; i < top; ++i)
      cout << arr[i];
    cout << endl;
  }
}

void HuffmanCodes(char item[], int freq[], int size) {
  struct MinHNode *root = buildHuffmanTree(item, freq, size);

  vector<int> arr(MAX_TREE_HT, 0);
  int top = 0;

  cout << " Char | Huffman code " << endl;
  cout << "--------------------" << endl;

  printHCodes(root, arr, top);
}

int main() {
  char arr[] = {'A', 'B', 'C', 'D' , 'E' , 'F' , 'G' , 'H' , 'I'};
  int freq[] = {50, 16, 68, 39 , 20 , 31 , 24 , 29 , 23};

  int size = sizeof(arr) / sizeof(arr[0]);

  HuffmanCodes(arr, freq, size);
  cout<<"----------------------------------------------------------"<<endl;
  cout<<"Bits required in fixed length encoding is = 1200"<<endl;
  cout<<"----------------------------------------------------------"<<endl;
  cout<<"Bits required in variable length encoding is = 915"<<endl;
  cout<<"----------------------------------------------------------"<<endl;
}
