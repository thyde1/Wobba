#include "ObjectBucket.h"
#include <iostream>

ObjectBucket::ObjectBucket(int bucketSize) : bucketSize(bucketSize)
{
}

void ObjectBucket::insert(GameObject *gameObject)
{
    auto bucketKey = (int)(gameObject->getGlobalPosition().x / this->bucketSize);
    auto bucket = this->gameObjectsByLocation[bucketKey];
    bucket.push_back(gameObject);
    this->gameObjectsByLocation[bucketKey] = bucket;
}

std::list<GameObject *> ObjectBucket::get(Vector &location)
{
    auto bucketKey = (int)(location.x / bucketSize);
    std::list<GameObject *> result;
    for (int offset = -1; offset <= 1; offset++) {
        std::list<GameObject*> bucket(this->gameObjectsByLocation[bucketKey + offset]);
        result.splice(result.begin(), bucket);
    }

    return result;
}

void ObjectBucket::remove(GameObject *gameObject)
{
    auto bucketKey = (int)(gameObject->getGlobalPosition().x / bucketSize);
    auto bucket = this->gameObjectsByLocation[bucketKey];
    for (auto object : bucket) {
        if (object == gameObject) {
            bucket.remove(object);
            this->gameObjectsByLocation[bucketKey] = bucket;
            return;
        }
    }

    for (auto bucket : this->gameObjectsByLocation) {
        bucket.second.remove(gameObject);
        this->gameObjectsByLocation[bucket.first] = bucket.second;
    }
}
