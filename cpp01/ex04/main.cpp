
#include <iostream>
#include <fstream>

std::string replaceLine(std::string line, std::string s1, std::string s2)
{
    if (s1.empty())
        return (line);
        
    std::string result;
    size_t      pos         = 0;
    size_t      found_pos   = 0;

    while ((found_pos = line.find(s1, pos)) != std::string::npos)
    {
        result.append(line.substr(pos, found_pos - pos));
        result.append(s2);
        pos = found_pos + s1.length();
    }
    result.append(line.substr(pos));
    return (result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Enter 3 parameters: <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string fileName    = argv[1];
    std::string s1          = argv[2];
    std::string s2          = argv[3];
  
    std::ifstream inFile(fileName.c_str());
    if (!inFile.is_open())
    {
        std::cout << "Error opening file: " << fileName << std::endl;
        return (1);
    }
    std::string outfileName = fileName + ".replace";
    std::ofstream outFile (outfileName.c_str());
    if (!outFile.is_open())
    {
        std::cout << "Error creating file: " << outfileName << std::endl;
        inFile.close();
        return (1);
    }
    std::string line;
    while (std::getline(inFile, line))
    {
        outFile << replaceLine(line, s1, s2) << std::endl;
    }
    inFile.close();
    outFile.close();
    return (0);
}