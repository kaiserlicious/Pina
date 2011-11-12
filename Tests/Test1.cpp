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
    Pina::Document doc;
    doc.collada->get(Pina::Collada::Name)->get("");
}
