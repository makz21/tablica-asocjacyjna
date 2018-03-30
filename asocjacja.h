#ifndef asocjacja_h
#define asocjacja_h

#include <iostream>
#include "string.h"

using namespace std;

class asocjacja
{
protected:
  struct node;
  node *head;
  void insert (const char *key, int value);
  void clear ();
  virtual node *find (const char *key){return 0;}
  void swap (asocjacja & l);
public:
  asocjacja ();
  asocjacja (const asocjacja & l);
  ~asocjacja ();
  
  asocjacja & operator= (const asocjacja & l);
  int &operator[] (const char *);
};

struct asocjacja::node
  {
    node *next;
    char *key;
    int wartosc;


    node (const char *k):next (NULL)
    {
      key = new char[strlen (k) + 1];
      strcpy (key, k);
    };
 
    node (const node & s):next (NULL)
    {
      if (s.key == NULL)
	key = NULL;
      else
      {
	key = new char[strlen (s.key) + 1];
        strcpy (key, s.key);
      }
      wartosc=s.wartosc;
    };


     ~node ()
    {
      delete[]key;
    }
  private:
    node & operator= (const node &);
  };

class asocjacjaMale : public asocjacja
{
    node* find (const char* key){
        node* obecny = head;
	  	while (obecny) {

	    		if(!strcmp(obecny->key,key))
	      			return obecny;
	    		obecny = obecny->next;
	  	}
      
	  	return NULL;
	}
};

class asocjacjaDuze : public asocjacja
{
   node* find (const char* key){
        node* obecny = head;
	  	while (obecny) {

	    		if(!strcasecmp(obecny->key,key))
	      			return obecny;
	    		obecny = obecny->next;
	  	}
      
	  	return NULL;
	}  
};



#endif
