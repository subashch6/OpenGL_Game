#include "ModelParser.h"

/*ModelParser::ModelParser(std::string str)
{	
	std::ifstream data(str.c_str(), std::ios::in);
	if (data.is_open())
	{
		std::string line;
		float num;
		std::vector<glm::vec2> textureCoordsHolder;
		std::vector<glm::vec3> vertexNormalsHolder;
		while (getline(data, line))
		{
			if (line[0] == 'v' && line[1] == ' ')
			{
				line = line.substr(2);
				std::vector<std::string> strings = splitString(line, " ");
				glm::vec3 vertex;
				for(int i = 0; i < 3; i++)
				{
					std::stringstream floats(strings[i]);
					if(floats >> num)
					{
						vertex[i] = num;
					}
				}
				vertices.push_back(vertex);
			}
			else if (line[0] == 'v' && line[1] == 't')
			{
				line = line.substr(2);
				std::vector<std::string> strings = splitString(line, " ");
				glm::vec2 coords;
				for(int i = 0; i < 2; i++)
				{
					std::stringstream floats(strings[i]);
					if(floats >> num)
					{
						coords[i] = num;
					}
				}
				textureCoordsHolder.push_back(coords);
			}
			else if (line[0] == 'v' && line[1] == 'n')
			{
				line = line.substr(2);
				std::vector<std::string> strings = splitString(line, " ");
				glm::vec3 norms;
				for(int i = 0; i < 3; i++)
				{
					std::stringstream floats(strings[i]);
					if(floats >> num)
					{
						norms[i] = num;
					}
				}
				vertexNormalsHolder.push_back(norms);
			}
			else if (line[0] == 'f' && line[1] == ' ')
			{
				line = line.substr(2);
				std::vector<std::string> strings = splitString(line, " ");
				std::vector<std::string> vec1 = splitString(strings[0], "/");
				std::vector<std::string> vec2 = splitString(strings[1], "/");
				std::vector<std::string> vec3 = splitString(strings[2], "/");
				processVertex(vec1, textureCoordsHolder, vertexNormalsHolder);
				processVertex(vec2, textureCoordsHolder, vertexNormalsHolder);
				processVertex(vec3, textureCoordsHolder, vertexNormalsHolder);
			}
		}
	}
}


std::vector<std::string> ModelParser::splitString(std::string str, std::string character)
{
	std::vector < std::string > strings;
	if (character == " ")
	{
		std::stringstream ss(str);
		std::string sub;
		while (ss >> sub)
		{
			strings.push_back(sub);
		}
	}
	else
	{
		char* sf;
		char* sd = &str[0];
		char* chars = NULL;
		sf = strtok(sd, character.c_str());
		while (sf != NULL)
		{
			std::stringstream ss(sf);
			std::string sub;
			ss >> sub;
			strings.push_back(sub);
			sf = strtok(NULL, character.c_str());
		}

	}
	return strings;
}


void ModelParser::processVertex(std::vector<std::string> strings, std::vector<glm::vec2> textureCoordsHolder, std::vector<glm::vec3> vertexNormalsHolder)
{
	std::stringstream sa(strings[0]);
	float num;
	if(sa >> num)
	{
		num -= 1;
		indicies.push_back(num);
	}
	std::stringstream sb(strings[1]);
	if(sb >> num)
	{
		num -= 1;
		textureCoords.push_back(textureCoordsHolder[num]);
		textureCoords[textureCoords.size()-1][1] = 1 - textureCoords[textureCoords.size()-1][1];
	}
	std::stringstream sc(strings[2]);
	if(sc >> num)
	{
		num -= 1;
		vertexNormals.push_back(vertexNormalsHolder[num]);
	}
}
*/
ModelParser::~ModelParser()
{
}


ModelParser::ModelParser(std::string path)
{
    const char * fileName = path.c_str();
    FILE * file = fopen(fileName, "r");
    if( file == NULL )
    {
        printf("Impossible to open the file !\n");
        exit(EXIT_FAILURE);
    }
    std::vector <glm::vec3> temp_verts;
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
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            vertices.push_back(vertex);    
        }
        else if(strcmp(lineHead, "vt") == 0)
        {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            temp_uvs.push_back(uv);
        }
        else if(strcmp(lineHead, "vn") == 0)
        {
            glm::vec3 norm;
            fscanf(file, "%f %f %f\n", &norm.x, &norm.y, &norm.z);
            temp_norms.push_back(norm);
        }
        else if(strcmp(lineHead, "f") == 0)
        {
            unsigned int vertIndex[3], uvIndex[3], normIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertIndex[0], &uvIndex[0], &normIndex[0],&vertIndex[1], &uvIndex[1], &normIndex[1],&vertIndex[2], &uvIndex[2], &normIndex[2]);
            //printf("verts = %d %d %d\n",vertIndex[0], vertIndex[1], vertIndex[2]);
            //printf("texCoords = %d %d %d\n", uvIndex[0], uvIndex[1], uvIndex[2]);
            //printf("norms = %d %d %d\n", normIndex[0], normIndex[1], normIndex[2]);

            indicies.push_back(vertIndex[0] - 1);
            indicies.push_back(vertIndex[1] - 1);
            indicies.push_back(vertIndex[2] - 1);
            textureCoords.push_back(temp_uvs[uvIndex[0] - 1]);
            textureCoords[textureCoords.size() - 1][1] = 1 - textureCoords[textureCoords.size() - 1][1];    
            textureCoords.push_back(temp_uvs[uvIndex[1] - 1]);
            textureCoords[textureCoords.size() - 1][1] = 1 - textureCoords[textureCoords.size() - 1][1];    
            textureCoords.push_back(temp_uvs[uvIndex[2] - 1]);
            textureCoords[textureCoords.size() - 1][1] = 1 - textureCoords[textureCoords.size() - 1][1];    
            vertexNormals.push_back(temp_norms[normIndex[0] - 1]);
            vertexNormals.push_back(temp_norms[normIndex[1] - 1]);
            vertexNormals.push_back(temp_norms[normIndex[2] - 1]);

        }
    }
}















