#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct n
{
  int priority;
  int info;
  struct n *next;
};
class Priority_Queue
{
private:
  n *f;

public:
  Priority_Queue()
  {

    f = NULL;
  }
  void insert(int i, int p)
  {
    n *t, *q;
    t = new n;
    t->info = i;
    t->priority = p;
    if (f == NULL || p < f->priority)
    {
      t->next = f;
      f = t;
    }
    else
    {
      q = f;
      while (q->next != NULL && q->next->priority > p)
        q = q->next;
      t->next = q->next;
      q->next = t;
    }
  }
  void delet()
  {
    n *t;
    if (f == NULL) // se a fila for nula
      cout << "Fila foi nula\n";
    else
    {
      t = f;
      cout << "O item deletado é: " << t->info << endl;
      f = f->next;
      free(t);
    }
  }
  void show() //print queue {
  {
    n *ptr;
    ptr = f;
    if (f == NULL)
      cout << "A fila está vazia\n";
    else
    {
      cout << "[-] A fila é :\n";
      int count = 1;
      while (ptr != NULL)
      {
        cout << "    " << count << "º - " << ptr->priority << " " << ptr->info << endl;
        ptr = ptr->next;
        count++;
      }
      cout << "\n";
    }
  }
};
int main()
{
  int c, i, p;
  Priority_Queue pq;
  do
  {
    cout << "1.Insert\n";
    cout << "2.Delete\n";
    cout << "3.Display\n";
    cout << "4.Exit\n";
    cout << "Faça sua escolha : ";
    cin >> c;
    switch (c)
    {
    case 1:
      cout << "Coloque o código do cliente (Número inteiro) : ";
      cin >> i;
      cout << "Coloque sua prioridade : ";
      cin >> p;
      pq.insert(i, p);
      break;
    case 2:
      pq.delet();
      break;
    case 3:
      pq.show();
      break;
    case 4:
      break;
    default:
      cout << "[!] Essa opção não existe, escolha um número inteiro de 1 a 4.\n";
    }
  } while (c != 4);

  return 0;
}