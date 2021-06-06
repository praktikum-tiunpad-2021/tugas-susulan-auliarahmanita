#include "problem_a.hpp"

template <typename T>
void BFSTraversal(Tree<T> &Root, vector<T> &traversedData)
{
  if (Root == nullptr){
    return;
  } else{
    vector<pointer<T>> store; 
    store.push_back(Root); 
    while(!store.empty()){ 
      pointer<T> pBantu;
      pBantu = store.front(); 
      
      traversedData.push_back(pBantu->data); 
      
      store.erase(store.begin()); 
      
      if(pBantu->left != nullptr){
        store.push_back(pBantu->left);
      } if(pBantu->right != nullptr){
        store.push_back(pBantu->right);
      }
    }
  }
}

template <typename T>
Tree<T> lowestCommonAncestor(Tree<T>& Root, pointer<T> a, pointer<T> b)
{
  if(Root == nullptr) return nullptr;
  if(a->data < Root->data && b->data < Root->data){      
    return lowestCommonAncestor(Root->left, a, b);
  } if(a->data > Root->data && b->data > Root->data){ 
    return lowestCommonAncestor(Root->right, a, b);
  } else return Root;
}

template <typename T>
Tree<T> invertBST(Tree<T>& Root)
{
  if(Root == nullptr) return nullptr;
  else {
    invertBST(Root->left);
    invertBST(Root->right);

    pointer<T> pBantu;
    pBantu = Root->left;
    Root->left = Root->right;
    Root->right = pBantu;

    return Root;
  }
}