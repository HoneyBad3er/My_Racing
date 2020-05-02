#ifndef TMP_NAMESPACES_H
#define TMP_NAMESPACES_H
#include "car.h"
#include "carmodifications.h"
#include <memory>

namespace Pit{
    void GoPit(std::shared_ptr<Car> car) {
        OnPitDecorator obj(car);
        obj.Power_Up();
        obj.Change_Tyres();
        obj.Change_Front_Wing();
    }
}

#endif // TMP_NAMESPACES_H