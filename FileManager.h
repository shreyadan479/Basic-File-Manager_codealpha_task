#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class FileManager {
public:
    void ls(const fs::path& path) {
        for (const auto & entry : fs::directory_iterator(path))
            std::cout << entry.path() << std::endl;
    }

    void cd(const fs::path& path) {
        fs::current_path(path);
    }

    void view(const fs::path& file) {
        std::ifstream f(file);
        if (f.is_open()) {
            std::cout << f.rdbuf();
        }
        f.close();
    }

    void mkdir(const fs::path& dir) {
        fs::create_directory(dir);
    }

    void cp(const fs::path& src, const fs::path& dest) {
        fs::copy(src, dest);
    }

    void mv(const fs::path& src, const fs::path& dest) {
        fs::rename(src, dest);
    }

    void help() {
        std::cout << "Available commands:\n";
        std::cout << "  ls           - List directory contents\n";
        std::cout << "  cd <dir>     - Change directory\n";
        std::cout << "  view <file>  - View file contents\n";
        std::cout << "  mkdir <dir>  - Create directory\n";
        std::cout << "  cp <src> <dest> - Copy file\n";
        std::cout << "  mv <src> <dest> - Move file\n";
        std::cout << "  help         - Show this help message\n";
        std::cout << "  exit         - Exit the file manager\n";
    }

    void exit() {
        std::exit(0);
    }
};