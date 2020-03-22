#include<iostream>
#include<stdlib.h>

inline char gtch();
inline void clrs();

inline char gtch()
{
     char ch;
     std::cin>>ch;
     return ch;
}

inline void clrs()
{
     for(int i = 0; i < 1024 ; i++)
      std::cout<<" "<<std::endl;
}
