
# 42_Libft_Updated
*My own version of Libft, after the official cursus project.*

## List of the functions :

#### 00 - is_something functions:

| Function Name | Description | Prototype |
|--|--|--|
| ft_incharset | return TRUE if the character 'c' is in the charset given in argument. | `t_bool  ft_incharset(char  c, const  char *charset)`|
| ft_isalnum | return TRUE if the character 'c' is alphanumerical | `t_bool  ft_isalnum(int  c)` |
| ft_isalpha | return TRUE if 'c' is a letter | `t_bool  ft_isalpha(int  c)` |
| ft_isascii | return TRUE if 'c' is an ascii character (0 to 128) | `t_bool  ft_isascii(int  c)`|
| ft_isbinary | return TRUE if 'c' is '0' or '1' | `t_bool  ft_isbinary(char  *str)` |
| ft_isdigit | return TRUE if 'c' is a number | `t_bool  ft_isdigit(int  c)` |
| ft_ishexa | return TRUE if 'c' is an hexa character (0123456789abcdefABCDEF) | `t_bool  ft_ishexa(char  *nbr)` |
| ft_isoctal | return TRUE if 'c' is an octal number (01234567) | `t_bool  ft_isoctal(char  *str)` |
| ft_isprint | return TRUE if 'c' is a printable character | `t_bool  ft_isprint(int  c)` |
| ft_isspace | return TRUE if 'c' is a space char (' ', '\t',...) | `t_bool  ft_isspace(int  c)` |
| ft_islower |  return TRUE if 'c' is a lowercase letter| `t_bool  ft_islower(int  c)` |
| ft_isupper | return TRUE if 'c' is an uppercase letter | `t_bool  ft_isupper(int  c)` |
| ft_isnumber | return TRUE if the string "nb" is only composed of numbers (allowed one '-' or '+' at first char) | `t_bool  ft_isnumber(char  *nb)`|
| ft_hasdouble | return TRUE if the int table tab[] contains at least two times the same int | `t_bool  ft_hasdouble(int  tab[], int  len)` |
| ft_issorted | return TRUE if tab[] is sorted in ascending (increasing = TRUE) or descending (increasing = FALSE) order | `t_bool  ft_issorted(int  tab[], int  len, t_bool  increasing)`|

#### 01 - get_len functions:

| Function Name | Description | Prototype |
|--|--|--|
| ft_hexalen | return the length of the hexadecimal number nb (size_t format)| `size_t  ft_hexalen(size_t  nb)` |
| ft_intlen | return the length of the int nb | `size_t  ft_intlen(int  nb)` |
| ft_nbrlen | return the length of the long int nb | `size_t  ft_nbrlen(long  nb)` |
| ft_strlen | return the lenght of the string s | `size_t  ft_strlen(const  char  *s)` |

#### 02 - numbers functions:

| Function Name | Description | Prototype |
|--|--|--|
| ft_atoi | return the given string str transformed to an int | int  ft_atoi(const  char  *str) |
| ft_atol | return the given string str transformed to a long | long  ft_atol(const  char  *str) |
| ft_max | return the max between ont a and b | `int  ft_max(int  a, int  b)` |
| ft_min | return the min between ont a and b | `int  ft_min(int  a, int  b)` |
| ft_power | return nbr ^ power  | `int  ft_power(int  power, int  nbr)` |
| ft_itoa | return the given int in the string format | `char  *ft_itoa(int  n)` | 

#### 03 - bases functions:

- ft_base_to_dec
- ft_bin_to_dec
- ft_oct_to_dec
- ft_hex_to_dec

#### 04 - put_something functions:

- ft_putchar_fd
- ft_putnbr_fd
- ft_putendl_fd
- ft_putstr_fd

#### 05 - strings functions:

- ft_split
- ft_strchr
- ft_striteri
- ft_strlcpy
- ft_strnstr
- ft_strlen
- ft_strrchr
- ft_strdup
- ft_strjoin
- ft_strmapi
- ft_strtrim
- ft_strlcat
- ft_strncmp
- ft_substr
- ft_ctolower
- ft_ctoupper

#### 06 - memory functions:

- ft_bzero
- ft_calloc
- ft_memchr
- ft_memset
- ft_memcpy
- ft_memmove
- ft_memcmp

#### 07 - chained_lists functions:
(void : http://sdz.tdct.org/sdz/les-listes-chainees-2.html)

- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- lstlast
- lstadd_back
- lstadd_back
- lstdelone
- lstclear

#### 08 - ft_printf function:

- ft_printf

## Whats next ?

#### 09 - get_next_line:
- GNL

#### 05 - strings:
- ft_stolower
- ft_stoupper

#### Convert

- (int)decimal to hex
- (int)decimal to octal
- (int)decimal to bin
- decimal to (char base + char nbr)
- convert_base
