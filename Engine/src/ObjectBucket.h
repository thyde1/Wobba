#pragma once

#include <map>
#include <list>
#include "GameObject.h"

class ObjectBucket {
public:
    ObjectBucket(int bucketSize);
    void insert(GameObject *gameObject);
    std::list<GameObject*> get(Vector &location);
    void remove(GameObject *gameObject);

private:
    int bucketSize;
    std::map<int, std::list<GameObject *>> gameObjectsByLocation;
};
