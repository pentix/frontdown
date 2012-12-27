#ifndef __FRONTDOWN_H__
#define __FRONTDOWN_H__

#define FD_VERSION "0.1"
#define FD_PATHLEN 512
#define FD_BUCKETSIZE 256

struct exclude_list{
	char exclude_path[16384];
	struct exclude_list *next;
};
struct exclude_list *latest_file_exclude;
struct exclude_list *latest_dir_exclude;


struct{
	char source[16384];
	char destination[16384];
	
	unsigned int threads;
	char hidden;
	
	struct exclude_list *file_excludes;
	struct exclude_list *dir_excludes;
	
	char conf[16384];
	long long last_backup;
} config;


extern void parse_options(int argc, char **argv);
extern void help(void);

#endif
	
