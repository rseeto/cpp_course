//Hen.h

#ifndef HEN_H
#define HEN_H


class Hen {
   public:
      Hen();
      ~Hen();
      void display();
      class Nest {     
        public:
          Nest();
          ~Nest();
          void display();
          class Egg {  
            public:
              Egg();
              ~Egg();
              void display();
          };
      };
 };

#endif