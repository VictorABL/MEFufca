#ifndef MEF_UFCA_APOIO_H
#define MEF_UFCA_APOIO_H

#include "no.h"
#include "graus.h"

namespace FEM {

template<template<class B> class Estrutura, class Tipo = double>
class Apoio {

    // Implementação da classe apoio, referencia os nós
    // com graus impedidos.

public:

    typedef typename std::shared_ptr< FEM::No<Estrutura, Tipo> > shared_ptr;

private:

    // Ponteiro para o nó impedido:
    shared_ptr ponteiro;
    // Vetor dos graus impedidos:
    std::vector<int> apoios;

public:

    // Construtor:
    Apoio(const shared_ptr &no,
            const std::vector<int> &apoio)

          : ponteiro(no),
            apoios(apoio)
            {RestringirNo();}

    // Destrutor:
    ~Apoio () {}

private:

    // Função de restrição do nó:
    void RestringirNo() {ponteiro->RestringirGraus(apoios);}

};
}

#endif
