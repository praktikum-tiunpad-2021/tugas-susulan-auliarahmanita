#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data, priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
   ElementPtr<T> Head, Tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> Q;
  Q.Head = nullptr;
  Q.Tail = nullptr;
  return Q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> pNew = new Element<T>;
  pNew -> data = value;
  pNew -> priority = priority;
  pNew -> next = nullptr;

if (q.Head == nullptr && q.Tail == nullptr) {
    q.Head = pNew;
    q.Tail = pNew;
  }

  else {
    ElementPtr<T> temp = q.Head;
    ElementPtr<T> pRev = nullptr;

    while (pNew -> priority <= temp -> priority) {
      if (temp -> next == nullptr) {
        break;
      }
      
      pRev = temp;
      temp = temp -> next;
    }
    
    // Insert First
    if (temp == q.Head && pNew -> priority > temp -> priority) {
      pNew -> next = temp;
      q.Head = pNew;
    }

    // Insert Last
    else if (temp == q.Tail && pNew->priority < temp -> priority) {
      temp -> next = pNew;
      q.Tail = pNew;
    }

    // Insert Middle
    else {
      pRev -> next = pNew;
      pNew -> next = temp;
    }
  }
}


/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.Head -> data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> pDel;
  if (q.Head == nullptr && q.Tail == nullptr) {
    pDel = nullptr;
  }

  else if (q.Head -> next == nullptr) {
    pDel = q.Head;
    q.Head = nullptr;
    q.Tail = nullptr;
  }

  else {
    pDel = q.Head;
    q.Head = q.Head -> next;
    pDel -> next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat