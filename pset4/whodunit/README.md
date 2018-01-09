# Questions

## What's `stdint.h`?

A library that provides a set of typedefs which specify exact-width integer types.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are values that will specify specific sizes for values, unsigned or otherwise.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A BYTE is 1 byte.  A DWORD, and LONG are both 8 bits.  A WORD is 2 bits.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

They must be BM.

## What's the difference between `bfSize` and `biSize`?

bfSize is the size (in bytes) of the BMP file. It is in the BITMAPFILEHEADER.
biSize is the size (in bytes) required by the structure.  It is in the BITMAPINFOHEADER.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the image is top-down.  The origin is the upper-left corner.  This is the sort we're working with.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

The file pointer returns NULL.

## Why is the third argument to `fread` always `1` in our code?

It is reading ONE RGBTRIPLE at a time.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

Padding will be 0.

## What does `fseek` do?

Sets the position of the steam to a given location

## What is `SEEK_CUR`?

That is a constant used with fseek.  It will specify that the offset being provided is in relation to the current file position.
