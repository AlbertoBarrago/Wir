#include "utils.h"
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/* Global flag for controlling color output */
bool use_colors = true;

/**
 * Print text with color support
 * @param color ANSI color code (or NULL/empty for no color)
 * @param format printf-style format string
 */
void print_color(const char *color, const char *format, ...) {
    va_list args;

    if (use_colors && color && *color) {
        printf("%s", color);
    }

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if (use_colors && color && *color) {
        printf("%s", COLOR_RESET);
    }
}

/**
 * Print error message in red
 */
void print_error(const char *format, ...) {
    va_list args;

    if (use_colors) {
        fprintf(stderr, "%s", COLOR_RED);
    }

    fprintf(stderr, "Error: ");

    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    fprintf(stderr, "\n");

    if (use_colors) {
        fprintf(stderr, "%s", COLOR_RESET);
    }
}

/**
 * Print warning message in yellow
 */
void print_warning(const char *format, ...) {
    va_list args;

    if (use_colors) {
        fprintf(stderr, "%s", COLOR_YELLOW);
    }

    fprintf(stderr, "Warning: ");

    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    fprintf(stderr, "\n");

    if (use_colors) {
        fprintf(stderr, "%s", COLOR_RESET);
    }
}

/**
 * Print success message in green
 */
void print_success(const char *format, ...) {
    va_list args;

    if (use_colors) {
        printf("%s", COLOR_GREEN);
    }

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");

    if (use_colors) {
        printf("%s", COLOR_RESET);
    }
}

/**
 * Print info message in cyan
 */
void print_info(const char *format, ...) {
    va_list args;

    if (use_colors) {
        printf("%s", COLOR_CYAN);
    }

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");

    if (use_colors) {
        printf("%s", COLOR_RESET);
    }
}

/**
 * Safe malloc with error checking
 * Dies if allocation fails
 */
void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        DIE("Memory allocation failed: %s", strerror(errno));
    }
    return ptr;
}

/**
 * Safe calloc with error checking
 * Dies if allocation fails
 */
void *safe_calloc(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if (!ptr) {
        DIE("Memory allocation failed: %s", strerror(errno));
    }
    return ptr;
}

/**
 * Safe realloc with error checking
 * Dies if allocation fails
 */
void *safe_realloc(void *ptr, size_t size) {
    void *new_ptr = realloc(ptr, size);
    if (!new_ptr && size > 0) {
        DIE("Memory reallocation failed: %s", strerror(errno));
    }
    return new_ptr;
}

/**
 * Safe strdup with error checking
 * Dies if allocation fails
 */
char *safe_strdup(const char *s) {
    if (!s) {
        return NULL;
    }

    char *dup = strdup(s);
    if (!dup) {
        DIE("String duplication failed: %s", strerror(errno));
    }
    return dup;
}

/**
 * Trim leading and trailing whitespace from a string (in-place)
 * Returns the trimmed string
 */
char *trim_whitespace(char *str) {
    if (!str) {
        return NULL;
    }

    /* Trim leading whitespace */
    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == '\0') {
        return str;
    }

    /* Trim trailing whitespace */
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    /* Write new null terminator */
    *(end + 1) = '\0';

    return str;
}

/**
 * Check if string starts with a prefix
 */
bool str_starts_with(const char *str, const char *prefix) {
    if (!str || !prefix) {
        return false;
    }

    size_t str_len = strlen(str);
    size_t prefix_len = strlen(prefix);

    if (prefix_len > str_len) {
        return false;
    }

    return strncmp(str, prefix, prefix_len) == 0;
}

/**
 * Check if string ends with a suffix
 */
bool str_ends_with(const char *str, const char *suffix) {
    if (!str || !suffix) {
        return false;
    }

    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    if (suffix_len > str_len) {
        return false;
    }

    return strcmp(str + str_len - suffix_len, suffix) == 0;
}
