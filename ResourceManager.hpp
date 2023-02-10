#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
 
public: 
    Resource *obj;


ResourceManager() : obj{new Resource} { };

ResourceManager(const ResourceManager& other)
    : obj{new Resource{*other.obj}} {       
};
  
ResourceManager& operator=(const ResourceManager& other)
{
    *obj = *other.obj; 
    return *this;
}


ResourceManager(ResourceManager&& other) noexcept : obj{new Resource{std::move(*other.obj)}}
{
    //obj = new Resource;
    //*obj = std::move(*other.obj);
    delete other.obj;
    other.obj = nullptr; 
    
}


ResourceManager& operator=(ResourceManager&& other) noexcept
{
    *obj = std::move(*other.obj); 
    delete other.obj; 
    other.obj = nullptr; 

    return *this;
}

~ResourceManager() 
{ 
    delete obj;
    printf("ResourceManager Destructor \n");
}; 

double get() 
{
    return obj->get(); 
}; 



};
