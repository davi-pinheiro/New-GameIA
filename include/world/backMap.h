#ifndef BACKMAP_H
#define BACKMAP_H

#include <vector>
#include "tipoMundo.h"
#include "camera.h"
#include "area.h"
#include "subArea.h"
#include "coletavel.h"
#include "vivo.h"
#include "rgba.h"

using std::vector;

class BackMap{
    protected:
        vector<Area*> areas;
        vector<Vivo*> vivos;
        vector<Coletavel*> coletaveis;

        int tamanhoMapa;
        bool ativo;
        Rgba background;
        TipoMundo tipoMundo;
        TipoMundo proximoMundo;
    public:
        BackMap(void);

        Area* retornarAreas(int indice);
        Vivo* retornarVivos(int indice);
        Coletavel* retornarColetaveis(int indice);
        SubArea* retornarSubArea(int x, int y);

        int tamanhoVectorAreas(void);
        int tamanhoVectorVivos(void);
        int tamanhoVectorColetaveis(void);

        void generateAreas(int tamanhoMapa, int proporcaoArea);
        void generateEntities();

        bool isAtivo(void);
        TipoMundo getTipoMundo(void);
        TipoMundo getProximoMundo(void);
        Rgba getBackground(void);

        void setAtivo(bool ativo);

        
        void setProximoMundo(TipoMundo tipoMundo);

        void updateAreas(Camera &camera);
        void deleteVivo(int indice);
};

#endif