#ifndef _QUEUELIST_
#define _QUEUELIST_
#include <iostream>
#include <fstream>
#include "TList.h"

using namespace std;

template <class T>
class TQueueList
{
protected:
  TList<T> list;
public:
  TQueueList();
  TQueueList(TQueueList<T>& _v);
  ~TQueueList();

  TQueueList<T>& operator =(TQueueList<T>& _v);

  void Push(T d); //������� ��������
  T Get(); //��������� ��������

  int IsEmpty(void) const; // �������� �������
  int IsFull(void) const; //�������� ������������

  //DOP
  T Min_elem();
  T Max_elem();
  void File();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TQueueList<T1>& A);
  template <class T1>
  friend istream& operator>> (istream& istr, TQueueList<T1>& A);

  int GetCount();
};
#endif