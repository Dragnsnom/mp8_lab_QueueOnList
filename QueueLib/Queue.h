#ifndef _QUEUELIST_
#define _QUEUELIST_
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

    TQueueList<T>& operator =(TQueueList<T>& _v);

    void Push(T d); 
    T Get(); 

    int IsEmpty(void) const; 
    int IsFull(void) const; 

    //доп
    T Min_elem();
    T Max_elem();

    template <class T1>
    friend ostream& operator<< (ostream& ostr, const TQueueList<T1>& A);
    template <class T1>
    friend istream& operator>> (istream& istr, TQueueList<T1>& A);

    int GetCount();

};

template<class T1>
inline ostream& operator<<(ostream& ostr, const TQueueList<T1>& A)
{
    return ostr << A.list;
}

template<class T1>
inline istream& operator>>(istream& istr, TQueueList<T1>& A)
{
    return istr >> A.list;
}

template<class T>
inline TQueueList<T>::TQueueList()
{
 
}

template<class T>
inline TQueueList<T>::TQueueList(TQueueList<T>& _v)
{
    list = _v.list;
}

template<class T>
inline TQueueList<T>& TQueueList<T>::operator=(TQueueList<T>& _v)
{
    if (this == &_v)
    {
        return *this;
    }
    else
    {
        list = _v.list;
    }
    return *this;
}

template<class T>
inline void TQueueList<T>::Push(T d)
{
    list.InsLast(d);
}

template<class T>
inline T TQueueList<T>::Get()
{
    if (list.IsEmpty())
    {
        throw logic_error ("Error");
    }

    T tmp = list.GetFirst()->GetData();
    list.DelFirst();
    return tmp;
}

template<class T>
inline int TQueueList<T>::IsEmpty(void) const
{
    return list.IsEmpty();
}

template<class T>
inline int TQueueList<T>::IsFull(void) const
{
    return list.IsFull();
}

template<class T>
inline T TQueueList<T>::Min_elem()
{
    int count = this->GetCount();
    T tmp = NULL;
    for (int i = 0; i < count; i++)
    {
        if (tmp == NULL)
        {
            tmp = this->Get();
        }
        else
        {
            T tmp_for = this->Get();
            if (tmp_for < tmp)
            {
                tmp = tmp_for;
            }
        }
    }
    return tmp;
}

template<class T>
inline T TQueueList<T>::Max_elem()
{
    int count = this->GetCount();
    T tmp = NULL;
    for (int i = 0; i < count; i++)
    {
        if (tmp == NULL)
        {
            tmp = this->Get();
        }
        else
        {
            T tmp_for = this->Get();
            if (tmp_for > tmp)
            {
                tmp = tmp_for;
            }
        }
    }
    return tmp;
}


template<class T>
inline int TQueueList<T>::GetCount()
{
    return list.GetCount();
}

#endif