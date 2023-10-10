/* 
 * Fast Create Documentation (facdoc)
 * Copyright (C) 2023 Free Software Foundation, Inc.
 *
 * This file is part of facdoc.
 *
 * Facdoc is free software: you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Foobar. If not, see <https://www.gnu.org/licenses/>. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "util.h"

#ifdef HAVE_CONFIG_H
#   include "config.h"
#endif

#if defined(_WIN32) || defined(_WIN64)
#   ifdef HAVE_WINDOWS_H
#       include <windows.h>
#   else
#       error "Not have windows.h"
#   endif
#elif defined(unix) || defined(__unix) || defined(__unix__)
#   ifdef HAVE_ARGP_H
#       include <argp.h>
#endif

const char *argp_program_version = PACKAGE_STRING;
const char *argp_program_bug_address = PACKAGE_BUGREPORT;

/* Struct to hold command-line arguments */
static struct arguments
{
    char *input_file;
    char *output_file;
    int check_syntax;
    char *template_path;
    char *output_format;
    int one_file;
    int using_extern_media;
};

/* Options parser */
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;

    switch (key) {
        case 'i':
            arguments->input_file = arg;
            break;
        case 'o':
            arguments->output_file = arg;
            break;
        case 'c':
            arguments->check_syntax = 1;
            break;
        case 't':
            arguments->template_path = arg;
            break;
        case 'f':
            arguments->output_format = arg;
            break;
        case '1':
            arguments->one_file = 1;
            break;
        case 'e':
            arguments->using_extern_media = 1;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

/* Description of the arguments for the help message */
static char doc[] =
    "This is a program that takes input and output files, "
    "a check syntax parameter, a template path, "
    "an output format, an option for one file, "
    "and an option for using external media.";

/* Options supported */
static struct argp_option options[] =
{
    {"input", 'i', "INPUT_FILE", 0, "Input file path", 0},
    {"output", 'o', "OUTPUT_FILE", 0, "Output file path", 0},
    {"check", 'c', 0, 0, "Only check syntax", 0},
    {"template", 't', "TEMPLATE_PATH", 0, "Create template at path", 0},
    {"format", 'f', "OUTPUT_FORMAT", 0, "Output format", 0},
    {"one-file", '1', 0, 0, "Option for one file", 0},
    {"using-extern-media", 'e', 0, 0, "Option for using external media", 0},
    {0}
};

/* Argp parser */
static struct argp argp =
{
    options, parse_opt, 0, doc
};

/* Check if required arguments are provided */
static error_t check_required_args(int key, char *arg, struct argp_state *state)
{
    if (key == ARGP_KEY_END) {
        struct arguments *arguments = state->input;
        if (!arguments->input_file || !arguments->output_file) {
            argp_failure(state, 1, 0, "Input and output files are required.");
        }
    }
    return 0;
}

#   else
#       error "Not have argp.h"
#   endif
#else
#   error "Platform not supported"
#endif


int do_step(void)
{

    if(input_file_data_cursor_offset == input_file_data_size)
    {
        return -1;
    }
    input_file_data_cursor += 1;
    input_file_data_cursor_offset -= 1;
    return 0;
}


int main(int argc, char **argv)
{
    /*
#if defined(_WIN32) || defined(_WIN64)
    printf("windows,");
#endif 

#if defined(__CYGWIN__)
    printf("cygwin,");
#endif

#if defined(unix) || defined(__unix) || defined(__unix__)
    printf("unix,");
#endif

#if defined(__APPLE__) || defined(__MACH__)
    printf("unix,");
#endif

#if defined(__linux__) || defined(linux) || defined(__linux)
    printf("linux,");
#endif

#if defined(__FreeBSD__)
    printf("freebsd");
#endif

    printf(" platform.\n");
    return 0;
*/

    int _ret = EXIT_FAILURE;
    /* set default streams  */
    input_stream = stdin;
    output_stream = stdout;
    input_stream_is_pipe = 1;


    struct arguments arguments;

    /* Default values for arguments */
    arguments.input_file = NULL;
    arguments.output_file = NULL;
    arguments.check_syntax = 0;
    arguments.template_path = NULL;
    arguments.output_format = NULL;
    arguments.one_file = 0;
    arguments.using_extern_media = 0;


    /* Parse the arguments */
    argp_parse(&argp, argc, argv, 0, 0, &arguments);


    /* Display the parsed arguments */
    printf("Input file: %s\n", arguments.input_file);
    printf("Output file: %s\n", arguments.output_file);
    printf("Check syntax: %d\n", arguments.check_syntax);
    printf("Template path: %s\n", arguments.template_path);
    printf("Output format: %s\n", arguments.output_format);
    printf("One file option: %d\n", arguments.one_file);
    printf("Using extern media: %d\n", arguments.using_extern_media);


    exit(_ret);
}
