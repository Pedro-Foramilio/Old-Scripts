#define N 123
int hash(long int x);
typedef struct Info Info;
struct Info
{
    char info;
    long int unique_id;
    Info *next;
};
typedef Info* Hash[N];
void upsert(Hash table, Info *info);
Info* search(Hash table, long int unique_id);
void print_hash_table(Hash table);
void remove_info(Hash table, long int unique_id);
Info* create_info_random_id(char c);
Info* create_info(char c, long int id);
void free_hash_table(Hash table);