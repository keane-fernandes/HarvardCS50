# Questions

## What's `stdint.h`?
The <stdint.h> header shall declare sets of integer types having specified widths, and shall define corresponding sets of macros. It shall also define macros that specify limits of integer types corresponding to types defined in other standard headers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

uint8_t  - unsigned integer type (8 bit)
uint16_t - unsigned integer type (16 bit)
uint32_t - unsigned integer type (32 bit)
int32_t  - signed integer type (32 bit)

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE  - 1 byte
DWORD - 4 bytes
LONG  - 8 bytes
WORD  - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Identify the file format, For BMP files, it is BM.
   
B (66)     |    M (77) 
01000010   |    01001101        
0x42       |    0x4D

## What's the difference between `bfSize` and `biSize`?

bfSize stores the size of the whole BMP file — the size of the BMP image + the size of the headers.

biSizeImage stores the size of the BMP image — the size of the RGBTRIPLEs + the total size of the padding.

## What does it mean if `biHeight` is negative?

biHeight

The height of the bitmap, in pixels. If biHeight is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner. If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biBitCount member of the BITMAPINFOHEADER structure determines the number of bits that define each pixel and the maximum number of colors in the bitmap.

## Why might `fopen` return `NULL` in `copy.c`?

fopen might return a NULL pointer if the file that fopen is trying to 
write to doesn't exist.

## Why is the third argument to `fread` always `1` in our code?

We’re specifiying number of elements read, there’s only 1 struct

If we had been reading two files, it’d be 2 (e.g. two bitmap files)

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

Scanline needs to be a multiple of 4. Why it needs to be this way it isn’t explained. Bi.biwidth =3. 

Basically, it has to do with the CPU and intels standarization to 4 bytes, and a byte being 4 bits.

## What does `fseek` do?

Skips over any padding and then looks for the next pixel represented by RGB triple. File position indicator

## What is `SEEK_CUR`?

TODO
