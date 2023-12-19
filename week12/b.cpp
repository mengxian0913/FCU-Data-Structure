#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
struct HeapTree{
    int data[MAX];
    int count;
    HeapTree(const string filename);
    void InsertData(int);
    void Show();
    int GetLevel();
    void ShowTree();
    void HeapSort();
    void AdjustHeap();
};

HeapTree:: HeapTree(string filename){
    ifstream ifs(filename);
    count = 0;
    if(ifs.is_open()){
        int val;
        while(ifs >> val){
            InsertData(val);
            AdjustHeap();
        }
    }
}

void HeapTree::Show(){
    for(int i = 0; i < count; i++) cout<<data[i]<<"\n "[i != count - 1 ? 1 : 0];
}

void HeapTree::InsertData(int val){
    data[count++] = val;
}

void HeapTree::AdjustHeap(){
    int pos = count;
    while(pos > 1){
        int node1 = data[(pos >> 1) - 1], node2 = data[pos - 1];
        if(pos % 2 == 1 && node1 < node2) swap(data[pos - 1], data[(pos >> 1) - 1]);
        if(pos % 2 == 0 && node1 < node2) swap(data[pos - 1], data[(pos >> 1) - 1]);
        pos >>= 1;
    }
}

void HeapTree::HeapSort(){
    for(int i = count; i > 0; i--){
        int pos = i;
        while(pos > 1){
            int node1 = data[(pos >> 1) - 1], node2 = data[pos - 1];
            if(pos % 2 == 1 && node1 < node2) swap(data[pos - 1], data[(pos >> 1) - 1]);
            if(pos % 2 == 0 && node1 < node2) swap(data[pos - 1], data[(pos >> 1) - 1]);
            pos >>= 1;
        }
    }
}

int HeapTree::GetLevel(){
    int pos = count - 1, level = 0;
    while(pos && ++level) pos >>= 1;
    return level;
}

void HeapTree::ShowTree(){
    int height = GetLevel();
    for(int i = 0; i < count; i++){
        int j = i + 1, level = 0;
        while(j && ++level) j >>= 1;
        for(int k = 0; k < pow(2, height - level + 1) - 1; k++) cout<<"  ";
        cout<<data[i];
        for(int k = 0; k < pow(2, height - level + 1) - 1; k++) cout<<"  ";
        cout<<"  ";
        if(i + 1 == pow(2, level) - 1) puts("");
    }
}

signed main(){
    string filename = "a.txt";
    HeapTree* heap = new HeapTree(filename);
    heap -> HeapSort();
    heap -> Show();
    heap -> ShowTree();
    return 0;
}
