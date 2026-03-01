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
  List();
  void add(const T& v)
  {
    BiList< T >* newNode = new BiList({v, nullptr, nullptr});
    if(emppty())
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
    List< T >* n = tail->prev;
    delete tail;
    tail = prev;
  }

  void pop_first()
  {
    BiList< T >* n = head->next;
    delete head;
    head = n;
  }

  bool emppty()
  {
    return head == nullptr;
  }

  void clear(List< T > h)
  {
    while (!emppty())
    {
      pop_first();
    }
  }
  T& begin()
  {
    return head->val;
  }
  T& end()
  {
    return tail->val;
  }

  private:
  BiList< T >* head;
  BiList< T >* tail;
};

