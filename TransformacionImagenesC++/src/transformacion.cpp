#include "transformacion.h" // Aquí se define el valor de CUAL_COMPILO

#if CUAL_COMPILO==1
  #include "transformacion1.cpp"
#else
  #include "transformacion2.cpp"
#endif
