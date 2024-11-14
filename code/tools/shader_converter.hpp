#pragma once

namespace editor::tools
{
    class ShaderConverter
    {
    public:
        static void convert(const std::filesystem::path& input, const std::filesystem::path& output);
    };
}