#include "objimageloader.h"

objImageLoader::objImageLoader()
{

}

objImageLoader::~ objImageLoader()
{

}

void objImageLoader::loadMesh(std::vector<std::string> objFileVec, bool stopOBJLoading, int meshNum)
{

    // hold name of obj file
    std::string file_name;
    // Initialize Loader
    objl::Loader Loader;
    //objl::Loader Loader2;
    //will contain x,y,z position of each face
    //OBJContainer meshData;

    //this is a test to see if at least one thing will load
    //std::string test = "/Users/nancy/Documents/spring2021/CSCI_5565_introComputerGraphics/project/surfaceAnimationViewer__/Sphere_Animation/sphere_000.obj";

    //the entire path shoudnt matter right?
    std::string test = "/Users/nancy/Documents/spring2021/CSCI_5565_introComputerGraphics/project/surfaceAnimationViewer__/Sphere_Animation/box_stack.e.obj";
    objFileVec.push_back(test);

    for (meshNum; meshNum < objFileVec.size(); meshNum++)
    {
        // stop drawing meshes
//        if (stopOBJLoading == true)
//        { break;}
//        else
//        {
           file_name = objFileVec[meshNum];
           //file_name =  "sphere_000.obj";
//        }
    }


    // struct of obj image
    imageElements image;

    // Load .obj File
    bool loadout = Loader.LoadFile(file_name);
    //bool loadout = Loader.LoadFile(filePath);

    // Check to see if it loaded

    //Loader.LoadedMeshes.push_back(Loader2.LoadFile());

    // If so continue and display

    if (loadout)
    {

        // Go through each loaded mesh and out its contents
        for (int i = 0; i < Loader.LoadedMeshes.size(); i++)
        {

            // Copy one of the loaded meshes to be our current mesh
            objl::Mesh curMesh = Loader.LoadedMeshes[meshNum];


            // Go through each vertex and print its number,
            //  position, normal, and texture coordinate
            for (int j = 0; j < curMesh.Vertices.size(); j++)
            {
                // object holds x,y,z position of each face
                image.X = curMesh.Vertices[j].Position.X;
                image.Y = curMesh.Vertices[j].Position.Y;
                image.Z = curMesh.Vertices[j].Position.Z;
                // object holds normals
                image.X = curMesh.Vertices[j].Normal.X;
                image.Y = curMesh.Vertices[j].Normal.Y;
                image.Z = curMesh.Vertices[j].Normal.Z;
                // object holds texture coordinates
                image.X = curMesh.Vertices[j].TextureCoordinate.X;
                image.Y = curMesh.Vertices[j].TextureCoordinate.Y;
                OBJContainer.push_back(image);

            }


        }

    }
    // If not output an error
    else
    {

        // Output Error
        std::cout << "Failed to Load File. May have failed to find it or it was not an .obj file." << std::endl;


    }


}
