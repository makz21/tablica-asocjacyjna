#include <iostream>
using namespace std;
#include "asocjacja.h"

asocjacja::asocjacja ()
{
  head = NULL;
}

asocjacja::asocjacja (const asocjacja & l)
{
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  try
  {
    while (src)
      {
	*dst = new node (*src);
	src = src->next;
	dst = &((*dst)->next);
      }
  }
  catch (...)
  {
    clear ();
    throw;
  };
}

asocjacja::~asocjacja ()
{
  clear ();
}

void asocjacja::clear ()
{
  while (head)
    {
      node *t = head->next;
      delete head;
      head = t;
    };
}

void asocjacja::insert (const char *key, int value)
{
  node *nowy = new node (key);
  nowy->next = head;
  head = nowy;
  head->wartosc = value;
}

void asocjacja::swap (asocjacja & l)
{
  node *t = head;
  head = l.head;
  l.head = t;
}

asocjacja & asocjacja::operator= (const asocjacja & l)
{
  if (&l == this)
    return *this;
  asocjacja t (l);
  swap (t);
  return *this;
}

int & asocjacja::operator[] (const char *key)
{
  node *obecny = find (key);
  if (!obecny)
    {
      insert (key, 0);
      obecny = head;
    };
  return obecny->wartosc;
}
