#pragma once

namespace strukdat {

namespace circular_list {

/**
 * @brief Node linked list berisi nilai bertipe T yang disimpan pada data
 */
template <typename T>
struct Node {
  T data;
  Node *prev;
  Node *next;
};

/**
 * @brief Tipe pointer dari node
 */
template <typename T>
using NodePtr = Node<T> *;

/**
 * @brief Membuat dan menginisialisasi head/sentinel node linked list
 * @note Sentinel node adalah node yang tidak digunakan untuk menyimpan data,
 *       akan tetapi digunakan sebagai node pembantu untuk mempermudah
 *       operasi-operasi pada linked list.
 *
 * @see https://en.wikipedia.org/wiki/Sentinel_node
 *
 * @return        pointer ke head/sentinel node
 */
template <typename T>
NodePtr<T> new_list() {
  NodePtr<T> head = new Node<T>;
  head -> next = head;
  head -> prev = head;
  return head;
}

/**
 * @brief Melakukan delete pada semua elemen dari linked list
 *
 * @param head    pointer ke sentinel node
 */
template <typename T>
void destroy_list(NodePtr<T> head) {
  NodePtr<T> temp = head -> next;
  NodePtr<T> del;
  while(temp!=head){
    del = temp;
    temp = temp -> next;
    delete del;
  }
}

/**
 * @brief Menambahkan elemen pada awal list
 *
 * @param head    pointer ke sentinel node
 * @param data    data baru yang akan disimpan pada linked list
 * @return        pointer ke node yang menyimpan data baru
 */
template <typename T>
NodePtr<T> push_front(NodePtr<T> head, const T &data) {
  NodePtr<T> baru = new Node<T>;
  baru -> data = data;
  baru -> prev = head;
  baru -> next = head -> next;
  head -> next -> prev = baru;
  head -> next = baru;
  return baru;
}

/**
 * @brief Menambahkan elemen pada ujung list
 *
 * @param head    pointer ke sentinel node
 * @param data    data baru yang akan disimpan pada linked list
 * @return        pointer ke node yang menyimpan data baru
 */
template <typename T>
NodePtr<T> push_back(NodePtr<T> head, const T &data) {
  NodePtr<T> baru = new Node <T>;
  baru -> data = data;
  baru -> next = head;
  baru -> prev = head -> prev;
  head -> prev -> next = baru;
  head -> prev = baru;
  return baru;
}

/**
 * @brief Menambahkan elemen setelah posisi tertentu pada linked list
 *
 * @param position  pointer ke posisi target
 * @param data      data baru yang akan disisipkan setelah posisi target
 * @return          pointer ke node yang menyimpan data baru
 */
template <typename T>
NodePtr<T> insert_after(NodePtr<T> position, const T &data) {
  NodePtr<T> baru = new Node<T>;
  baru -> data = data;
  baru -> prev = position;
  baru -> next = position -> next;
  position -> next -> prev = baru;
  position -> next = baru;
  return baru;
}

/**
 * @brief Menghapus sebuah sebuah node pada linked list.
 *
 * @note Penghapusan tidak dilakukan jika target merupakan sentinel node
 *
 * @param head      pointer ke sentinel node
 * @param position  pointer ke node yang akan dihapus
 */
template <typename T>
void erase(NodePtr<T> const head, NodePtr<T> position) {
  NodePtr<T> help = position -> next;
  NodePtr<T> help1 = position -> prev;
  help -> prev = help1;
  help1 -> next = help;
  position -> next = nullptr;
  position -> prev = nullptr;
  delete position;
}

/**
 * @brief Mengiterasi dan mengeksekusi fungsi pada setiap elemen linked list
 *
 * @param head      pointer ke sentinel node
 * @param func      fungsi yang akan dieksekusi pada setiap elemen
 */
template <typename T, typename F>
void for_each(NodePtr<T> head, F func) {
  NodePtr<T> help = head -> next;
  while(help!=head){
    func(help -> data);
    help = help -> next;
  }
}
/**
 * @brief Mencari node yang memiliki data tertentu
 *
 * @param head      pointer ke sentinel node
 * @param data      data yang akan dicari
 * @return          pointer ke node yang pertama kali ditemukan memiliki data.
 *                  nullptr jika tidak ditemukan
 */
template <typename T>
NodePtr<T> find(NodePtr<T> head, const T &data) {
  NodePtr<T> help = head -> next;
  while(help!=head){
    if(help -> data == data){
      return help;
    }
    help = help -> next;
  }
  return nullptr;
}

}  // namespace circular_list

}  // namespace strukdat