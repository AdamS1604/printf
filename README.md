# ft_printf
21school project ft_printf

This branch works on linux (ubuntu 20.04) tested 23.02.21
For macOS use branch macos.

## DIFFERENCE (linux | macos)
1. %p and %s different handling (if NULL passed)
2. different invaling spec handling:
   - (linux -> just output spec how it is)
   - (macos -> output width and flags no matter what)
3. percent handling

## TESTS
1. test1 - [ft_printf_tester](https://github.com/romslf/ft_printf_tester)
2. test2 - [ft_printf test](https://github.com/cacharle/ft_printf_test)
3. test3 - [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
