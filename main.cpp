#include <cstddef>
#include <iostream>

template< class T >
struct BiList
{
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template< class T >
struct List
{
  List():
    head(nullptr),
    tail(nullptr)
  {}

  void add(const T& v)
  {
    BiList< T >* newNode = new BiList< T >{v, nullptr, nullptr};
    if(empty())
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  void pop_last()
  {
    BiList<T>* n = tail->prev;
    delete tail;
    tail = n;
    if (tail)
      tail->next = nullptr;
    else
      head = nullptr;
  }

  void pop_first()
  {
    BiList<T>* n = head->next;
    delete head;
    head = n;
    if (head)
      head->prev = nullptr;
    else
      tail = nullptr;
  }

  bool empty() const
  {
    return head == nullptr;
  }

  void clear()
  {
    while (!empty())
    {
      pop_first();
    }
  }

  T& begin() const
  {
    return head->val;
  }

  T& end() const
  {
    return tail->val;
  }

  size_t size() const
  {
    BiList< T >* h = head;
    size_t count = 0;
    while (h)
    {
      count++;
      h = h->next;
    }
    return count;
  }

  T* convert() const
  {
    size_t s = size();
    T* res = new T[s];
    BiList< T >* h = head;
    for(size_t i = 0; i < s; i++)
    {
      res[i] = h->val;
      h = h->next;
    }
    return res;
  }

  ~List()
    {
      clear();
    }

  private:
  BiList< T >* head;
  BiList< T >* tail;
  
};

int main()
{
  List<int> lst;

  std::cout << lst.empty() << "\n";

  lst.add(10);
  lst.add(20);
  lst.add(30);
  lst.add(40);

  std::cout << lst.size() << "\n";

  std::cout << lst.begin() << "\n";
  std::cout << lst.end() << "\n";

  lst.pop_first();
  std::cout << "Размер: " << lst.size() << "\n";
  std::cout << "Первый: " << lst.begin() << "\n";

  lst.pop_last();
  std::cout << "Размер: " << lst.size() << "\n";
  std::cout << "Последний: " << lst.end() << "\n";

  int* arr = lst.convert();
  size_t s = lst.size();

  for (size_t i = 0; i < s; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";

  delete[] arr;

  lst.clear();
  std::cout << lst.empty() << "\n";
  return 0;
}
