#include "ModelParser.h"
ModelParser::~ModelParser()
{
}

ModelParser::ModelParser()
{
}

Model ModelParser::createModel(std::string path)
{

    std::vector<glm::vec3> vertices;
	std::vector<int> indicies;
	std::vector<glm::vec2> textureCoords;
	std::vector<glm::vec3> vertexNormals;

    const char * fileName = path.c_str();
    FILE * file = fopen(fileName, "r");
    if( file == NULL )
    {
        printf("Impossible to open the file !\n");
        exit(EXIT_FAILURE);
    }
    std::vector <glm::vec2> temp_uvs;
    std::vector <glm::vec3> temp_norms;
    while(true)
    {
        char lineHead[128];
        int res = fscanf(file, "%s", lineHead);
        if(res == EOF)
        {
            break;
        }
        if(strcmp(lineHead, "v") == 0)
        {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
            vertices.push_back(vertex);
        }
        else if(strcmp(lineHead, "vt") == 0)
        {
            glm::vec2 uv;
            fscanf(file, "%f %f", &uv.x, &uv.y);
            temp_uvs.push_back(uv);
        }
        else if(strcmp(lineHead, "vn") == 0)
        {
            glm::vec3 norm;
            fscanf(file, "%f %f %f", &norm.x, &norm.y, &norm.z);
            temp_norms.push_back(norm);
        }
        else if(strcmp(lineHead, "f") == 0)
        {
            unsigned int vertIndex[3], uvIndex[3], normIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d", &vertIndex[0], &uvIndex[0], &normIndex[0],&vertIndex[1], &uvIndex[1], &normIndex[1],&vertIndex[2], &uvIndex[2], &normIndex[2]);

    
            indicies.push_back(vertIndex[0] - 1);
            indicies.push_back(vertIndex[1] - 1);
            indicies.push_back(vertIndex[2] - 1);
            textureCoords.push_back(temp_uvs[uvIndex[0] - 1]);
            textureCoords[textureCoords.size() - 1].y = 1 - textureCoords[textureCoords.size() - 1].y;    
            textureCoords.push_back(temp_uvs[uvIndex[1] - 1]);
            textureCoords[textureCoords.size() - 1].y = 1 - textureCoords[textureCoords.size() - 1].y;    
            textureCoords.push_back(temp_uvs[uvIndex[2] - 1]);
            textureCoords[textureCoords.size() - 1].y = 1 - textureCoords[textureCoords.size() - 1].y;    
            vertexNormals.push_back(temp_norms[normIndex[0] - 1]);
            vertexNormals.push_back(temp_norms[normIndex[1] - 1]);
            vertexNormals.push_back(temp_norms[normIndex[2] - 1]);

        }
    }
    Model model(vertices, textureCoords, indicies, vertexNormals);
    return model;
}


