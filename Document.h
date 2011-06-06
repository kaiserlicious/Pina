
/*copyright 2010 Simon Graeser*/

/*
This file is part of Pina.

Pina is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Pina is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Pina.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef COLLADA_DOCUMENT_H
#define COLLADA_DOCUMENT_H

#include "Config.h"
#include "Tinyxml/tinyxml.h"
#include <map>
#include <vector>
#include <queue>
#include "Log/Log.h"

namespace PINA_NAMESPACE{
  class Element;
  class Collada;
}

#define THIS Document
namespace PINA_NAMESPACE{

/**
@brief Every Element must belong to a Document
*/
class THIS{

  friend class Element;

  public:
  THIS();
  ~THIS();

  bool load(std::string filename);
  bool save(std::string filename);

  Element* getByURL(std::string);

  template<typename TYPE>
  void getByURL(TYPE*& t, std::string str){
    t = dynamic_cast<TYPE*>(getByURL(str));
  }

  void postLogEntry(LogEntry<Enum::Debug>* logEntry){
    #if PINA_ENABLE_DEBUG_LOG
    log.push(logEntry);
      #if PINA_PIPE_DEBUG
        std::cout << "[Debug] ";
        std::cout << logEntry->getElementName() <<": ";
        std::cout << logEntry->getMessage() << std::endl;
      #endif
    #endif
  }

  void postLogEntry(LogEntry<Enum::Info>* logEntry){
    #if PINA_ENABLE_INFO_LOG
    log.push(logEntry);
      #if PINA_PIPE_INFO
        std::cout << "[Info] ";
        std::cout << logEntry->getElementName() <<": ";
        std::cout << logEntry->getMessage() << std::endl;
      #endif
    #endif
  }

  void postLogEntry(LogEntry<Enum::Error>* logEntry){
    #if PINA_ENABLE_ERROR_LOG
    log.push(logEntry);
      #if PINA_PIPE_ERROR
        std::cerr << "[Error] ";
        std::cerr << logEntry->getElementName() <<": ";
        std::cerr << logEntry->getMessage() << std::endl;
      #endif
    #endif
  }

  void postLogEntry(LogEntry<Enum::Severe>* logEntry){
    #if PINA_ENABLE_SEVERE_LOG
    log.push(logEntry);
      #if PINA_PIPE_SEVERE
        std::cerr << "[Severe] ";
        std::cerr << logEntry->getElementName() <<": ";
        std::cerr << logEntry->getMessage() << std::endl;
      #endif
    #endif
  }

  void postLogEntry(LogEntry<Enum::Fatal>* logEntry){
    #if PINA_ENABLE_FATAL_LOG
    log.push(logEntry);
      #if PINA_PIPE_FATAL
        std::cerr << "[Fatal] ";
        std::cerr << logEntry->getElementName() <<": ";
        std::cerr << logEntry->getMessage() << std::endl;
      #endif
    #endif
  }

  AbstractLogEntry* getLogEntry(){
    return log.front();
  }

  bool popLogEntry();

  Collada* collada;

  private:
  Element* searchId(Element*,std::string );
  std::vector<Element*> elements;
  std::queue<AbstractLogEntry*> log;
};

}/*PINA_NAMESPACE*/
#undef THIS
#endif
