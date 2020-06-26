#include "ObjectBucket.h"

ObjectBucket::ObjectBucket(int bucketSize) : bucketSize(bucketSize)
{
}

void ObjectBucket::insert(GameObject *gameObject)
{
    auto bucketKey = (int)(gameObject->globalPosition.x / this->bucketSize);
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
    for (auto bucket : this->gameObjectsByLocation) {
        bucket.second.remove(gameObject);
        this->gameObjectsByLocation[bucket.first] = bucket.second;
    }
}
