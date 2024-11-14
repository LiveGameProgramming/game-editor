#include "shader_converter.hpp"

namespace editor::tools
{
    void ShaderConverter::convert(const std::filesystem::path& input, const std::filesystem::path& output)
    {
        std::vector<std::filesystem::path> files;

        for (const auto& file : std::filesystem::directory_iterator(input.parent_path()))
        {
            if (file.is_regular_file() && file.path().filename().replace_extension() == input.filename())
            {
                files.push_back(file.path());
            }
        }

        for (const auto& file : files)
        {
            const std::string filename = file.filename().string();

            std::string command = std::format("glslangValidator -V -G -S {} -o {} {}", file.extension().string().erase(0, 1), output.string() + filename, input.parent_path().string() + "/" + file.filename().string());

            std::system(command.c_str());
        }
    }
}