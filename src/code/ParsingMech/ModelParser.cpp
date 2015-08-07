#include "ModelParser.h"

ModelParser::ModelParser(std::string str)
{	
	std::ifstream data(str.c_str(), std::ios::in);
	if (data.is_open())
	{
		std::string line;
		while (getline(data, line))
		{
			if (line[0] == 'v' && line[1] == ' ')
			{
				std::string str;
				str = line.substr(2);
				vertices.push_back(splitString(str, " "));
			}
		}
	}
}

std::vector<glm::vec3> ModelParser::getVertices()
{
	return vertices;
}

glm::vec3 ModelParser::splitString(std::string str, std::string character)
{
	std::vector < float > floats;
	if (character == " ")
	{
		std::stringstream ss(str);
		float sub;
		while (ss >> sub)
		{
			floats.push_back(sub);
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
			float sub;
			ss >> sub;
			floats.push_back(sub);
			sf = strtok(NULL, character.c_str());
		}

	}
	return glm::vec3(floats[0], floats[1], floats[2]);
}

ModelParser::~ModelParser()
{
}
