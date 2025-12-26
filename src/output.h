#ifndef OUTPUT_H
#define OUTPUT_H

#include "platform.h"
#include "args.h"

/**
 * Output process information in the requested format
 * @param info Process information
 * @param args CLI arguments (determines output format)
 * @return 0 on success, -1 on error
 */
int output_process_info(const process_info_t *info, const cli_args_t *args);

/**
 * Output process tree in the requested format
 * @param tree Process tree
 * @param args CLI arguments (determines output format)
 * @return 0 on success, -1 on error
 */
int output_process_tree(const process_tree_node_t *tree, const cli_args_t *args);

/**
 * Output process environment variables
 * @param env_vars Array of environment variable strings
 * @param count Number of variables
 * @param args CLI arguments (determines output format)
 * @return 0 on success, -1 on error
 */
int output_process_env(char **env_vars, int count, const cli_args_t *args);

/**
 * Output port connection information
 * @param port Port number
 * @param connections Array of connections
 * @param count Number of connections
 * @param args CLI arguments (determines output format)
 * @return 0 on success, -1 on error
 */
int output_port_info(int port, const connection_info_t *connections,
                     int count, const cli_args_t *args);

/**
 * Output list of all processes
 * @param processes Array of process information
 * @param count Number of processes
 * @param args CLI arguments (determines output format)
 * @return 0 on success, -1 on error
 */
int output_process_list(const process_info_t *processes, int count,
                        const cli_args_t *args);

#endif /* OUTPUT_H */
