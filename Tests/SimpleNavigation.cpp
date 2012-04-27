#include "Pina.h"
#include "Core/Collada.h"
#include "Core/Asset.h"
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
        Pina::Asset* asset =0;
        collada.queryElement(asset);
        if(!asset){
            std::cout << "Failed to navigate to asset element in file " << argv[i] << std::endl;
            return EXIT_FAILURE;
        }
        Pina::Created* created =0;
        Pina::Modified* modified =0;
        asset->queryElement(created);
        asset->queryElement(modified);
        if( !(created && modified) ){
            std::cout << "Failed to navigate to created or modified element in file " << argv[i] << std::endl;
            return EXIT_FAILURE;
        }

        created = collada.get<Pina::Asset>().get<Pina::Created>();
        if(!created){
            std::cout << "Failed to navigate to created in file " << argv[i] << "using Get method" << std::endl;
            return EXIT_FAILURE;
        }
        Pina::Collada* falseElmement =0;
        if(asset->queryElement(falseElmement)){
            return EXIT_FAILURE;
        }
        if(falseElmement){
            return EXIT_FAILURE;
        }
        modified =0;
        if(!collada.queryElement("asset",modified)){
            return EXIT_FAILURE;
        }
        if(!modified){
            return EXIT_FAILURE;
        }
    }
}
