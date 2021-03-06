

#ifndef PINA_CONFIG_H
#define PINA_CONFIG_H


/* namespaces to use */
#define PINA_NAMESPACE Pina

/* allow undefined elements? */
#define PINA_ALLOW_UNDEFINED true

/* log */
/*what to log?*/
#define PINA_ENABLE_DEBUG_LOG ${PINA_ENABLE_DEBUG_LOG}
#define PINA_ENABLE_INFO_LOG ${PINA_ENABLE_INFO_LOG}
#define PINA_ENABLE_ERROR_LOG ${PINA_ENABLE_ERROR_LOG}
#define PINA_ENABLE_SEVERE_LOG ${PINA_ENABLE_SEVERE_LOG}
#define PINA_ENABLE_FATAL_LOG ${PINA_ENABLE_FATAL_LOG}

/*pipe log to std::cout/std::cerr*/
#define PINA_PIPE_DEBUG false
#define PINA_PIPE_INFO false
#define PINA_PIPE_ERROR true
#define PINA_PIPE_SEVERE true
#define PINA_PIPE_FATAL true

#endif
