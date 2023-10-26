#ifndef BACKMAP_H
#define BACKMAP_H

#include <vector>
#include "camera.h"
#include "area.h"
#include "coletavel.h"
#include "vivo.h"

using std::vector;

class BackMap{
    private:
        int tamanhoMapa;
        vector<Area*> areas;
        vector<Vivo*> vivos;
        vector<Coletavel*> coletaveis;
    public:
        Area* retornarAreas(int indice);
        Vivo* retornarVivos(int indice);
        Coletavel* retornarColetaveis(int indice);

        int tamanhoVectorAreas(void);
        int tamanhoVectorVivos(void);
        int tamanhoVectorColetaveis(void);

        void generateAreas(int tamanhoMapa, int proporcaoArea);
        void generateEntities();

        void updateAreas(Camera &camera);


};

#endif