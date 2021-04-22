#ifndef OBJIMAGELOADER_H
#define OBJIMAGELOADER_H
#include "OBJ_Loader.h"
#include <vector>
#include <string>

class objImageLoader
{
public:
    objImageLoader();
    ~objImageLoader();
   // will hold values needed to draw 3D image
   struct imageElements
   {
       float X;
       float Y;
       float Z;
       int normalX;
       int normalY;
       int normalZ;
       int textCoorX;
       int textCoorY;
   };

   // will hold output of OBJ loader
   std::vector<imageElements>OBJContainer;

   std::vector<std::string>objFileVec;

   // will load obj file into OBJ container
   void loadMesh(std::vector<std::string>, bool, int);

};


#endif // OBJIMAGELOADER_H
