#include "AbstractShader.h"



AbstractShader::AbstractShader(const char* vertShaderPath, const char* fragShaderPath)
{
	program = loadShader(vertShaderPath,fragShaderPath);
}

AbstractShader::~AbstractShader()
{

}

GLuint AbstractShader::getProgram()
{
	return program;
}

GLuint AbstractShader::loadShader(const char* vertShaderPath, const char* fragShaderPath)
{
	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertShaderSource = LoadFileToString(vertShaderPath);
	std::string fragShaderSource = LoadFileToString(fragShaderPath);

	const char* rawVertShaderSource = vertShaderSource.c_str();
	const char* rawFragShaderSource = fragShaderSource.c_str();

	glShaderSource(vertShader, 1, &rawVertShaderSource, NULL);
	glShaderSource(fragShader, 1, &rawFragShaderSource, NULL);

	glCompileShader(vertShader);
	glCompileShader(fragShader);

	GLint params;
	GLsizei infoLen;
	GLchar infoLog;

	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &params);
	if(params == GL_FALSE)
	{
		glGetShaderInfoLog(vertShader, GL_INFO_LOG_LENGTH, &infoLen, &infoLog);
		fprintf(stderr, "vertShaderIssue: %s", infoLog);
		exit(EXIT_FAILURE);
	}
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &params);
	if (params == GL_FALSE)
	{
		glGetShaderInfoLog(fragShader, GL_INFO_LOG_LENGTH, &infoLen, &infoLog);
		fprintf(stderr, "fragShaderIssue: %s", infoLog);
		exit(EXIT_FAILURE);
	}

	GLuint program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);

	glLinkProgram(program);

	return program;

}

std::string AbstractShader::LoadFileToString(const char* filepath)
{
	std::string fileData;
	std::ifstream stream(filepath, std::ios::in);
	if (stream.is_open())
	{
		std::string line;

		while (getline(stream, line))
		{
			fileData += "\n" + line;
		}
		stream.close();
	}
	return fileData;
}

