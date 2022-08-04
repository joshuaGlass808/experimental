#ifndef JLANG_IO_H
#define JLANG_IO_H

char*jlang_read_file(const char* filename);
void jlang_write_file(const char* filename, char* outbuffer);
char* sh(const char* cmd);

#endif
