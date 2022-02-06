# ft_printf
### libcのprintf関数を再コーディングする

|Function         | ft_printf                 |
|:-----------------|:-------------------------------|
|**Prototype**        | **int ft_printf(const char * , ...);** |
|**Turn in files**    | **\*.c, \*.h, Makefile** |
|**External functs**  | **malloc, free, write, va_start, va_arg, va_copy, va_end**            |

**以下に対応する**  
- フラグ文字  
「-0.# +」(そのうちの1つはスペース)
- フィールド幅  
最小のフィールド幅を指定する10進数の数値文字列 (文字列の最初の文字はゼロ以外)。
- 精度  
オプションである精度は、ピリオド ('.') とそれに続く10進数という形式で指定する 。
- 変換指定子  
「cspdiuxX%」
