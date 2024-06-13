#include "FileManager.h"
#include <string>

int main(int argc, char* argv[]) {
    FileManager fm;

    if (argc < 2) {
        std::cout << "No command provided. Use 'help' to see available commands." << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "ls") {
        if (argc == 3) {
            fm.ls(argv[2]);
        } else {
            std::cout << "Usage: ls <path>" << std::endl;
        }
    } else if (command == "cd") {
        if (argc == 3) {
            fm.cd(argv[2]);
        } else {
            std::cout << "Usage: cd <path>" << std::endl;
        }
    } else if (command == "view") {
        if (argc == 3) {
            fm.view(argv[2]);
        } else {
            std::cout << "Usage: view <file>" << std::endl;
        }
    } else if (command == "mkdir") {
        if (argc == 3) {
            fm.mkdir(argv[2]);
        } else {
            std::cout << "Usage: mkdir <dir>" << std::endl;
        }
    } else if (command == "cp") {
        if (argc == 4) {
            fm.cp(argv[2], argv[3]);
        } else {
            std::cout << "Usage: cp <src> <dest>" << std::endl;
        }
    } else if (command == "mv") {
        if (argc == 4) {
            fm.mv(argv[2], argv[3]);
        } else {
            std::cout << "Usage: mv <src> <dest>" << std::endl;
        }
    } else if (command == "help") {
        fm.help();
    } else if (command == "exit") {
        fm.exit();
    } else {
        std::cout << "Unknown command. Use 'help' to see available commands." << std::endl;
    }

    return 0;
}