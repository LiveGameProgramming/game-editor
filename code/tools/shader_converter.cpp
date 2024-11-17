#include "shader_converter.hpp"

namespace tools
{
    void ShaderConverter::convert(const std::string& filename, const std::string& input, const std::string& output)
    {
        std::vector<std::filesystem::path> files;

        for (const auto& item : std::filesystem::directory_iterator(input))
        {
            if (!item.is_regular_file())
                continue;

            if (item.path().stem() == filename)
            {
                files.emplace_back(item.path());
            }
        }

        for (const auto& item : files)
        {
            const std::string name = item.filename().string();
                  std::string ext  = item.extension().string(); ext.erase(ext.begin());

            std::string command = std::format("glslangValidator -V -G -S {} -o {} {}", ext, output + name, input + name);
            std::system(command.c_str());
        }
    }
}