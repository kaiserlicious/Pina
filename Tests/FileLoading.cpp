#include <string>
#include <iostream>
#include <cassert>
#include <exception>

#include "Pina.h"
#include "Core/Collada.h"
#include "Xml/Xml.h"

int main(int args, char** argv){
    Pina::TinyXml::Parser parser;
    Pina::XmlParser::environment = &parser;
    for(unsigned int i = 1; i<args; i++){
        Pina::Collada collada;
        bool ok = collada.load(argv[i]);
        if(!ok){
            std::cout << "Failed to load " << argv[i] << std::endl;
            return EXIT_FAILURE;
        }
    }
}
