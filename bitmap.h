/*
 * Insert some licensing stuff here.
 * Copyright (c) 2013 shoumik palkar.
 */

typedef uint8_t* BitMap_t;

/*
 * Allocate a bitmap with the input size
 *
 * Return: struct representing a new bitmap
 * Side Effects: errno set to ENOMEM if could not allocate 
 */
BitMap_t alloc_bitmap(unsigned int);

/*
 * Free the bitmap
 *
 * Return: 0 on success, nonzero value on error
 * Side Effects: errno set to EINVAL if invalid bitmap 
 */
int check_bitmap(BitMap_t, unsigned int);

/*
 * Free the bitmap
 *
 * Return: None
 * Side Effects: input pointer is invalidated 
 */
void free_bitmap(BitMap_t);

/*
 * Set the passed index to 1 in the bitmap
 *
 * Return: 0 if success, nonzero otherwise.
 * Side Effects: errno set
 */
int set_bitmap(BitMap_t, unsigned int);

/*
 * Set the passed value in the bitmap to 0
 *
 * Return: 0 if success, nonzero otherwise.
 * Side Effects: errno set
 */
int unset_bitmap(BitMap_t, unsigned int);
