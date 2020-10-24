#include "ObjectBucket.h"
#include <iostream>

ObjectBucket::ObjectBucket(int bucketSize) : bucketSize(bucketSize)
{
}

void ObjectBucket::insert(GameObject *gameObject)
{
    auto position = gameObject->getGlobalPosition();
    auto bucketKey = this->getBucketKey(position);
    auto bucket = this->gameObjectsByLocation[bucketKey];
    bucket.push_back(gameObject);
    this->gameObjectsByLocation[bucketKey] = bucket;
    this->gameObjectBuckets[gameObject] = bucketKey;
}

std::list<GameObject *> ObjectBucket::get(Vector &location, double maxWidth)
{
    auto bucketKey = this->getBucketKey(location);
    auto bucketsToCheckEitherSide = std::ceil(maxWidth / bucketSize);
    std::list<GameObject *> result;
    for (int offset = -bucketsToCheckEitherSide; offset <= bucketsToCheckEitherSide; offset++) {
        std::list<GameObject*> bucket(this->gameObjectsByLocation[bucketKey + offset]);
        result.splice(result.begin(), bucket);
    }

    return result;
}

void ObjectBucket::remove(GameObject *gameObject)
{
    auto bucketKey = this->gameObjectBuckets[gameObject];
    auto bucket = this->gameObjectsByLocation[bucketKey];
    bucket.remove(gameObject);
    this->gameObjectsByLocation[bucketKey] = bucket;
    this->gameObjectBuckets.erase(gameObject);
}

void ObjectBucket::updateLocation(GameObject *gameObject)
{
    auto position = gameObject->getGlobalPosition();
    auto bucketKey = this->getBucketKey(position);
    if (this->gameObjectBuckets[gameObject] != bucketKey) {
        this->remove(gameObject);
        this->insert(gameObject);
    }
}

int ObjectBucket::getBucketKey(Vector &position)
{
    return (int)(position.x / bucketSize);
}
