/*
 * Insert some licensing stuff here.
 * Copyright (c) 2013 shoumik palkar.
 */

typedef uint8_t* BitMap_t;

BitMap_t alloc_bitmap(unsigned int size) {
    size_t buffSize = (size / 8) + 1;
    BitMap_t bmp = (BitMap_t)calloc(buffSize, sizeof(uint8_t));
    
    if (bmp == NULL) {
        errno = ENOMEM;
    }
    
    return bmp;
}

int check_bitmap(BitMap_t bitmap, unsigned int index) {
    
    if (bitmap == NULL) {
        errno = EINVAL;
        return errno;
    }
    
    unsigned int byte =  index / 8;
    uint8_t offset = index % 8;
    
    uint8_t shift = (0x1 << offset) & bitmap[byte];
    return (shift != 0);
}

void free_bitmap(BitMap_t bitmap) {
    if (bitmap != NULL) {
        free(bitmap);
    }
}

int set_bitmap(BitMap_t bitmap, unsigned int index) {
    
    if (bitmap == NULL) {
        errno = EINVAL;
        return errno;
    }
    
    unsigned int byte =  index / 8;
    uint8_t offset = index % 8;
    
    bitmap[byte] |= (0x1 << offset);
    
    return 0;
}

int unset_bitmap(BitMap_t bitmap, unsigned int index) {
    if (bitmap == NULL) {
        errno = EINVAL;
        return errno;
    }
    
    unsigned int byte =  index / 8;
    uint8_t offset = index % 8;
    
    bitmap[byte] &= (~(0x1 << offset));
    
    return 0;
}
