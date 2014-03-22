
// TIM MAX
template<class T> T Max(T a,T b)
{
  if (a>=b) return a;
  else return b;
}
// LIST
template <class T> struct Phantu
{       
  T info;
  Phantu *next;
  Phantu *prev;      
};
template <class T> class List
{
  public:       
  Phantu<T> *frist;
  Phantu<T> *last;
  int Count;
  // Ham Khoi tao
  List()    
  {
   frist = NULL;
   last = NULL;
   Count = 0;   
  }     
  // Ham them phan tu
  void Add(T d)
   {
     Phantu<T> *p = new Phantu<T>;
     p->info = d;
     if (frist == NULL)
      {
        frist = p;
        frist->next = NULL;
        frist->next = NULL;
        last=frist;
        Count += 1;
      }
     else
      {
        last->next = p;
        p->prev=last;
        last=p;
        last->next = NULL;
        Count+=1;                           
      }                            
    }
  // duyet phan tu trong mang  
  T ptu(int id)
    {
     Phantu<T> *p;
     p = frist;
     int n=0;
     
     while  ((p!= NULL) && (n< id))
      {
        p=p->next;
        n++;
      }
      
     return p->info;
    }
  // Tro den phan tu trong mang   
  T *Ptu(int id)
  {
    Phantu<T> *p;
    p = frist;
    int n=0;
     while  ((p!= NULL) && (n< id))
      {
        p=p->next;
        n++;
      }
    return &(p->info);
  }
  // Xoa phan tu theo vi tri
  void RemoveAt(int id)
    {
      Phantu<T> *p,*p1,*p2;
      p = frist;
      int n=0;
      while  ((p!= NULL) && (n< id))
       {
            p=p->next;
            n++;
       }
      if (p!=NULL) 
      {
        if (p==last)
        { 
            last=p->prev;
            last->next=NULL;
            delete(p);
        }
        else if (p==frist)
        {
            frist=p->next;
            frist->prev=NULL;
            delete(p);
        }
        else
        {
            p1=p->prev;
            p2=p->next;
            p1->next=p2;
            p2->prev=p1;
            delete(p);
        }
      }                           
    }
    
    void Remove(int id)
    {
       Phantu<T> *ptr;
       ptr=frist;
       if (ptr!=NULL)
        {
          T p= ptr->info;
          if (Count == 1 && p.id==id)
           {
                    
             frist = NULL;
             last = NULL;
             Count = 0;  
             delete (ptr);     
           }
          else
           {
             while (ptr != NULL && p.id != id)
              {
                 ptr = ptr->next;
                 p= ptr->info;  
              }
             if (ptr == frist)
              {
                 frist=ptr->next;
                 frist->prev = NULL;
                 delete (ptr);
                 Count -=1;    
              }
             else if (ptr == last)
              {
                 last=last->prev;
                 last->next=NULL; 
                 delete (ptr);
                 Count -=1;    
              }              
             else
              {
                  Phantu<T> *ptr1,*ptr2;
                  ptr1=ptr->prev;
                  ptr2=ptr->next;
                  ptr1->next=ptr2;
                  ptr2->prev=ptr1;
                  delete (ptr);
                  Count -=1;          
              }                
           }                  
        }           
    }  
   
};
// Cac ham hien so ngau nhien
void randomize()
{ 
    srand(time(NULL)); 
}

int Random(int min,int max) 
{ 
  if(min>=max) 
   return 0; 
  else 
  {
   int d=max-min; 
   return (rand()%(d)+min); 
  }
}
