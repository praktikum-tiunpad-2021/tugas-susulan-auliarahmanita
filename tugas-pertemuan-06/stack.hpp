#pragma once

namespace strukdat {

namespace stack {

/**
 * @brief Node linked list berisi nilai bertipe `T` yang disimpan pada `data`
 */
template <typename T>
struct Node {
  T data;
  Node *next;
};

/**
 * @brief Tipe pointer dari node
 */
template <typename T>
using pointer = Node<T>*;

template <typename T>
using Stack = pointer<T>;

template <typename T>
Stack<T> Top;

/**
 * @brief Membuat dan menginisialisasi stack baru
 * @param Top       pointer ke puncak stack
 * @param data      data yang akan dicari
 * 
 * @return          pointer ke puncak stack
 */
template <typename T>
Stack<T> createStack(Stack<T> Top) {
  Top = nullptr;
  return Top;
}

/**
 * @brief Membuat dan menginisialisasi element baru untuk dimasukan ke stack
 * @param newElement  pointer ke element baru
 * @param data        data yang akan dimasukan
 */
template <typename T>
void createElement(pointer<T>& newElement, T data) {
 newElement = new Node<T>;
 newElement->data = data;
 newElement->next = nullptr;
}

/**
 * @brief Mengambil data pada element yang berada di puncak stack
 * @param Top       pointer ke puncak stack
 * 
 * @return          data pada element puncak stack
 */
template <typename T>
T peek(Stack<T> Top) {
  // TODO: Implementasikan!
  return Top->data;
}

/**
 * @brief Mengecek apakah suatu stack kosong atau sudah mempunyai element
 * @param Top       pointer ke puncak stack
 * 
 * @return          'true' jika stack kosong dan 'false' jika stack tidak kosong
 */
template <typename T>
bool isEmpty(Stack<T> Top) {
  return Top !=nullptr ? false:true;
}

/**
 * @brief Memasukan element ke puncak stack (push / insert first)
 * @param Top         pointer ke puncak stack
 * @param newElement  pointer ke element baru
 * 
 * @return            pointer ke puncak stack
 */
template <typename T>
Stack<T> push(Stack<T> Top, pointer<T> newElement) {
  newElement->next = Top;
  Top = newElement;
  return Top;
}

/**
 * @brief Mengeluarkan element dari puncak stack (pop / delete first)
 * @param Top         pointer ke puncak stack
 * @param delElement  pointer ke element yang dihapus
 * 
 * @return            pointer ke element yang dihapus
 */
template <typename T>
Stack<T> pop(Stack<T>& Top, pointer<T> delElement) {
  delElement = Top;
  if(Top != nullptr){
    Top=Top->next;
  }
  return delElement;
}

/**
 * @brief Mengambil element terdalam / element dasar / element terakhir pada stack
 * @note Gunakan algoritma traversal sebagai referensi
 * @param Top         pointer ke puncak stack
 * 
 * @return            pointer ke element terdalam
 */
template <typename T>
Stack<T> lastNode(Stack<T> Top) {
  pointer<T> pHelp = Top;
  if(pHelp != nullptr){
    while(pHelp->next != nullptr){
      pHelp=pHelp->next;
    }
  }
  return pHelp;
}

}  // namespace stack

}  // namespace strukdat