

#ifndef PINA_CONFIG_H
#define PINA_CONFIG_H


/* namespaces to use */
#define PINA_NAMESPACE Pina
#define PINA_SUBNAMESPACES true

#define PINA_FX true
#define PINA_PHYSICS true
#define PINA_BREP true
#define PINA_KINEMATICS true

/* Prefix to use for classes */
#define PINA_PREFIX 

/* allow undefined elements? */
#define PINA_ALLOW_UNDEFINED true

/* log */
/*what to log?*/
#define PINA_ENABLE_DEBUG_LOG true
#define PINA_ENABLE_INFO_LOG true
#define PINA_ENABLE_ERROR_LOG true
#define PINA_ENABLE_SEVERE_LOG true
#define PINA_ENABLE_FATAL_LOG true

/*pipe log to std::cout/std::cerr*/
#define PINA_PIPE_DEBUG false
#define PINA_PIPE_INFO false
#define PINA_PIPE_ERROR true
#define PINA_PIPE_SEVERE true
#define PINA_PIPE_FATAL true

#endif
