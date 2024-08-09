#ifndef clox_table_h
#define clox_table_h

typedef struct {
  ObjString *key;
  Value value;
} Entry;

typedef struct {
  int count;
  int capacity;
  Entry *entries;
} Table;

void initTable(Table *table);
void freeTable(Table *table);
bool tableSet(Table *, ObjString *key, Value value);
void tableAddAll(Table *from, Table *to);
bool tableGet(Table *table, ObjString *key, Value *value);
bool tableDelete(Table *table, ObjString *key);
ObjString *tableFindString(Table *table, const char *chars, int length,
                           uint32_t hash);
void tableRemoveWhite(Table *table);
void markTable(Table *table);

#endif // clox_table_h