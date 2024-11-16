#pragma once

namespace tools
{
    class ShaderConverter
    {
    public:
        static void convert(const std::string& filename, const std::string& input, const std::string& output = "./");
    };
}