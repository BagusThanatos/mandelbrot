#pragma once

//#include <unistd.h> TODO(bagus) : should also rewrite this

int getopt(
int argc,
char *argvp[],
char *optstring);

extern char *optarg;
extern int optind, opterr, optopt;

