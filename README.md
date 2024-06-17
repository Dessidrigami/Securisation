How to launch the program ?

1- Use the "make" command in the terminal
2- Create a "main.c" file at the root with a main function to test whatever you want
Example:

int main(int ac, const char *av[])
{
    hashtable_t *ht = new_hashtable(hash, 5);

    ht_insert(ht, "test", "réussi");
    ht_insert(ht, "Hallo ?", "oui");
    ht_dump(ht);
    return 0;
}

3- Use command "./cypher.sh" and here ! It's done :)
If any error occurs, please read it and correct what's wrong

Help:

You can use 5 functions in the main:

1- ht_dump: Show the hashtable and the value stored into
use: ht_dump([hashtable_name]);

2- ht_search: Search a value with a given key
use: char *[var_name] = ht_search([hashtable_name], [key]);

3- ht_delete: delete data from the hashtable
use: ht_delete([hashtable_name], [key])

4- ht_insert: adding a data to the hashtable with a key that'll be cyphered
use: ht_insert([hashtable_name], [key], [value]);

5- new_hashtable: create an hashtable to stock data
use: hashtable_t *[hashtable_name] = new_hashtable(hash, [hashtable_size]);
