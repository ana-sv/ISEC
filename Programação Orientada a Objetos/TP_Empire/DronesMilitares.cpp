// Programação Orientada a Objectos 2020/2021
// Ana Rita Videira - 5012012218

#include "DronesMilitares.h"
#include "Imperio.h"

DronesMilitares::DronesMilitares(Imperio * imp) {
    designacao = "Drones Militares";
    ident = "drones";
    custo = 3;
    accao = "[ * ] Imperio pode ter agora um maximo de 5 de forca militar! ";
     imp->setMaxMilitar(5);
}

DronesMilitares::DronesMilitares(const DronesMilitares& orig) {
}

DronesMilitares::~DronesMilitares() {
}


